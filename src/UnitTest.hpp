#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <string>
#include <iostream>
#include "student.hpp"
namespace UnitTest{

    void TestInsert(){
        //corner: right data type, wrong range
        //illegal case: wrong data type

        //test 1
        DomesticList test;
        cout <<"\nDomestic inserting Normal Case: first, last, 4.33, 100, 123456789, BC\n";
        test.sortedInsert("first", "last", "4.33", "100", 123456789, "BC");
        cout <<"\nDomestic inserting Corner Case: first, last, 5.33, 110, 123456789, FAKEPROVINCE\n";
        test.sortedInsert("first", "last", "5.33", "110", 123456789, "FAKEPROVINCE");
        cout <<"\nDomestic inserting Illegal Case: first, last, four, hundred, 123456789, 123\n";
        test.sortedInsert("first", "last", "four", "hundred", 123456789, "123");
        test.display();

        cout << "TOEFL: S:30, R:30, L:30, W:30" << endl;
        toefl toeflTest; //correct
        toeflTest.setSpeaking(30);
        toeflTest.setReading(30);
        toeflTest.setListening(30);
        toeflTest.setWriting(30);
        toeflTest.setTotal();

        cout << "TOEFL: S:1, R:1, L:1, W:1" << endl;
        toefl toeflWrong; //should be caught by error check
        toeflWrong.setSpeaking(1);
        toeflWrong.setReading(1);
        toeflWrong.setListening(1);
        toeflWrong.setWriting(1);
        toeflWrong.setTotal();

        InternationalList Test;
         cout <<"\nInternational inserting Normal Case: first, last, 4.33, 100, 123456789, China, toeflTest\n";
         Test.sortedInsert("first", "last", "4.33", "100", 123456789, "China", toeflTest);
         cout <<"\nInternational inserting Corner Case: first, last, 5.33, 110, 123456789, FAKECOUNTRY, toeflWrong\n";
         Test.sortedInsert("first", "last", "5.33", "110", 123456789, "FAKEPROVINCE", toeflWrong);
         cout <<"\nInternational inserting Illegal Case: first, last, four, hundred, 123456789, 123, toeflWrong\n";
         Test.sortedInsert("first", "last", "four", "hundred", 123456789, "123", toeflWrong);
         Test.display();


        //test 2


        //test 3

    }

    // static void TestDelete(DomesticList* &DomesticHead, InternationalList* &InternationalHead);
    // static void TestDeleteHeadTail(DomesticList* &DomesticHead, InternationalList* &InternationalHead);

};

#endif
