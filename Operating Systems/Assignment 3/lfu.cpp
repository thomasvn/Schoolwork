//
//  lfu.cpp
//  Assignment 3
//
//  Created by Thomas Nguyen on 11/9/16.
//  Copyright © 2016 Thomas Nguyen. All rights reserved.
//

#include <iostream>
#include <deque>
#include <utility>
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
    
    
    // Initialize Page Table to size "cacheSize" (Pair includes [data, counter])
    deque< pair<int,int> > pgtble;
    
    
    // File placed into standard input
    int data;
    while (!cin.eof()) {
        cin >> data;
        
        bool found = false;
        
        // Check to see if the data is in the deque
        deque< pair<int,int> >::iterator it;
        for (it = pgtble.begin(); it != pgtble.end(); it++) {
            
            // If it is in the deque, remove from its current location and place to top
            if (it->first == data) {
                pair<int,int> temp;
                temp = make_pair(data,(it->second)+1);
                
                pgtble.erase(it);
                
                pgtble.push_front(temp);
                found = true;
                break;
            }
        }
        
        // If not found report a page fault and place it in the front.
        if (!found) {
            cout << data << endl;
            
            // Check if page table exceeds "cacheSize" and remove least frequently used if it does.
            while (pgtble.size() >= cacheSize) {
                deque< pair<int,int> >::iterator it;
                deque< pair<int,int> >::iterator min;
                int minAppearances = 10000;
                
                for (it = pgtble.begin(); it != pgtble.end(); it++) {
                    if (it->second <= minAppearances) {
                        minAppearances = it->second;
                        min = it;
                    }
                }
                
                pgtble.erase(min);
            }
            
            pair<int,int> temp;
            temp = make_pair(data, 1);
            pgtble.push_front(temp);
        }
        
    }
    
    
    return 0;
}

