//header file stu_sort.hpp to declare your sorting functions
#ifndef PROJECT_STU_SORT_HPP
#define PROJECT_STU_SORT_HPP


#include <string> //you will have to use string in C++
#include "vector" //vectors
#include "student.hpp"
using namespace std;

namespace studentSort{ //make it namespace, so that functions can be accessed outside
	//lastName sort
	int partition1(vector<Student> array, int first, int last); //from low to high
	void sortLastName(vector<Student> array, int first, int last);

    //firstname sort
    int partition2(vector<Student> array, int low, int high);
    void sortFirstName(vector<Student> array, int first, int last);

    //cgpa sort
    int partition3(vector<Student> array, int low, int high);
    void sortCGPA(vector<Student> array, int first, int last);

    //research score sort
    int partition4(vector<Student> array, int low, int high);
    void sortResearchScore(vector<Student> array, int first, int last);

    //overall sort for domestic
    int partition5(vector<Student> array, int low, int high);
    void sortOverallDomestic(vector<Student> array, int first, int last);

    //overall sort for international
    int partition6(vector<Student> array, int low, int high);
    void sortOverallInternational(vector<Student> array, int first, int last);
    //swap
	void swap(Student& input1, Student& input2); //function to swap

}

#endif
