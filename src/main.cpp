//testing push/pull
//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include "stu_sort.hpp"
#include "toefl.hpp"
#include "student.hpp"
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
    
    //input domesticStudents
    getline(domesticFile, line);
    int domesticCount = 0;
    DomesticList DL1;
    while (getline(domesticFile, line)) {
        istringstream ss(line);
        string firstName, lastName, province, s_cgpa, s_researchScore; //strings
        float cgpa; //to convert string cgpa to
        int researchScore; //to convert string researchScore to

        getline(ss, firstName, ','); //get firstName
        getline(ss, lastName, ','); //get lastName
        getline(ss, province, ','); //get province
        getline(ss, s_cgpa, ','); //get cgpa
        getline(ss, s_researchScore, ','); //get researchScore

        if(firstName == "" || lastName == "" || province == "" || s_cgpa == "" || s_researchScore == ""){ //checking for empty fields
            cout << "ERROR: One field in this line is missing. Exiting the program now" << endl;
            exit(1);
        }

        if(province != "NL" && province != "PE" && province != "NS" && province != "NB" && province != "QC" &&
           province != "ON" && province != "MB" && province != "SK" && province != "AB" && province != "BC" &&
           province != "YT" && province != "NT" && province != "NU"){ //checks if one of the valid provinces
            cout << "ERROR: Province input is invalid. Exiting the program now" << endl;
            exit(1);
        }

        cgpa = stof(s_cgpa);
        researchScore = stoi(s_researchScore);

        DL1.sortedInsert(firstName, lastName, cgpa, researchScore, DL1.getDomesticID(),province);
        domesticCount++;
        DL1.setDomesticID(DL1.getDomesticID() + 1);


    }

//   DL1.display();
//    cout << "\ntesting delete\n";
//    DL1.selectDelete();
//    DL1.display();;
//    cout << endl << endl;
//    DL1.display();
//    cout << endl;
//    DL1.displayHead();
//    DL1.displayTail();

     //DL1.searchOne();

//   //input internationalStudents
     getline(internationalFile, line);
     int internationalCount = 0;
     InternationalList LI;
     while (getline(internationalFile, line)){
         istringstream ss(line);
         string firstName, lastName, country, s_cgpa, s_researchScore, reading, listening, speaking, writing;
         float cgpa;
         int researchScore;

         getline(ss, firstName, ','); //get firstName
         getline(ss, lastName, ','); //get lastName
         getline(ss, country, ','); //get province
         getline(ss, s_cgpa, ','); //get cgpa
         getline(ss, s_researchScore, ','); //get researchScore
         getline(ss, reading, ','); //set toefl reading
         getline(ss, listening, ','); //set toefl listening
         getline(ss, speaking, ','); //set toefl speaking
         getline(ss, writing, ','); //set toefl writing

         if(firstName == "" || lastName == "" || country == "" || s_cgpa == "" || s_researchScore == "" || reading == "" ||
         listening == "" || speaking == "" || writing == ""){
             cout << "ERROR: One field in this line is missing. Exiting program now" << endl;
             exit(1);
         }

         if(country == "Idian"){ //correct spelling error
             country = "India";
         }

         if(country != "Canada" && country != "China" && country != "India" && country != "Iran" && country != "Korea"){ //checking if valid country
             cout << "ERROR: Country input is invalid. Exiting the program now" << endl;
             exit(1);
         }

         //create toefl object
         toefl score;
         score.setReading(stoi(reading));
         score.setListening(stoi(listening));
         score.setSpeaking(stoi(speaking));
         score.setWriting(stoi(writing));
         score.setTotal();

         cgpa = stof(s_cgpa);
         researchScore = stoi(s_researchScore);

         if(score.getReading() > 19 && score.getListening() > 19 && score.getSpeaking() > 19 &&
                  score.getWriting() > 19 && score.getTotal() > 92) {
              LI.sortedInsert(firstName, lastName, cgpa, researchScore, LI.getIntID(), country, score);
             internationalCount++;
         }
         LI.setIntID(LI.getIntID() + 1);
     }
