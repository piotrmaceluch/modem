#include "functions.hpp"


//========================== MODULATOR ===============================================

void fillInputBitsVector(std::vector<int> &inputBits, const int M, const int BPS)
{
    for (int i=0 ; i<M*BPS ; i++)
    {
        inputBits.push_back(( std::rand() % 2 ) + 0);
    }
}

void setInputBits (std::vector<OFDM::Modulator> &modulatorVector, const std::vector<int> &inputBits)
{
    for (auto &i : modulatorVector)
    {
        i.setInputBits(inputBits);
    }
}

void setRealAndImaginary(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (auto &i : modulatorVector)
    {
        i.setReal();
        i.setImaginary();
    }
    
}

void convertComplexToPolar(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (auto &i : modulatorVector)
    {
        i.convertComplexToPolar();
    }
}

void fillVectorOfFrequencies(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &frequencies)
{
    for (std::size_t i=0 ; i<modulatorVector.size() ; i++)
    {
        frequencies.push_back((i+1) * 15);
    }
}

void setZ(std::vector<OFDM::Modulator> &modulatorVector)
{   // operuję na wartościach w formacie a + ib, więc zamiana na postać wykładniczą nie jest mi potrzebna
    for (auto &i : modulatorVector)
    {
        //  Later I'll use in generator, complex values instead of exponential
        i.setZ(); 
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
    for (auto &i : modulatorVector)
    {
        i.setFrequency(frequencies);
    }
}

void setModulatorAngularVelocities(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (auto &i : modulatorVector)
    {
        i.setAngularVelocity();
    }
}

void createSubcarriers(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &time, const int N)
{
    for (auto &i : modulatorVector)
    {
        i.createSubcarrier(time, N);
    }
}

void calculateIDFT(std::vector<OFDM::Modulator> &modulatorVector, std::vector<std::complex<double>> &sumOfSubcarriers, 
    const int N)
{
    std::complex<double> temp;
    for (int i=0 ; i<N ; i++)
    {
        temp = {0.0, 0.0};
        for (std::size_t j=0 ; j<modulatorVector.size() ; j++)
        {
            temp += modulatorVector[j].returnSubcarrierSample(i); 
        }
        sumOfSubcarriers.push_back(temp);
    }
}

void extractRealPart(std::vector<std::complex<double>> &sumOfSubcarriers, std::vector<double> &modulatorOutput, 
    const int N)
{
    for (int i=0 ; i<N ; i++)
    {
        modulatorOutput.push_back(sumOfSubcarriers[i].real());
    }
}

void showModulatorValues(std::vector<OFDM::Modulator> &modulatorVector)
{
    for (auto &i : modulatorVector)
    {
        i.showValues();
    }
}

void sendModulatorValuesToFiles(std::vector<OFDM::Modulator> &modulatorVector, std::vector<double> &modulatorOutput, 
    std::vector<std::complex<double>> &sumOfSubcarriers, const std::vector<double> &time, int N, int M)
{
    // std::ofstream myfile;
    // myfile.open("c_mod_inputBits", std::fstream::app);
    // for(int i=0 ; i<32 ; i++)
    // {
    //     myfile << inputBits[i];
    //     myfile << "\n";
    // }
    // myfile.close();

    for (auto &i : modulatorVector)
    {
        i.sendModulatorValuesToFiles(N);
    }

    std::ofstream myfile1;
    myfile1.open("c_mod_realIDFT", std::fstream::app);
    for (int i=0 ; i<N ; i++)
    {
        myfile1 << real(sumOfSubcarriers[i]);
        myfile1 << "\n";
    }
    myfile1.close();

    std::ofstream myfile2;
    myfile2.open("c_mod_imagIDFT", std::fstream::app);
    for (int i=0 ; i<N ; i++)
    {
        myfile2 << imag(sumOfSubcarriers[i]);
        myfile2 << "\n";
    }
    myfile2.close();

    std::ofstream myfile3;
    myfile3.open("c_mod_output", std::fstream::app);
    for (int i=0 ; i<N ; i++)
    {
        myfile3 << modulatorOutput[i];
        myfile3 << "\n";
    }
    myfile3.close();

    std::ofstream myfile4;
    myfile4.open("c_mod_time", std::fstream::app);
    for (int i=0 ; i<N ; i++)
    {
        myfile4 << time[i];
        myfile4 << "\n";
    }
    myfile4.close();
}

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


void sendDemodulatorValuesToFiles(std::vector<OFDM::Demodulator> &demodulatorVector, std::vector<double> demodulatorInput, std::vector<std::complex<double>> &DFToutput, const int M, const int N)
{
    for (auto &i : demodulatorVector)
    {
        i.sendDemodulatorValuesToFile(N);
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
