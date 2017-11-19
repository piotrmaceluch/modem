#pragma once

#include<iostream>
#include<array>
#include<complex>


namespace modulator
{

  const std::complex<double> i(0, 1);
  static const int N = 16;

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
        std::complex<double> z;
        double samples[N];
        double generatorValue[N];
        std::complex<double> complex;
	
        Symbol( double real = 0.0,
                double imaginary = 0.0,
                double amplitude = 0.0,
                double phase = 0.0,
                double frequency = 0.0,
                double angularVelocity = 0.0,
                double z[2] = {},
                double generatorValue[N] = {},
                std::complex<double> complex = (0.0, 0.0))
	{
            this-> real = real;
            this-> imaginary = imaginary;
            this-> amplitude = amplitude;
            this-> phase = phase;
            this-> frequency = frequency;
            this-> angularVelocity = angularVelocity;
            //this-> z = z;
            //this-> generatorValue = generatorValue;
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

  


