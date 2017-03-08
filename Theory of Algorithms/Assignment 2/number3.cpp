// How could you simply modify the recursion in our version of quicksort to
// allow the program to switch to a simpler routine, say, insertion sort, for
// subarrays of length below some cutoff value? Write such a program and
// experiment with the cutoff sizes 4, 8, and 16 for an array of 5000 randomly
// generated floats to see what the effect on the number of comparisons might be

#include <iostream>
#include <cstdlib>
#define CUTOFF 16

void insertion_sort(int arr[], int length);
void print_array(int array[],int first, int last);
void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);
void print(int array[], const int& N);
int counter = 0;
using namespace std;

int main()
{
    int test[5000];
    int i;
    for (i = 0; i < 5000; i++) {
        test[i] = rand()%10000;
    }
    int N = sizeof(test)/sizeof(int);
    cout << "Cut Off Length: " << CUTOFF << endl;

    quickSort(test, 0, N-1);

    cout <<"Number of Comparisons: " << counter << endl;
    return 0;
}

void insertion_sort(int arr[], int first, int last) {
    int i, j ,tmp;
    for (i = first; i <= last; i++) {
        j = i;
        while (j > first && arr[j - 1] > arr[j]) {
            counter++;
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void quickSort( int a[], int first, int last )
{
    int pivotElement;
    if(first < last && (last-first)>CUTOFF)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
    if ((last-first)<=CUTOFF){
        insertion_sort(a,first,last);
    }
}


int pivot(int a[], int first, int last)
{
        int  p = first;
        int pivotElement = a[first];

        for(int i = first+1 ; i <= last ; i++)
        {
            counter++;
            /* If you want to sort the list in the other order, change "<=" to ">" */
            if(a[i] <= pivotElement)
            {
                p++;
                swap(a[i], a[p]);
            }
        }
        swap(a[p], a[first]);
        return p;

}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapNoTemp(int& a, int& b)
{
    a -= b;
    b += a;// b gets the original value of a
    a = (b - a);// a gets the original value of b
}

void print(int a[], const int& N)
{
    for(int i = 0 ; i < N ; i++)
        cout <<  a[i] << " ";
    cout<< endl;
}
