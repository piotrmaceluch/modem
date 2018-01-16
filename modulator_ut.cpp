#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <complex>

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"
#include "Modulator_functions.hpp"


namespace modem_ut
{
    struct ModulatorTests: public ::testing::Test
    {
        const int M = 8;
        const int N = 1024;
        ModulatorTests()
        {}
        ~ModulatorTests()
        {}
    };
 
    TEST_F(ModulatorTests, compareInputBits)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_bits");

        std::fstream myfile2;
        myfile2.open("m_mod_bits");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_EQ(c[i], m[i]);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareRealParts)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_real");

        std::fstream myfile2;
        myfile2.open("m_mod_real");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_EQ(c[i], m[i]);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareImaginaryParts)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_imaginary");

        std::fstream myfile2;
        myfile2.open("m_mod_imaginary");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_EQ(c[i], m[i]);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareTimeVectors)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_time");

        std::fstream myfile2;
        myfile2.open("m_mod_time");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<N ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareAmplitudes)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_amplitude");

        std::fstream myfile2;
        myfile2.open("m_mod_amplitude");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, comparePhases)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_phase");

        std::fstream myfile2;
        myfile2.open("m_mod_phase");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareFrequencies)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_frequency");

        std::fstream myfile2;
        myfile2.open("m_mod_frequency");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareAngularVelocities)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_angularVelocity");

        std::fstream myfile2;
        myfile2.open("m_mod_angularVelocity");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<M ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
    }

    TEST_F(ModulatorTests, compareSubcarriersSamples)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_rSubcarrierSamples");

        std::fstream myfile2;
        myfile2.open("c_mod_iSubcarrierSamples");

        std::fstream myfile3;
        myfile3.open("m_mod_rSubcarrierSamples");

        std::fstream myfile4;
        myfile4.open("m_mod_iSubcarrierSamples");

        std::vector<double> rc; //real part of vector in c++
        std::vector<double> ic; //imag part of vector in c++
        std::vector<double> rm; //real part of vector in matlab
        std::vector<double> im; //imag part of vector in matlab

        for( double i; myfile1 >> i ; i++)
        {
            rc.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            ic.push_back(i);
        }
        
        for( double i; myfile3 >> i ; i++)
        {
            rm.push_back(i);
        }

        for( double i; myfile4 >> i ; i++)
        {
            im.push_back(i);
        }

        for (int i=0 ; i<N*8 ; i++)
        {
            ASSERT_NEAR(rc[i], rm[i], 0.0005);
            ASSERT_NEAR(ic[i], im[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
        myfile3.close();
        myfile4.close();
    }

    TEST_F(ModulatorTests, compareIDFTvalues)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_realIDFT");

        std::fstream myfile2;
        myfile2.open("c_mod_imagIDFT");

        std::fstream myfile3;
        myfile3.open("m_mod_realIDFT");

        std::fstream myfile4;
        myfile4.open("m_mod_imagIDFT");

        std::vector<double> rc; //real part of vector in c++
        std::vector<double> ic; //imag part of vector in c++
        std::vector<double> rm; //real part of vector in matlab
        std::vector<double> im; //imag part of vector in matlab

        for( double i; myfile1 >> i ; i++)
        {
            rc.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            ic.push_back(i);
        }
        
        for( double i; myfile3 >> i ; i++)
        {
            rm.push_back(i);
        }

        for( double i; myfile4 >> i ; i++)
        {
            im.push_back(i);
        }

        for (int i=0 ; i<N ; i++)
        {
            ASSERT_NEAR(rc[i], rm[i], 0.0005);
            ASSERT_NEAR(ic[i], im[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
        myfile3.close();
        myfile4.close();
    }

    TEST_F(ModulatorTests, compareModulatorOutputValues)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_output");

        std::fstream myfile2;
        myfile2.open("m_mod_output");

        std::vector<double> m;
        std::vector<double> c;

        for( double i; myfile1 >> i ; i++)
        {
            c.push_back(i);
        }

        for( double i; myfile2 >> i ; i++)
        {
            m.push_back(i);
        }
        
        for (int i=0 ; i<N ; i++)
        {
            ASSERT_NEAR(c[i], m[i], 0.0005);
        }
        myfile1.close();
        myfile2.close();
    }

}  // namespace modem_ut
