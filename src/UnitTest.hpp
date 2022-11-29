#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <string>
#include <iostream>
#include "student.hpp"
namespace UnitTest{

    void TestInsert(){
        //test 1
        DomesticList test;
        cout <<"\nDomestic inserting Normal Case: first, last, 4.33, 100, 123456789, BC\n";
        test.sortedInsert("first", "last", "4.33", "100", 123456789, "BC");
        cout <<"\nDomestic inserting Corner Case: first, last, 5.33, 110, 123456789, FAKEPROVINCE\n";
        test.sortedInsert("first", "last", "5.33", "110", 123456789, "FAKEPROVINCE");
        cout <<"\nDomestic inserting Illegal Case: first, last, four, hundred, 123456789, 123\n";
        test.sortedInsert("first", "last", "four", "hundred", 123456789, "123");
        test.display();

        InternationalList Test;
        // cout <<"\nInternational inserting Normal Case: first, last, 4.33, 100, 123456789, China, 50\n";
        // Test.sortedInsert("first", "last", 4.33, 100, 123456789, "China", 50);
        // cout <<"\nInternational inserting Corner Case: first, last, 5.33, 110, 123456789, FAKECOUNTRY, 200\n";
        // Test.sortedInsert("first", "last", 5.33, 110, 123456789, "FAKEPROVINCE", 200);
        // cout <<"\nInternational inserting Illegal Case: first, last, four, hundred, 123456789, 123, Fail\n";
        // Test.sortedInsert("first", "last", "four", "hundred", 123456789, "123", "Fail");
        // Test.display();


        //test 2
        test.

        //test 3

    }

    // static void TestDelete(DomesticList* &DomesticHead, InternationalList* &InternationalHead);
    // static void TestDeleteHeadTail(DomesticList* &DomesticHead, InternationalList* &InternationalHead);

};

#endif
