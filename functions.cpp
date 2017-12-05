#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>

#include "functions.hpp"

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"

//typedef std::array<OFDM::Modulator,4> scArray_;

// void showValues(const std::vector<OFDM::Modulator> &modulatorVector)
// {
//     for (int i=0 ; i<modulatorVector.size() ; i++)
//     {
//         modulatorVector[i].showValues();
//     }
// }

template <typename T1>
void setFrequencies(std::vector<T1> &Vector, const std::vector<double> &frequencies)
{
    for (int i=0 ; i<Vector.size() ; i++)
    {
        Vector[i].frequency = frequencies[i];
    }
}

template <typename T>
void setAngularVelocity (std::vector<T> &Vector, const std::vector<double> &frequencies)
{
    setFrequencies(Vector, frequencies);

    for (int i=0 ; i<Vector.size() ; i++)
        Vector[i].angularVelocity = 2*M_PI*Vector[i].frequency;
}




void fillInputBitsVector(std::vector<int> &inputBits, const int M, const int BPS)
{
    for (int i=0 ; i<M*BPS ; i++)
    {
        inputBits.push_back(( std::rand() % 2 ) + 0);
    }
}


void setInputBits(std::vector<OFDM::Modulator> &modulatorVector, const std::vector<int> &inputBits,  const int bitsPerSymbol)
{
    int k=0;
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].fourBits.resize(4);

        for (int j=0 ; j<bitsPerSymbol ; j++)
        {
            modulatorVector[i].fourBits[j] = inputBits[k++];
        }
    }
}

void setRe(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        if (modulatorVector[i].fourBits[0] == 0 &&  modulatorVector[i].fourBits[1] == 0)
        {
            modulatorVector[i].complex.real(-3.0);
        }
        if (modulatorVector[i].fourBits[0] == 0 &&  modulatorVector[i].fourBits[1] == 1)
        {
            modulatorVector[i].complex.real(-1.0);
        }
        if (modulatorVector[i].fourBits[0] == 1 &&  modulatorVector[i].fourBits[1] == 1)
        {
            modulatorVector[i].complex.real(1.0);
        }
        if (modulatorVector[i].fourBits[0] == 1 &&  modulatorVector[i].fourBits[1] == 0)
        {
            modulatorVector[i].complex.real(3.0);
        }
    }
}

void setIm(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        if (modulatorVector[i].fourBits[2] == 0 &&  modulatorVector[i].fourBits[3] == 0)
        {
            modulatorVector[i].complex.imag(-3.0);
        }
        if (modulatorVector[i].fourBits[2] == 0 &&  modulatorVector[i].fourBits[3] == 1)
        {
            modulatorVector[i].complex.imag(-1.0);
        }
        if (modulatorVector[i].fourBits[2] == 1 &&  modulatorVector[i].fourBits[3] == 1)
        {
            modulatorVector[i].complex.imag(1.0);
        }
        if (modulatorVector[i].fourBits[2] == 1 &&  modulatorVector[i].fourBits[3] == 0)
        {
            modulatorVector[i].complex.imag(3.0);
        }
    }
}

void setRealAndImaginary(std::vector<OFDM::Modulator> &modulatorVector)
{
    setRe(modulatorVector);
    setIm(modulatorVector);
}

void convertComplexToPolar(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].amplitude = std::abs(modulatorVector[i].complex);
        modulatorVector[i].phase = std::arg(modulatorVector[i].complex);
    }
}

void fillFrequencies(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &frequencies, int M)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        frequencies.push_back((i+1) * 15);
    }
}
void setZ(std::vector<OFDM::Modulator> &modulatorVector)
{   // operuję na wartościach w formacie a + ib, więc zamiana na postać wykładniczą nie jest mi potrzebna
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        //  Later I'll use in generator, complex values instead of exponential
        modulatorVector[i].z = { modulatorVector[i].amplitude * cos(modulatorVector[i].phase),
                                modulatorVector[i].amplitude * sin(modulatorVector[i].phase) };
    }
}

void setTime(std::vector<double> &t, const int N, double ts)
{
   //   0 : ts : (N-1)*ts
   for (int i=0 ; i<N ; i++)
   {
       t.push_back(ts * i);
   }
}

void createSubcarrier(std::vector<OFDM::Modulator> &modulatorVector, const std::vector<double> frequencies, std::vector<double> &t, const double ts, const int N)
{
    setAngularVelocity(modulatorVector, frequencies);
    setTime(t, N, ts);
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
       for (int j=0 ; j<N ; j++)
        {
            double a=0.0, b=0.0;
            a = cos(modulatorVector[i].angularVelocity * t[j]);
            b = sin(modulatorVector[i].angularVelocity * t[j]);
            std::complex<double> R = {a,b};
            modulatorVector[i].subcarrierSamples.push_back(modulatorVector[i].z * R);
        }
    }
}

void calculateIDFT(std::vector<OFDM::Modulator> &modulatorVector, std::vector<std::complex<double>> &sumOfSubcarriers, const int N)
{
    std::complex<double> temp;

    for (int i=0 ; i<N ; i++)
    {
        temp = {0.0, 0.0};
        for (int j=0 ; j<modulatorVector.size() ; j++)
        {
            temp += modulatorVector[j].subcarrierSamples[i]; 
        }
        sumOfSubcarriers.push_back(temp);
    }
}

