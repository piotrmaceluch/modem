#include<iostream>
#include<string>
#include<complex>
#include<array>


#include "symbol.hpp"
#include "functions.cpp"


int main()
{
	int inputBits[16] = {0,0,1,1,0,1,0,1,0,0,1,0,1,1,1,1};
	
	const double frequencies[4] = {15000.0, 30000.0, 45000.0, 60000.0};
	
	const int sc_size = 4;
	modulator::Symbol scArray[4];	//stworzenie 4 przyszlych-podnosnych
	
	setInputBits(scArray, inputBits);
	//showValuesForEverySymbol(scArray);	
	
	setFrequencies(scArray, frequencies);
	//showValuesForEverySymbol(scArray);

	setAmplitudeAndPhase(scArray);	
	showValuesForEverySymbol(scArray);



}


