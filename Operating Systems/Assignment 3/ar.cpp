//
//  ar.cpp
//  Assignment 3
//
//  Created by Thomas Nguyen on 11/15/16.
//  Copyright © 2016 Thomas Nguyen. All rights reserved.
//

#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Not the correct number of arguments" << endl;
        return 0;
    }
    
    
    // Cache size from argv[1]
    int cacheSize = atoi(argv[1]);
    
    
    // Initialize Page Table to size "cacheSize" (Pair includes [data, binary counter])
    deque< pair<int,int> > pgtble;
   
    
    // File placed into standard input
    int data;
    while (!cin.eof()) {
        cin >> data;
        
        bool found = false;
        
        // Check to see if the data is in the deque
        deque< pair<int,int> >::iterator it;
        for (it = pgtble.begin(); it != pgtble.end(); it++) {
            
            // Update binary counter if it is the correct data
            if (it->first == data) {
                it->second >>= 1;
                it->second += 10000000;
                found = true;
            }
            // Shift bits right if not what we are looking for
            else {
                it->second >>= 1;
            }
            
        }
        
        // If not found report a page fault and place it in the front.
        if (!found) {
            cout << data << endl;
            
            // Remove the smallest priority entry
            int minNum = 11111111;
            while (pgtble.size() >= cacheSize) {
                deque< pair<int,int> >::iterator it;
                deque< pair<int,int> >::iterator temp;
                
                for (it = pgtble.begin(); it != pgtble.end(); it++) {
                    if (it->second <= minNum) {
                        it->second = minNum;
                        temp = it;
                    }
                }
                
                pgtble.erase(temp);
            }
            
            pair<int,int> add;
            add = make_pair(data, 10000000);
            pgtble.push_front(add);
        }
        
    }
    
    
    return 0;
}
