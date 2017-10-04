#include<iostream>
#include<string>
#include<complex>
#include<array>

#include"symbol.hpp"



int main()
{
	const int SIZE = 16;
	int inputBits[SIZE] = {0,0,1,1,0,1,0,1,0,0,0,0,1,1,1,1};

	const int sc_n = 4;
	Symbol scArray[sc_n];
	
	setInputBits(scArray);
	
}
