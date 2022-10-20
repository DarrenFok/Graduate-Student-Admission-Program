#include "DomesticStudent.hpp"
#include <iostream>
using namespace std;

//overload <<
std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, CGPA: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << inputDS.getID() << ", " << inputDS.getLastName() << ", " << inputDS.getFirstName() << ", Province: " <<
			inputDS.getProvince() << ", CGPA: " << inputDS.getCGPA() << ", Research Score: " << inputDS.getResearch() << endl;

	return os;
}

//getter and setter
void DomesticStudent::setProvince(string input){
	province = input;
}

string DomesticStudent::getProvince() const{
	return province;
}

//compare function
string DomesticStudent::compareProvince(const DomesticStudent& DS1, const DomesticStudent& DS2){
	if(DS1.province < DS2.province){
		return "<";
	}
	else if(DS1.province == DS2.province){
		return "==";
	}
	else if(DS1.province > DS2.province){
		return ">";
	}
	else{
		cout << "ERROR: DomesticStudent.compareProince";
		exit(1);
	}
}
