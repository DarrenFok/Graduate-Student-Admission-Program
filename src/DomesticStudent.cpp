#include "DomesticStudent.hpp"

//overload <<
std::ostream& operator<<(std::ostream& os, const DomesticStudent& stu){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, CGPA: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << stu.getID() << ", " << stu.getLastName << ", " << stu.getFirstName << ", Province: " <<
			stu.getProvince << ", CGPA: " << stu.getCGPA << ", Research Score: " << stu.getResearch << std::endl;

	return os;
}

//getter and setter
void DomesticStudent::setProvince(string input){
	province = input;
}

string DomesticStudent::getProvince() const{
	return province;
}
