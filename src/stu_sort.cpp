#include "student.hpp"
#include <iostream>
#include <string>
using namespace std;


//Default constructor
Student::Student(){
    firstName = "FirstName";
    lastName = "LastName";
    cgpa = 4.33;
    research = 100;
    studentID = 301123456;
}

//non-default constructor
Student::Student(string inputFirstName, string inputLastName, float inputCGPA, int inputResearch, int inputStudentID){
	firstName = inputFirstName;
	lastName = inputLastName;
	cgpa = inputCGPA;
	research = inputResearch;
	studentID = inputStudentID;
}


//compare functions
string compareCGPA(const Student& student1, const Student& student2){
	if(student1.cgpa < student2.cgpa){
		return "<";
	}
	else if(student1.cgpa == student2.cgpa){
		return "==";
	}
	else if(student1.cgpa > student2.cgpa){
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

//cgpa
void Student::setCGPA(float input){
	cgpa = input;
}
float Student::getCGPA() const{
	return cgpa;
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

//overload <<
std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, cgpa: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << inputDS.getID() << ", " << inputDS.getLastName() << ", " << inputDS.getFirstName() << ", Province: " <<
			inputDS.getProvince() << ", cgpa: " << inputDS.getCGPA() << ", Research Score: " << inputDS.getResearch() << endl;

	return os;
}

//getter and setter
void DomesticStudent::setProvince(string input){
	province = input;
}

string DomesticStudent::getProvince() const{
	return province;
}

void DomesticStudent::sortedInsert(string firstName, string lastName, float cgpa,
	int research, int studentID, string province) {
		domesticNode* current;
		domesticNode* before;
		domesticNode* newNode = new domesticNode(firstName, lastName, cgpa, research, studentID, province);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else if (head->nresearch < newNode->nresearch) {
			newNode->next = head;
			head = newNode;
		} else {
			current = head;
			before = head;
			while(current->next != NULL && current->next->nresearch >= newNode->nresearch) {
				current = current->next;
			}
			if(current != head) {
				while (before->next != current) {
					before = before->next;
				}
			}
			if(newNode->nresearch < tail->nresearch) {
				tail = newNode;
			}
			if( current->next->nresearch > newNode->nresearch) {
				newNode->next = current->next;
				current->next = newNode;
			} else if (current->nresearch == newNode->nresearch){
				if(current->ncgpa > newNode->ncgpa) {
					newNode->next = current->next;
					current->next = newNode;
				} else if (current->ncgpa < newNode->ncgpa) {
					newNode->next = before->next;
					before->next = newNode;
				} else if(current->ncgpa == newNode->ncgpa) {
					if(current->nprovince < newNode->nprovince) {
						newNode->next = current->next;
						current->next = newNode;
					} else if(current->nprovince > newNode->nprovince) {
						newNode->next = before->next;
						before->next = newNode;
					}
				}
			} 
			
		}
	}



void DomesticStudent::display() const {
	if(!empty()) {
		domesticNode* temp = head;
		cout << "Linked list: \n";
		while(temp != NULL) {
			cout << temp-> nstudentID << ", " << temp->nfirstName << ", " << temp->nlastName << ", " << temp->nresearch << ", " 
			 	 << temp->ncgpa << ", " << temp->nprovince << ", " << endl;
			temp = temp->next;
		}
	}
}

DomesticStudent::~DomesticStudent() {
	domesticNode* current = head;
	while(current != NULL) {
		domesticNode* temp = current;
		current = current->next;
		delete temp;
	}
}

int DomesticStudent::pop() {
	int result;
	if(!empty()) {
		domesticNode* temp;
		temp = new domesticNode();
		temp = head;
		head = head->next;
		delete temp;
		result = head->nresearch;
	}
	return result;
}


bool DomesticStudent::empty() const {
	return (head == NULL);
}

// //compare function
// string compareProvince(const DomesticStudent& DS1, const DomesticStudent& DS2){
// 	if(DS1.province < DS2.province){
// 		return "<";
// 	}
// 	else if(DS1.province == DS2.province){
// 		return "==";
// 	}
// 	else if(DS1.province > DS2.province){
// 		return ">";
// 	}
// 	else{
// 		cout << "ERROR: DomesticStudent.compareProince";
// 		exit(1);
// 	}
// }

//overload <<
std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, cgpa: 3.14, Research Score: 25
	//output
	os << "International Student #: " << inputIS.getID() << ", " << inputIS.getLastName() << ", " << inputIS.getFirstName() << ", Country: " <<
			inputIS.getCountry() << ", cgpa: " << inputIS.getCGPA() << ", Research Score: " << inputIS.getResearch() << endl;

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
string compareCountry(const InternationalStudent& IS1, const InternationalStudent& IS2){
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
void InternationalStudent::setTOEFL(const toefl& input){
	TOEFL.setReading(input.getReading());
	TOEFL.setListening(input.getListening());
	TOEFL.setSpeaking(input.getSpeaking());
	TOEFL.setWriting(input.getWriting());
	//after setting all new scores, set new total
	TOEFL.setTotal();
}

toefl InternationalStudent::getTOEFL() const{
	//create toefl object to fill and return
	return TOEFL;
}
