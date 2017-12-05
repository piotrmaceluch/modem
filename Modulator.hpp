#pragma once

#include <iostream>
#include <array>
#include <complex>

#include "Modem.hpp"

namespace OFDM
{
    class Modulator final : public Modem
    {
    public:
        Modulator(  double _real = 0.0,
                    double _imaginary = 0.0,
                    double _amplitude = 0.0,
                    double _phase = 0.0,
                    double _frequency = 0.0,
                    double _angularVelocity = 0.0,
                    std::complex<double> _complex = {},
                    std::complex<double> _generatorValue = {},
                    std::complex<double> _z = {},
                    std::vector<int> _fourBits = {},
                    std::vector<std::complex<double>> _subcarrierSamples = {} 
                 )  :   Modem(  _real,
                                _imaginary,
                                _amplitude,
                                _phase,
                                _frequency,
                                _angularVelocity,
                                _complex,
                                _generatorValue,
                                _z,
                                _fourBits,
                                _subcarrierSamples   )
                    {}  

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
        
        virtual ~Modulator()
        {}

        void showValues() const;  
    }; //  class Modulator
} //  namespace OFDM