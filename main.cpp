#include<iostream>
#include<string>
#include<complex>
#include<array>
//#include "gtest/gtest.h"


#include "symbol.cpp"
#include "functions.cpp"


int main(int argc, char** argv)
{

    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS(); 

	const int inputBits[16] = {0,0,1,1,0,1,0,1,0,0,1,0,1,1,1,1};
	const double t = 66.7e-06; //  duration of symbol
	const double frequencies[4] = {15000.0, 30000.0, 45000.0, 60000.0};

	modulator::Symbol scArray[4]; //  table for 4 subcarriers
	
	setInputBits(scArray, inputBits);
	setFrequencies(scArray, frequencies);
	calculateAmplitudeAndPhase(scArray);
	convertComplexToPolar(scArray);
        setAngularVelocity(scArray);
        setZ(scArray);
        generateIDFT(scArray, t);
	showValuesForEverySymbol(scArray);

        long double sum = sumOfSubcarriers(scArray);

        std::cout << "Suma na wyjsciu demodulatora: " << sum << std::endl;

        int N = 4;
        double fAnalysis[N];
        std::cout << "fAnalysis: " ;
        for(int i=0 ; i<N ; i++)
        {
            fAnalysis[m] = scArray[i].angularVelocity;
            std::cout << fAnalysis[i] << "  ";
        }



        DFT(sum, int m, int N, scArray);

        std::cout << std::endl;
}


