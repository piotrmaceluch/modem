#include <iostream>
#include <string>

#include "symbol.hpp"


void modulator::Symbol::showValues() const
{	
	std::cout << "Input bits: ";
	for (int i=0 ; i<4 ; i++)
	{
		std::cout << inputBits[i];
	}
	std::cout << std::endl;
        std::cout << "Real: " << complex.real() << std::endl;
        std::cout << "Imaginary: " << complex.imag() << std::endl;
        std::cout << "Amplitude: " << amplitude << std::endl;
        double degrees;
        if(phase<0)
            degrees = phase * 180/M_PI + 360;
        if(phase >= 0)
            degrees = phase * 180/M_PI;
        std::cout << "Phase[radians]: " << phase << ", [degrees]: " << degrees  << std::endl;
        std::cout << "Frequency[Hz]: " << frequency << std::endl;
        std::cout << "AngularVelocity: " << angularVelocity << std::endl;
        std::cout << "Z: " << z << std::endl;
        std::cout << "GeneratorValue: " << generatorValue << std::endl;
	std::cout << std::endl;	
}



