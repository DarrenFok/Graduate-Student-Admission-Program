//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include "vector" //vectors
#include "DomesticStudent.hpp"
#include "InternationalStudent.hpp"
#include <iostream>
using namespace std;

namespace studentSort{ //make it namespace, so that functions can be accessed outside
	vector<Student> sortLastName(vector<Student> input); //sort function by Darren
	void swap(Student& input1, Student& input2); //function to swap
}
