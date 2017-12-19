#include <iostream>

#include <gtest/gtest.h>
//#include "modem.hpp"

namespace gard
{
    struct myTest: ::testing::Test
    {
        myTest()
        {}
        
    };
 
    TEST_F(myTest, just_for_lunch_test)
    {
        EXPECT_EQ(true, true);
    }
}