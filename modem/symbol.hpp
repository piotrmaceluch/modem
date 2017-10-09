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
	double re;
	double im;


	Symbol( double amplitude = 0.0, 
		double phase = 0.0,
		double frequency = 0.0,
		double angularVelocity = 0.0,
		double re = 0.0,
		double im = 0.0)
	{
		this-> amplitude = amplitude;
		this-> phase = phase;
		this-> frequency = frequency;
		this-> angularVelocity = angularVelocity;
		this-> re = re;
		this-> im = im;
	}

	Symbol(Symbol &X)
	{
		this-> amplitude = amplitude;
		this-> phase = phase;
		this-> frequency = frequency;
		this-> angularVelocity = angularVelocity;
		this-> re = re;
		this-> im = im;
	}
	
	~Symbol() 
	{}
	
 	void showValues();
  };

  void Symbol::showValues()
  {
	std::cout << "Input bits: " << inputBits[0] 
				    << inputBits[1] 
				    << inputBits[2] 
				    << inputBits[3] << std::endl;
	std::cout << "Amplitude: " << amplitude << std::endl;
	std::cout << "Phase: " 	   << phase     << std::endl;
	std::cout << "Frequency: " << frequency << std::endl;
	std::cout << "AngularVelocity: " << angularVelocity << std::endl;
	std::cout << std::endl;	
  }

} //namespace modulator
