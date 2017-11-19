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
        scArray[i].phase < 0
        ?   scArray[i].phase = 2*M_PI + scArray[i].phase
        :   scArray[i].phase = scArray[i].phase;
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
{// operuję na wartościach w formacie a + ib, więc zamiana na postać wykładniczą nie jest mi potrzebna
 // oczywiście dostaję tu te same wartości co Re{z} oraz Im{z}, z mapowania na konstelacje.
   for (int i=0 ; i<4 ; i++)
   {
        double a=0.0, b=0.0;
        a = scArray[i].amplitude * cos(scArray[i].phase);
        b = scArray[i].amplitude * sin(scArray[i].phase);
        scArray[i].z = {a, b};
   }
}

void setTime(double t[], const int N)
{
   double fs = 200.0; // Ponad 2 razy większa od największej częstotliwości zawartej w sygnale, czyli > 2*60kHz
   double ts = 1/fs;
   //double L = 100; //liczba próbek
   for (int i=0 ; i<N ; i++)
   {
       t[i] = ts * i;
       std::cout << t[i] << ", ";
       if (i%4 == 3)
            std::cout << std::endl;
   }
}

void generator(modulator::Symbol scArray[], int M, int N, double t[])
{
   for (int i=0 ; i<M ; i++)
   {
       for (int j=0 ; j<N ; j++)
       {
           //scArray[i].generatorValue[j] = scArray[i].z * exp(scArray[i].angularVelocity * t[j]);

            double a=0.0, b=0.0;
            a = cos(scArray[i].angularVelocity * t[j]);
            b = sin(scArray[i].angularVelocity * t[j]);
            std::complex<double> R = {a,b};
            scArray[i].generatorValue[j] = scArray[i].z * R;
       }
   }
}

void IDFT(modulator::Symbol scArray[], std::complex<double> summary[], int M, int N)
{
   for (int i=0 ; i<M ; i++)
   {
       for(int j=0 ; j<N ; j++)
       {
           summary[j] += scArray[i].generatorValue[j];
       }
   }
   std::cout << std::endl;
}

void realPartofOutput(std::complex<double> summary[], double output[], int M, int N)
{
    for (int i=0 ; i<N ; i++)
    {
        output[i] = summary[i].real();
    }

}
//============================================================================================================

void showFAnalysis (double fAnalysis[], int N, modulator::Symbol scArray[])
{
    std::cout << std::endl << "fAnalysis: " << std::endl;
    for(int i=0 ; i<N ; i++)
    {
        fAnalysis[i] = scArray[i].angularVelocity;
        std::cout << fAnalysis[i] << "  ";
    }
    std::cout << std::endl << std::endl;
}

void calculateDFT (std::complex<double> DFToutput[], int N, double output[])
{	// n-ilosc probek wejsciowych
       // m-indeks wartosci wyjsciowych
       // N-ilosc probek wejsciowych oraz wyjsciowych / rozdzielczosc
    for ( int m=0 ; m<N ; m++ )
    {
        for ( int n=0 ; n<N ; n++ )
        {
            double a = output[n] * cos(2*M_PI * n * m/N);
            double b = output[n] * sin(2*M_PI * n * m/N);
            DFToutput[m] = {a, b};
        }
    }
}

void showDFT (std::complex<double> DFToutput[], int M, int N) //  NAPRAWIĆ
{
std::cout << "wartości DFT:" << std::endl;
   for (int i=0 ; i<M ; i++)
   {
       for (int j=0 ; j<N ; j++)
       {
           std::cout << DFToutput[j] << std::endl;
       }
       std::cout << std::endl;
   }
}

void calculateAmplitudeAndPhase (std::complex<double> DFToutput[], int M, int N)
{
   std::cout << std::endl << "Amplituda i faza: " << std::endl;
   for (int i=0 ; i<N ; i++)
   {
       double a = DFToutput[i].real();
       double b = DFToutput[i].imag();
       std::complex<double> temp = {a, b};
       std::cout << abs(temp) << "e^";
       std::cout << arg(temp) << std::endl;
   }
}