//     LI.display();
//     LI.create();
//     LI.display();
//     LI.selectedDelete();
//     LI.display();
// cout << internationalCount;

    MergeList MI;
    MI.sortedMerge(DL1, LI);
    MI.display();






    // cout << "\nWelcome to the Graduate Student Admission Program\n";
    // //menu - loops until user wants to exit
    // do{
    //     //UI asking for user input
    //     cout << "\nMAIN MENU\n";
    //     cout << "Choose Domestic or International Students by typing in respective number: \n";
    //     cout << "1) Domestic Students\n";
    //     cout << "2) International Students\n";
    //     cout << "0) Exit program\n";
    //     cin >> menuChoice;
    //     //check user input for errors
    //     if(functions::isNumerical(menuChoice) == false){ //check for number inputs only
    //         cout << "ERROR: Invalid input, numbers accepted only\n";
    //         continue;
    //     }
    //     else if(stoi(menuChoice) > 2 || stoi(menuChoice) < 0){ //check for valid numbers only
    //         cout << "ERROR: Invalid number, please input 0-2\n";
    //         continue;
    //     }
    //     else{ //if input is valid
    //         if(menuChoice == "1"){ //domestic students
    //             cout << "\nDOMESTIC STUDENT MENU\n";
    //             cout << "Please choose a way to sort Domestic Students: \n";
    //             cout << "1) cgpa\n";
    //             cout << "2) Research Score\n";
    //             cout << "3) First Name\n";
    //             cout << "4) Last Name\n";
    //             cout << "5) Overall Sort (Research Score -> cgpa -> Province)\n";
    //             cout << "0) Go back to main menu\n";
    //             cin >> menuChoice2;
    //             if(functions::isNumerical(menuChoice2) == false){ //check for number inputs only
    //                 cout << "ERROR: Invalid input, numbers accepted only\n";
    //                 continue;
    //             }
    //             else if(stoi(menuChoice2) > 5 || stoi(menuChoice2) < 0){ //check for valid numbers only
    //                 cout << "ERROR: Invalid number, please input 0-5\n";
    //                 continue;
    //             }
    //             else{
    //                 if(menuChoice2 == "1"){
    //                     cout << "Sorting by cgpa...\n";
    //                     //sort by cgpa
    //                     //print list
    //                     studentSort::sortCGPADomestic(domesticStudents, 0, domesticStudents.size()-1);
    //                     for(int i = 0; i < domesticStudents.size(); i++){
    //                         cout << domesticStudents[i];
    //                     }
    //                 }
    //                 else if(menuChoice2 == "2"){
    //                     cout << "Sorting by Research Score...\n";
    //                     //sort by research score
    //                     //print list
    //                     studentSort::sortResearchScoreDomestic(domesticStudents, 0, domesticStudents.size()-1);
    //                     for(int i = 0; i < domesticStudents.size(); i++){
    //                         cout << domesticStudents[i];
    //                     }
    //                 }
    //                 else if(menuChoice2 == "3"){
    //                     cout << "Sorting by First Name...\n";
    //                     //sort by first name
    //                     //print list
    //                     studentSort::sortFirstNameDomestic(domesticStudents, 0, domesticStudents.size()-1);
    //                     for(int i = 0; i < domesticStudents.size(); i++){
    //                         cout << domesticStudents[i];
    //                     }
    //                 }
    //                 else if(menuChoice2 == "4"){
    //                     cout << "Sorting by Last Name...\n";
    //                     //sort by last name
    //                     //print list
    //                     studentSort::sortLastNameDomestic(domesticStudents, 0, domesticStudents.size()-1);
    //                     for(int i = 0; i < domesticStudents.size(); i++){
    //                         cout << domesticStudents[i];
    //                     }
    //                 }
    //                 else if(menuChoice2 == "5"){
    //                     cout << "Sorting by overall attributes...\n";
    //                     //overall sort
    //                     //print list
    //                     studentSort::sortOverallDomestic(domesticStudents, 0, domesticStudents.size()-1);
    //                     for(int i = 0; i < domesticStudents.size(); i++){
    //                         cout << domesticStudents[i];
    //                     }
    //                 }
    //             } 
    //         } else if(menuChoice == "2"){ //international students
    //             cout << "\nINTERNATIONAL STUDENT MENU\n";
    //             cout << "Please choose a way to sort International Students: \n";
    //             cout << "1) cgpa\n";
    //             cout << "2) Research Score\n";
    //             cout << "3) First Name\n";
    //             cout << "4) Last Name\n";
    //             cout << "5) Overall Sort (Research Score -> cgpa -> Country)\n";
    //             cout << "0) Go back to main menu\n";
    //             cin >> menuChoice2;
    //             if(functions::isNumerical(menuChoice2) == false){ //check for number inputs only
    //                 cout << "ERROR: Invalid input, numbers accepted only\n";
    //                 continue;
    //             }
    //             else if(stoi(menuChoice2) > 5 || stoi(menuChoice2) < 0){ //check for valid numbers only
    //                 cout << "ERROR: Invalid number, please input 0-5\n";
    //                 continue;
    //             }
    //             else{
    //                 if(menuChoice2 == "1"){
    //                     cout << "Sorting by cgpa...\n";
    //                     //sort by cgpa
    //                     //print list
    //                     studentSort::sortCGPAInternational(internationalStudents, 0 , internationalStudents.size()-1);
    //                         for(int i = 0; i < internationalStudents.size(); i++){
    //                             cout << internationalStudents[i];
    //                         }
    //                 }
    //                 else if(menuChoice2 == "2"){
    //                     cout << "Sorting by Research Score...\n";
    //                     //sort by research score
    //                     //print list
    //                     studentSort::sortResearchScoreInternational(internationalStudents, 0 , internationalStudents.size()-1);
    //                         for(int i = 0; i < internationalStudents.size(); i++){
    //                             cout << internationalStudents[i];
    //                         }
    //                 }
    //                 else if(menuChoice2 == "3"){
    //                     cout << "Sorting by First Name...\n";
    //                     //sort by first name
    //                     //print list
    //                     studentSort::sortFirstNameInternational(internationalStudents, 0 , internationalStudents.size()-1);
    //                         for(int i = 0; i < internationalStudents.size(); i++){
    //                             cout << internationalStudents[i];
    //                         }
    //                 }
    //                 else if(menuChoice2 == "4"){
    //                     cout << "Sorting by Last Name...\n";
    //                     //sort by last name
    //                     //print list
    //                     studentSort::sortLastNameInternational(internationalStudents, 0 , internationalStudents.size()-1);
    //                     for(int i = 0; i < internationalStudents.size(); i++){
    //                         cout << internationalStudents[i];
    //                     }
    //                 }
    //                 else if(menuChoice2 == "5"){
    //                     cout << "Sorting by overall attributes...\n";
    //                     cout << "Filtering out students that don't meet TOEFL requirements...\n";
    //                     //overall sort
    //                     //print list
    //                     studentSort::sortOverallInternational(internationalStudents, 0 , internationalStudents.size()-1);
    //                     for(int i = 0; i < internationalStudents.size(); i++){
    //                         //filter out students that don't meet TOEFL requirements
    //                         if(internationalStudents[i].getTOEFL().getTotal() > 92 && internationalStudents[i].getTOEFL().getWriting() > 19 && internationalStudents[i].getTOEFL().getSpeaking() > 19 &&
    //                         internationalStudents[i].getTOEFL().getListening() > 19 && internationalStudents[i].getTOEFL().getReading() > 19){
    //                             cout << internationalStudents[i];
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // while(menuChoice != "0"); //exiting program if 0
    //cout << "Thank you for using the program\n";


  return 0;

}
