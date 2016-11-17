//
//  sc.cpp
//  Assignment 3
//
//  Created by Thomas Nguyen on 11/15/16.
//  Copyright © 2016 Thomas Nguyen. All rights reserved.
//

#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
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
    
    
    // Initialize Page Table to size "cacheSize" (Pair includes [data, reference bit])
    deque< pair<int,int> > pgtble;
    deque< pair<int,int> >::iterator clock = pgtble.begin();
    
    // File placed into standard input
    int data;
    while (!cin.eof()) {
        cin >> data;
        
        bool found = false;
        
        // Check to see if the data is in the deque
        deque< pair<int,int> >::iterator it;
        for (it = pgtble.begin(); it != pgtble.end(); it++) {
            
            // If it is in the deque, set its reference bit to 1
            if (it->first == data) {
                it->second = 1;
                found = true;
                break;
            }

        }
        
        // If not found report a page fault and place it in the front.
        if (!found) {
            cout << data << endl;
            
            // Check if page table exceeds "cacheSize" and remove entry that clock points to
            while (pgtble.size() >= cacheSize) {
                
                for (int i = 0; i < cacheSize; i++) {
                    
                    clock = pgtble.begin();
                    
                    // Erase or continue based on reference bit
                    if (clock->second == 0) {
                        pgtble.pop_front();
                        break;
                    }
                    else if (clock->second == 1) {
                        clock->second = 0;
                    }
                    
                    // Shifts all items in the deque one to the left
                    // Items in the front will wrap around the the end
                    rotate(pgtble.begin(), pgtble.begin()+1, pgtble.end());
                    
                }
                
            }
            
            pair<int,int> add;
            add = make_pair(data, 1);
            pgtble.push_back(add);
        }
        
    }
    
    
    return 0;
}
