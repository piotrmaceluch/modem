#include <iostream>
#include <string>

#include "Demodulator.hpp"

void OFDM::Deodulator::showValues() const
{	
    std::cout << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Input bits: \t";
    for (int i=0 ; i<4 ; i++)
    {
        std::cout << inputBits[i];
    }
    std::cout << std::endl;
    std::cout << "Real: \t\t" << complex.real() << std::endl;
    std::cout << "Imaginary: \t" << complex.imag() << std::endl;
    std::cout << "Amplitude: \t" << amplitude << std::endl;
    std::cout << "Phase[radians]: " << phase << std::endl;
    std::cout << "Z: \t\t" << z  << " ["<< amplitude << "e^" << phase << "]" << std::endl;
    std::cout << "Frequency[kHz]: " << frequency << std::endl;
    std::cout << "AngularVelocity: " << angularVelocity << std::endl;
    std::cout << "GeneratorValue: " << std::endl;
    for (int i=0 ; i<N ; i++)
    {
        std::cout << this->generatorValue[i] << std::endl;
    }
    std::cout << std::endl;
}