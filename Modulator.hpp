#pragma once

#include<iostream>
#include<array>
#include<complex>

#include "Modem.hpp"

namespace OFDM
{
    class Modulator final : public Modem
    {
    public:
        Modulator(  double real = 0.0,
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
                        this-> generatorValue = generatorValue;
                        this-> z = z;
                        this-> complex = complex;
                    }
        Modulator(Modulator &Mod)
        {
            real = Mod.real;
            imaginary = Mod.imaginary;
            amplitude = Mod.amplitude;
            phase = Mod.phase;
            frequency = Mod.frequency;
            angularVelocity = Mod.angularVelocity;
            generatorValue = Mod.generatorValue;
            z = Mod.z;
            complex = Mod.complex;
        }
        ~Modulator()
        {}

        void showValues() const;  
    }; //  class Modulator
} //  namespace OFDM