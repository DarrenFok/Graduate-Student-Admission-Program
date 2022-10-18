//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>

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
	void setResarch(int research);
	void setID(int studentID);

	//get
	string getFirstName();
	string getLastName();
	float getCGPA();
	int getResearch();
	int getID();

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
	//province
	void SetProvince(string province);
	string getProvince();

private:
	string province;

};

class InternationalStudent : public Student{
public:
private:
	string country;
	int TOEFL;

};

class TOEFLScore{
public:
private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int total;
};
