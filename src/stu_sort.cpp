

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
		if(compareLastName(array[j], pivot) == "==" || compareLastName(array[j], pivot) == ">" ||compareLastName(array[j], pivot) == "<" ){
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
int studentSort::partition2(vector<Student> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareFirstName(array[j], pivot) == "==" || compareFirstName(array[j], pivot) == ">" ||compareFirstName(array[j], pivot) == "<" ){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}
void studentSort::sortFirstName(vector<Student> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = partition2(array, first, last);
		sortFirstName(array, first, pivot-1);
		sortFirstName(array, pivot+1, last);
	}
}

//sort cgpa
int studentSort::partition3(vector<Student> array, int low, int high){ //for cgpa sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j > high-1; j++){ //looping from high to low (decesending order)
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getCGPA() > pivot.getCGPA()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortCGPA(vector<Student> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = partition3(array, first, last);
		sortCGPA(array, first, pivot-1);
		sortCGPA(array, pivot+1, last);
	}
}

//sort research score
int studentSort::partition3(vector<Student> array, int low, int high){ //for research score sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j > high-1; j++){ //looping from high to low (descending order)
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getResearch() > pivot.getResearch()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortResearchScore(vector<Student> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = partition4(array, first, last);
		sortResearchScore(array, first, pivot-1);
		sortResearchScore(array, pivot+1, last);
	}
}

//overall sort Domestic
int studentSort::partition5(vector<Student> array, int low, int high){ //for province/country sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareProvince(array[j], pivot) == "==" || compareProvince(array[j], pivot) == ">" ||compareProvince(array[j], pivot) == "<" ){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortOverallDomestic(vector<Student> array ,int first, int last){
    //sort ResearchScore first
    if(last < first){
		//partition array
		int pivot = partition4(array, first, last);
		sortResearchScore(array, first, pivot-1);
		sortResearchScore(array, pivot+1, last);
	}
        //if the research score is the same sort cgpa
        if(first == last){
		//partition array
		    int pivot = partition3(array, first, last);
		    sortCGPA(array, first, pivot-1);
		    sortCGPA(array, pivot+1, last);
	    }   
            //if cgpa the same sort by province/country
            if(first == last){
                //partition array
		        int pivot = partition5(array, first, last);
		        sortOverallDomestic(array, first, pivot-1);
		        sortOverallDomestic(array, pivot+1, last);
            }
}

//overall sort International
int studentSort::partition6(vector<Student> array, int low, int high){ //for province/country sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareCountry(array[j], pivot) == "==" || compareCountry(array[j], pivot) == ">" ||compareCountry(array[j], pivot) == "<" ){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortOverallInternational(vector<Student> array ,int first, int last){
    //sort ResearchScore first
    if(last < first){
		//partition array
		int pivot = partition4(array, first, last);
		sortResearchScore(array, first, pivot-1);
		sortResearchScore(array, pivot+1, last);
	}
        //if the research score is the same sort cgpas
        if(first == last){
		//partition array
		    int pivot = partition3(array, first, last);
		    sortCGPA(array, first, pivot-1);
		    sortCGPA(array, pivot+1, last);
	    }   
            //if cgpa the same sort by province/country
            if(first == last){
                //partition array
		        int pivot = partition6(array, first, last);
		        sortOverallInternational(array, first, pivot-1);
		        sortOverallInternational(array, pivot+1, last);
            }
}
*/