void extractRealPart(std::vector<std::complex<double>> &sumOfSubcarriers, std::vector<double> &modulatorOutput, const int N)
{
    for (int i=0 ; i<N ; i++)
    {
        modulatorOutput.push_back(sumOfSubcarriers[i].real());
    }
}

//====================================================================================
//======================== DEMODULATOR ===============================================
//====================================================================================

void calculateDFT (std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<double> &DFTinput, std::vector<std::complex<double>> &DFToutput, const int N)
{       // n-indeks wartosci wejsciowych
        // m-indeks wartosci wyjsciowych
        // N-ilosc probek wejsciowych oraz wyjsciowych / rozdzielczosc
    std::complex<double> stripe;
    std::complex <double> temp;
    double a;
    double b;
    for ( int m=0 ; m<N ; m++ )
    {
        a = 0.0;
        b = 0.0;
        stripe = {0,0};
        for ( int n=0; n<N ; n++)
        {
            a = DFTinput[n] *        cos(2*M_PI*n*m/N);
            b = DFTinput[n] * (-1) * sin(2*M_PI*m*n/N);
            temp = {a, b};
            stripe += temp;
        }
        DFToutput.push_back(stripe);
    }
}

void setFAnalysis (std::vector<double> &fAnalysis, const double fs, const int N)
{   
    for(int m=0 ; m<N ; m++)
    {
        fAnalysis.push_back(m*fs/N);
    }
}             

void setSubcarriersVector (std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<std::complex<double>> &DFToutput, const int N)
{
    
    for (int i=0,j=0 ; j<demodulatorVector.size() || i<N ; i++)
    {
        if ( std::abs(DFToutput[i]) > 1 )
        {
            demodulatorVector[j++].generatorValue = DFToutput[i];   // do pola 'generatorValue' trafia wartosc wyjsciowa DFT. generatorVaue to inaczej z * e^(j*w*t)
        }
        else
        {
            continue;
        }
    }
}

void extractZ (std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<std::complex<double>> &DFToutput, const std::vector<double> &frequencies, const double ts, const int N)
{   
    std::complex<double> gen ;  // gen = a+ib  czyli  e^(j*w*t) 
    double ratio = 2.0/N; // Mr=A*N/2  =>  A=Mr*2/N  (Mr = amplituda prążka)
    setAngularVelocity(demodulatorVector, frequencies);

    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        double a = cos(demodulatorVector[i].angularVelocity* ts*N);
        double b = sin(demodulatorVector[i].angularVelocity* ts*N);
        gen = {a,b}; // gen = e^(jwt)

        demodulatorVector[i].z = demodulatorVector[i].generatorValue;
        demodulatorVector[i].amplitude = ratio * std::abs(demodulatorVector[i].z);
        demodulatorVector[i].phase = std::arg(demodulatorVector[i].z);
    }
}

void setComplex (std::vector<OFDM::Demodulator> &demodulatorVector)
{
    double a,b;
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        a = demodulatorVector[i].amplitude * cos(demodulatorVector[i].phase);
        b = demodulatorVector[i].amplitude * sin(demodulatorVector[i].phase);
        demodulatorVector[i].complex = {a,b};
    }
}

void setBits(std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].fourBits.resize(4);
        
        if (demodulatorVector[i].complex.real() < -2 )
        {
            demodulatorVector[i].fourBits[0] = 0;
            demodulatorVector[i].fourBits[1] = 0;
        }
        if (demodulatorVector[i].complex.real() >= -2 && demodulatorVector[i].complex.real() < 0)
        {
            demodulatorVector[i].fourBits[0] = 0;
            demodulatorVector[i].fourBits[1] = 1;
        }
        if (demodulatorVector[i].complex.real() >= 0 && demodulatorVector[i].complex.real() < 2)
        {
            demodulatorVector[i].fourBits[0] = 1;
            demodulatorVector[i].fourBits[1] = 1;
        }
        if (demodulatorVector[i].complex.real() >= 2)
        {
            demodulatorVector[i].fourBits[0] = 1;
            demodulatorVector[i].fourBits[1] = 0;
        }



        if (demodulatorVector[i].complex.imag() < -2)
        {
            demodulatorVector[i].fourBits[2] = 0;
            demodulatorVector[i].fourBits[3] = 0;
        }
        if (demodulatorVector[i].complex.imag() >= -2 && demodulatorVector[i].complex.imag() < 0)
        {
            demodulatorVector[i].fourBits[2] = 0;
            demodulatorVector[i].fourBits[3] = 1;
        }
        if (demodulatorVector[i].complex.imag() >= 0 && demodulatorVector[i].complex.imag( ) < 2)
        {
            demodulatorVector[i].fourBits[2] = 1;
            demodulatorVector[i].fourBits[3] = 1;
        }
        if (demodulatorVector[i].complex.imag() >= 2 )
        {
            demodulatorVector[i].fourBits[2] = 1;
            demodulatorVector[i].fourBits[3] = 0;
        }
    }
}