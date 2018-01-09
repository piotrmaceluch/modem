#include <iomanip>

#include "Modulator.hpp"


namespace GLOBAL
{
    static int bitsCounter = 0;
    static int freqCounter = 0;
}

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
    for (auto &k : fourBits)
    {
        std::cout << k;
    }
    std::cout   << " \tZ " << complex <<"   " 
                << " \tCzestotliwosc " << frequency
                //<< ": \tGenerator value: " << generatorValue
                << ": \tAmplituda " << amplitude
                << ": \tFaza " << phase << std::endl;
}

void OFDM::Modulator::sendModulatorValuesToFiles(int N)
{
        std::ofstream myfile;
        myfile.open("c_mod_bits", std::fstream::app);
        for (int i=0 ; i<bitsPerSymbol ; i++)
        {
            myfile << int(fourBits[i]);
            myfile << "\n";
        }
        myfile.close();

        std::ofstream myfile1;
        myfile1.open("c_mod_real", std::fstream::app);
        myfile1 << complex.real();
        myfile1 << "\n";
        myfile1.close();

        std::ofstream myfile2;
        myfile2.open("c_mod_imaginary", std::fstream::app);
        myfile2 << complex.imag();
        myfile2 << "\n";
        myfile2.close();

        std::ofstream myfile3;
        myfile3.open("c_mod_complex", std::fstream::app);
        myfile3 << complex;
        myfile3 << "\n";
        myfile3.close();

        std::ofstream myfile4;
        myfile4.open("c_mod_amplitude", std::fstream::app);
        myfile4 << amplitude;
        myfile4 << "\n";
        myfile4.close();

        std::ofstream myfile5;
        myfile5.open("c_mod_phase", std::fstream::app);
        myfile5 << phase;
        myfile5 << "\n";
        myfile5.close();

        std::ofstream myfile6;
        myfile6.open("c_mod_frequency", std::fstream::app);
        myfile6 << frequency;
        myfile6 << "\n";
        myfile6.close();

        std::ofstream myfile7;
        myfile7.open("c_mod_angularVelocity", std::fstream::app);
        myfile7 << angularVelocity;
        myfile7 << "\n";
        myfile7.close();

        std::ofstream myfile8;
        myfile8.open("c_mod_rSubcarrierSamples", std::fstream::app);
        for(int i=0 ; i<N ; i++)
        {
            myfile8 << std::real(subcarrierSamples[i]);
            myfile8 << "\n";
        }
        myfile8.close();

        std::ofstream myfile9;
        myfile9.open("c_mod_iSubcarrierSamples", std::fstream::app);
        for(int i=0 ; i<N ; i++)
        {
            myfile9 << std::imag(subcarrierSamples[i]);
            myfile9 << "\n";
        }
        myfile9.close();
}