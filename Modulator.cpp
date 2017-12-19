#include "Modulator.hpp"



void OFDM::Modulator::setInputBits(const std::vector<int> &inputBits)
{
    for (int i=0 ; i<bitsPerSymbol ; i++)
    {
        fourBits.push_back(inputBits[GLOBAL::bitsCounter++]);
    }
}

void OFDM::Modulator::setReal()
{
    if (fourBits[0] == 0 &&  fourBits[1] == 0)
    {
        complex.real(-3.0);
    }
    if (fourBits[0] == 0 &&  fourBits[1] == 1)
    {
        complex.real(-1.0);
    }
    if (fourBits[0] == 1 &&  fourBits[1] == 1)
    {
        complex.real(1.0);
    }
    if (fourBits[0] == 1 &&  fourBits[1] == 0)
    {
        complex.real(3.0);
    }
}

void OFDM::Modulator::setImaginary()
{
    
    if (fourBits[2] == 0 &&  fourBits[3] == 0)
    {
        complex.imag(-3.0);
    }
    if (fourBits[2] == 0 &&  fourBits[3] == 1)
    {
        complex.imag(-1.0);
    }
    if (fourBits[2] == 1 &&  fourBits[3] == 1)
    {
        complex.imag(1.0);
    }
    if (fourBits[2] == 1 &&  fourBits[3] == 0)
    {
        complex.imag(3.0);
    }
}

void OFDM::Modulator::convertComplexToPolar()
{
    amplitude = std::abs(complex);
    phase = std::arg(complex); 
}

void OFDM::Modulator::setZ()
{
    z = { amplitude*cos(phase) , amplitude * sin(phase) };
}
        
void OFDM::Modulator::setFrequency(const std::vector<double> &frequencies)
{
    frequency = frequencies[GLOBAL::freqCounter++];
}

void OFDM::Modulator::setAngularVelocity()
{
    angularVelocity = 2*M_PI*frequency;
}

void OFDM::Modulator::createSubcarrier(std::vector<double> &time, const int N)
{
    for (int i=0 ; i<N ; i++)
    {
        double a=0.0, b=0.0;
        a = cos(angularVelocity * time[i]);
        b = sin(angularVelocity * time[i]);
        std::complex<double> R = {a,b};
        subcarrierSamples.push_back(z * R);
    }
}

std::complex<double> OFDM::Modulator::returnSubcarrierSample(int i)
{
    return subcarrierSamples[i];
}


void OFDM::Modulator::showValues() const
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

