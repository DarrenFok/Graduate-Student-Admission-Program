//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

void studentSort::swapDomestic(DomesticStudent& input1, DomesticStudent& input2){
	DomesticStudent temp; //temp student object to hold info
	temp = input1;
	input1 = input2;
	input2 = temp;
}

void studentSort::swapInternational(InternationalStudent &input1, InternationalStudent &input2) {
    InternationalStudent temp; //temp student object to hold info
    temp = input1;
    input1 = input2;
    input2 = temp;
}

//Sort lastName
int studentSort::domesticPartition1(vector<DomesticStudent>& array, int first, int last){ //for lastName sort
	DomesticStudent pivot = array[last]; //pivot element
	int i = (first - 1); //index of smaller element
	for(int j = first; j <= last - 1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareLastName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swapDomestic(array[i], array[j]);
		}
	}
	swapDomestic(array[i+1], array[last]);
	return (i+1);
}

int studentSort::internationalPartition1(vector<InternationalStudent>& array, int low, int high){ //for lastName sort
	InternationalStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareLastName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swapInternational(array[i], array[j]);
		}
	}
	swapInternational(array[i+1], array[high]);
	return (i+1);
}


void studentSort::sortLastNameDomestic(vector<DomesticStudent>& array, int first, int last){
	if(first < last){
		//partition array
		int pivot = domesticPartition1(array, first, last);
		sortLastNameDomestic(array, first, pivot-1);
		sortLastNameDomestic(array, pivot+1, last);
	}
}

void studentSort::sortLastNameInternational(vector<InternationalStudent>& array, int first, int last){
	if(first < last){
		//partition array
		int pivot = internationalPartition1(array, first, last);
		sortLastNameInternational(array, first, pivot-1);
		sortLastNameInternational(array, pivot+1, last);
	}
}

//sort firstname
int studentSort::domesticPartition2(vector<DomesticStudent>& array, int low, int high){ //for lastName sort
	DomesticStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareFirstName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swapDomestic(array[i], array[j]);
		}
	}
	swapDomestic(array[i+1], array[high]);
	return (i+1);
}

int studentSort::internationalPartition2(vector<InternationalStudent>& array, int low, int high){ //for lastName sort
	InternationalStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareFirstName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swapInternational(array[i], array[j]);
		}
	}
	swapInternational(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortFirstNameDomestic(vector<DomesticStudent>& array, int first, int last){
	if(first < last){
		//partition array
		int pivot = domesticPartition2(array, first, last);
		sortFirstNameDomestic(array, first, pivot-1);
		sortFirstNameDomestic(array, pivot+1, last);
	}
}

void studentSort::sortFirstNameInternational(vector<InternationalStudent>& array, int first, int last){
	if(first < last){
		//partition array
		int pivot = internationalPartition2(array, first, last);
		sortFirstNameInternational(array, first, pivot-1);
		sortFirstNameInternational(array, pivot+1, last);
	}
}

//sort cgpa
int studentSort::domesticPartition3(vector<DomesticStudent>& array, int low, int high){ //for cgpa sort
	DomesticStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareCGPA(array[j], pivot) == ">"){
			i++; //increment index of smaller element
			swapDomestic(array[i], array[j]);
		}
	}
	swapDomestic(array[i+1], array[high]);
	return (i+1);
}

int studentSort::internationalPartition3(vector<InternationalStudent>& array, int low, int high){ //for cgpa sort
	InternationalStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareCGPA(array[j], pivot) == ">"){
			i++; //increment index of smaller element
			swapInternational(array[i], array[j]);
		}
	}
	swapInternational(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortCGPADomestic(vector<DomesticStudent>& array, int first, int last){
    if(first < last){
		//partition array
		int pivot = domesticPartition3(array, first, last);
		sortCGPADomestic(array, first, pivot-1);
		sortCGPADomestic(array, pivot+1, last);
	}
}

void studentSort::sortCGPAInternational(vector<InternationalStudent>& array, int first, int last){
    if(first < last){
		//partition array
		int pivot = internationalPartition3(array, first, last);
		sortCGPAInternational(array, first, pivot-1);
		sortCGPAInternational(array, pivot+1, last);
	}
}

//sort research score
int studentSort::domesticPartition4(vector<DomesticStudent>& array, int low, int high){ //for research score sort
	DomesticStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getResearch() > pivot.getResearch()){
			i++; //increment index of smaller element
			swapDomestic(array[i], array[j]);
		}
	}
	swapDomestic(array[i+1], array[high]);
	return (i+1);
}

