#ifndef PROJECT_FUNCTIONS_HPP
#define PROJECT_FUNCTIONS_HPP



#include <string>
#include <iostream>
using namespace std;

namespace functions{
    //checks if inputted string is a number or not
    bool isNumerical(string in){
        int decimalCheck = 0;
        for(char i : in){
            if(!isdigit(i)) //if a single character is not a digit then invalid
                return false;
        }
        return true;
    }
}

#endif //PROJECT_FUNCTIONS_HPP
