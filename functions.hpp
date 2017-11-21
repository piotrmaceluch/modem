#pragma once


void showValuesForEverySymbol (modulator::Symbol scArray[]);
void setInputBits (modulator::Symbol scArray[], const int inputBits[]);
void serFrequencies (modulator::Symbol scArray[], const double frequencies[]);
void calculateAmplitudeAndPhase	(modulator::Symbol scArray[]);
void setRe (modulator::Symbol scArray[]);
void setIm (modulator::Symbol scArray[]);
void convertComplexToPolar (modulator::Symbol scArray[]);
void setAngularVelocity (modulator::Symbol scArray[]);
void setZ (modulator::Symbol scArray[]);
void setTime(double t[], const int N, double fs, double ts);
void generator (modulator::Symbol scArray[], int M, int N, double t[]);
void IDFT(modulator::Symbol scArray[], std::complex<double> summary[], int M, int N);
void realPartofOutput(std::complex<double> summary[], double output[], int M, int N);
void setFAnalysis(double fAnalysis[], int N, modulator::Symbol scArray[], double fs, double ts);
void calculateDFT (std::complex<double> DFToutput[], int N, double output[]);
void showDFT(std::complex<double> DFToutput[], int M, int N);
void calculateAmplitudeAndPhase (std::complex<double> DFToutput[], int M, int N);
