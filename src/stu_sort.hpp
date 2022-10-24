//header file stu_sort.hpp to declare your sorting functions
#ifndef PROJECT_STU_SORT_HPP
#define PROJECT_STU_SORT_HPP
//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include "vector" //vectors
#include "student.hpp"
#include "toefl.hpp"
using namespace std;

namespace studentSort{ //make it namespace, so that functions can be accessed outside
    //lastName sort
    int domesticPartition1(vector<DomesticStudent>& array, int first, int last); //from low to high
    int internationalPartition1(vector < InternationalStudent >& array, int first, int last);
    void sortLastNameDomestic(vector<DomesticStudent>& array, int first, int last); //works
    void sortLastNameInternational(vector<InternationalStudent>& array, int first, int last);

    //firstname sort
    int domesticPartition2(vector < DomesticStudent >& array, int low, int high);
    int internationalPartition2(vector < InternationalStudent >& array, int low, int high);
    void sortFirstNameDomestic(vector<DomesticStudent>& array, int first, int last); //works
    void sortFirstNameInternational(vector<InternationalStudent>& array, int first, int last);

    //cgpa sort
    int domesticPartition3(vector<DomesticStudent>& array, int low, int high);
    int internationalPartition3(vector<InternationalStudent>& array, int low, int high);
    void sortCGPADomestic(vector<DomesticStudent>& array, int first, int last);
    void sortCGPAInternational(vector<InternationalStudent>& array, int first, int last);

    //research score sort
    int domesticPartition4(vector < DomesticStudent >& array, int low, int high);
    int internationalPartition4(vector < InternationalStudent >& array, int low, int high);
    void sortResearchScoreDomestic(vector<DomesticStudent>& array, int first, int last);
    void sortResearchScoreInternational(vector<InternationalStudent>& array, int first, int last);

    //overall sort
    int domesticPartition5(vector < DomesticStudent >& array, int low, int high);
    int internationalPartition5(vector < InternationalStudent >& array, int low, int high);
    void sortOverallDomestic(vector<DomesticStudent>& array, int first, int last);
    void sortOverallInternational(vector<InternationalStudent>& array, int first, int last);
    //
    int domesticPartition7(vector < DomesticStudent >& array, int low, int high);
    int domesticPartition8(vector < DomesticStudent >& array, int low, int high);
    int internationalPartition7(vector < InternationalStudent >& array, int low, int high);
    int internationalPartition8(vector < InternationalStudent >& array, int low, int high);
    //swap
	void swapDomestic(DomesticStudent& input1, DomesticStudent& input2); //function to swap
    void swapInternational(InternationalStudent& input1, InternationalStudent& input2);



}
#endif
