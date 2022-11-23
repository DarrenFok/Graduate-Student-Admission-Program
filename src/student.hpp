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
    //Default constructor
    DomesticStudent();
	//overload <<
	friend std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS);

	//province
	void setProvince(string province);
	string getProvince() const;
    void setNext(DomesticStudent *input);
    DomesticStudent* getNext() const;

	//compare function
	friend string compareProvince(const DomesticStudent& DS1, const DomesticStudent& DS2);

private:
	string province;
    DomesticStudent *next;

};

class DomesticList{
public:
    DomesticList();
	
	//insert functions, search functions, everything goes here
    ~DomesticList();

    //getter
    void setDomesticID(int input);
    int getDomesticID() const;

    //Insert in an overall sorted order
    void sortedInsert(string firstName, string lastName, float cgpa,
                      int research, int studentID, string province);

    //display
    void display() const;

    //search and print functions
    void searchOne() const; //cgpa, research score, id
    void searchTwo() const; //first name and last name

    //create node
    bool create(); //create new domesticStudent object, and insert them into list..


    bool empty() const;

    int pop();

	void displayHead() const;

	void displayTail() const;

private:
    DomesticStudent *head = NULL;
    DomesticStudent *tail = NULL;
    int idDomestic = 20220000;
};

class InternationalStudent : public Student{
public:
	//default constructor
	InternationalStudent();
	//overload the operator
	friend std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS);

	//getter, setter
	void setCountry(string input);
	string getCountry() const;

	//compare
	friend string compareCountry(const InternationalStudent& IS1, const InternationalStudent& IS2);

	void setTOEFL(const toefl& input);
	toefl getTOEFL() const;
	void setNext(InternationalStudent *input);
    InternationalStudent* getNext() const;


private:
	string country;
	toefl TOEFL;
    InternationalStudent *next;
};

class InternationalList{
public:
    InternationalList();
	
	//insert functions, search functions, everything goes here
	~InternationalList();
	
	void sortedInsert(string firstName, string lastName, float cgpa,
                      int research, int studentID, string country, toefl TOEFL);

    //display
    void display() const;

    //search and print functions
    void searchOne() const; //for research, cgpa, id
    void searchTwo() const; //for firstname and last name (both)

    bool empty() const;

    int pop();

	void displayHead() const;

	void displayTail() const;

private:
    InternationalStudent *head;
    InternationalStudent *tail;
};
#endif
