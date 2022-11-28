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
#include "functionTwo.hpp"
//#include "UnitTest.hpp"
using namespace functionTwo;
using namespace std;

int main() {
    string menuChoice; //to choose domestic, international, exit
    string menuChoice2; //to choose what to do
    string menuChoice3; //to choose whether test case or main program
    string menuChoice4, menuChoice5;
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


    //                                      Inputting Domestic Students
    //---------------------------------------------------------------------------------------------------------
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

//                                      Inputting International Students
//--------------------------------------------------------------------------------------------
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
        }
        internationalCount++;
        LI.setIntID(LI.getIntID() + 1);
    }

     MergeList MI;
    //  MI.sortedMerge(DL1, LI);


//                                             Graudation Adimission V2.0
    //----------------------------------------------------------------------------------------------------------
    cout << "\nWelcome to Graduate Studemt Admission System Version 2.0\n";
    do{
        cout << "\nMain Menu" << endl;
        cout << "1) Unit Test" << endl;
        cout << "2) Main Program" << endl;
        cout << "0) Exit Program" << endl;
        cin >> menuChoice3;
        if(functionTwo::isNumerical(menuChoice3) == false){
            cout << "ERROR: Invalid input, numbers accepted only" << endl;
            continue;
        }
        else if(stoi(menuChoice3) > 2 || stoi(menuChoice3) < 0){
            cout << "ERROR: Invalid number, please input 0-2" << endl;
        }

        else if(stoi(menuChoice3) == 1){
            //unit test
            DL1.createTestNormal();
            DL1.createTestCorner();
            DL1.createTestIllegal();
            cout <<"\n";
            DL1.display();

            cout <<"\nTesting Normal case for searchone\n";
            DL1.searchOneNormal();
            cout <<"\nTesting Corner case for searchone\n";
            DL1.searchOneCorner();
            cout <<"\nIllegal Corner case for searchone\n";
            DL1.searchOneIllegal();

            cout <<"\nTesting Normal case for searchtwo\n";
            DL1.searchTwoNormal();
            cout <<"\nTesting Corner case for searchtwo\n";
            DL1.searchTwoCorner();
            cout <<"\nIllegal Corner case for searchtwo\n";
            DL1.searchTwoIllegal();

            cout <<"\nTesting case for Deleting Domestic Student\n";
            DL1.selectDeleteNormal();
            DL1.selectDeleteCorner();
            DL1.selectDeleteIllegal();
            DL1.display();

            cout <<"\nTesting Delete Head and Node for Domestic List\n";
            DL1.deleteHeadTail();
            DL1.display();

            cout <<"\nTesting merging Domestic List and International List\n";
            MI.sortedMerge(DL1, LI);
            MI.display();

            cout<<"\nTesting search for Merged list\n";
            MI.searchNormal();
            MI.searchCorner();
            MI.searchIllegal();



            
        }

















        else if(stoi(menuChoice3) == 2){
            //main program
            cout << "\nMain Program\n";
            cout << "Select which of the following you would like by entering respective number: \n";
            cout << "1) Domestic Students\n";
            cout << "2) International Students\n";
            cout << "3) Merge Domestic and International Students\n";
            cout << "0) Return back to Main Menu\n";
            cin >> menuChoice;
            //check user input for errors
            if(functionTwo::isNumerical(menuChoice) == false){ //check for number inputs only
                cout << "ERROR: Invalid input, numbers accepted only\n";
                continue;
            }
            else if(stoi(menuChoice) > 3 || stoi(menuChoice) < 0){ //check for valid numbers only
                cout << "ERROR: Invalid number, please input 0-3\n";
                continue;
            }
            else if(menuChoice == "1"){
                cout << "\nDomestic Student List Menu\n";
                cout <<"Enter the following number of the option you would like\n";
                cout <<"1) Search Student based on Student Objects\n";
                cout <<"2) Search Student based on Student Name\n";
                cout <<"3) Insert a new Student\n";
                cout <<"4) Delete Student\n";
                cout <<"5) Delete the head and tail of Student list\n";
                cout <<"6) Print out list\n";
                cout <<"7) Return back to Main Program Menu\n";
                cin >> menuChoice2;
                if(functionTwo::isNumerical(menuChoice2) == false){ //check for number inputs only
                    cout << "ERROR: Invalid input, numbers accepted only\n";
                    continue;
                }
                else if(stoi(menuChoice2) > 7 || stoi(menuChoice2) < 1){ //check for valid numbers only
                    cout << "ERROR: Invalid number, please input 1-7\n";
                    continue;
                }
                else{
                    if(menuChoice2 == "1"){
                        DL1.searchOne();
                    }
                    else if(menuChoice2 == "2"){
                        DL1.searchTwo();
                    }
                    else if (menuChoice2 == "3"){
                        DL1.create();
                    }
                    else if(menuChoice2 == "4"){
                        DL1.selectDelete();
                    }
                    else if(menuChoice2 == "5"){
                        DL1.deleteHeadTail();
                    }
                    else if(menuChoice2 == "6"){
                        DL1.display();
                    }
                }
            }
            else if(menuChoice == "2"){
                cout << "\nInternational Student List Menu\n";
                cout <<"Enter the following number of the option you would like\n";
                cout <<"1) Search Student based on Student Objects\n";
                cout <<"2) Search Student based on Student Name\n";
                cout <<"3) Insert a new Student\n";
                cout <<"4) Delete Student\n";
                cout <<"5) Delete the head and tail of Student list\n";
                cout <<"6) Print out list\n";
                cout <<"7) Return back to Main Program Menu\n";
                cin >> menuChoice3;
                if(functionTwo::isNumerical(menuChoice3) == false){ //check for number inputs only
                    cout << "ERROR: Invalid input, numbers accepted only\n";
                    continue;
                }
                else if(stoi(menuChoice2) > 7 || stoi(menuChoice2) < 1){ //check for valid numbers only
                    cout << "ERROR: Invalid number, please input 1-7\n";
                    continue;
                }
                else{
                    if(menuChoice2 == "1"){
                        LI.searchOne();
                    }
                    else if(menuChoice2 == "2"){
                        LI.searchTwo();
                    }
                    else if (menuChoice2 == "3"){
                        LI.create();
                    }
                    else if(menuChoice2 == "4"){
                        LI.selectedDelete();
                    }
                    else if(menuChoice2 == "5"){
                        LI.deleteHeadTail();
                    }
                    else if(menuChoice2 == "6"){
                        LI.display();
                    }
                }
            }
            else if(menuChoice == "3"){
                cout << "\nMerge List Menu" << endl;
                cout << "1) Search with criteria" << endl;
                cout << "2) Print out merged list" << endl;
                cout << "0) Return to Main Program Menu" << endl;
                cin >> menuChoice2;
                if(functionTwo::isNumerical(menuChoice2) == false){
                    cout << "ERROR: Invalid input, numbers accepted only" << endl;
                    continue;
                }
                else if(stoi(menuChoice2) > 3 || stoi(menuChoice2) < 0){
                    cout << "ERROR: Invalid number, please input 1-7" << endl;
                    continue;
                }
                else if(menuChoice2 == "1"){
                    MI.search();
                }
                else if(menuChoice2 == "2"){
                    MI.display();
                }
            }
        }
    }
    while(menuChoice3 != "0");
    cout <<"\n Exiting Program, thank you for usiing Graduate Student Admission System Version 2.0\n";

}



    //----------------------------------------------------------------------------------------------------------

     //DL1.searchOne();

