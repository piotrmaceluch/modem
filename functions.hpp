#pragma once


void showValuesForEverySymbol	(modulator::Symbol scArray[]);
void setInputBits		(modulator::Symbol scArray[], const int inputBits[]);
void serFrequencies		(modulator::Symbol scArray[], const double frequencies[]);
void calculateAmplitudeAndPhase	(modulator::Symbol scArray[]);
void setRe			(modulator::Symbol scArray[]);
void setIm			(modulator::Symbol scArray[]);
void convertComplexToPolar	(modulator::Symbol scArray[]);
void setAngularVelocity         (modulator::Symbol scArray[]);
void setZ                       (modulator::Symbol scArray[]);
void generateIDFT               (modulator::Symbol scArray[], const double t);
long double sumOfSubcarriers         (modulator::Symbol scArray[]);


void DFT                        (double x, int m, int N, modulator::Symbol::scArray[]);

