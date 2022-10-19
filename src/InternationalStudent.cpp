#include "InternationalStudent.hpp"

//overload <<
std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, CGPA: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << inputIS.getID() << ", " << inputIS.getLastName() << ", " << inputIS.getFirstName() << ", Country: " <<
			inputIS.getCountry() << ", CGPA: " << inputIS.getCGPA() << ", Research Score: " << inputIS.getResearch() << endl;

	return os;
}
