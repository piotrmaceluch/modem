#pragma once

#include <iostream>
#include <array>
#include <complex>
#include <string>

#include "Modem.hpp"

namespace OFDM
{
    class Modulator final : protected Modem
    {
    public:
        

        Modulator(  int _bitsPerSymbol = 4,
                    double _real = 0.0,         // ALBO COMPLEX, ALBO REAL + IMAGINARY. JEDNO WYJEBAĆ
                    double _imaginary = 0.0,    // ALBO COMPLEX, ALBO REAL + IMAGINARY. JEDNO WYJEBAĆ
                    double _amplitude = 0.0,
                    double _phase = 0.0,
                    double _frequency = 0.0,
                    double _angularVelocity = 0.0,
                    std::complex<double> _complex = {}, // ALBO COMPLEX, ALBO REAL + IMAGINARY. JEDNO WYJEBAĆ
                    std::complex<double> _generatorValue = {},
                    std::complex<double> _z = {},
                    std::vector<int> _fourBits = {},
                    std::vector<std::complex<double>> _subcarrierSamples = {} 
                 )  :   Modem(  _bitsPerSymbol,
                                _real,
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

        // Modulator(Modulator &Mod)
        // {
        //     real = Mod.real;
        //     imaginary = Mod.imaginary;
        //     amplitude = Mod.amplitude;
        //     phase = Mod.phase;
        //     frequency = Mod.frequency;
        //     angularVelocity = Mod.angularVelocity;
        //     generatorValue = Mod.generatorValue;
        //     z = Mod.z;
        //     complex = Mod.complex;
        // }
        
        virtual ~Modulator()
        {}
        
        void setInputBits(const std::vector<int> &inputBits);
        void setReal();
        void setImaginary();
        void convertComplexToPolar();
        void setZ();
        void setFrequency(const std::vector<double> &frequencies);
        void setAngularVelocity();
        std::complex<double> returnSubcarrierSample(int i);
        void createSubcarrier(std::vector<double> &time, const int N);
        
        void showValues() const;
    }; //  class Modulator
} //  namespace OFDM
