//header file student.hpp to declare your classes
#ifndef PROJECT_STUDENT_HPP
#define PROJECT_STUDENT_HPP
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#include "toefl.hpp"
using namespace std;

//DomesticStudent node class
class domesticNode {
	public:
	string nfirstName;
	string nlastName;
	float ncgpa;
	int nresearch;
	int nstudentID;
	string nprovince;
	domesticNode* next;

	domesticNode() {
	nfirstName = "FirstName";
	nlastName = "LastName";
	ncgpa = 4.33;
	nresearch = 100;
	nstudentID = 301123456;
	nprovince = "ProvinceOrTerritory";
	next = NULL;
	}

	domesticNode(string newFirstName, string newLastName, float newCGPA,
	int newResearch, int newStudentID, string newProvince) {
	nfirstName = newFirstName;
	nlastName = newLastName;
	ncgpa = newCGPA;
	nresearch = newResearch;
	nprovince = newProvince;
	next = NULL;
	}

};

//InternationStudent node class
class internationalNode {
	public:
	string firstName;
	string lastName;
	float cgpa;
	int research;
	int studentID;
	string country;
	string TOEFL;
	internationalNode* next;
};

class Student{
public:
	//Default constructor
	Student();

	//Constructor
	Student(string firstName, string lastName, float cgpa, int research, int studentID);

	//set
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setCGPA(float cgpa);
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
	float cgpa;
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

	~DomesticStudent();
	
	//Insert in an overall sorted order
	void sortedInsert(string firstName, string lastName, float cgpa,
				 int research, int studentID, string province);

	//display
	void display() const;

	bool empty() const;

	int pop();

	
private:
	string province;
	domesticNode* head;
	domesticNode* tail;

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

	//Insert in an overall sorted order


private:
	string country;
	toefl TOEFL;
	internationalNode* head;
	internationalNode* tail;
};
#endif
