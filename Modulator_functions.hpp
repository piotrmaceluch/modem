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
