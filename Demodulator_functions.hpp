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
#include "Demodulator.hpp"

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
    std::vector<std::complex<double>> &DFToutput, const int N);

