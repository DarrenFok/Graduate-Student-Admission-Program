//header file stu_sort.hpp to declare your sorting functions
#ifndef PROJECT_STU_SORT_HPP
#define PROJECT_STU_SORT_HPP
//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include "vector" //vectors
#include <student.hpp>
#include <toefl.hpp>
using namespace std;

namespace studentSort{ //make it namespace, so that functions can be accessed outside
	//lastName sort
	int Domesticpartition1(vector<DomesticStudent> array, int first, int last); //from low to high
    int Internationalpartition1(vector<InternationalStudent> array, int first, int last);
	void sortLastNameDomestic(vector<DomesticStudent> array, int first, int last);
    void sortLastNameInternational(vector<InternationalStudent> array, int first, int last);

    //firstname sort
    int Domesticpartition2(vector<DomesticStudent> array, int low, int high);
    int Internationalpartition2(vector<InternationalStudent> array, int low, int high);
    void sortFirstNameDomestic(vector<DomesticStudent> array, int first, int last);
    void sortFirstNameInternational(vector<InternationalStudent> array, int first, int last);

    //cgpa sort
    int Domesticpartition3(vector<DomesticStudent> array, int low, int high);
    int Internationalpartition3(vector<InternationalStudent> array, int low, int high);
    void sortCGPADomestic(vector<DomesticStudent> array, int first, int last);
    void sortCGPAInternational(vector<InternationalStudent> array, int first, int last);

    //research score sort
    int Domesticpartition4(vector<DomesticStudent> array, int low, int high);
    int Internationalpartition4(vector<InternationalStudent> array, int low, int high);
    void sortResearchScoreDomestic(vector<DomesticStudent> array, int first, int last);
    void sortResearchScoreInternational(vector<InternationalStudent> array, int first, int last);

    //overall sort
    int Domesticpartition(vector<DomesticStudent> array, int low, int high);
    int Internationalpartition(vector<InternationalStudent> array, int low, int high);
    void sortOverallDomestic(vector<DomesticStudent> array, int first, int last);
    void sortOverallInternational(vector<InternationalStudent> array, int first, int last);
    //swap
	void swap(Student& input1, Student& input2); //function to swap

}
#endif
