#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include <string>
#include <iostream>
#include "student.hpp"
namespace UnitTest{

    void TestInsert(){
        //test 1
        DomesticList test;
        test.sortedInsert("first", "last", "4.33", "100", 123456789, "BC");
        test.display();

        //test 2


        //test 3

    }

    // static void TestDelete(DomesticList* &DomesticHead, InternationalList* &InternationalHead);
    // static void TestDeleteHeadTail(DomesticList* &DomesticHead, InternationalList* &InternationalHead);

};

#endif