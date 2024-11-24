//
// Created by Zaw Lin Than on 11/24/24.
//

#include <vector>
#include <math.h>
#include "calculator.h"

double basicCalculation(const std::string& str)
{
    std::vector<std::string> numVec;

    for (char i : str)
    {
        std::string temp;
        if (i != '+' && i != '-' && i != '*' && i != '/')
        {
            temp += i;
        } else {
            numVec.push_back(temp);
        }
    }


}