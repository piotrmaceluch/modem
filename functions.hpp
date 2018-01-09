#pragma once

#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

// template <typename T>
//     void setAngularVelocities(T &vector);
// template <typename T>
//     void showValues(T &vector);


void fillInputBitsVector(std::vector<int> &inputBits, const int M, const int BPS);
void setInputBits (std::vector<OFDM::Modulator> &modulatorVector, const std::vector<int> &inputBits);
void setTime (std::vector<double> &t, const int N, double const ts);
void setRealAndImaginary (std::vector<OFDM::Modulator> &modulatorVector);
void convertComplexToPolar (std::vector<OFDM::Modulator> &modulatorVector);
void fillVectorOfFrequencies(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &frequencies);
void setZ (std::vector<OFDM::Modulator> &modulatorVector);
void setFrequencies(std::vector<OFDM::Modulator> &modulatorVector, const std::vector<double> &frequencies);
void setModulatorAngularVelocities(std::vector<OFDM::Modulator> &modulatorVector);
void createSubcarriers(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &time, const int N);
void calculateIDFT (std::vector<OFDM::Modulator> &modulatorVector, 
    std::vector<std::complex<double>> &sumOfSubcarriers, const int N);
void extractRealPart (std::vector<std::complex<double>> &sumOfSubcarriers, 
    std::vector<double> &modulatorOutput, const int N);

void showModulatorValues(std::vector<OFDM::Modulator> &modulatorVector);
void sendModulatorValuesToFiles(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &modulatorOutput, 
    std::vector<std::complex<double>> &sumOfSubcarriers, const std::vector<double> &time, int N, int M);


void setFAnalysis (std::vector<double> &fAnalysis, const double fs, const int N);
void calculateDFT (const std::vector<double> &DFTinput, std::vector<std::complex<double>> &DFToutput, const int N);
void setFrequencies(std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<double> &fAnalysis, 
    std::vector<std::complex<double>> &DFToutput);
void setDemodulatorAngularVelocities(std::vector<OFDM::Demodulator> &demodulatorVector);
void setSubcarriersVector (std::vector<OFDM::Demodulator> &demodulatorVector, 
    const std::vector<std::complex<double>> &DFToutput, const int N);
void extractZ (std::vector<OFDM::Demodulator> &demodulatorVector);
void extractAmplitude (std::vector<OFDM::Demodulator> &demodulatorVector, const int N);
void extractPhase (std::vector<OFDM::Demodulator> &demodulatorVector);
void setComplex (std::vector<OFDM::Demodulator> &demodulatorVector);
void setBits (std::vector<OFDM::Demodulator> &demodulatorVector);

void showDemodulatorValues(std::vector<OFDM::Demodulator> &demodulatorVector);
void sendDemodulatorValuesToFiles(std::vector<OFDM::Demodulator> &demodulatorVector, std::vector<double> demodulatorInput, 
    std::vector<std::complex<double>> &DFToutput, const int M, const int N);

