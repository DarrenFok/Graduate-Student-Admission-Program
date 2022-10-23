//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <string>

//Default constructor
Student::Student(){
	firstName = "FirstName";
	lastName = "LastName";
	CGPA = 4.33;
	research = 100;
	studentID = 301123456;
}

//Non-default constructor
Student::Student(string inputFirstName, string inputLastName, float inputCGPA, int inputResearch, int inputStudentID){
	firstName = inputFirstName;
	lastName = inputLastName;
	CGPA = inputCGPA;
	research = inputResearch;
	studentID = inputStudentID;
}

//compare functions
string compareCGPA(const Student& student1, const Student& student2){
	if(student1.CGPA < student2.CGPA){
		return "<";
	}
	else if(student1.CGPA == student2.CGPA){
		return "==";
	}
	else if(student1.CGPA > student2.CGPA){
		return ">";
	}
	else{
		cout << "ERROR: compareCGPA";
		exit(1);
	}
}

string compareResearchScore(const Student& student1, const Student& student2){
	if(student1.research < student2.research){
		return "<";
	}
	else if(student1.research == student2.research){
		return "==";
	}
	else if(student1.research > student2.research){
		return ">";
	}
	else{
		cout <<"ERROR: compareResearchScore";
		exit(1);
	}
}

string compareFirstName(const Student& student1, const Student& student2){
	if(student1.firstName < student2.firstName){
		return "<";
	}
	else if(student1.firstName == student2.firstName){
		return "==";
	}
	else if(student1.firstName > student2.firstName){
		return ">";
	}
	else{
		cout << "ERROR: compareFirstName";
		exit(1);
	}
}

string compareLastName(const Student& student1, const Student& student2){
	if(student1.lastName < student2.lastName){
		return "<";
	}
	else if(student1.lastName == student2.lastName){
		return "==";
	}
	else if(student1.lastName > student2.lastName){
		return ">";
	}
	else{
		cout << "ERROR: compareLastName";
		exit(1);
	}
}




//getters and setters
//firstName
void Student::setFirstName(string input){
	firstName = input;
}
string Student::getFirstName() const{
	return firstName;
}

//lastName
void Student::setLastName(string input){
	lastName = input;
}
string Student::getLastName() const{
	return lastName;
}

//CGPA
void Student::setCGPA(float input){
	CGPA = input;
}
float Student::getCGPA() const{
	return CGPA;
}

//research
void Student::setResearch(int input){
	research = input;
}
int Student::getResearch() const{
	return research;
}

//studentID
void Student::setID(int input){
	studentID = input;
}
int Student::getID() const{
	return studentID;
}

//DomesticStudent
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

//overload <<
std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, CGPA: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << inputIS.getID() << ", " << inputIS.getLastName() << ", " << inputIS.getFirstName() << ", Country: " <<
			inputIS.getCountry() << ", CGPA: " << inputIS.getCGPA() << ", Research Score: " << inputIS.getResearch() << endl;

	return os;
}

//country getter and setter
void InternationalStudent::setCountry(string input){
	country = input;
}

string InternationalStudent::getCountry() const{
	return country;
}

//compare function
string InternationalStudent::compareCountry(const InternationalStudent& IS1, const InternationalStudent& IS2){
	if(IS1.country < IS2.country){
		return "<";
	}
	else if(IS1.country == IS2.country){
		return "==";
	}
	else if(IS1.country > IS2.country){
		return ">";
	}
	else{
		cout << "ERROR: InternationalStudent.compareCountry";
		exit(1);
	}
}

//TOEFL score getter and setter
//replace old toefl scores with the "new" input ones
void InternationalStudent::setTOEFL(const toefl input){
	TOEFL.setReading(input.getReading());
	TOEFL.setListening(input.getListening());
	TOEFL.setSpeaking(input.getSpeaking());
	TOEFL.setWriting(input.getWriting());
	//after setting all new scores, set new total
	TOEFL.setTotal();
}

toefl& InternationalStudent::getTOEFL() const{
	//create toefl object to fill and return
	toefl temp;
	temp.setReading(TOEFL.getReading());
	temp.setListening(TOEFL.getListening());
	temp.setSpeaking(TOEFL.getSpeaking());
	temp.setWriting(TOEFL.getWriting());
	//after filling, then return entire object
	return temp;
}


