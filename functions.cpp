#include "functions.hpp"

// #include "Modem.hpp"
// #include "Modulator.hpp"
// #include "Demodulator.hpp"
//typedef std::vector<OFDM::Modulator> ModVec;
//typedef std::vector<OFDM::Demodulator> DemVec;

//====================================================================================
//========================== TEMPLATES ===============================================
//====================================================================================
template <typename T>
void setAngularVelocities(T &Vector)
{
    for (int i=0 ; i<Vector.size() ; i++)
    {
        Vector[i].setAngularVelocity();
    }
}

template <typename T>
void showValues(T &vector)
{
    for (int i=0 ; i<vector.size() ; i++)
    {
        vector[i].showValues();
    }
}

//====================================================================================
//========================== MODULATOR ===============================================
//====================================================================================

void fillInputBitsVector(std::vector<int> &inputBits, const int M, const int BPS)
{
    for (int i=0 ; i<M*BPS ; i++)
    {
        inputBits.push_back(( std::rand() % 2 ) + 0);
    }
}

void setInputBits (std::vector<OFDM::Modulator> &modulatorVector, const std::vector<int> &inputBits)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].setInputBits(inputBits);
    }
}

void setRealAndImaginary(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].setReal();
        modulatorVector[i].setImaginary();
    }
    
}

void convertComplexToPolar(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].convertComplexToPolar();
    }
}

void fillVectorOfFrequencies(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &frequencies, int M)
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
        modulatorVector[i].setZ(); 
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

void setFrequencies(std::vector<OFDM::Modulator> &modulatorVector, const std::vector<double> &frequencies)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].setFrequency(frequencies);
    }
}

void createSubcarriers(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &time, const int N)
{
    for (int i=0 ; i<modulatorVector.size() ; i++)
    {
        modulatorVector[i].createSubcarrier(time, N);
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
            temp += modulatorVector[j].returnSubcarrierSample(i); 
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

void setFAnalysis (std::vector<double> &fAnalysis, const double fs, const int N)
{   
    for(int m=0 ; m<N ; m++)
    {
        fAnalysis.push_back(m*fs/N);
    }
}     

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

void setFrequencies(std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<double> &fAnalysis, 
    std::vector<std::complex<double>> &DFToutput)
{
    int counter = 0;
    for (int i=0 ; i<DFToutput.size() ; i++)
    {
        if (std::abs(DFToutput[i]) > 1)
            demodulatorVector[counter++].setFrequency(fAnalysis[i]);
        else
            continue;
    }
}

void setSubcarriersVector (std::vector<OFDM::Demodulator> &demodulatorVector, const std::vector<std::complex<double>> &DFToutput, const int N)
{
    
    for (int i=0,j=0 ; j<demodulatorVector.size() || i<N ; i++)
    {
        if ( std::abs(DFToutput[i]) > 1 )
        {
            demodulatorVector[j++].setGeneratorValue(DFToutput, i);   // do pola 'generatorValue' trafia wartosc wyjsciowa DFT. generatorVaue to inaczej z * e^(j*w*t)
        }
        else
        {
            continue;
        }
    }
}

void extractZ (std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].setZ();
    }
}

void extractAmplitude (std::vector<OFDM::Demodulator> &demodulatorVector, const int N)
{   
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].setAmplitude(N);
    }
}

void extractPhase (std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].setPhase();
    }
}

void setComplex (std::vector<OFDM::Demodulator> &demodulatorVector)
{
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].setComplex();
    }
}

void setBits(std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (int i=0 ; i<demodulatorVector.size() ; i++)
    {
        demodulatorVector[i].setBits();
    }
}