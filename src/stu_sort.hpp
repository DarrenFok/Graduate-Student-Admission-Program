//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include "vector" //vectors
#include "student.hpp"
using namespace std;

namespace studentSort{ //make it namespace, so that functions can be accessed outside
	//lastName sort
	int partition1(vector<Student> array, int first, int last); //from low to high
	void sortLastName(vector<Student> array, int first, int last);
	//firstname sort
	void sortFirstName(vector<Student> array, int first, int last);
	//cgpa sort
	void sortCGPA(vector<Student> array, int first, int last);
	//researchscore sort
	void sortResearchScore(vector<Student> array, int first, int last);
	//overall sort
    	void sortOverall(vector<Student> array, int first, int last);

	void swap(Student& input1, Student& input2); //function to swap

}
