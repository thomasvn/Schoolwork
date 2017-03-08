// How could you simply modify the recursion in our version of quicksort to
// allow the proggram to switch to a simpler routine, say, insertion sort, for
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

int insertion_sort_happened = 0;

using namespace std;

int main()
{
    int test[CUTOFF];
    int i;
    for (i = 0; i < CUTOFF; i++) {
        test[i] = rand()%1000;
    }


    int N = sizeof(test)/sizeof(int);

    cout << "Size of test array : "  << N << endl;

    cout << "Before sorting: " << endl;
    print(test, N);
    cout << endl << endl;

    quickSort(test, 0, N-1);

    cout << endl << endl << "After sorting : " << endl;
    print(test, N);
    cout << endl;

    return 0;
}

void insertion_sort(int arr[], int first, int last) {
    // cout<<"checkpoint1"<<endl;
    int i, j ,tmp;
    for (i = first; i <= last; i++) {
        j = i;
        while (j > first && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
    print_array(arr,first,last);
}

void quickSort( int a[], int first, int last )
{

    int pivotElement;

    if(first < last && (last-first)>4)
    {
        pivotElement = pivot(a, first, last);

        cout<<"Pivot: " << pivotElement << endl;
        cout<<"Quicksort Left\n";
        quickSort(a, first, pivotElement-1);
        cout<<"Quicksort Right\n";
        quickSort(a, pivotElement+1, last);
        // if (insertion_sort_happened)
        //     return;
    }
    if ((last-first)<=4){
        insertion_sort(a,first,last);
    }

}


int pivot(int a[], int first, int last)
{
    //     cout<<"checkpoint2"<<endl;
    // cout<<endl<<"IN PIVOT: "<<"first: "<<first << "last"<<last<<endl;

        int  p = first;
        int pivotElement = a[first];

        for(int i = first+1 ; i <= last ; i++)
        {
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
}

void print_array(int array[], int first, int last){
        // cout<<"checkpoint4"<<endl;
        cout<<endl<<"IN INSERT PRINT: "<<"first: "<<first << "last"<<last<<endl;
    cout<< endl<<"----------------InsertionSort: -----------"<<endl;
    int j;
    for (j=first; j<=last;j++)
    cout <<" "<< array[j];
    cout <<endl<<"-----------------"<< endl;
}//end of print_array
