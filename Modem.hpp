# pragma once

#include<iostream>
#include<array>
#include<complex>
#include<vector>

namespace OFDM
{

    class Modem
    {
    public:
        static const int M = 6; //  number of subcarriers
        static const int N = 64;

        std::vector<int> fourBits;
        double real;
        double imaginary;
        double amplitude;
        double phase;
        double frequency;
        double angularVelocity;	
        std::complex<double> complex;
        std::vector<std::complex<double>> subcarrierSamples;
        std::complex<double> z;
        
    }; // class Modem
} //  namespace OFDM

  


