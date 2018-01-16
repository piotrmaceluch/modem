#include "Demodulator.hpp"

void OFDM::Demodulator::setFrequency(const double freq)
{
    frequency = freq;
}

void OFDM::Demodulator::setAngularVelocity()
{
    angularVelocity = 2 * M_PI * frequency;
}

void OFDM::Demodulator::setGeneratorValue(const std::vector<std::complex<double>> &DFToutput, int i)
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

void OFDM::Demodulator::sendDemodulatorValuesToFile()
{


    //   ODPOWIEDNIA KOLEJNOŚĆ
    //   ODPOWIEDNIE WARTOŚCI
        std::ofstream myfile1;
        myfile1.open("c_dem_frequency", std::fstream::app);
        myfile1 << frequency;
        myfile1 << "\n";
        myfile1.close();
        
        std::ofstream myfile4;
        myfile4.open("c_dem_amplitude", std::fstream::app);
        myfile4 << amplitude;
        myfile4 << "\n";
        myfile4.close();

        std::ofstream myfile5;
        myfile5.open("c_dem_phase", std::fstream::app);
        myfile5 << phase;
        myfile5 << "\n";
        myfile5.close();

        std::ofstream myfile6;
        myfile6.open("c_dem_bits", std::fstream::app);
        for (int i=0 ; i<bitsPerSymbol ; i++)
        {
            myfile6 << int(fourBits[i]);
            myfile6 << "\n";
        }
        myfile6.close();
}
