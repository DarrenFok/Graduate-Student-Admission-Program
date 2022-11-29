#include "student.hpp"
#include <iostream>
#include <string>
#include "functions.hpp"
#include <iomanip>
using namespace std;
using namespace functions;


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

//next
void Student::setNextStudent(Student *input) {
    next = input;
}
Student* Student::getNextStudent() const {
    return next;
}

//overload <<
std::ostream& operator<<(std::ostream& os, const DomesticStudent& inputDS){
	//Example: Domestic Student #: 301461164, Fok, Darren, Province: BC, cgpa: 3.14, Research Score: 25
	//output
	os << "Domestic Student #: " << inputDS.getID() << ", " << inputDS.getLastName() << ", " << inputDS.getFirstName() << ", Province: " <<
			inputDS.getProvince() << ", cgpa: " << inputDS.getCGPA()  << ", Research Score: " << inputDS.getResearch() << endl;

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

DomesticList::DomesticList() {
    head = NULL;
    tail = NULL;
}

bool DomesticList::sortedInsert(string firstName, string lastName, string cgpa,
	string research, int studentID, string province) {
    string provinceInput2 = toUpperCase(province);

    //error checking for research score (int only), and research score (double only)
    if(isNumerical(research) == false){ //if not int type
        cout << "ERROR: Research score input is not an integer" << endl;
        return false;
    }
    if(isDouble(cgpa) == false){
        cout << "ERROR: CGPA input is not a double" << endl;
        return false;
    }
    //error checking to check if cgpa and research score are within bounds
    if(stoi(research) < 0 || stoi(research) > 100){
        cout << "ERROR: Research score is not within the bounds" << endl;
        return false;
    }
    if(stod(cgpa) < 0 || stod(cgpa) > 4.33){
        cout << "ERROR: CGPA is not within the bounds" << endl;
        return false;
    }

    if(provinceInput2 != "NL" && provinceInput2 != "PE" && provinceInput2 != "NS" && provinceInput2 != "NB" && provinceInput2 != "QC" &&
       provinceInput2 != "ON" && provinceInput2 != "MB" && provinceInput2 != "SK" && provinceInput2 != "AB" && provinceInput2 != "BC" &&
       provinceInput2 != "YT" && provinceInput2 != "NT" && provinceInput2 != "NU"){ //checks if one of the valid provinces
        cout << "ERROR: Province input is invalid" << endl;
        return false;
    }

    float cgpaInput = stof(cgpa);
    int researchInput = stoi(research);



		DomesticStudent *current;
		DomesticStudent *before;
		DomesticStudent *temp;
		DomesticStudent *newNode = new DomesticStudent;
        newNode->setFirstName(firstName);
        newNode->setLastName(lastName);
        newNode->setCGPA(cgpaInput);
        newNode->setResearch(researchInput);
        newNode->setID(studentID);
        newNode->setProvince(province);
        newNode->setNext(NULL);

		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else if (head->getResearch() < newNode->getResearch() 
            || head->getResearch() == newNode->getResearch() && head->getCGPA() < newNode->getCGPA() 
                || head->getResearch() == newNode->getResearch() && head->getCGPA() == newNode->getCGPA() && head->getProvince() > newNode->getProvince()) { //if current head research score is less, replace it with the new top
            //setting old head as the next of newnode
			newNode->setNext(head);
            //setting newnode as new head
			head = newNode;
		} else {
			current = head;
			before = head;
			while(current->getNext() != NULL && current->getNext()->getResearch() >= newNode->getResearch()) { //looping through
				current = current->getNext();
                if(current->getResearch() == newNode->getResearch()) {
                    break;
                }
			}
			if(current != head) {
				while (before->getNext() != current) {
					before = before->getNext();
				}
			}
			if(newNode->getResearch() < tail->getResearch() 
                || tail->getResearch() == newNode->getResearch() && tail->getCGPA() < newNode->getCGPA() 
                    || tail->getResearch() == newNode->getResearch() && tail->getCGPA() == newNode->getCGPA() && tail->getProvince() > newNode->getProvince()) {
                tail->setNext(newNode->getNext());
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
					&& current->getNext()->getCGPA() >= newNode->getCGPA()) { //looping through
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
        while(tail->getNext() != NULL) {
            tail = tail->getNext();
        }
        return true;
	}



void DomesticList::display() const {
	if(!empty()) {
		DomesticStudent *temp = head;
		cout << "Displaying Domestic List: \n";
		while(temp != NULL) {
            cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", " << fixed << setprecision(1)
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

void DomesticList::setDomesticID(int input) {
    idDomestic = input;
}

int DomesticList::getDomesticID() const {
    return idDomestic;
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

void DomesticList::displayHead() const {
    cout << "Domestic Head Pointer: ";
    cout << head->getID() << ", " << head->getFirstName() << ", " << head->getLastName() << ", " << head->getResearch() << ", "
			 	 << head->getCGPA() << ", " << head->getProvince() << endl; 
}

void DomesticList::displayTail() const {
    cout << "Domestic Tail Pointer: ";
    cout << tail->getID() << ", " << tail->getFirstName() << ", " << tail->getLastName() << ", " << tail->getResearch() << ", "
			 	 << tail->getCGPA() << ", " << head->getProvince() << endl;
}

void DomesticList::searchOne() const {
    string inputSearchOne1;
    cout << "Please input number corresponding to which field you would like to search" << endl;
    cout << "1) CGPA" << endl;
    cout << "2) Research Score" << endl;
    cout << "3) Application ID" << endl;
    cin >> inputSearchOne1;
    if(isNumerical(inputSearchOne1) == false){
        cout << "ERROR: Invalid input, integers accepted only" << endl;
    }

    else if(stoi(inputSearchOne1) > 3 || stoi(inputSearchOne1) <= 0){
        cout << "ERROR: Invalid integer, please input 1-3" << endl;
    }
    else{
        if(stoi(inputSearchOne1) == 1){ //cgpa is data type double, NEED TO CREATE A FUNCTION TO CHECK IF VALID DOUBLE
            string inputSearchOne2;
            int count = 0;
            //output prompt
            cout << "Please input a CGPA to search by" << endl;
            //user input
            cin >> inputSearchOne2;
            //print the ones that meet the requirement
            DomesticStudent *temp = head;
            if(isDouble(inputSearchOne2) == false){ //checks whether inputSearchOne2 is a double
                cout << "ERROR: Invalid input, doubles accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(compareDoubles(temp->getCGPA(), stod(inputSearchOne2)) == true){ //stod always adds on extra decimals... thus never equal?
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getProvince() << endl;
                        count++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
        else if(stoi(inputSearchOne1) == 2){ //research score is data type int
            string inputSearchOne2;
            int count = 0;
            cout << "Please input a Research Score to search by" << endl;
            cin >> inputSearchOne2;
            DomesticStudent *temp = head;
            if(isNumerical(inputSearchOne2) == false){
                cout << "ERROR: Invalid input, integers accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(temp->getResearch() == stoi(inputSearchOne2)){
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getProvince() << endl;
                        count++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
        else if(stoi(inputSearchOne1) == 3){ //id is data type int
            string inputSearchOne2;
            int count = 0;
            cout << "Please input an Application ID to search by" << endl;
            cin >> inputSearchOne2;
            DomesticStudent *temp = head;
            if(isNumerical(inputSearchOne2) == false){
                cout << "ERROR: Invalid input, integers accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(temp->getID() == stoi(inputSearchOne2)){
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getProvince() << endl;
                        count ++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
    }
}

void DomesticList::searchTwo() const {
    string firstNameInput;
    string lastNameInput;
    int count = 0;
    cout << "Please input a first name: " << endl;
    cin >> firstNameInput;
    cout << "Please input a last name: " << endl;
    cin >> lastNameInput;
    DomesticStudent *temp = head;
    while(temp!= NULL){
        if((toLowerCase(temp->getFirstName()) == toLowerCase(firstNameInput)) && (toLowerCase(temp->getLastName()) ==
                toLowerCase(lastNameInput))){
            cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                 << temp->getCGPA() << ", " << temp->getProvince() << endl;
            count++;
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matches found" << endl;
    }
}

DomesticStudent* DomesticList::getHead() const {
    return head;
}
DomesticStudent* DomesticList::getTail() const{
    return tail;
}

bool DomesticList::create(string firstInput, string lastInput, string researchInput, string cgpaInput, string provinceInput){
    string provinceInput2 = toUpperCase(provinceInput);

    //error checking for research score (int only), and research score (double only)
    if(isNumerical(researchInput) == false){ //if not int type
        cout << "ERROR: Research score input is not an integer" << endl;
        return false;
    }
    if(isDouble(cgpaInput) == false){
        cout << "ERROR: CGPA input is not a double" << endl;
        return false;
    }
    //error checking to check if cgpa and research score are within bounds
    if(stoi(researchInput) < 0 || stoi(researchInput) > 100){
        cout << "ERROR: Research score is not within the bounds" << endl;
        return false;
    }
    if(stod(cgpaInput) < 0 || stod(cgpaInput) > 4.33){
        cout << "ERROR: CGPA is not within the bounds" << endl;
        return false;
    }

    if(provinceInput2 != "NL" && provinceInput2 != "PE" && provinceInput2 != "NS" && provinceInput2 != "NB" && provinceInput2 != "QC" &&
    provinceInput2 != "ON" && provinceInput2 != "MB" && provinceInput2 != "SK" && provinceInput2 != "AB" && provinceInput2 != "BC" &&
    provinceInput2 != "YT" && provinceInput2 != "NT" && provinceInput2 != "NU"){ //checks if one of the valid provinces
        cout << "ERROR: Province input is invalid" << endl;
        return false;
    }
    sortedInsert(firstInput, lastInput, cgpaInput, researchInput, idDomestic, provinceInput2);
    idDomestic++;
    return true;
}

void DomesticList::selectDelete(string firstnameInput, string lastnameInput){
    DomesticStudent* before = head;
    DomesticStudent* current = head; //node that we want to delete
    int count = 0;
    //get user input

    //case insensitive
    firstnameInput = toLowerCase(firstnameInput);
    lastnameInput = toLowerCase(lastnameInput);

    //get current and before
    while(current != NULL) {
        //set new before
        if(current != head){
            while(before->getNext() != current){
                before = before->getNext();
            }
        }

        if(firstnameInput == toLowerCase(current->getFirstName()) && lastnameInput == toLowerCase(current->getLastName())){
            if(current == head){
                current = current->getNext();
                pop();
                before = head;
                count++;
            }
            else{
                DomesticStudent *temp = current;
                DomesticStudent *temp2 = current->getNext();
                before->setNext(temp->getNext()); //set before's next to current's next (skip over current)
                delete temp;
                current = temp2;
                count++;
            }
        }
        else{
            current = current->getNext();
        }
    }
    if(count == 0){
        cout << "No matches found" << endl;
    }

}


//--------------------------------------------------------------------------------------------

void DomesticList::deleteHeadTail(){
	//deletes head
	pop();

	DomesticStudent* current = head;
	DomesticStudent* before = head;

	//get current and before
	while(current->getNext() != NULL){
		current = current->getNext();
	} 
	if(current != head){//at least 2 nodes
		while(before->getNext() != current){
			before = before->getNext();
		}
	}
	before->setNext(NULL);
	delete current;
	tail = before;
}

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
 		cout << "ERROR: DomesticStudent.compareProvince";
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

void InternationalStudent::setNext(InternationalStudent *input) {
    next = input;
}

InternationalStudent* InternationalStudent::getNext() const {
    return next;
}
InternationalList::InternationalList() {
    head = NULL;
    tail = NULL;
}
bool InternationalList::sortedInsert(string firstName, string lastName, string cgpa,
	string research, int studentID, string country, toefl TOEFL) {
    //error check cgpa and research inputs
    if(isNumerical(research) == false){
        cout << "ERROR: Research score input is not an integer" << endl;
        return false;
    }
    if(isDouble(cgpa) == false){
        cout << "ERROR: CGPA input is not a double" << endl;
        return false;
    }
    //check if cgpa and research scores are within bounds
    if(stoi(research) < 0 || stoi(research) > 100){
        cout << "ERROR: Research score is not within the bounds" << endl;
        return false;
    }
    if(stod(cgpa) < 0 || stod(cgpa) > 4.33){
        cout << "ERROR: CGPA is not within the bounds" << endl;
        return false;
    }
    //check if country is valid
    if(country != "Canada" && country != "China" && country != "Iran" && country != "India" && country != "Korea"){
        cout << "ERROR: Country input is invalid" << endl;
        return false;
    }
    int total = TOEFL.getReading() + TOEFL.getListening() + TOEFL.getSpeaking() + TOEFL.getWriting();
    //check if TOEFL scores are valid
    if(TOEFL.getReading() < 20 || TOEFL.getListening() < 20 || TOEFL.getSpeaking() < 20 || TOEFL.getWriting() < 20 || total < 93){
        cout << "ERROR: TOEFL scores do not meet the requirement" << endl;
        return false;
    }

    float cgpaInput = stof(cgpa);
    int researchInput = stoi(research);


		InternationalStudent *current;
		InternationalStudent *before;
		InternationalStudent *temp;
		InternationalStudent *newNode = new InternationalStudent;
        newNode->setFirstName(firstName);
        newNode->setLastName(lastName);
        newNode->setCGPA(cgpaInput);
        newNode->setResearch(researchInput);
        newNode->setID(studentID);
        newNode->setCountry(country);
		newNode->setTOEFL(TOEFL);
        newNode->setNext(NULL);

		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else if (head->getResearch() < newNode->getResearch() 
            || head->getResearch() == newNode->getResearch() && head->getCGPA() < newNode->getCGPA() 
                || head->getResearch() == newNode->getResearch() && head->getCGPA() == newNode->getCGPA()&& head->getCountry() > newNode->getCountry()) { //if current head research score is less, replace it with the new top
            //setting old head as the next of newnode
			newNode->setNext(head);
            //setting newnode as new head
			head = newNode;
		} else {
			current = head;
			before = head;
			while(current->getNext() != NULL && current->getNext()->getResearch() >= newNode->getResearch()) { //looping through
				current = current->getNext();
                if(current->getResearch() == newNode->getResearch()){
                    break;
                }
			}
			if(current != head) {
				while (before->getNext() != current) {
					before = before->getNext();
				}
			}
			if(newNode->getResearch() < tail->getResearch()) {
                tail->setNext(newNode->getNext());
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
                        if(current->getCGPA() == newNode->getCGPA()) {
                            break;
                        }
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
                        && current->getNext()->getCGPA()  == newNode->getCGPA() && current->getNext()->getCountry() > newNode->getCountry()) { //looping through
							current = current->getNext();
					}
					if(current != head) {
						while (before->getNext() != current) {
							before = before->getNext();
						}
					}
					if(current->getCountry() < newNode->getCountry()) {
                        //set newNode next to current next
                        newNode->setNext(current->getNext());
                        //set current next to newnode
                        current->setNext(newNode);
					}
                    else if(current->getCountry() > newNode->getCountry()) { //Also similar to line 209, doesn't work when current's province is greater than newNode's
                        //set newNode next to current next
                        newNode->setNext(before->getNext());
                        //set current next to newnode
                        before->setNext(newNode);
					}
				}
			} 
		}
        while(tail->getNext() != NULL) {
            tail = tail->getNext();
        }
	}


InternationalList::~InternationalList() {
	InternationalStudent *current = head;
	while(current != NULL) {
		InternationalStudent *temp = current;
		current = current->getNext();
		delete temp;
	}
}

void InternationalList::setIntID(int input) {
    idInternational = input;
}

int InternationalList::getIntID() const {
    return idInternational;
}

int InternationalList::pop(){
    int result;
    if(!empty()) {
        InternationalStudent *temp;
        temp = new InternationalStudent;
        temp = head;
        head = head->getNext();
        delete temp;
        result = head->getResearch();
    }
    return result;
}

void InternationalList::display() const {
	if(!empty()) {
		InternationalStudent *temp = head;
		cout << "Displaying International List: \n";
		while(temp != NULL) {
			cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", " << fixed << setprecision(1)
			 	 << temp->getCGPA() << ", " << temp->getCountry()  << endl;
			temp = temp->getNext();
		}
	}
}

bool InternationalList::empty() const {
	return (head == NULL);
}

void InternationalList::displayHead() const {
    cout << "International Head Pointer: ";
    cout << head->getID() << ", " << head->getFirstName() << ", " << head->getLastName() << ", " << head->getResearch() << ", "
			 	 << head->getCGPA() << ", " << head->getCountry() << endl; 
}

void InternationalList::displayTail() const {
    cout << "International Tail Pointer: ";
    cout << tail->getID() << ", " << tail->getFirstName() << ", " << tail->getLastName() << ", " << tail->getResearch() << ", "
			 	 << tail->getCGPA() << ", " << head->getCountry() << endl;
}



void InternationalList::searchOne() const {
    string inputSearchOne1;
    cout << "Please input number corresponding to which field you would like to search" << endl;
    cout << "1) CGPA" << endl;
    cout << "2) Research Score" << endl;
    cout << "3) Application ID" << endl;
    cin >> inputSearchOne1;
    if(isNumerical(inputSearchOne1) == false){
        cout << "ERROR: Invalid input, integers accepted only" << endl;
    }

    else if(stoi(inputSearchOne1) > 3 || stoi(inputSearchOne1) <= 0){
        cout << "ERROR: Invalid integer, please input 1-3" << endl;
    }
    else{
        if(stoi(inputSearchOne1) == 1){ //cgpa is data type double, NEED TO CREATE A FUNCTION TO CHECK IF VALID DOUBLE
            string inputSearchOne2;
            int count = 0;
            //output prompt
            cout << "Please input a CGPA to search by" << endl;
            //user input
            cin >> inputSearchOne2;
            //print the ones that meet the requirement
            InternationalStudent *temp = head;
            if(isDouble(inputSearchOne2) == false){ //checks whether inputSearchOne2 is a double
                cout << "ERROR: Invalid input, doubles accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(compareDoubles(temp->getCGPA(), stod(inputSearchOne2)) == true){ //stod always adds on extra decimals... thus never equal?
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getCountry() << endl;
                        count++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
        else if(stoi(inputSearchOne1) == 2){ //research score is data type int
            string inputSearchOne2;
            int count = 0;
            cout << "Please input a Research Score to search by" << endl;
            cin >> inputSearchOne2;
            InternationalStudent *temp = head;
            if(isNumerical(inputSearchOne2) == false){
                cout << "ERROR: Invalid input, integers accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(temp->getResearch() == stoi(inputSearchOne2)){
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getCountry() << endl;
                        count++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
        else if(stoi(inputSearchOne1) == 3){ //id is data type int
            string inputSearchOne2;
            int count = 0;
            cout << "Please input an Application ID to search by" << endl;
            cin >> inputSearchOne2;
            InternationalStudent *temp = head;
            if(isNumerical(inputSearchOne2) == false){
                cout << "ERROR: Invalid input, integers accepted only" << endl;
            }
            else{
                while(temp != NULL){
                    if(temp->getID() == stoi(inputSearchOne2)){
                        cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                             << temp->getCGPA() << ", " << temp->getCountry() << endl;
                        count ++;
                    }
                    temp = temp->getNext();
                }
                if(count == 0){
                    cout << "No matches found" << endl;
                }
            }
        }
    }
}

void InternationalList::searchTwo() const{
    string firstNameInput;
    string lastNameInput;
    int count = 0;
    cout << "Please input a first name: " << endl;
    cin >> firstNameInput;
    cout << "Please input a last name: " << endl;
    cin >> lastNameInput;
    InternationalStudent *temp = head;
    while(temp!= NULL){
        if((toLowerCase(temp->getFirstName()) == toLowerCase(firstNameInput)) && (toLowerCase(temp->getLastName()) ==
                                                                                  toLowerCase(lastNameInput))){
            cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", "
                 << temp->getCGPA() << ", " << temp->getCountry() << endl;
            count++;
        }
        temp = temp->getNext();
    }
    if(count == 0){
        cout << "No matches found" << endl;
    }
}

InternationalStudent* InternationalList::getHead() const {
    return head;
}

bool InternationalList::create(string firstInput, string lastInput, string researchInput, string cgpaInput, string countryInput, string readingInput,
                               string listeningInput, string writingInput, string speakingInput){

    //error check cgpa and research inputs
    if(isNumerical(researchInput) == false){
        cout << "ERROR: Research score input is not an integer" << endl;
        return false;
    }
    if(isDouble(cgpaInput) == false){
        cout << "ERROR: CGPA input is not a double" << endl;
        return false;
    }
    //check if cgpa and research scores are within bounds
    if(stoi(researchInput) < 0 || stoi(researchInput) > 100){
        cout << "ERROR: Research score is not within the bounds" << endl;
        return false;
    }
    if(stod(cgpaInput) < 0 || stod(cgpaInput) > 4.33){
        cout << "ERROR: CGPA is not within the bounds" << endl;
        return false;
    }
    //check if country is valid
    if(countryInput != "Canada" && countryInput != "China" && countryInput != "Iran" && countryInput != "India" && countryInput != "Korea"){
        cout << "ERROR: Country input is invalid" << endl;
        return false;
    }
    int total = stoi(readingInput) + stoi(listeningInput) + stoi(speakingInput) + stoi(writingInput);
    //check if TOEFL scores are valid
    if(stoi(readingInput) < 20 || stoi(listeningInput) < 20 || stoi(speakingInput) < 20 || stoi(writingInput) < 20 || total < 93){
        cout << "ERROR: TOEFL scores do not meet the requirement" << endl;
        return false;
    }


    //create toefl object
    toefl score;
    score.setReading(stoi(readingInput));
    score.setListening(stoi(listeningInput));
    score.setSpeaking(stoi(speakingInput));
    score.setWriting(stoi(writingInput));
    score.setTotal();

    sortedInsert(firstInput, lastInput, cgpaInput, researchInput, idInternational, countryInput, score);
    idInternational++;
    return true;

}

void InternationalList::selectedDelete() {
    InternationalStudent* before = head;
    InternationalStudent* current = head; //node that we want to delete
    int count = 0;
    string firstnameInput;
    string lastnameInput;
    //get user input
    cout << "\nPlease enter the first name of a student you would like to delete: " << endl;
    cin >> firstnameInput;
    cout << "\nPlease input the last name of a student you would like to delete: " << endl;
    cin >> lastnameInput;

    //case insensitive
    firstnameInput = toLowerCase(firstnameInput);
    lastnameInput = toLowerCase(lastnameInput);

    //get current and before
    while(current != NULL) {
        //set new before
        if(current != head){
            while(before->getNext() != current){
                before = before->getNext();
            }
        }

        if(firstnameInput == toLowerCase(current->getFirstName()) && lastnameInput == toLowerCase(current->getLastName())){
            if(current == head){
                current = current->getNext();
                pop();
                before = head;
                count++;
            }
            else{
                InternationalStudent *temp = current;
                InternationalStudent *temp2 = current->getNext();
                before->setNext(temp->getNext()); //set before's next to current's next (skip over current)
                delete temp;
                current = temp2;
                count++;
            }
        }
        else{
            current = current->getNext();
        }
    }
    if(count == 0){
        cout << "No matches found" << endl;
    }
}

void InternationalList::deleteHeadTail(){
    //deletes head
    pop();

    InternationalStudent* current = head;
    InternationalStudent* before = head;

    //get current and before
    while(current->getNext() != NULL){
        current = current->getNext();
    }
    if(current != head){//at least 2 nodes
        while(before->getNext() != current){
            before = before->getNext();
        }
    }
    before->setNext(NULL);
    delete current;
    tail = before;
}

MergeList::MergeList() {
    head = NULL;
    tail = NULL;
}


MergeList::~MergeList() {
    Student *current = head;
    while (current != NULL) {
        Student *temp = current;
        current = current->getNextStudent();
        delete temp;
    }
}




void MergeList::sortedMerge(const DomesticList input, const InternationalList input2) {
    int countDom = 0; //for testing how many students are input
    //domestic part
    DomesticStudent *temp = input.getHead();
    Student *current = head;

    if(head == NULL){
        Student *copy1 = new Student;
        copy1->setFirstName(temp->getFirstName());
        copy1->setLastName(temp->getLastName());
        copy1->setID(temp->getID());
        copy1->setResearch(temp->getResearch());
        Student *copy2 = new Student;
        copy1->setNextStudent(copy2);

        current = copy1;
        head = current;

        temp = temp->getNext();
        current = current->getNextStudent();
        countDom++;
    }

    //copy over domestic list into merge list
    while(temp->getNext() != NULL){
        current->setFirstName(temp->getFirstName());
        current->setLastName(temp->getLastName());
        current->setID(temp->getID());
        current->setResearch(temp->getResearch());
        current->setCGPA(temp->getCGPA());
        Student *copy2 = new Student;
        current->setNextStudent(copy2);

        temp = temp->getNext();
        current = current->getNextStudent();
        countDom++;

    }
    if(temp->getNext() == NULL){
        current->setFirstName(temp->getFirstName());
        current->setLastName(temp->getLastName());
        current->setID(temp->getID());
        current->setResearch(temp->getResearch());
        current->setCGPA(temp->getCGPA());
        current->setNextStudent(NULL);

        tail = current;
        countDom++;
    }

    //cout << "student count: " << countDom << endl;
    //slot in international

    //insert the international dudes now in a sortedInsert fashion
    int intCount = 0;
    InternationalStudent *temp2 = input2.getHead(); //start from input2's head
    Student *current2;
    Student *before2;
    while(temp2 != NULL){ //temp2 is similar to newNode, as it iterates each time
        //create object to sort
        Student *newNode = new Student;
        newNode->setFirstName(temp2->getFirstName());
        newNode->setLastName(temp2->getLastName());
        newNode->setResearch(temp2->getResearch());
        newNode->setCGPA(temp2->getCGPA());
        newNode->setID(temp2->getID());

        if(head->getResearch() < newNode->getResearch()
        || head->getResearch() == newNode->getResearch() && head->getCGPA() < newNode->getCGPA()){
            newNode->setNextStudent(head);
            head = newNode;
        }
        else{
            current2 = head;
            before2 = head;
            while(current2->getNextStudent() != NULL && current2->getNextStudent()->getResearch() >= newNode->getResearch()){
                current2 = current2->getNextStudent();
                if(current2->getResearch() == newNode->getResearch()){
                    break;
                }
            }
            if(current2 != head){
                while(before2->getNextStudent() != current2){
                    before2 = before2->getNextStudent();
                }
            }
            if(newNode->getResearch() < tail->getResearch()
            || tail->getResearch() == newNode->getResearch() && tail->getCGPA() > newNode->getCGPA()){
                tail->setNextStudent(newNode->getNextStudent());
                tail = newNode;
            }

            if(current2->getNextStudent() == NULL){
                current2->setNextStudent(newNode);
            }
            else if(current2->getResearch() > newNode->getResearch()){
                newNode->setNextStudent(current2->getNextStudent());
                current2->setNextStudent(newNode);
            }
            else if(current2->getResearch() == newNode->getResearch()){
                while(current2->getNextStudent() != NULL && current2->getNextStudent()->getResearch() == newNode->getResearch()
                && current2->getNextStudent()->getCGPA() >= newNode->getCGPA()){
                    current2= current2->getNextStudent();
                }
                if(current2 != head){
                    while(before2->getNextStudent() != current2){
                        before2 = before2->getNextStudent();
                    }
                }
                if(current2->getCGPA() > newNode->getCGPA()){
                    newNode->setNextStudent(current2->getNextStudent());
                    current2->setNextStudent(newNode);
                }
                else if(current2->getCGPA() < newNode->getCGPA()){
                    newNode->setNextStudent(before2->getNextStudent());
                    before2->setNextStudent(newNode);
                }
                else if(current2->getCGPA() == newNode->getCGPA()){
                    while(current2->getNextStudent() != NULL && current2->getNextStudent()->getResearch() == newNode->getResearch()
                          && current2->getNextStudent()->getCGPA() > newNode->getCGPA()){
                        current2 = current2->getNextStudent();
                    }
                    newNode->setNextStudent(current2->getNextStudent());
                    current2->setNextStudent(newNode);
                }
            }
        }
        temp2 = temp2->getNext();
        intCount++;
    }
    while(tail->getNextStudent() != NULL) {
        tail = tail->getNextStudent();
    }

}



void MergeList::display() const {
    if(!empty()) {
        Student *temp = head;
        cout << "Displaying Merged List: \n";
        while(temp != NULL) {
            cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", " << fixed << setprecision(1)
                 << temp->getCGPA() << endl;
            temp = temp->getNextStudent();
        }
    }
}

bool MergeList::empty() const {
    return (head == NULL);
}

bool MergeList::search(string cgpa_threshold, string researchScore_threshold) const{
    int count = 0;

    Student *temp = head;
    while(temp != NULL){
        if(temp->getResearch() >= stoi(researchScore_threshold) && temp->getCGPA() >= stof(cgpa_threshold)){
            cout << temp->getID() << ", " << temp->getFirstName() << ", " << temp->getLastName() << ", " << temp->getResearch() << ", " << fixed << setprecision(1)
                 << temp->getCGPA() << endl;
            count++;
        }
        temp = temp->getNextStudent();
    }
    if(count == 0){
        cout << "No matches found" << endl;
    }
    return true;
}
