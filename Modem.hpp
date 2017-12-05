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
        
        double real;
        double imaginary;
        double amplitude;
        double phase;
        double frequency;
        double angularVelocity;	

        std::complex<double> complex;
        std::complex<double> generatorValue;
        std::complex<double> z;

        std::vector<int> fourBits;
        std::vector<std::complex<double>> subcarrierSamples;
        
        
        Modem(  double _real = 0.0,
                double _imaginary = 0.0,
                double _amplitude = 0.0,
                double _phase = 0.0,
                double _frequency = 0.0,
                double _angularVelocity = 0.0,
                std::complex<double> _complex = {},
                std::complex<double> _generatorValue = {},
                std::complex<double> _z = {},
                std::vector<int> _fourBits = {},
                std::vector<std::complex<double>> _subcarrierSamples = {} )  

                :   real(_real),
                    imaginary(_imaginary),
                    amplitude(_amplitude),
                    phase(_phase),
                    frequency(_frequency),
                    angularVelocity(_angularVelocity),
                    complex(_complex),
                    generatorValue(_generatorValue),
                    z(_z),
                    fourBits(_fourBits),
                    subcarrierSamples(_subcarrierSamples)  
                {}  
                
        Modem(Modem &Mod)
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
        
        virtual ~Modem()
        {}
        
    }; // class Modem
} //  namespace OFDM

  


