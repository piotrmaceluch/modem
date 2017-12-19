#include <iostream>
#include <string>
#include <complex>
#include <array>
#include <iomanip>  // wyswietlenie liczb w zapisie decymalnym, oraz dla dokladnosci liczb zmiennoprzecinkowych
#include <vector>
#include <cstdlib> // generowanie liczb pseudolosowych
//#include "gtest/gtest.h"

#include "functions.hpp"
#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

// ========= LAME VERSION =============
// #include "functions.cpp"
// #include "Modem.cpp"
// #include "Modulator.cpp"
// #include "Demodulator.cpp"
//=====================================

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();


    const int M = 8; //  number of subcarriers
    const int N = 64;

    std::vector<int> inputBits = {  0,0,0,0, 
                                    1,1,1,1, 
                                    0,1,1,0,
                                    1,0,0,1,
                                    1,0,0,0,
                                    0,1,0,0,
                                    0,0,1,0,
                                    0,0,0,1  };
                                    
    std::vector<double> frequencies;
    std::vector<double> time; // vector for time samples
    const double fs = 960;  // 8*fmax
    const double ts = 1/fs;
    const int bitsPerSymbol = 4;

    std::cout << std::fixed ;
    //===================== MODULATOR ==================================================================================
    
    std::vector<OFDM::Modulator> modulatorVector (M);   //  table for 4 subcarriers
    std::vector<std::complex<double>> sumOfSubcarriers; //  vector for output samples of subcarriers
    std::vector<double> modulatorOutput;                //  real part of IDFT output

    //fillInputBitsVector(inputBits, M, bitsPerSymbol); // tylko, gdy chcę, by modulator wypełniał wektor inputBits zależnie od ilości podnośnych

    setInputBits(modulatorVector, inputBits);
    setRealAndImaginary(modulatorVector);
    convertComplexToPolar(modulatorVector);
    fillVectorOfFrequencies(modulatorVector, frequencies, M);
    setZ(modulatorVector);
    setFrequencies(modulatorVector, frequencies);
    setTime(time, N, ts);
    setAngularVelocities(modulatorVector);
    createSubcarriers(modulatorVector, time, N);
    calculateIDFT(modulatorVector, sumOfSubcarriers, N);
    extractRealPart(sumOfSubcarriers, modulatorOutput, N);


    // //==================== DEMODULATOR =================================================================================
    
    std::vector<OFDM::Demodulator> demodulatorVector (M); // wektor 'podnosnych'
    std::vector<double> demodulatorInput(N);   // ciag probek wejsciowych na demodultorze
    std::vector<double> & DFTinput = demodulatorInput;  // alias
    std::vector<std::complex<double>> DFToutput;    // ciag wartosci zespolonych DFT
    std::vector<double> fAnalysis; // os czestotliwosci    
    std::copy(modulatorOutput.begin(), modulatorOutput.end(), demodulatorInput.begin());

    setFAnalysis(fAnalysis, fs, N);
    calculateDFT(demodulatorVector, DFTinput, DFToutput, N);
	
    setFrequencies(demodulatorVector, fAnalysis, DFToutput);
    setAngularVelocities(demodulatorVector);
    setSubcarriersVector (demodulatorVector, DFToutput, N);
    extractZ (demodulatorVector);
    extractAmplitude (demodulatorVector, N);
    extractPhase (demodulatorVector);
    setComplex(demodulatorVector);
    setBits(demodulatorVector);

    std::cout << "====== Modulator: =================================" << std::endl << std::endl;
    showValues(modulatorVector);

    std::cout << std::endl;

    std::cout << "====== Demodulator: ===================================" << std::endl << std::endl;
    showValues(demodulatorVector);

}
