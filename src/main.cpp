//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include "stu_sort.hpp"
#include "functions.hpp" //user created functions
using namespace std;

int main(){
	string menuChoice; //to choose domestic, international, exit
    string menuChoice2; //to choose what type of sort

    //read .txt files
    ifstream domesticFile("domestic-stu.txt");
    ifstream internationalFile("international-stu.txt");

    //check if files read properly
    if(!domesticFile.is_open()) {
        cout << "ERROR: Unable to open file domestic-stu.txt" << endl;
        return -1;
    }
    if(!internationalFile.is_open()){
        cout << "ERROR: Unable to open file international-stu.txt";
        return -1;
    }

    //menu - loops until user wants to exit
    do{
        //UI asking for user input
        cout << "Welcome to the Graduate Student Admission Program\n";
        cout << "Choose Domestic or International Students by typing in respective number: \n";
        cout << "1) Domestic Students\n";
        cout << "2) International Students\n";
        cout << "0) Exit program";
        cin >> menuChoice;

        //check user input for errors
        if(functions::isNumerical(menuChoice) == false){ //check for number inputs only
            cout << "ERROR: Invalid input, numbers accepted only\n";
            continue;
        }

        else if(stoi(menuChoice) > 2 || stoi(menuChoice) < 0){ //check for valid numbers only
            cout << "ERROR: Invalid number, please input 0-2\n";
            continue;
        }

        else{ //if input is valid
            if(menuChoice == "1"){ //domestic students
                cout << "Please choose a way to sort Domestic Students: \n";
                cout << "1) CGPA\n";
                cout << "2) Research Score\n";
                cout << "3) First Name\n";
                cout << "4) Last Name\n";
                cout << "5) Overall Sort (Research Score -> CGPA -> Province\n";
                cin >> menuChoice2;

                if(functions::isNumerical(menuChoice2) == false){ //check for number inputs only
                    cout << "ERROR: Invalid input, numbers accepted only\n";
                    continue;
                }
                else if(stoi(menuChoice2) > 5 || stoi(menuChoice2) < 0){ //check for valid numbers only
                    cout << "ERROR: Invalid number, please input 0-5\n";
                    continue;
                }
                else{
                    if(menuChoice2 == "1"){
                        cout << "Sorting by CGPA...\n";
                        //sort by CGPA
                        //print list
                    }
                    else if(menuChoice2 == "2"){
                        cout << "Sorting by Research Score...\n";
                        //sort by research score
                        //print list
                    }
                    else if(menuChoice2 == "3"){
                        cout << "Sorting by First Name...\n";
                        //sort by first name
                        //print list
                    }
                    else if(menuChoice2 == "4"){
                        cout << "Sorting by Last Name...\n";
                        //sort by last name
                        //print list
                    }
                    else if(menuChoice2 == "5"){
                        cout << "Sorting by overall attributes...\n";
                        //overall sort
                        //print list
                    }
                }
            }
            else if(menuChoice == "2"){ //international students
                cout << "Please choose a way to sort International Students: \n";
                cout << "1) CGPA\n";
                cout << "2) Research Score\n";
                cout << "3) First Name\n";
                cout << "4) Last Name\n";
                cout << "5) Overall Sort (Research Score -> CGPA -> Country\n";
                cin >> menuChoice2;

                if(functions::isNumerical(menuChoice2) == false){ //check for number inputs only
                    cout << "ERROR: Invalid input, numbers accepted only\n";
                    continue;
                }
                else if(stoi(menuChoice2) > 5 || stoi(menuChoice2) < 0){ //check for valid numbers only
                    cout << "ERROR: Invalid number, please input 0-5\n";
                    continue;
                }
                else{
                    if(menuChoice2 == "1"){
                        cout << "Sorting by CGPA...\n";
                        //sort by CGPA
                        //print list
                    }
                    else if(menuChoice2 == "2"){
                        cout << "Sorting by Research Score...\n";
                        //sort by research score
                        //print list
                    }
                    else if(menuChoice2 == "3"){
                        cout << "Sorting by First Name...\n";
                        //sort by first name
                        //print list
                    }
                    else if(menuChoice2 == "4"){
                        cout << "Sorting by Last Name...\n";
                        //sort by last name
                        //print list
                    }
                    else if(menuChoice2 == "5"){
                        cout << "Sorting by overall attributes...\n";
                        //overall sort
                        //print list
                    }
                }
            }
        }
    }
    while(menuChoice != "0"); //exiting program if 0
    cout << "Thank you for using the program";






























//
//
//  //Read the domestic-stu.txt file and exit if failed
//  string line;
//  ifstream domesticFile("domestic-stu.txt");
//  if(!domesticFile.is_open()) {
//    cout << "Unable to open file domestic-stu.txt" << endl;
//    return -1;
//  }
//
//  //Read the first line of domestic-stu.txt, which specifies
//  //the file format. And then print it out to the screen
//  getline(domesticFile, line);
//  cout << "File format: " << line << endl;
//
//  /*Keep reading the rest of the lines in domestic-stu.txt.
//   *In the example code here, I will read each data separated
//   *by a comma, and then print it out to the screen.
//   *In your lab assignment 1, you should use these read data
//   *to initialize your DomesticStudent object. Then you can
//   *use get and set functions to manipulate your object, and
//   *print the object content to the screen
//   */
//  int stu_count = 1;
//  while( getline(domesticFile, line) ) {
//    /*process each line, get each field separated by a comma.
//     *We use istringstream to handle it.
//     *Note in this example code here, we assume the file format
//     *is perfect and do NOT handle error cases. We will leave the
//     *error and exception handling of file format to Lab Assignment 4
//     */
//    istringstream ss(line);
//
//    string firstName, lastName, province, s_cgpa, s_researchScore;
//    float cgpa;
//    int researchScore;
//
//    //get firstName separated by comma
//    getline(ss, firstName, ',');
//
//    //get lastName separated by comma
//    getline(ss, lastName, ',');
//
//    //get province separated by comma
//    getline(ss, province, ',');
//
//    //get cpga separated by comma, and convert string to float
//    getline(ss, s_cgpa, ',');
//    cgpa = atof(s_cgpa.c_str());
//
//    //get researchScore separated by comma, and convert it to int
//    getline(ss, s_researchScore, ',');
//    researchScore = atoi(s_researchScore.c_str());
//
//    //print the student info to the screen
//    cout << "Domestic student " << stu_count << " " << firstName << " "
//	 << lastName << " from " << province << " province has cgpa of "
//	 << cgpa << ", and research score of " << researchScore << endl;
//
//    stu_count++;
//  }
//
//  //close your file
//  domesticFile.close();

  return 0;

}
