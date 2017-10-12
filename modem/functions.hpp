#pragma once


void showValuesForEverySymbol(modulator::Symbol scArray[]);
void setInputBits(modulator::Symbol scArray[], int inputBits[]);
void serFrequencies(modulator::Symbol scArray[], const double frequencies[]);
void calculateAmplitudeAndPhase(modulator::Symbol scArray[]);
void setRe(modulator::Symbol scArray[]);
void setIm(modulator::Symbol scArray[]);
void convertComplexToPolar(modulator::Symbol scArray[]);
void setAngularVelocity(modulator::Symbol scArray[]);
void setZ(modulator::Symbol scArray[]);
void generateGeneratorValues(modulator::Symbol scArray[], const double t);
double * calculateIFFT(modulator::Symbol scArray[], double ifftTab[]);
