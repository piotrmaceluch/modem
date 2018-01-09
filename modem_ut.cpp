#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <complex>

#include "Modem.hpp"
#include "Modulator.hpp"
#include "Demodulator.hpp"
#include "functions.hpp"


namespace modem_ut
{
    struct ModemTests: public ::testing::Test
    {
        const int M = 8;
        const int N = 1024;
        ModemTests()
        {}
        ~ModemTests()
        {}
    };
 
    TEST_F(ModemTests, compareInputAndOutputAmplitudes )
    {
        std::fstream myfile1;
        myfile1.open("c_mod_bits");

        std::fstream myfile2;
        myfile2.open("c_dem_bits");

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

    TEST_F(ModemTests, compareInputAndOutputPhases)
    {
        std::fstream myfile1;
        myfile1.open("c_mod_bits");

        std::fstream myfile2;
        myfile2.open("c_dem_bits");

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

    TEST_F(ModemTests, compareInputAndOutputFrequencies )
    {
        std::fstream myfile1;
        myfile1.open("c_mod_frequency");

        std::fstream myfile2;
        myfile2.open("c_dem_frequency");

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

    TEST_F(ModemTests, compareInputAndOutputBits )
    {
        std::fstream myfile1;
        myfile1.open("c_mod_bits");

        std::fstream myfile2;
        myfile2.open("c_dem_bits");

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

}  // namespace modem_ut