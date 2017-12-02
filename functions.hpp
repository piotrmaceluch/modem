#pragma once

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

// void showValues(std::array<OFDM::Modulator,4> &scArray);

template <typename T1> 
    void setFrequencies (std::vector<T1> &Vector, const std::vector<double> &frequencies);
template <typename T>
    void setAngularVelocity (std::vector<T> &Vector, const std::vector<double> &frequencies);

void setInputBits (std::vector<OFDM::Modulator> &modulatorVector, 
    const std::array<int,16> &inputBits, const int bitsPerSymbol);
void setTime (std::vector<double> &t, const int N, double const ts);
void setRealAndImaginary (std::vector<OFDM::Modulator> &modulatorVector);
void convertComplexToPolar (std::vector<OFDM::Modulator> &modulatorVector);
void setZ (std::vector<OFDM::Modulator> &modulatorVector);
void createSubcarrier (std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &t, 
    const int N, const std::vector<double> &frequencies);
void calculateIDFT (std::vector<OFDM::Modulator> &modulatorVector, 
    std::vector<std::complex<double>> &sumOfSubcarriers, const int N);
void extractRealPart (std::vector<std::complex<double>> &sumOfSubcarriers, 
    std::vector<double> &modulatorOutput, const int N);



void setFAnalysis (std::vector<double> &fAnalysis, const double fs, const int N);
void calculateDFT (std::vector<OFDM::Demodulator> &demodulatorVector, 
    const std::vector<double> &DFTinput, std::vector<std::complex<double>> &DFToutput, const int N);
void setSubcarriersVector (std::vector<OFDM::Demodulator> &demodulatorVector, 
    const std::vector<std::complex<double>> &DFToutput, const int N);
void extractZ (std::vector<OFDM::Demodulator> &demodulatorVector, 
    const std::vector<std::complex<double>> &DFToutput, 
    const std::vector<double> &frequencies, const double ts, const int N);
void setComplex (std::vector<OFDM::Demodulator> &demodulatorVector);
void setBits (std::vector<OFDM::Demodulator> &demodulatorVector);
