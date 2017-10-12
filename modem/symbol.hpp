#pragma once

#include<iostream>
#include<array>

namespace modulator
{

  class Symbol
  {
    public:
	int inputBits[4];
        double amplitude;
	double phase;
	double frequency;
	double angularVelocity;
	double real;
	double imaginary;
	double z;
	double generatorValue;
	double realGeneratorValue;
	double imaginaryGeneratorValue;
	
	Symbol( double amplitude = 0.0, 
		double phase = 0.0,
		double frequency = 0.0,
		double angularVelocity = 0.0,
		double real = 0.0,
		double imaginary = 0.0, 
		double z = 0.0,
		double generatorValue = 0.0,
		double realGeneratorValue = 0.0,
		double imaginaryGeneratorValue = 0.0)
	{
		this-> amplitude = amplitude;
		this-> phase = phase;
		this-> frequency = frequency;
		this-> angularVelocity = angularVelocity;
		this-> real = real;
		this-> imaginary = imaginary;
		this-> z = z;
		this-> generatorValue = generatorValue;
		this-> realGeneratorValue = realGeneratorValue;
		this-> imaginaryGeneratorValue = imaginaryGeneratorValue;
	}

	Symbol(Symbol &X)
	{
		this-> amplitude = amplitude;
		this-> phase = phase;
		this-> frequency = frequency;
		this-> angularVelocity = angularVelocity;
		this-> real = real;
		this-> imaginary = imaginary;
		this-> z = z;
		this-> generatorValue = generatorValue;
		this-> realGeneratorValue = realGeneratorValue;
		this-> imaginaryGeneratorValue = imaginaryGeneratorValue;
	}
	
	~Symbol() 
	{}
	
 	void showValues();


  }; // class Symbol
} //namespace modulator

  
void modulator::Symbol::showValues()
{	
	std::cout << "Input bits: ";
	for (int i=0 ; i<4 ; i++)
	{
		std::cout << inputBits[i];
	}
	std::cout << std::endl;
	std::cout << "Real: " 		<< real << std::endl;
	std::cout << "Imaginary: " 	<< imaginary << std::endl;
	std::cout << "Amplitude: " 	<< amplitude << std::endl;
	std::cout << "Phase[degrees]: " 	   	<< phase << std::endl;
	std::cout << "Frequency[kHz]: " 	<< frequency << std::endl;
	std::cout << "AngularVelocity: "<< angularVelocity << std::endl;
	std::cout << "Z: " 	   	<< z << std::endl;
	std::cout << "GeneratorValue: " << generatorValue << std::endl;		
	std::cout << std::endl;	
}

