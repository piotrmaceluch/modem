#pragma once

#include<iostream>
#include<array>
#include<complex>


namespace modulator
{
  static const int N = 64;

  class Symbol
  {
     public:
	int inputBits[4];
        double real;
        double imaginary;
        double amplitude;
	double phase;
	double frequency;
	double angularVelocity;
        std::complex<double> generatorValue[N] = {};
        std::complex<double> samples[N] = {};
        std::complex<double> z;
        std::complex<double> complex;
	
        Symbol( double real = 0.0,
                double imaginary = 0.0,
                double amplitude = 0.0,
                double phase = 0.0,
                double frequency = 0.0,
                double angularVelocity = 0.0,
                std::complex<double> generatorValue[N] = {},
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
        /*
	Symbol(Symbol &X)
	{
                this-> amplitude = amplitude;
                this-> phase = phase;
                this-> frequency = frequency;
                this-> angularVelocity = angularVelocity;
                this-> z = z;
                this-> generatorValue = generatorValue;
                this-> realGeneratorValue = realGeneratorValue;
                this-> imaginaryGeneratorValue	= imaginaryGeneratorValue;
        */
	~Symbol() 
	{}
	
 	void showValues() const;


  }; // class Symbol
} //namespace modulator

  


