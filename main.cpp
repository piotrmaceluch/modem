#include <iostream>
#include <string>
#include <complex>
#include <array>
#include <iomanip>
//#include "gtest/gtest.h"


#include "symbol.cpp"
#include "functions.cpp"


int main(int argc, char** argv)
{
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();



        //std::cout << std::fixed;
        //std::cout << std::setprecision(3);


        const int inputBits[16] = {0,0,0,0, 1,1,1,1, 1,0,0,1, 1,0,1,0};
        const int M = 4; //  number of subcarriers
        const int N = 128; //  number of samples in time and frequency domain + size of DFT
        const double frequencies[M] = {15.0, 30.0, 45.0, 60.0};
        double time[N]; //  time array for samples
        double fs = 120.0; // Ponad 2 razy większa od największej częstotliwości zawartej w sygnale, czyli > 2*60kHz
        double ts = 1/fs;
        std::complex<double> summary[N] = {}; //  array for output samples of subcarriers
        modulator::Symbol scArray[M]; //  table for 4 subcarriers

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << std::endl<< std::endl  << "==========  MODULATOR ======================" << std::endl;
        setInputBits(scArray, inputBits);
        setFrequencies(scArray, frequencies);
        calculateAmplitudeAndPhase(scArray);
        convertComplexToPolar(scArray);
        setAngularVelocity(scArray);
        setZ(scArray);
        setTime(time, N, fs, ts);
        generator(scArray, M, N, time);
        
        showValuesForEverySymbol(scArray);
        std::cout << "------- IDFT(sum of subcarriers) --------" << std::endl;
        IDFT(scArray, summary, M, N);
        for (int i=0 ; i<N ; i++)
                std::cout << summary[i] << std::endl;

        double DFTinput[N]; //  Real part of summary of samples
        
        std::cout << std::endl;
        std::cout << std::endl;

        realPartofOutput(summary, DFTinput, M, N);
        std::cout << "---- Real part of sum of subcarriers ----" << std::endl;
        for (int i=0 ; i<N ; i++)
        {
                std::cout << DFTinput[i] << std::endl;
        }
        std::cout << "========== DEMODULATOR =====================" << std::endl;

        std::complex<double> DFToutput[N];
        calculateDFT(DFToutput, N, DFTinput);

        double fAnalysis[N];
        setFAnalysis(fAnalysis, N, scArray, fs, ts);

        showDFT(DFToutput, M, N);
        calculateAmplitudeAndPhase(DFToutput, M, N, fAnalysis);

        showOutput( DFToutput, N, fAnalysis);

}
