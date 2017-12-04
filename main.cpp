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

    // TO DO:
    // niepotrzebnie zamieniam 3+3i na Ae^jfi, skoro potem mnożę 2pi*f przez 3+3i a nie Ae^jfi. convertComplexToPolar jest niepotrzebne 
    std::vector<int> inputBits;
    std::vector<double> frequencies;
    
    const double fs = 960; // 2x bigger than biggest freq. in whole signal ->    >= 2*60kHz
    const double ts = 1/fs;
    const int bitsPerSymbol = 4;
    std::vector<double> time; //  time array for samples


    std::cout << std::fixed ;
    //===================== MODULATOR ==================================================================================
    
    std::vector<OFDM::Modulator> modulatorVector (OFDM::Modem::M);   //  table for 4 subcarriers
    std::vector<std::complex<double>> sumOfSubcarriers; //  vector for output samples of subcarriers
    std::vector<double> modulatorOutput;                //  real part of IDFT output
    
    fillInputBitsVector(inputBits, OFDM::Modem::M, bitsPerSymbol);
    setInputBits(modulatorVector, inputBits, bitsPerSymbol);
    setRealAndImaginary(modulatorVector);
    convertComplexToPolar(modulatorVector);
    fillFrequencies(modulatorVector, frequencies, OFDM::Modem::M);
    setZ(modulatorVector);
    createSubcarrier(modulatorVector, frequencies, time, ts, OFDM::Modem::N);
    calculateIDFT(modulatorVector, sumOfSubcarriers, OFDM::Modem::N);
    extractRealPart(sumOfSubcarriers, modulatorOutput, OFDM::Modem::N);

    //==================== DEMODULATOR =================================================================================
    
    std::vector<OFDM::Demodulator> demodulatorVector (OFDM::Modem::M); // wektor 'podnosnych'
    std::vector<double> demodulatorInput(OFDM::Modem::N);   // ciag probek wejsciowych na demodultorze
    std::vector<double> & DFTinput = demodulatorInput;  // alias
    std::vector<std::complex<double>> DFToutput;    // ciag wartosci zespolonych DFT
    std::vector<double> fAnalysis; // os czestotliwosci    
    std::copy(modulatorOutput.begin(), modulatorOutput.end(), demodulatorInput.begin());

    setFAnalysis(fAnalysis, fs, OFDM::Modem::N);
    calculateDFT(demodulatorVector, DFTinput, DFToutput, OFDM::Modem::N);
    setSubcarriersVector (demodulatorVector, DFToutput, OFDM::Modulator::N);
    extractZ(demodulatorVector, DFToutput, frequencies, ts, OFDM::Modem::N); // wyodrębnienie 4 podnośnych. Trzeba rozbić na mniejsze funkcje!!!!!!
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
