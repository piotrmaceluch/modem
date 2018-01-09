#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Modem.hpp"
#include "Demodulator.hpp"
#include "functions.hpp"


namespace modem_ut
{
    struct DemodulatorTests: public ::testing::Test
    {
        const int M = 8;
        const int N = 1024;
        DemodulatorTests()
        {}
        ~DemodulatorTests()
        {}
    };
 

    TEST_F(DemodulatorTests, compareDemodulatorInputValues)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_input");

        std::fstream myfile2;
        myfile2.open("m_dem_input");

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

    TEST_F(DemodulatorTests, compareDFTs)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_rDFT");

        std::fstream myfile2;
        myfile2.open("c_dem_iDFT");

        std::fstream myfile3;
        myfile3.open("m_dem_rDFT");

        std::fstream myfile4;
        myfile4.open("m_dem_iDFT");

        std::vector<double> rc; // real part of DFT for C++ vector
        std::vector<double> ic; // imag part of DFT for C++ vector
        std::vector<double> rm; // real part of DFT for matlab vector
        std::vector<double> im; // imag part of DFT for matlab vector

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
            EXPECT_NEAR(rc[i], rm[i], 0.0005);
            ASSERT_NEAR(ic[i], im[i], 0.0005);
        }

        myfile1.close();
        myfile2.close();
        myfile3.close();
        myfile4.close();
    }

    TEST_F(DemodulatorTests, compareFrequencies)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_frequency");

        std::fstream myfile2;
        myfile2.open("m_dem_frequency");

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

    TEST_F(DemodulatorTests, compareAmplitudes)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_amplitude");

        std::fstream myfile2;
        myfile2.open("m_dem_amplitude");

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

    TEST_F(DemodulatorTests, comparePhases)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_phase");

        std::fstream myfile2;
        myfile2.open("m_dem_phase");

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


    // TEST_F(DemodulatorTests, compareRealParts)
    // {
    //     std::fstream myfile1;
    //     myfile1.open("c_dem_real");

    //     std::fstream myfile2;
    //     myfile2.open("m_dem_real");

    //     std::vector<double> m;
    //     std::vector<double> c;

    //     for( double i; myfile1 >> i ; i++)
    //     {
    //         c.push_back(i);
    //     }

    //     for( double i; myfile2 >> i ; i++)
    //     {
    //         m.push_back(i);
    //     }
        
    //     for (int i=0 ; i<M ; i++)
    //     {
    //         ASSERT_EQ(c[i], m[i]);
    //     }

    //     myfile1.close();
    //     myfile2.close();
    // }

    // TEST_F(DemodulatorTests, compareImaginaryParts)
    // {
    //     std::fstream myfile1;
    //     myfile1.open("c_dem_imaginary");

    //     std::fstream myfile2;
    //     myfile2.open("m_dem_imaginary");

    //     std::vector<double> m;
    //     std::vector<double> c;

    //     for( double i; myfile1 >> i ; i++)
    //     {
    //         c.push_back(i);
    //     }

    //     for( double i; myfile2 >> i ; i++)
    //     {
    //         m.push_back(i);
    //     }
        
    //     for (int i=0 ; i<M ; i++)
    //     {
    //         ASSERT_EQ(c[i], m[i]);
    //     }

    //     myfile1.close();
    //     myfile2.close();
    // }

    

    TEST_F(DemodulatorTests, compareOutputBits)
    {
        std::fstream myfile1;
        myfile1.open("c_dem_bits");

        std::fstream myfile2;
        myfile2.open("m_dem_bits");

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
        
        for (int i=0 ; i<32 ; i++)
        {
            ASSERT_EQ(c[i], m[i]);
        }

        myfile1.close();
        myfile2.close();
    }

}