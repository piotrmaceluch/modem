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
//void setTime(double t[], const int N);
//void generateIDFT (modulator::Symbol scArray[], int M, int N, double t[]);

//void sumOfSubcarriers (modulator::Symbol scArray[], double summary[], int M, int N);

//void showFAnalysis(double fAnalysis[], int N, modulator::Symbol scArray[]);
//void calculateDFT (double DFT[2][1024], int N, modulator::Symbol scArray[]);
//void showDFT(double DFT[][1024]);
//void calculateAmplitudeAndPhase (double DFT[2][1024]);
