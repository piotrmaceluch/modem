#include "Demodulator.hpp"

void OFDM::Demodulator::setFrequency(const double freq)
{
    frequency = freq;
}

void OFDM::Demodulator::setAngularVelocity()
{
    angularVelocity = 2 * M_PI * frequency;
}

std::complex<double> OFDM::Demodulator::setGeneratorValue(const std::vector<std::complex<double>> &DFToutput, int i)
{
    generatorValue = DFToutput[i]; 
}

void OFDM::Demodulator::setZ()
{
    z = generatorValue;
}

void OFDM::Demodulator::setAmplitude(const int N)
{
    double ratio = 2.0/N;
    amplitude = ratio * std::abs(z);
}

void OFDM::Demodulator::setPhase()
{
    phase = std::arg(z);
}

void OFDM::Demodulator::setComplex()
{
    double a = amplitude * cos(phase);
    double b = amplitude * sin(phase);
    complex = {a,b};
}

void OFDM::Demodulator::setBits()
{
    fourBits.resize(4);
        
    if (complex.real() < -2 )
    {
        fourBits[0] = 0;
        fourBits[1] = 0;
    }
    if (complex.real() >= -2 && complex.real() < 0)
    {
        fourBits[0] = 0;
        fourBits[1] = 1;
    }
    if (complex.real() >= 0 && complex.real() < 2)
    {
        fourBits[0] = 1;
        fourBits[1] = 1;
    }
    if (complex.real() >= 2)
    {
        fourBits[0] = 1;
        fourBits[1] = 0;
    }



    if (complex.imag() < -2)
    {
        fourBits[2] = 0;
        fourBits[3] = 0;
    }
    if (complex.imag() >= -2 && complex.imag() < 0)
    {
        fourBits[2] = 0;
        fourBits[3] = 1;
    }
    if (complex.imag() >= 0 && complex.imag( ) < 2)
    {
        fourBits[2] = 1;
        fourBits[3] = 1;
    }
    if (complex.imag() >= 2 )
    {
        fourBits[2] = 1;
        fourBits[3] = 0;
}
}

void OFDM::Demodulator::showValues() const
{ 
    std::cout << ":   Bity ";
    for (int k=0 ; k<fourBits.size() ; k++)
    {
        std::cout << fourBits[k];
    }
    std::cout   << "    Complex " << complex
                << " \tCzestotliwosc " << frequency
                //<< ": \tGenerator value: " << generatorValue
                << ": \tAmplituda " << amplitude
                << ": \tFaza " << phase << std::endl;
}
