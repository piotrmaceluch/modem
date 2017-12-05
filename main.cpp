#include <iostream>
#include <string>
#include <complex>
#include <array>
#include <iomanip>  // wyswietlenie liczb w zapisie decymalnym, oraz dla dokladnosci liczb zmiennoprzecinkowych
#include <array>
#include <vector>
#include <cstdlib> // generowanie liczb pseudolosowych
//#include "gtest/gtest.h"

#include "functions.hpp"
#include "functions.cpp"

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

int main(int argc, char** argv)
{
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();


    static const int M = 8; //  number of subcarriers
    static const int N = 1024;
    
    std::vector<int> inputBits;
    std::vector<double> frequencies;
    
    const double fs = 960; // 2x bigger than biggest freq. in whole signal ->    >= 2*60kHz
    const double ts = 1/fs;
    const int bitsPerSymbol = 4;
    std::vector<double> time; //  time array for samples


    std::cout << std::fixed ;
    //===================== MODULATOR ==================================================================================
    
    std::vector<OFDM::Modulator> modulatorVector (M);   //  table for 4 subcarriers
    std::vector<std::complex<double>> sumOfSubcarriers; //  vector for output samples of subcarriers
    std::vector<double> modulatorOutput;                //  real part of IDFT output
    
    fillInputBitsVector(inputBits, M, bitsPerSymbol);
    setInputBits(modulatorVector, inputBits, bitsPerSymbol);
    setRealAndImaginary(modulatorVector);
    convertComplexToPolar(modulatorVector);
    fillFrequencies(modulatorVector, frequencies, M);
    setZ(modulatorVector);
    createSubcarrier(modulatorVector, frequencies, time, ts, N);
    calculateIDFT(modulatorVector, sumOfSubcarriers, N);
    extractRealPart(sumOfSubcarriers, modulatorOutput, N);

    //==================== DEMODULATOR =================================================================================
    
    std::vector<OFDM::Demodulator> demodulatorVector (M); // wektor 'podnosnych'
    std::vector<double> demodulatorInput(N);   // ciag probek wejsciowych na demodultorze
    std::vector<double> & DFTinput = demodulatorInput;  // alias
    std::vector<std::complex<double>> DFToutput;    // ciag wartosci zespolonych DFT
    std::vector<double> fAnalysis; // os czestotliwosci    
    std::copy(modulatorOutput.begin(), modulatorOutput.end(), demodulatorInput.begin());

    setFAnalysis(fAnalysis, fs, N);
    calculateDFT(demodulatorVector, DFTinput, DFToutput, N);
    setSubcarriersVector (demodulatorVector, DFToutput, N);
    extractZ(demodulatorVector, DFToutput, frequencies, ts, N); // wyodrębnienie 4 podnośnych. Trzeba rozbić na mniejsze funkcje!!!!!!
    setComplex(demodulatorVector);
    setBits(demodulatorVector);

    std::cout << "====== Modulator: =================================" << std::endl << std::endl;
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        std::cout << "Podnosna nr: " << i 
            << " \tCzestotliwosc " << modulatorVector[i].frequency
            //<< ": \tGenerator value: " << modulatorVector[i].generatorValue
            << ": \tAmplituda " << modulatorVector[i].amplitude
            << ": \tFaza " << modulatorVector[i].phase 
            << ": \tBity ";
            for (int k=0 ; k<modulatorVector[i].fourBits.size() ; k++)
                std::cout << modulatorVector[i].fourBits[k];
        std::cout << std::endl;
    }


    std::cout << std::endl;

    std::cout << "====== Demodulator: ===================================" << std::endl << std::endl;
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        std::cout << "Podnosna nr: " << i 
            << " \tCzestotliwosc " << demodulatorVector[i].frequency
           //<< ": \tGenerator value: " << demodulatorVector[i].generatorValue
            << ": \tAmplituda " << demodulatorVector[i].amplitude
            << ": \tFaza " << demodulatorVector[i].phase
            << ": \tBity ";
            for (int k=0 ; k<demodulatorVector[i].fourBits.size() ; k++)
                std::cout << demodulatorVector[i].fourBits[k];
        std::cout << std::endl;
    }

}
