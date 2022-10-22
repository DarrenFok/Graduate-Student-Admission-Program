//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

void studentSort::swap(Student& input1, Student& input2){
	Student temp; //temp student object to hold info
	temp = input1;
	input1 = input2;
	input2 = temp;
}

//Sort lastName
int studentSort::partition1(vector<Student> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getLastName() < pivot.getLastName()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortLastName(vector<Student> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = partition1(array, first, last);
		sortLastName(array, first, pivot-1);
		sortLastName(array, pivot+1, last);
	}
}

//sort firstname
void studentSort::sortFirstName(vector<Student> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = partition1(array, first, last);
		sortFirstName(array, first, pivot-1);
		sortFirstName(array, pivot+1, last);
	}
}

//sort cgpa
void studentSort::sortCGPA(vector<Student> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = partition1(array, first, last);
		sortLastName(array, first, pivot-1);
		sortLastName(array, pivot+1, last);
	}
}

//sort research score
void studentSort::sortResearchScore(vector<Student> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = partition1(array, first, last);
		sortLastName(array, first, pivot-1);
		sortLastName(array, pivot+1, last);
	}
}
