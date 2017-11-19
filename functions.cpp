#include <iostream>
#include <string>
#include <complex>
#include <math.h>

#include "symbol.hpp"
#include "functions.hpp"
#include "complex"



void showValuesForEverySymbol(modulator::Symbol scArray[])
{
    for (int i=0 ; i<4 ; i++)
    {
        scArray[i].showValues();
    }
}

void setInputBits(modulator::Symbol scArray[], const int inputBits[])
{
    int k = 0;
    for(int i=0 ; i<4 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            scArray[i].inputBits[j] = inputBits[k++];
        }
    }
}

void setFrequencies(modulator::Symbol scArray[], const double frequencies[])
{
    for (int i=0 ; i<4 ; i++)
    {
        scArray[i].frequency = frequencies[i];
    }
}

void calculateAmplitudeAndPhase(modulator::Symbol scArray[])
{
    setRe(scArray);
    setIm(scArray);
}

void setRe(modulator::Symbol scArray[])
{
    for (int i=0 ; i<4 ; i++)
    {
        if (scArray[i].inputBits[0] == 0 &&  scArray[i].inputBits[1] == 0)
        {
            scArray[i].complex.real(-3.0);
        }

        if (scArray[i].inputBits[0] == 0 &&  scArray[i].inputBits[1] == 1)
        {
            scArray[i].complex.real(-1.0);
        }

        if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 1)
        {
            scArray[i].complex.real(1.0);
        }

        if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 0)
        {
            scArray[i].complex.real(3.0);
        }
    }
}

void setIm(modulator::Symbol scArray[])
{
    for (int i=0 ; i<4 ; i++)
    {
        if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 0)
        {
            scArray[i].complex.imag(-3.0);
        }

        if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 1)
        {
            scArray[i].complex.imag(-1.0);
        }

        if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 1)
        {
            scArray[i].complex.imag(1.0);
        }

        if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 0)
        {
            scArray[i].complex.imag(3.0);
        }
    }
}

void convertComplexToPolar(modulator::Symbol scArray[])
{
    for (int i=0 ; i<4 ; i++)
    {
        scArray[i].amplitude = std::abs(scArray[i].complex);
        scArray[i].phase = std::arg(scArray[i].complex);
    }
}

void setAngularVelocity(modulator::Symbol scArray[])
{
    for (int i=0 ; i<4 ; i++)
    {
        scArray[i].angularVelocity = 2 * M_PI * scArray[i].frequency;
    }
}

void setZ(modulator::Symbol scArray[])
{
    double a, b;
    a = double(scArray[0].amplitude * cos(scArray[0].phase));
    b = double(scArray[0].amplitude * sin(scArray[0].phase));
    std::cout << "amplitude: " << scArray[0].amplitude << std::endl;
    std::cout << "phase: " << scArray[0].phase << std::endl;
    std::cout << "A*cos(phase): " << double(a) << std::endl;
    std::cout << "A*sin(phase): " << (double)b << std::endl;
    std::complex<double> temp(a, b);
    scArray[0].z = temp;
    std::cout << "a + jb: " << temp << std::endl;
    std::cout << "z = temp? " << std::endl;
    std::cout << temp << " == " << scArray[0].z << std::endl << std::endl;

//    for (int i=0 ; i<4 ; i++)
//    {

//        std::cout << "amplitude: " << scArray[i].amplitude << std::endl;
//        std::cout << "phase: " << scArray[i].phase << std::endl;
//        std::cout << "A*cos(phase): " << (double)a << std::endl;
//        std::cout << "A*sin(phase): " << (double)b << std::endl;
//        std::complex<double> temp(a, b);
//        scArray[i].z = temp;
//        std::cout << "a + jb: " << temp << std::endl;
//        std::cout << "z = temp? " << std::endl;
//        std::cout << temp << " == " << scArray[i].z << std::endl << std::endl;
//    }
}

//void setTime(double t[], const int N)
//{
//    double fs = 1000.0;
//    double ts = 1/fs;
//    double L = 100; //liczba próbek
//    for (int i=0 ; i<N ; i++)
//    {
//        t[i] = ts * i;
//    }
//}

//void generateIDFT(modulator::Symbol scArray[], int M, int N, double t[])
//{
//    for (int i=0 ; i<M ; i++)
//    {
//        for (int j=0 ; j<N ; j++)
//        {
//            scArray[i].generatorValue[j] = scArray[i].z[0] * std::exp(scArray[i].angularVelocity * t[j]);
//            scArray[i].generatorValue[j] = scArray[i].z[1] * std::exp(scArray[i].angularVelocity * t[j]);
//        }
//    }
//}

//void sumOfSubcarriers(modulator::Symbol scArray[], double summary[], int M, int N)
//{
//    for (int i=0 ; i<M ; i++)
//    {
//        for(int j=0 ; j<N ; j++)
//        {
//            summary[j] += scArray[i].generatorValue[j];
//        }
//    }
//    std::cout << std::endl;
//}
//============================================================================================================

//void showFAnalysis (double fAnalysis[], int N, modulator::Symbol scArray[])
//{
//    std::cout << std::endl << "fAnalysis: " << std::endl;
//    for(int i=0 ; i<N ; i++)
//    {
//        fAnalysis[i] = scArray[i].angularVelocity;
//        std::cout << fAnalysis[i] << "  ";
//    }
//    std::cout << std::endl << std::endl;
//}

//void calculateDFT (double DFT[][4], int N, modulator::Symbol scArray[])
//{	// n-ilosc probek wejsciowych
//        // m-indeks wartosci wyjsciowych
//        // N-ilosc probek wejsciowych oraz wyjsciowych / rozdzielczosc
//    for ( int m=0 ; m<N ; m++ )
//    {
//        for ( int n=0 ; n<N ; n++ )
//        {
//            DFT[0][m] = scArray[m].z * cos(2*M_PI * n * m/N);
//            DFT[1][m] = scArray[m].z * sin(2*M_PI * n * m/N);
//        }
//    }
//}

////void sample(modulator:Symbol scArray[])
////{
////	double samples[4] =
////}

//void showDFT (double DFT[][4])
//{
//std::cout << "wartości DFT:" << std::endl;
//    for (int i=0 ; i<4 ; i++)
//    {
//        for (int j=0 ; j<2 ; j++)
//        {
//            std::cout << DFT[j][i] << ", \t";
//        }
//        std::cout << std::endl;
//    }
//}

//void calculateAmplitudeAndPhase (double DFT[][4])
//{
//    std::cout << std::endl << "Amplituda i faza: " << std::endl;
//    for (int i=0 ; i<4 ; i++)
//    {
//        double a = DFT[0][i];
//        double b = DFT[1][i];
//        std::complex<double> temp (a, b);
//        std::cout << abs(temp) << "e^";
//        std::cout << arg(temp) << std::endl;
//    }
//}
