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

        const int inputBits[16] = {0,0,1,1, 0,1,0,1, 0,0,1,0, 1,1,1,1};
        const int M = 4; // number of subcarriers
        const int N = 16;
        const double frequencies[M] = {15, 30, 45, 60};
        double time[N]; // time array

        modulator::Symbol scArray[M]; //  table for 4 subcarriers

        setInputBits(scArray, inputBits);
        setFrequencies(scArray, frequencies);
        calculateAmplitudeAndPhase(scArray);
        convertComplexToPolar(scArray);
        setAngularVelocity(scArray);
        setZ(scArray);
//        setTime(time, N);
//        generateIDFT(scArray, M, N, time);
//        showValuesForEverySymbol(scArray);

//        double summary[N] = {};
//        sumOfSubcarriers(scArray, summary, M, N); // NIEUŻYTE
//        for (int i=0 ; i<16 ; i++)
//          std::cout << summary[i] << ", ";
//        std::cout << "Suma na wyjsciu demodulatora: " << std::endl << sum << std::endl;

        std::cout << "=================================" << std::endl;

//        double DFToutput[2][N];
//        calculateDFT (DFToutput, N, scArray);

//        double fAnalysis[N];

//        showFAnalysis(fAnalysis, N, scArray);
//        showDFT(DFToutput);
//        calculateAmplitudeAndPhase(DFToutput);


}
