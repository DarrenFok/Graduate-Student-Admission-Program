//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
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
