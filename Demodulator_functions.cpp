#include "Demodulator_functions.hpp"


//======================== DEMODULATOR ===============================================

void setFAnalysis (std::vector<double> &fAnalysis, const double fs, const int N)
{   
    for(int m=0 ; m<N ; m++)
    {
        fAnalysis.push_back(m*fs/N);
    }
}     

void calculateDFT (const std::vector<double> &DFTinput, std::vector<std::complex<double>> &DFToutput, const int N)
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
    for (std::size_t i=0 ; i<DFToutput.size() ; i++)
    {
        if (std::abs(DFToutput[i]) > 1)
            demodulatorVector[counter++].setFrequency(fAnalysis[i]);
        else
            continue;
    }
}

// void setDemodulatorAngularVelocities(std::vector<OFDM::Demodulator> &demodulatorVector)
// {
//     for (auto &i : demodulatorVector)
//     {
//         i.setAngularVelocity();
//     }
// }

void setSubcarriersVector (std::vector<OFDM::Demodulator> &demodulatorVector, 
    const std::vector<std::complex<double>> &DFToutput, const int N)
{
    for (int i=0, j=0 ; j<demodulatorVector.size() && i<N ; i++)
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
    for (auto &i : demodulatorVector)
    {
        i.setZ();
    }
}

void extractAmplitude (std::vector<OFDM::Demodulator> &demodulatorVector, const int N)
{   
    for (auto &i : demodulatorVector)
    {
        i.setAmplitude(N);
    }
}

void extractPhase (std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (auto &i : demodulatorVector)
    {
        i.setPhase();
    }
}

void setComplex (std::vector<OFDM::Demodulator> &demodulatorVector)
{
    for (auto &i : demodulatorVector)
    {
        i.setComplex();
    }
}

void setBits(std::vector<OFDM::Demodulator> &demodulatorVector)
{   
    for (auto &i : demodulatorVector)
    {
        i.setBits();
    }
}

void showDemodulatorValues(std::vector<OFDM::Demodulator> &demodulatorVector)
{
    for (auto &i : demodulatorVector)
    {
        i.showValues();
    }
}


void sendDemodulatorValuesToFiles(std::vector<OFDM::Demodulator> &demodulatorVector, std::vector<double> demodulatorInput, 
    std::vector<std::complex<double>> &DFToutput, const int N)
{
    for (auto &i : demodulatorVector)
    {
        i.sendDemodulatorValuesToFile();
    }

    std::ofstream myfile1;
    myfile1.open("c_dem_input", std::fstream::app);
    for (int i=0 ; i<N ; i++)
    {
        myfile1 << demodulatorInput[i];
        myfile1 << "\n";
    }
    myfile1.close();

    std::ofstream myfile2;
    myfile2.open("c_dem_rDFT", std::fstream::app);  // real values of DFT
    for (int i=0 ; i<N ; i++)
    {
        myfile2 << std::real(DFToutput[i]);
        myfile2 << "\n";
    }
    myfile2.close();

    std::ofstream myfile3;
    myfile3.open("c_dem_iDFT", std::fstream::app);  // imag values of DFT
    for (int i=0 ; i<N ; i++)
    {
        myfile3 << std::imag(DFToutput[i]);
        myfile3 << "\n";
    }
    myfile3.close();


}
