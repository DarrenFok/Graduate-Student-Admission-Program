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

DomesticStudent* DomesticStudent::getNext() const {
    return next;
}

void DomesticList::sortedInsert(string firstName, string lastName, float cgpa,
	int research, int studentID, string province) {
		DomesticStudent *current;
		DomesticStudent *before;
		DomesticStudent *temp;
		DomesticStudent *newNode = new DomesticStudent;
        newNode->setFirstName(firstName);
        newNode->setLastName(lastName);
        newNode->setCGPA(cgpa);
        newNode->setResearch(research);
        newNode->setID(studentID);
        newNode->setProvince(province);
        newNode->setNext(NULL);

		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else if (head->getResearch() < newNode->getResearch() || head->getResearch() == newNode->getResearch() 
			&& head->getCGPA() < newNode->getCGPA() || head->getResearch() == newNode->getResearch() && head->getCGPA() == newNode->getCGPA()
			&& head->getProvince() > newNode->getProvince()) { //if current head research score is less, replace it with the new top
            //setting old head as the next of newnode
			newNode->setNext(head);
            //setting newnode as new head
			head = newNode;
		} else {
			current = head;
			before = head;
			while(current->getNext() != NULL && current->getNext()->getResearch() >= newNode->getResearch()) { //looping through
				current = current->getNext();
			}
			if(current != head) {
				while (before->getNext() != current) {
					before = before->getNext();
				}
			}
			if(newNode->getResearch() < tail->getResearch()) {
				tail = newNode;
			}
            if(current->getNext() == NULL){
                current->setNext(newNode);
            }
			else if((current->getResearch()) > (newNode->getResearch())){
                //set newNode next to current next
				newNode->setNext(current->getNext());
                //set current next to newnode
				current->setNext(newNode);
			}
            else if (current->getResearch() == newNode->getResearch()){ //CGPA is descending order
				while(current->getNext() != NULL && current->getNext()->getResearch() == newNode->getResearch() 
					&& current->getNext()->getCGPA()  >= newNode->getCGPA()) { //looping through
						current = current->getNext();
				}
				if(current != head) {
					while (before->getNext() != current) {
						before = before->getNext();
					}
				}
				if(current->getCGPA() > newNode->getCGPA()) { //correct
                    //set newNode next to current next
                    newNode->setNext(current->getNext());
                    //set current next to newnode
                    current->setNext(newNode);
				}
                else if (current->getCGPA() < newNode->getCGPA()) { //Right now, this line does not work, whenever the current CGPA is less than newNode's
                    //set newNode next to current next
                    newNode->setNext(before->getNext());
                    //set current next to newnode
                    before->setNext(newNode);
				}
                else if(current->getCGPA() == newNode->getCGPA()) {
					while(current->getNext() != NULL && current->getNext()->getResearch() == newNode->getResearch() 
						&& current->getNext()->getCGPA()  == newNode->getCGPA() && current->getNext()->getProvince() > newNode->getProvince()) { //looping through
							current = current->getNext();
					}
					if(current != head) {
						while (before->getNext() != current) {
							before = before->getNext();
						}
					}
					if(current->getProvince() < newNode->getProvince()) {
                        //set newNode next to current next
                        newNode->setNext(current->getNext());
                        //set current next to newnode
                        current->setNext(newNode);
					}
                    else if(current->getProvince() > newNode->getProvince()) { //Also similar to line 209, doesn't work when current's province is greater than newNode's
                        //set newNode next to current next
                        newNode->setNext(before->getNext());
                        //set current next to newnode
                        before->setNext(newNode);
					}
				}
			} 
			
		}
	}



void DomesticList::display() const {
	if(!empty()) {
		DomesticStudent *temp = head;
		cout << "Linked list: \n";
		while(temp != NULL) {
			cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
			 	 << temp->getCGPA() << ", " << temp->getProvince() << endl;
			temp = temp->getNext();
		}
	}
}

DomesticList::~DomesticList() {
	DomesticStudent *current = head;
	while(current != NULL) {
		DomesticStudent *temp = current;
		current = current->getNext();
		delete temp;
	}
}

int DomesticList::pop() {
	int result;
	if(!empty()) {
		DomesticStudent *temp;
		temp = new DomesticStudent;
		temp = head;
		head = head->getNext();
		delete temp;
		result = head->getResearch();
	}
	return result;
}


bool DomesticList::empty() const {
	return (head == NULL);
}

//void DomesticList::searchOne() const {
//    string inputSearchOne1;
//    string inputSearchOne2;
//    cout << "Please input number corresponding to which field you would like to search" << endl;
////    cout << "1) CGPA" << endl;
//    cout << "2) Research Score" << endl;
//    cout << "3) Application ID" << endl;
//    cin >> inputSearchOne1;
//    if(stoi(inputSearchOne1) == 1){
//
//    }
//    else if(stoi(inputSearchOne1) == 2){
//
//    }
//    else if(stoi(inputSearchOne1) == 3){
//
//    }
//
//}

//compare function
 string compareProvince(const DomesticStudent& DS1, const DomesticStudent& DS2){
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

DomesticStudent::DomesticStudent() {
    next = NULL;
}

void DomesticStudent::setNext(DomesticStudent *input) {
    next = input;
}

//overload <<
std::ostream& operator<<(std::ostream& os, const InternationalStudent& inputIS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, cgpa: 3.14, Research Score: 25
	//output
	os << "International Student #: " << inputIS.getID() << ", " << inputIS.getLastName() << ", " << inputIS.getFirstName() << ", Country: " <<
			inputIS.getCountry() << ", cgpa: " << inputIS.getCGPA() << ", Research Score: " << inputIS.getResearch() << endl;

	return os;
}

InternationalStudent::InternationalStudent() {
	next = NULL;
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
