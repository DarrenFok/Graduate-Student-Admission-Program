//header file student.hpp to declare your classes
#ifndef PROJECT_STUDENT_HPP
#define PROJECT_STUDENT_HPP
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include "toefl.hpp"
using namespace std;

class Student{
public:
	//Default constructor
	Student();

	//Constructor
	Student(string firstName, string lastName, float CGPA, int research, int studentID);

	//set
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setCGPA(float CGPA);
	void setResearch(int research);
	void setID(int studentID);

	//get
	string getFirstName() const;
	string getLastName() const;
	float getCGPA() const;
	int getResearch() const;
	int getID() const;

	//compare friend functions, either returns less, equal or greater
	friend string compareCGPA(const Student& student1, const Student& student2);
	friend string compareResearchScore(const Student& student1, const Student& student2);
	friend string compareFirstName(const Student& student1, const Student& student2);
	friend string compareLastName(const Student& student1, const Student& student2);


private:
	//fields
	string firstName;
	string lastName;
	float CGPA;
	int research;
	int studentID;

};

//DomesticStudent child class of Student
class DomesticStudent : public Student{
public:
	//overload <<
	friend std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS);

	//province
	void setProvince(string province);
	string getProvince() const;

	//compare function
	friend string compareProvince(const DomesticStudent& DS1, const DomesticStudent& DS2);

private:
	string province;

};

class InternationalStudent : public Student{
public:
	//overload the operator
	friend std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS);

	//getter, setter
	void setCountry(string input);
	string getCountry() const;

	//compare
	friend string compareCountry(const InternationalStudent& IS1, const InternationalStudent& IS2);

	void setTOEFL(const toefl& input);
	toefl getTOEFL() const;


private:
	string country;
	toefl TOEFL;

};
#endif
