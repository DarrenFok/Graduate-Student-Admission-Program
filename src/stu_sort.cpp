//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

vector<Student> studentSort::sortLastName(vector<Student> input){

}

void studentSort::swap(Student& input1, Student& input2){
	Student temp; //temp student object to hold info
	temp = input1;
	input1 = input2;
	input2 = temp;
}
