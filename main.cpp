#include <iostream>
#include <string>
#include <complex>
#include <array>
#include <iomanip> 
#include <vector>
#include <gtest/gtest.h>
#include <fstream>

#include "functions.hpp"
#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    const int M = 8; //  number of subcarriers
    const int N = 1024;

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

    std::cout << std::fixed;
    std::setprecision(10);
    //===================== MODULATOR ==================================================================================
    
    std::vector<OFDM::Modulator> modulatorVector (M);   //  table for 4 subcarriers
    std::vector<std::complex<double>> sumOfSubcarriers; //  vector for output samples of subcarriers
    std::vector<double> modulatorOutput;                //  real part of IDFT output

        
    setInputBits(modulatorVector, inputBits);
    setRealAndImaginary(modulatorVector);
    convertComplexToPolar(modulatorVector);
    fillVectorOfFrequencies(modulatorVector, frequencies);
    setZ(modulatorVector);
    setFrequencies(modulatorVector, frequencies);
    setTime(time, N, ts);
    setModulatorAngularVelocities(modulatorVector);
    createSubcarriers(modulatorVector, time, N);
    calculateIDFT(modulatorVector, sumOfSubcarriers, N);
    extractRealPart(sumOfSubcarriers, modulatorOutput, N);
    sendModulatorValuesToFiles(modulatorVector, modulatorOutput, sumOfSubcarriers, time, N, M);

    //==================== DEMODULATOR =================================================================================
    
    std::vector<OFDM::Demodulator> demodulatorVector (M); // wektor 'podnosnych'
    std::vector<double> demodulatorInput(N);   // ciag probek wejsciowych na demodultorze
    std::vector<double> & DFTinput = demodulatorInput;  // alias
    std::vector<std::complex<double>> DFToutput;    // ciag wartosci zespolonych DFT
    std::vector<double> fAnalysis; // os czestotliwosci    
    std::copy(modulatorOutput.begin(), modulatorOutput.end(), demodulatorInput.begin());

    setFAnalysis(fAnalysis, fs, N);
    calculateDFT(DFTinput, DFToutput, N);
    setFrequencies(demodulatorVector, fAnalysis, DFToutput);
    //setDemodulatorAngularVelocities(demodulatorVector);
    setSubcarriersVector (demodulatorVector, DFToutput, N);
    extractZ (demodulatorVector);
    extractAmplitude (demodulatorVector, N);
    extractPhase (demodulatorVector);
    setComplex(demodulatorVector);
    setBits(demodulatorVector);
    sendDemodulatorValuesToFiles(demodulatorVector, demodulatorInput, DFToutput, M, N);



    std::cout << "====== Modulator: =================================" << std::endl << std::endl;
        showModulatorValues(modulatorVector);
    std::cout << std::endl;

    std::cout << "====== Demodulator: ===================================" << std::endl << std::endl;
        showDemodulatorValues(demodulatorVector);
    std::cout << std::endl;
    
    

    return RUN_ALL_TESTS();
    }
