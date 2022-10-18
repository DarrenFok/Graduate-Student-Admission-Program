//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <string>

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