int studentSort::internationalPartition4(vector<InternationalStudent>& array, int low, int high){ //for research score sort
	InternationalStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getResearch() < pivot.getResearch()){
			i++; //increment index of smaller element
			swapInternational(array[i], array[j]);
		}
	}
	swapInternational(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortResearchScoreDomestic(vector<DomesticStudent>& array, int first, int last){
    if(first < last){
		//partition array
		int pivot = domesticPartition4(array, first, last);
		sortResearchScoreDomestic(array, first, pivot-1);
		sortResearchScoreDomestic(array, pivot+1, last);
	}
}

void studentSort::sortResearchScoreInternational(vector<InternationalStudent>& array, int first, int last){
    if(first < last){
		//partition array
		int pivot = internationalPartition4(array, first, last);
		sortResearchScoreInternational(array, first, pivot-1);
		sortResearchScoreInternational(array, pivot+1, last);
	}
}


void studentSort::sortOverallDomestic(vector<DomesticStudent>& array ,int first, int last){
    //sort ResearchScore first
    if(first < last){
		//partition array
        int pivot3 = domesticPartition8(array, first, last);
        sortOverallDomestic(array, first, pivot3-1);
        sortOverallDomestic(array, pivot3+1, last);
	}
}

int studentSort::domesticPartition8(vector<DomesticStudent>& array, int low, int high){ //for cgpa sort
    DomesticStudent pivot = array[high]; //pivot element
    int i = (low-1); //index of smaller element

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == ">"){
            i++; //increment index of smaller element
            swapDomestic(array[i], array[j]);
        }
    }

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == "=="){
            if(compareCGPA(array[j], pivot) == ">"){
                i++; //increment index of smaller element
                swapDomestic(array[i], array[j]);
            }
        }
    }

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == "=="){
            if(compareCGPA(array[j], pivot) == "=="){
                if(compareProvince(array[j], pivot) == "<"){
                    i++; //increment index of smaller element
                    swapDomestic(array[i], array[j]);
                }
            }
        }
    }
    swapDomestic(array[i+1], array[high]);
    return (i+1);
}

void studentSort::sortOverallInternational(vector<InternationalStudent>& input, int first, int last){
    
    //sort ResearchScore first
    if(first < last){
		//partition array
		int pivot4 = internationalPartition8(input, first, last);
		sortOverallInternational(input, first, pivot4-1);
		sortOverallInternational(input, pivot4+1, last);
	}
}

int studentSort::internationalPartition8(vector<InternationalStudent>& array, int low, int high){ //for cgpa sort
    InternationalStudent pivot = array[high]; //pivot element
    int i = (low-1); //index of smaller element

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == ">"){
            i++; //increment index of smaller element
            swapInternational(array[i], array[j]);
        }
    }

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == "=="){
            if(compareCGPA(array[j], pivot) == ">"){
                i++; //increment index of smaller element
                swapInternational(array[i], array[j]);
            }
        }
    }

    for(int j = low; j <= high-1; j++){ //loop from low to high
        //if current iteration is less than pivot, increment low AND swap elements at i and j
        if(compareResearchScore(array[j], pivot) == "=="){
            if(compareCGPA(array[j], pivot) == "=="){
                if(compareCountry(array[j], pivot) == "<"){
                    i++; //increment index of smaller element
                    swapInternational(array[i], array[j]);
                }
            }
        }
    }
    swapInternational(array[i+1], array[high]);
    return (i+1);
}