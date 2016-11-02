////
////  2a.cpp
////  Homework 1
////
////  Created by Thomas Nguyen on 9/27/16.
////  Copyright © 2016 Thomas Nguyen. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//// Credit to (http://www.geeksforgeeks.org/iterative-quick-sort/) for help on various functions
//// throughout this program
//
//
//// Swaps two integers passed into function
//void swap (int* a, int* b) {
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//
//
//// This function takes an array as well as the
//// l --> starting index
//// h --> ending index
//int partition (int arr[], int l, int h) {
//    // x is the pivot
//    int x = arr[h];
//    int i = (l - 1);
//    
//    for (int j = l; j < h; j++) {
//        if (arr[j] <= x) {
//            i++;
//            swap (&arr[i], &arr[j]);
//        }
//    }
//    
//    // Places the pivot where it needs to go
//    swap (&arr[i + 1], &arr[h]);
//    return (i + 1);
//}
//
//
///* A[] --> Array to be sorted,
// l  --> Starting index,
// h  --> Ending index */
//void quickSort(int A[], int l, int h) {
//    if (l < h) {
//        /* Partitioning index */
//        int p = partition(A, l, h);
//        quickSort(A, l, p - 1);
//        quickSort(A, p + 1, h);
//    }
//}
//
//
//// A utility function to print contents of arr
//void printArr( int arr[], int n ) {
//    for (int i = 0; i < n; i++)
//        printf( "%d ", arr[i] );
//}
//
//
//int main() {
//    int arr [] = {1,4,7,9,3,4,5};
//    int n = sizeof(arr) / sizeof(*arr);
//    quickSort(arr, 0, n-1);
//    
//    printArr(arr, 7);
//    
//    return 0;
//}
//
//
//
//
//
