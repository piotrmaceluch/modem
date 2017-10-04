#pragma once

#include<iostream>
#include<array>


class Symbol
{
    private:
        double amplitude;
	double phase;
	const int nBits = 4;
	int iBits[nBits];    
    public:

	Symbol(double amplitude = 0.0, double phase = 0.0)
	{
		this->amplitude = amplitude;
		this->phase     = phase; 
	}

	Symbol(Symbol &X)
	{
		this->amplitude = X.amplitude;
		this->phase     = X.phase;
	}
	
	~Symbol() 
	{}

	
	void setBits(int inputBits[]); 
};

