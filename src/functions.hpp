#ifndef PROJECT_FUNCTIONS_HPP
#define PROJECT_FUNCTIONS_HPP
#include <string>
#include <iostream>
using namespace std;

namespace functions{
    //checks if inputted string is a number or not
    bool isNumerical(string in){
        for(char i : in){
            if(!isdigit(i)) //if a single character is not a digit then invalid
                return false;
        }
        return true;
    }
    //converts entire string to lower case
    string toLowerCase(string in){
        for(int i = 0; i < in.length(); i++){
            if(in[i] >= 65 && in[i] <= 90){
                in[i] = in[i]+32;
            }
        }
        return in;
    }
    //checks if inputted string is a double
    bool isDouble(const string in){
        int point=0;
        for (int i = 0; i < in.length(); i++){
            if (in[i]=='.'){
                point++;
            }
            else if (!isdigit(in[i])){
                return false;
            }
        }
        if (point<=1){
            return true;
        }
        else{
            return false;
        }
    }

}

#endif //PROJECT_FUNCTIONS_HPP