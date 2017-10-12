#include<iostream>
#include<string>
#include<complex>
#include<array>


#include "symbol.hpp"
#include "functions.cpp"


int main()
{
	int inputBits[16] = {0,0,1,1,0,1,0,1,0,0,1,0,1,1,1,1};
	const double t = 66.7e-06; //  duration of symbol
	const double frequencies[4] = {15000.0, 30000.0, 45000.0, 60000.0};
	double ifftTab[2] {}; //  ifftTab[0] for real, ifftTab[1] for imaginary
	double reSamples[16] {}; // real samples after IFFT
	double imSamples[16] {}; // imaginary samples after IFFT

	modulator::Symbol scArray[4];	//table for 4 subcarriers
	
	setInputBits(scArray, inputBits);	
	setFrequencies(scArray, frequencies);
	calculateAmplitudeAndPhase(scArray);	
	convertComplexToPolar(scArray);
	setAngularVelocity(scArray);
	setZ(scArray);
	generateGeneratorValues(scArray,t);
	showValuesForEverySymbol(scArray);
	calculateIFFT(scArray, ifftTab);
	std::cout << ifftTab[0] << std::endl;
	std::cout << ifftTab[1] << std::endl;
}


