#include <iostream>
#include <string>
#include <complex>
#include <array>
#include <iomanip>
#include <array>
#include <vector>
//#include "gtest/gtest.h"

#include "functions.hpp"
#include "functions.cpp"

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

int main(int argc, char** argv)
{
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();

    // TO DO:
    // niepotrzebnie zamieniam 3+3i na Ae^jfi, skoro potem mnożę 2pi*f przez 3+3i a nie Ae^jfi. convertComplexToPolar jest niepotrzebne 
    const std::vector<int> inputBits = {0,0,0,0,  1,1,1,1,  1,1,0,0,  0,0,1,1,  0,1,1,0,  1,0,0,1};
    const std::vector<double> frequencies = {15.0, 30.0, 45.0, 60.0, 75.0, 90.0};
    
    const double fs = 960; // 2x bigger than biggest freq. in whole signal ->    >= 2*60kHz
    const double ts = 1/fs;
    const int bitsPerSymbol = 4;
    std::vector<double> time; //  time array for samples


    std::cout << std::fixed ;
    //===================== MODULATOR ==================================================================================
    
    std::vector<OFDM::Modulator> modulatorVector (OFDM::Modem::M);   //  table for 4 subcarriers
    std::vector<std::complex<double>> sumOfSubcarriers; //  vector for output samples of subcarriers
    std::vector<double> modulatorOutput;                //  real part of IDFT output
    
    setInputBits(modulatorVector, inputBits, bitsPerSymbol);
    setRealAndImaginary(modulatorVector);
    convertComplexToPolar(modulatorVector);
    setZ(modulatorVector);
    createSubcarrier(modulatorVector, frequencies, time, ts, OFDM::Modem::N);
    calculateIDFT(modulatorVector, sumOfSubcarriers, OFDM::Modem::N);
    extractRealPart(sumOfSubcarriers, modulatorOutput, OFDM::Modem::N);

    //==================== DEMODULATOR =================================================================================
    
    std::vector<OFDM::Demodulator> demodulatorVector (OFDM::Modem::M); // wektor 'podnosnych'
    std::vector<double> demodulatorInput(OFDM::Modem::N);   // ciag probek wejsciowych na demodultorze
    std::vector<double> & DFTinput = demodulatorInput;  // alias
    std::vector<std::complex<double>> DFToutput;    // ciag wartosci zespolonych DFT
    std::vector<double> fAnalysis; // os czestotliwosci    
    std::copy(modulatorOutput.begin(), modulatorOutput.end(), demodulatorInput.begin());

    setFAnalysis(fAnalysis, fs, OFDM::Modem::N);
    calculateDFT(demodulatorVector, DFTinput, DFToutput, OFDM::Modem::N);
    setSubcarriersVector (demodulatorVector, DFToutput, OFDM::Modulator::N);
    extractZ(demodulatorVector, DFToutput, frequencies, ts, OFDM::Modem::N); // wyodrębnienie 4 podnośnych. Trzeba rozbić na mniejsze funkcje!!!!!!
    setComplex(demodulatorVector);
    setBits(demodulatorVector);





    // std::cout << std::endl;
    // std::cout << "====== Modulator: =================================" << std::endl << std::endl;

    // std::cout << "------------------- Input bits: -------------------" << std::endl;
    // for ( int i=0 ; i<modulatorVector.size() ; i++)
    // {
    //     for (int j=0 ; j<modulatorVector[i].fourBits.size() ; j++)
    //         std::cout << modulatorVector[i].fourBits[j];
    //     std::cout << std::endl;
    // }

    // std::cout << "----------------- Real i Imag: --------------------" << std::endl;
    // for ( int i=0 ; i<modulatorVector.size() ; i++)
    // {
    //     std::cout << "Complex: " << modulatorVector[i].complex << std::endl;
    // }
    // std::cout << std::endl;

    // std::cout << "------------- Amplitude and Phase: ----------------" << std::endl;
    // for ( int i=0 ; i<modulatorVector.size() ; i++)
    // {
    //     std::cout << "Amplitude: " << modulatorVector[i].amplitude << std::endl;
    //     std::cout << "Phase: ";
    //     if (modulatorVector[i].phase >= 0)
    //     {
    //         std::cout << modulatorVector[i].phase * 180/M_PI << std::endl;
    //     }
    //     if (modulatorVector[i].phase < 0)
    //     {
    //         std::cout << 360 + modulatorVector[i].phase * 180/M_PI << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    // // ================= DO USTAWIENIA: CZY NA GENERATOR WYSYŁAĆ a) a+ib   czy    b) Ae^(j*fi)==========================
    // std::cout << "---------------------- Z: -------------------------" << std::endl; 
    // for ( int i=0 ; i<modulatorVector.size() ; i++)
    // {
    //     std::cout << "Z: " << modulatorVector[i].z << std::endl;
    // }
    // std::cout << std::endl;

    // std::cout << "-------------------- Time: ------------------------" << std::endl; 
    // for ( int i=0 ; i<time.size() ; i++)
    // {
    //     std::cout << "Time: " << time[i] << std::endl;
    // }
    // std::cout << std::endl;

    // std::cout << "----- Generator Value (Subcarriers samples): ------" << std::endl;
    // for ( int i=0 ; i<modulatorVector.size() ; i++)
    // {
    //     for (int j=0 ; j<modulatorVector[i].subcarrierSamples.size() ; j++)
    //         std::cout << modulatorVector[i].subcarrierSamples[j] << std::endl;
    //     std::cout << std::endl;
    // }

    // std::cout << "-------------------- IDFT: ------------------------" << std::endl;
    // for ( int i=0 ; i<sumOfSubcarriers.size() ; i++)
    // {
    //     std::cout << sumOfSubcarriers[i] << std::endl;
    // }
    // std::cout << std::endl;

    std::cout << "------------- Real part of output: ----------------" << std::endl;
    std::cout << "Wartosci wyjsciowe modulatora: " << std::endl;
    for(int i=0 ; i<OFDM::Modem::N ; i++)
    {
        std::cout << modulatorOutput[i] << std::endl;
    }
    std::cout << std::endl;







    std::cout << "====== Demodulator: ===================================" << std::endl << std::endl;
    
    std::cout << "--------------------- Input: ----------------------" << std::endl;
    for(int i=0 ; i<OFDM::Modem::N ; i++)
    {    
        std::cout << demodulatorInput[i] << std::endl;
    }
    std::cout << std::endl;
 

    std::cout << "------------------- DFT output --------------------" << std::endl;

    for (int j=0 ; j<DFToutput.size() ; j++)
    {
        std::cout << DFToutput[j] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "------ Check fAnalysis and demodulatorVector ------" << std::endl;
    std::cout << "fs: " << fs << std::endl;
    for(int i=0 ; i<OFDM::Modem::N ; i++)
    {    
        std::cout << "f: " << fAnalysis.at(i) << "\tDftsum: " << DFToutput.at(i) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "------------------ Extracted Z --------------------" << std::endl;
    for(int i=0 ; i<demodulatorVector.size() ; i++)
    {    
        std::cout << demodulatorVector[i].z << std::endl;
    }
    std::cout << std::endl;

    std::cout << "----------------- Real i Imag: --------------------" << std::endl;
    for ( int i=0 ; i<demodulatorVector.size() ; i++)
    {
        std::cout << "Complex: " << demodulatorVector[i].z << std::endl;
    }
    std::cout << std::endl;

    // std::cout << "------------- Amplitude and Phase: ----------------" << std::endl;
    // for ( int i=0 ; i<demodulatorVector.size() ; i++)
    // {
    //     std::cout << "Amplitude: " << demodulatorVector[i].amplitude << std::endl;
    //     if (demodulatorVector[i].phase >= 0)
    //     {
    //         std::cout << demodulatorVector[i].phase * 180/M_PI << std::endl;
    //     }
    //     if (demodulatorVector[i].phase < 0)
    //     {
    //         std::cout << 360 + demodulatorVector[i].phase * 180/M_PI << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
    // //    PYTANIA:
    // //              a) funkcja setTime. Jak wyskalować wektor czasu
    // //              b) w extractZ, *t.  Czy to ma być tak pomnożone, razy okres próbkowania
    
    std::cout << "---------------------- ZZZZZZZZZZZZZZZ ----------------------: " << std::endl;
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        std::cout << demodulatorVector[i].complex << std::endl;
    }



    std::cout << "====== Modulator: =================================" << std::endl << std::endl;
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        std::cout << "Prazek: " << i 
            << " \tCzestotliwosc " << modulatorVector[i].frequency
            //<< ": \tGenerator value: " << modulatorVector[i].generatorValue
            << ": \tAmplituda " << modulatorVector[i].amplitude
            << ": \tFaza " << modulatorVector[i].phase
            << ": \tBity ";
            for (int k=0 ; k<modulatorVector[i].fourBits.size() ; k++)
                std::cout << modulatorVector[i].fourBits[k];
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====== Demodulator: ===================================" << std::endl << std::endl;
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        std::cout << "Prazek: " << i 
            << " \tCzestotliwosc " << demodulatorVector[i].frequency
           //<< ": \tGenerator value: " << demodulatorVector[i].generatorValue
            << ": \tAmplituda " << demodulatorVector[i].amplitude
            << ": \tFaza " << demodulatorVector[i].phase
            << ": \tBity ";
            for (int k=0 ; k<demodulatorVector[i].fourBits.size() ; k++)
                std::cout << demodulatorVector[i].fourBits[k];
        std::cout << std::endl;
    }

    

}
