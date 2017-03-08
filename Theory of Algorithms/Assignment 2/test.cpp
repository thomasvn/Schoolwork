#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int pivot(int a[], int first, int last)
{
        int  p = first;
        int pivotElement = a[first];

        for(int i = first+1 ; i <= last ; i++)
        {
            // counter++;
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

void quickSort( int a[], int first, int last )
{
    int pivotElement;
    if(first < last)
    {
        pivotElement = pivot(a, first, last);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}


int main() {
    int test[] = {4,7,1,12,14,3,99};

    quickSort(test, 0, 6);
}
