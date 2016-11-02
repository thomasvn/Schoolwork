////
////  1b.cpp
////  Homework 1
////
////  Created by Thomas Nguyen on 9/27/16.
////  Copyright © 2016 Thomas Nguyen. All rights reserved.
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    // Declare the vectors to hold data of each individual student
//    vector <string> name;
//    vector <int> age;
//    vector <float> GPA;
//    vector <string> gradeLevel;
//    
//    
//    // Add a new student named Bobby
//    // This requires careful insertion and removal to all vectors to
//    // ensure all information about students are aligned
//    name.push_back("Bobby Wagner");
//    age.push_back(19);
//    GPA.push_back(4.0);
//    gradeLevel.push_back("Junior");
//    
//    
//    // Print out the contents of the arrays
//    vector <string>::iterator nameIt = name.begin();
//    vector <int>::iterator ageIt = age.begin();
//    vector <float>::iterator gpaIt = GPA.begin();
//    vector <string>::iterator gradeLevelIt = gradeLevel.begin();
//    
//    int counter = 0;
//    while (counter < name.size()) {
//        
//        advance(nameIt, counter);
//        cout << *nameIt << endl;
//        
//        advance(ageIt, counter);
//        cout << *ageIt << endl;
//        
//        advance(gpaIt, counter);
//        cout << *gpaIt << endl;
//        
//        advance(gradeLevelIt, counter);
//        cout << *gradeLevelIt << endl;
//        
//        counter++;
//
//    }
//    
//    return 0;
//    
//}
