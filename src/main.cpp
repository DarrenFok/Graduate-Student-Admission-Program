//testing push/pull
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

int main() {
    string menuChoice; //to choose domestic, international, exit
    string menuChoice2; //to choose what type of sort
    string line;

    //read .txt files
    ifstream domesticFile("domestic-stu.txt");
    ifstream internationalFile("international-stu.txt");

    //check if files read properly
    if (!domesticFile.is_open()) {
        cout << "ERROR: Unable to open file domestic-stu.txt" << endl;
        return -1;
    }
    if (!internationalFile.is_open()) {
        cout << "ERROR: Unable to open file international-stu.txt";
        return -1;
    }

    //put .txt files into arrays
    vector<DomesticStudent> domesticStudents;
    vector<InternationalStudent> internationalStudents;

    //input domesticStudents
    getline(domesticFile, line);
    int domesticCount = 0;
    int idCountDomestic = 20220000;
    while (getline(domesticFile, line)) {
        istringstream ss(line);
        string firstName, lastName, province, s_cgpa, s_researchScore; //strings
        float cgpa; //to convert string cgpa to
        int researchScore; //to convert string researchScore to

        getline(ss, firstName, ','); //get firstName
        getline(ss, lastName, ','); //get lastName
        getline(ss, province, ','); //get province
        getline(ss, s_cgpa, ','); //get cgpa
        cgpa = stof(s_cgpa);
        getline(ss, s_researchScore, ','); //get researchScore
        researchScore = stoi(s_researchScore);

        DomesticStudent inputDomestic;
        inputDomestic.setFirstName(firstName);
        inputDomestic.setLastName(lastName);
        inputDomestic.setProvince(province);
        inputDomestic.setCGPA(cgpa);
        inputDomestic.setResearch(researchScore);
        inputDomestic.setID(idCountDomestic);

        domesticStudents.push_back(inputDomestic);

        domesticCount++;
        idCountDomestic++;
    }

    //input internationalStudents
    getline(internationalFile, line);
    int internationalCount = 0;
    int idCountInternational = 20220000;
    while (getline(internationalFile, line)){
        istringstream ss(line);
        string firstName, lastName, country, s_cgpa, s_researchScore, reading, listening, speaking, writing;
        float cgpa;
        int researchScore;

        getline(ss, firstName, ','); //get firstName
        getline(ss, lastName, ','); //get lastName
        getline(ss, country, ','); //get province
        getline(ss, s_cgpa, ','); //get cgpa
        cgpa = stof(s_cgpa);
        getline(ss, s_researchScore, ','); //get researchScore
        researchScore = stoi(s_researchScore);
        getline(ss, reading, ',');
        getline(ss, listening, ',');
        getline(ss, speaking, ',');
        getline(ss, writing, ',');

        toefl score;
        score.setReading(stoi(reading));
        score.setListening(stoi(listening));
        score.setSpeaking(stoi(speaking));
        score.setWriting(stoi(writing));
        score.setTotal();

        InternationalStudent inputInternational;
        inputInternational.setFirstName(firstName);
        inputInternational.setLastName(lastName);
        inputInternational.setCountry(country);
        inputInternational.setCGPA(cgpa);
        inputInternational.setResearch(researchScore);
        inputInternational.setTOEFL(score);
        inputInternational.setID(idCountInternational);

        internationalStudents.push_back(inputInternational);

        internationalCount++;
        idCountInternational++;
    }

    //before sort
    for(int i = 0; i < domesticStudents.size(); i++){
        cout << domesticStudents[i];
    }

        for(int i = 0; i < internationalStudents.size(); i++){
        cout << internationalStudents[i];
    }

/*
    //after sort
    vector<InternationalStudent> final;
    for(int i = 0; i < internationalStudents.size(); i++){ //takes out internationalStudent objects that do not fulfill the TOEFL requirements
        if(internationalStudents.at(i).getTOEFL().getTotal() > 92 && internationalStudents[i].getTOEFL().getReading() > 19 && internationalStudents[i].getTOEFL().getListening() > 19 && internationalStudents[i].getTOEFL().getSpeaking() > 19 && internationalStudents[i].getTOEFL().getWriting() > 19){
            final.push_back(internationalStudents[i]);
        }
    }*/

    studentSort::sortOverallDomestic(domesticStudents, 0, domesticStudents.size()-1);

    cout << "\nNow sorting...\n";
    for(int i = 0; i < domesticStudents.size(); i++){
        cout << domesticStudents[i];
    }

    studentSort::sortOverallInternational(internationalStudents, 0 , internationalStudents.size()-1);

    cout << "\nNow sorting...\n";
    for(int i = 0; i < internationalStudents.size(); i++){
        cout << internationalStudents[i];
    }
/*

    cout << "Welcome to the Graduate Student Admission Program\n";

    //menu - loops until user wants to exit
    do{
        //UI asking for user input
        cout << "MAIN MENU\n";
        cout << "Choose Domestic or International Students by typing in respective number: \n";
        cout << "1) Domestic Students\n";
        cout << "2) International Students\n";
        cout << "0) Exit program\n";
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
                cout << "DOMESTIC STUDENT MENU\n";
                cout << "Please choose a way to sort Domestic Students: \n";
                cout << "1) CGPA\n";
                cout << "2) Research Score\n";
                cout << "3) First Name\n";
                cout << "4) Last Name\n";
                cout << "5) Overall Sort (Research Score -> CGPA -> Province)\n";
                cout << "0) Go back to main menu";
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
                cout << "INTERNATIONAL STUDENT MENU\n";
                cout << "Please choose a way to sort International Students: \n";
                cout << "1) CGPA\n";
                cout << "2) Research Score\n";
                cout << "3) First Name\n";
                cout << "4) Last Name\n";
                cout << "5) Overall Sort (Research Score -> CGPA -> Country)\n";
                cout << "0) Go back to main menu";
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

    */

  return 0;

}
