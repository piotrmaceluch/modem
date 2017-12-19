# pragma once

#include<iostream>
#include<array>
#include<complex>
#include<vector>


namespace GLOBAL
{
    static int bitsCounter = 0;
    static int freqCounter = 0;
}



namespace OFDM
{
    class Modem
    {
    protected:
        int bitsPerSymbol;
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
        
    public:   
        Modem(  int _bitsPerSymbol = 4,
                double _real = 0.0,
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

                :   bitsPerSymbol(_bitsPerSymbol),
                    real(_real),
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
            bitsPerSymbol = Mod.bitsPerSymbol;
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
        
        //void showValues() const;

        virtual ~Modem()
        {}
        
    }; // class Modem
} //  namespace OFDM

  


