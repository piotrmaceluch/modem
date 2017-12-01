#pragma once

#include<iostream>
#include<array>
#include<complex>

#include "Modem.hpp"

namespace OFDM
{
    class Demodulator : public Modem
    {
    public:
        std::complex<double> generatorValue;
        
        Demodulator(  double real = 0.0,
                      double imaginary = 0.0,
                      double amplitude = 0.0,
                      double phase = 0.0,
                      double frequency = 0.0,
                      double angularVelocity = 0.0,
                      std::complex<double> generatorValue = {},
                      std::complex<double> z = {},
                      std::complex<double> complex = {} )
    	            {
                      this-> real = real;
                      this-> imaginary = imaginary;
                      this-> amplitude = amplitude;
                      this-> phase = phase;
                      this-> frequency = frequency;
                      this-> angularVelocity = angularVelocity;
                      //this-> generatorValue = generatorValue;
                      this-> z = z;
                      this-> complex = complex;
                    }
        ~Demodulator()
        {}
    }; //  class Demodulator
} // namespace OFDM