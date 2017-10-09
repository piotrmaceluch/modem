#include <iostream>
#include <string>



#include "symbol.hpp"




void showValuesForEverySymbol(modulator::Symbol scArray[])
{
	scArray[0].showValues();
	scArray[1].showValues();
	scArray[2].showValues();
	scArray[3].showValues();
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

void setAmplitudeAndPhase(modulator::Symbol scArray[])
{
	for (int i=0 ; i<4 ; i++)
	{
		setRe(modulator::Symbol scArray[]);
		setIm(modulator::Symbol scArray[]);	
	}
}

void setRe(modulator::Symbol scArray[])
{
	if (scArray[i].inputBits[0] == 0 &&  scArray[i].inputBits[1] == 0)
	{
		scArray[i].re = -3.0;
	}

	if (scArray[i].inputBits[0] == 0 &&  scArray[i].inputBits[1] == 1)
	{
		scArray[i].re = -1.0;
	}

	if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 1)
	{
		scArray[i].re = 1.0;
	}

	if (scArray[i].inputBits[0] == 1 &&  scArray[i].inputBits[1] == 0)
	{
		scArray[i].re = 3.0;
	}
}

void setIm(modulator::Symbol scArray[])
{
	if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 0)
	{
		scArray[i].im = -3.0;
	}

	if (scArray[i].inputBits[2] == 0 &&  scArray[i].inputBits[3] == 1)
	{
		scArray[i].im = -1.0;
	}

	if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 1)
	{
		scArray[i].im = 1.0;
	}		

	if (scArray[i].inputBits[2] == 1 &&  scArray[i].inputBits[3] == 0)
	{
		scArray[i].im = 3.0;
	}
}


















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
