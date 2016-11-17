//
//  lru.cpp
//  Assignment 3
//
//  Created by Thomas Nguyen on 11/9/16.
//  Copyright © 2016 Thomas Nguyen. All rights reserved.
//

#include <iostream>
#include <deque>
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
    
    
    // Initialize Page Table to size "cacheSize" filled with zeros
    deque<int> pgtble;
    
    
    // File placed into standard input
    int data;
    while (!cin.eof()) {
        cin >> data;
        
        bool found = false;
        
        // Check to see if the data is in the deque
        deque<int>::iterator it;
        for (it = pgtble.begin(); it != pgtble.end(); it++) {
            if (*it == data) {
                // If it is in the deque, remove from its current location and place to top
                pgtble.erase(it);
                pgtble.push_front(data);
                found = true;
                break;
            }
        }
        
        // If not found report a page fault and place it in the front.
        if (!found) {
            cout << data << endl;
            pgtble.push_front(data);
            
            // Check if page table exceeds "cacheSize" and remove from tail if it does.
            while (pgtble.size() > cacheSize) {
                pgtble.pop_back();
            }
        }
        
    }
    
    
    
    
    
    
    
    // Print out the pages that fault (Exactly that number ... nothing else)
    // Page Fault: Any time a number shows and it's not already in the page table
    
    
    // -------------------- Instructions --------------------
    // Three Algorithms
    // LRU (Last Recently Used)
    // LFU (Last Frequently Used)
    //      - Even if element is in the cache, move it to the front
    //      - Throws out number with the least uses in the cache
    // Second Chance (Clock Version)
    // Some fourth algorith besides FIFO
    //
    // 1. Read a Number
    // 2. Is that # in my cache?
    //      If yes: do nothing
    //      If no: Write out the # (Bc it's a page fault)
    // 3. Adjust your Cache (different parts in each algorithm)
    // 4. Explain why this language is worthwhile and what advantage does the algorithm bring
    
    
    // --------------- Counts.txt ---------------
    // LRU and LFU use number pairs (Input Size, Output Size)
    
    
    // -------------------- Output --------------------
    // 50 is the # of cached pages?
    // < represents a redirect to standard in
    // > represents a redirect to standard out
    // 2> represents a redirect to standard error
    // ./LRU 50 < numbers.txt > lru_out.txt; wc -l lru_out.txt
    // ./LFU 20 < numbers.txt | wc -l
    
    
    
    return 0;
}

