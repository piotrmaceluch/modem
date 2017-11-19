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

        const int inputBits[16] = {0,0,1,0, 1,1,1,0, 1,0,0,1, 0,1,0,1};
        const int M = 4; //  number of subcarriers
        const int N = 16; //  number of samples in time and frequency domain + size of DFT
        const double frequencies[M] = {15, 30, 45, 60};
        double time[N]; //  time array
        std::complex<double> summary[N] = {}; //  array for output samples of subcarriers
        modulator::Symbol scArray[M]; //  table for 4 subcarriers

        setInputBits(scArray, inputBits);
        setFrequencies(scArray, frequencies);
        calculateAmplitudeAndPhase(scArray);
        convertComplexToPolar(scArray);
        setAngularVelocity(scArray);
        setZ(scArray);
        setTime(time, N);
        generator(scArray, M, N, time);
        
        showValuesForEverySymbol(scArray);
        std::cout << " IDFT(sum of subcarriers) " << std::endl;
        IDFT(scArray, summary, M, N);
        for (int i=0 ; i<N ; i++)
                std::cout << summary[i] << std::endl;

        double output[N]; //  Real part of summary of samples
        
        std::cout << std::endl;
        std::cout << std::endl;

        realPartofOutput(summary, output, M, N);
        std::cout << " Real part of sum of subcarriers " << std::endl;
        for (int i=0 ; i<N ; i++)
        {
                std::cout << output[i] << std::endl;
        }
        std::cout << "=================================" << std::endl;

        std::complex<double> DFToutput[N];
        calculateDFT(DFToutput, N, output);

        double fAnalysis[N];
        showFAnalysis(fAnalysis, N, scArray);


        showDFT(DFToutput, M, N);
        calculateAmplitudeAndPhase(DFToutput, M, N);


}
