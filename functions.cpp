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
        for (int i=0 ; i<4 ; i++)
        {
                scArray[i].z = scArray[i].amplitude * std::exp(i * scArray[i].phase);
        }
}

void generateIDFT(modulator::Symbol scArray[], const double t)
{
        for (int i=0 ; i<4 ; i++)
        {
                scArray[i].generatorValue = scArray[i].z * exp(scArray[i].angularVelocity * t);
        }
}

long double sumOfSubcarriers(modulator::Symbol scArray[])
{
    double sum = 0;
    for(int i=0 ; i<4 ; i++)
    {
        sum += scArray[i].generatorValue;
    }
    return sum;
}

void DFT(double x, int m, int N, modulator::Symbol::scArray[])
{

    for ( )
    {
        for ()
        {
            Y[m] =
        }
    }
}















// VERSION II



//void setZ(modulator::Symbol scArray[])
//{
//	for (int i=0 ; i<4 ; i++)
//	{
//		scArray[i].z = scArray[i].amplitude * exp(scArray[i].phase); //A*e^(j*fi)
//	}
//}

//void generateFFT(modulator::Symbol scArray[], const double t)
//{
//	for (int i=0 ; i<4 ; i++)
//	{
//                scArray[i].generatorValue = scArray[i].z * exp(scArray[i].angularVelocity * t);
//        }
//}


//double sumOfSubcarriers(modulator::Symbol scArray[])
//{
//    double sum = 0.0;

//    for(int i=0 ; i<4 ; i++)
//    {
//        sum += scArray[i].generatorValue;
//    }

//    return sum;
//}










//void sample(modulator::Symbol scArray[], double ifftTab[])
//{
//        double tab[16];
//        for (int i=0 ; i<16 ; i++)
//        {
//                tab[i] = scArray[i].realGeneratorValue * i * t;
//        }
//}














/*
if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = -3.0;
			scArray[0].im = -3.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = -3.0;
			scArray[0].im = -1.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = -3.0;
			scArray[0].im =  3.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = -3.0;
			scArray[0].im =  1.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = -1.0;
			scArray[0].im = -3.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = -1.0;
			scArray[0].im = -1.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = -1.0;
			scArray[0].im =  3.0;
		}

	if (scArray[0].inputBits[0] == 0 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = -1.0;
			scArray[0].im =  1.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re =  3.0;;
			scArray[0].im = -3.0;;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re =  3.0;
			scArray[0].im = -1.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = 3.0;
			scArray[0].im = 3.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 0 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = 3.0;
			scArray[0].im = 1.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re =  1.0;
			scArray[0].im = -3.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 0 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re =  1.0;
			scArray[0].im = -1.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 0)
		{
			scArray[0].re = 1.0;
			scArray[0].im = 3.0;
		}

	if (scArray[0].inputBits[0] == 1 &&
	    scArray[0].inputBits[1] == 1 &&
	    scArray[0].inputBits[2] == 1 &&
	    scArray[0].inputBits[3] == 1)
		{
			scArray[0].re = 1.0;
			scArray[0].im = 1.0;
		}



*/
