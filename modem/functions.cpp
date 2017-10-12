#include <iostream>
#include <string>
#include <complex>
#include <math.h>


#include "symbol.hpp"
#include "functions.hpp"





void showValuesForEverySymbol(modulator::Symbol scArray[])
{
	for (int i=0 ; i<4 ; i++)
	{
		scArray[i].showValues();
	}
}

void setInputBits(modulator::Symbol scArray[], int inputBits[])
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
			scArray[i].real = -3.0;
		}
	
		if (scArray[i].inputBits[0] == 0 &&  scArray[i].inputBits[1] == 1)
		{
			scArray[i].real = -1.0;
		}

		if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 1)
		{
			scArray[i].real = 1.0;
		}

		if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 0)
		{
			scArray[i].real = 3.0;
		}
	}
}

void setIm(modulator::Symbol scArray[])
{
	for (int i=0 ; i<4 ; i++)
	{
		if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 0)
		{
			scArray[i].imaginary = -3.0;
		}

		if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 1)
		{
			scArray[i].imaginary = -1.0;
		}

		if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 1)
		{
			scArray[i].imaginary = 1.0;
		}		

		if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 0)
		{
			scArray[i].imaginary = 3.0;
		}
	}
}
 
void convertComplexToPolar(modulator::Symbol scArray[])
{
	for (int i=0 ; i<4 ; i++)
	{
		for (int j=0 ; j<4 ; j++)
		{
			std::complex<double> z(scArray[i].real, scArray[i].imaginary);
			scArray[i].amplitude = std::abs(z);
			scArray[i].phase     = std::arg(z) * 180.0/M_PI; //degrees
			//scArray[i].phase     = std::arg(z); 		 //radians
			if (scArray[i].phase < 0)			 //to avoid negative degrees
			{
				scArray[i].phase = 360.0 + scArray[i].phase;	
			}
		}
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
		scArray[i].z = scArray[i].amplitude * exp(scArray[i].phase); //A*e^(j*fi)
	}
}

void generateGeneratorValues(modulator::Symbol scArray[], const double t)
{	//From Euler's dependence: e^(jwt) = cos(wt) + isin(wt)
	for (int i=0 ; i<4 ; i++)
	{		
		scArray[i].realGeneratorValue = scArray[i].z * cos(scArray[i].angularVelocity * t);
		scArray[i].imaginaryGeneratorValue = scArray[i].z * sin(scArray[i].angularVelocity * t);
	}
}

double * calculateIFFT(modulator::Symbol scArray[], double ifftTab[])
{
	for(int i=0 ; i<4 ; i++)
	{
		ifftTab[0] +=scArray[i].realGeneratorValue;
		ifftTab[1] +=scArray[i].imaginaryGeneratorValue;
	}
	return ifftTab;
}

//void sample( )
//{

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
