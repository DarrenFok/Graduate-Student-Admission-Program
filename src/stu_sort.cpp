//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

void studentSort::swap(Student& input1, Student& input2){
	Student temp; //temp student object to hold info
	temp = input1;
	input1 = input2;
	input2 = temp;
}

//Sort lastName
int studentSort::Domesticpartition1(vector<DomesticStudent> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareLastName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

int studentSort::Internationalpartition1(vector<InternationalStudent> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareLastName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}


void studentSort::sortLastNameDomestic(vector<DomesticStudent> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = Domesticpartition1(array, first, last);
		sortLastNameDomestic(array, first, pivot-1);
		sortLastNameDomestic(array, pivot+1, last);
	}
}

void studentSort::sortLastNameInternational(vector<InternationalStudent> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = Internationalpartition1(array, first, last);
		sortLastNameInternational(array, first, pivot-1);
		sortLastNameInternational(array, pivot+1, last);
	}
}

//sort firstname
int studentSort::Domesticpartition2(vector<DomesticStudent> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareFirstName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

int studentSort::Internationalpartition2(vector<InternationalStudent> array, int low, int high){ //for lastName sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareFirstName(array[j], pivot) == "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortFirstNameDomestic(vector<DomesticStudent> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = Domesticpartition2(array, first, last);
		sortFirstNameDomestic(array, first, pivot-1);
		sortFirstNameDomestic(array, pivot+1, last);
	}
}

void studentSort::sortFirstNameInternational(vector<InternationalStudent> array, int first, int last){
	if(first < last){
		//partition array
		int pivot = Internationalpartition2(array, first, last);
		sortFirstNameInternational(array, first, pivot-1);
		sortFirstNameInternational(array, pivot+1, last);
	}
}

//sort cgpa
int studentSort::Domesticpartition3(vector<DomesticStudent> array, int low, int high){ //for cgpa sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getCGPA() > pivot.getCGPA()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

int studentSort::Internationalpartition3(vector<InternationalStudent> array, int low, int high){ //for cgpa sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getCGPA() > pivot.getCGPA()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortCGPADomestic(vector<DomesticStudent> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = Domesticpartition3(array, first, last);
		sortCGPADomestic(array, first, pivot-1);
		sortCGPADomestic(array, pivot+1, last);
	}
}

void studentSort::sortCGPAInternational(vector<InternationalStudent> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = Internationalpartition3(array, first, last);
		sortCGPAInternational(array, first, pivot-1);
		sortCGPAInternational(array, pivot+1, last);
	}
}

//sort research score
int studentSort::Domesticpartition4(vector<DomesticStudent> array, int low, int high){ //for research score sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getResearch() > pivot.getResearch()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

int studentSort::Internationalpartition4(vector<InternationalStudent> array, int low, int high){ //for research score sort
	Student pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element

	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(array[j].getResearch() > pivot.getResearch()){
			i++; //increment index of smaller element
			swap(array[i], array[j]);
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortResearchScoreDomestic(vector<DomesticStudent> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = Domesticpartition4(array, first, last);
		sortResearchScoreDomestic(array, first, pivot-1);
		sortResearchScoreDomestic(array, pivot+1, last);
	}
}

void studentSort::sortResearchScoreInternational(vector<InternationalStudent> array, int first, int last){
    if(last < first){
		//partition array
		int pivot = Internationalpartition4(array, first, last);
		sortResearchScoreInternational(array, first, pivot-1);
		sortResearchScoreInternational(array, pivot+1, last);
	}
}

//overall sort Domestic
int studentSort::Domesticpartition(vector<DomesticStudent> array, int low, int high){ //for province/country sort
	DomesticStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareProvince(array[j], pivot)== "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

int studentSort::Domesticpartition(vector<DomesticStudent> array, int low, int high){ //for province/country sort
	DomesticStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareProvince(array[j], pivot)== "<"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortOverallDomestic(vector<DomesticStudent> array ,int first, int last){
    //sort ResearchScore first
    if(last < first){
		//partition array
		int pivot = Domesticpartition4(array, first, last);
		sortResearchScoreDomestic(array, first, pivot-1);
		sortResearchScoreDomestic(array, pivot+1, last);
	}
        //if the research score is the same sort cgpa
        if(first == last){
		//partition array
		    int pivot = Domesticpartition3(array, first, last);
		    sortCGPADomestic(array, first, pivot-1);
		    sortCGPADomestic(array, pivot+1, last);
	    }   
            //if cgpa the same sort by province/country
            if(first == last){
                //partition array
		        int pivot = Domesticpartition(array, first, last);
		        sortOverallDomestic(array, first, pivot-1);
		        sortOverallDomestic(array, pivot+1, last);
            }
}

//overall sort International
int studentSort::Internationalpartition(vector<InternationalStudent> array, int low, int high){ //for province/country sort
	InternationalStudent pivot = array[high]; //pivot element
	int i = (low-1); //index of smaller element
	for(int j = low; j <= high-1; j++){ //loop from low to high
		//if current iteration is less than pivot, increment low AND swap elements at i and j
		if(compareCountry(array[j], pivot) == " <"){
			i++; //increment index of smaller element
			swap(array[i], array[j]);   
		}
	}
	swap(array[i+1], array[high]);
	return (i+1);
}

void studentSort::sortOverallInternational(vector<InternationalStudent> array ,int first, int last){
    
    //sort ResearchScore first
    if(last < first){
		//partition array
		int pivot = Internationalpartition4(array, first, last);
		sortResearchScoreInternational(array, first, pivot-1);
		sortResearchScoreInternational(array, pivot+1, last);
	}
        //if the research score is the same sort cgpas
        if(first == last){
		//partition array
		    int pivot = Internationalpartition3(array, first, last);
		    sortCGPAInternational(array, first, pivot-1);
		    sortCGPAInternational(array, pivot+1, last);
	    }   
            //if cgpa the same sort by province/country
            if(first == last){
                //partition array
		        int pivot = Internationalpartition(array, first, last);
		        sortOverallInternational(array, first, pivot-1);
		        sortOverallInternational(array, pivot+1, last);
            }
}