//   //input internationalStudents
    // getline(internationalFile, line);
    // int internationalCount = 0;
    // InternationalList LI;
    // while (getline(internationalFile, line)){
    //     istringstream ss(line);
    //     string firstName, lastName, country, s_cgpa, s_researchScore, reading, listening, speaking, writing;
    //     float cgpa;
    //     int researchScore;

    //     getline(ss, firstName, ','); //get firstName
    //     getline(ss, lastName, ','); //get lastName
    //     getline(ss, country, ','); //get province
    //     getline(ss, s_cgpa, ','); //get cgpa
    //     getline(ss, s_researchScore, ','); //get researchScore
    //     getline(ss, reading, ','); //set toefl reading
    //     getline(ss, listening, ','); //set toefl listening
    //     getline(ss, speaking, ','); //set toefl speaking
    //     getline(ss, writing, ','); //set toefl writing

    //     if(firstName == "" || lastName == "" || country == "" || s_cgpa == "" || s_researchScore == "" || reading == "" ||
    //     listening == "" || speaking == "" || writing == ""){
    //         cout << "ERROR: One field in this line is missing. Exiting program now" << endl;
    //         exit(1);
    //     }

    //     if(country == "Idian"){ //correct spelling error
    //         country = "India";
    //     }

    //     if(country != "Canada" && country != "China" && country != "India" && country != "Iran" && country != "Korea"){ //checking if valid country
    //         cout << "ERROR: Country input is invalid. Exiting the program now" << endl;
    //         exit(1);
    //     }

    //     //create toefl object
    //     toefl score;
    //     score.setReading(stoi(reading));
    //     score.setListening(stoi(listening));
    //     score.setSpeaking(stoi(speaking));
    //     score.setWriting(stoi(writing));
    //     score.setTotal();

    //     cgpa = stof(s_cgpa);
    //     researchScore = stoi(s_researchScore);

    //     if(score.getReading() > 19 && score.getListening() > 19 && score.getSpeaking() > 19 &&
    //              score.getWriting() > 19 && score.getTotal() > 92) {
    //          LI.sortedInsert(firstName, lastName, cgpa, researchScore, LI.getIntID(), country, score);
    //     }
    //     internationalCount++;
    //     LI.setIntID(LI.getIntID() + 1);
    // }
    //  LI.display();
    //  LI.displayHead();
    //  LI.displayTail();

    // LI.searchTwo();

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
