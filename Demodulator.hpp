#pragma once

#include<iostream>
#include<array>
#include<complex>

#include "Modem.hpp"

namespace OFDM
{
    class Demodulator final : public Modem
    {
    public:
        Demodulator(    double _real = 0.0,
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
                    )   :   Modem(  _real,
                                    _imaginary,
                                    _amplitude,
                                    _phase,
                                    _frequency,
                                    _angularVelocity,
                                    _complex,
                                    _generatorValue,
                                    _z,
                                    _fourBits,
                                    _subcarrierSamples 
                                ) {}  

        // Demodulator(Demodulator &Dem)
        // {
        //     real = Dem.real;
        //     imaginary = Dem.imaginary;
        //     amplitude = Dem.amplitude;
        //     phase = Dem.phase;
        //     frequency = Dem.frequency;
        //     angularVelocity = Dem.angularVelocity;
        //     generatorValue = Dem.generatorValue;
        //     z = Dem.z;
        //     complex = Dem.complex;
        // }

        virtual ~Demodulator()
        {}

        void showValues() const;
    }; //  class Demodulator
} // namespace OFDM