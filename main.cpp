#include<iostream>

using namespace std;
void swap(int first, int second, int array[])
{
    cout << "we'll now swap " << array[first] << " with " << array[second] << endl;
    int third = array[first];
    array[first] = array[second];
    array[second] = third;
}


int findLargestNumIndex(int array[], int size, bool ascending)
{
      int index = 0;


     if(ascending == true) {
         cout << "the size is " <<  size << endl;
         int largest = array[0];

         for (int x = 1; x < size; x++) {

             if (largest < array[x]) {
                 largest = array[x];
                 index = x;
             }
         }
     }
     else if(ascending == false)
     {
         //wot?
         cout << "the size is " <<  size << endl;
         int largest = array[size - 1];
         cout << "initial largest" << largest << endl;
         //cout << "this loop was run" << endl;
         for (int x = size - 2; x > 0; x--) {

             if (largest < array[x]) {
                 largest = array[x];
                 index = x;
                 //cout << "largest is " << largest << endl;
             }
         }
     }

    return index;
}

void selectionSort (int array[], int ascending, int size)
{
    int len = size;
    if(ascending == true) {

        for (int x = len; x > 1; x--) {

            int biggest = findLargestNumIndex(array, x, ascending);
            swap(biggest, x - 1, array);
        }
    }else
    {
        for (int x = 0; x <= len-1; x++) {
            int biggest = findLargestNumIndex(array, x, ascending);
            swap(biggest, x, array);
        }
    }

    for(int i = 0; i < len; i++)cout << array[i] << endl;
};

void bubbleSort (int array[], int size)
{
    bool sorted = false;

    int pass = 1;
    while(!sorted && (pass < size - 1))
    {
        sorted = true;
        for(int i = 0; i < size - pass; i++)
        {
            int nextIndex = i + 1;
            if( array[i] > array[nextIndex])
            {
                sorted = false;
                swap(i , nextIndex, array);
            }
        }

        pass++;
    }

    for(int j = 0; j < size; j++)cout << array[j] << endl;
}

void insertionSort(int array[], bool ascending, int size)
{
    for(int unsorted = 1; unsorted < size-1 ; unsorted++)
    {
        int nextItem = array[unsorted];
        int loc = unsorted;
        while(loc > 0 && array[loc - 1] > nextItem)
        {
            array[loc] = array[loc - 1] ;
            loc--;
        }
        array[loc] = nextItem;

    }

    for(int i = 0; i < size ; i ++)cout << array[i] << endl;
}

void mergeSort(int array[], bool ascending, int size)
{
    if(size != 1)
    {
        int firstHalf = size/2;
        int secondHalf = size - firstHalf;

        int a1[firstHalf] ={};
        for (int i = 0; i < firstHalf; i++) a1[i] = array[i];

        cout << "first half is" << endl;
        for(int m = 0; m < firstHalf; m++)cout << a1[m] << endl;

        int a2[secondHalf] = {};
        for (int j = firstHalf; j < size; j++) a2[j] = array[j];

        cout << "secondHalf is " << endl;
        for(int l = firstHalf; l < size; l++)cout << a2[l] << endl;
        cout << "we will now merge a1 with size" << firstHalf << endl;
        mergeSort(a1, ascending, firstHalf );
        //mergeSort(a2, ascending, secondHalf);
    }
}
/*inertionSort(Array)
        {
                // unsorted = first index of the unsorted region,
                for unsorted = 1 to n - 1
                {
                    // Find the right position for the nextItem in
                    // Array[0..unsorted]
                    // At the same time shifting to make a room
                    nextItem = Array[unsorted];
                    loc = unsorted;
                    while ((loc > 0) && (Array[loc - 1] > nextItem))
                    {
                        // Shift Array[loc - 1] to the right
                        Array[loc] = Array[loc - 1];
                    } // end while
                    // Insert nextItem into sorted region
                    Array[loc] = nextItem;
                    loc--;
                }// end for
        } // end insertionSort*/
int main (){



    int array[] = {6,1,5,2,4,14};
    int len = sizeof(array)/sizeof(array[0]);

    //cout << "size is " << len << endl;
    /*cout << "Hello, please choose the desired sort method" << endl
         << "1.selection sort"  << endl
         << "2.bubble sort" << endl
         << "3.merge sort" << endl
         << "4.insertion sort" << endl
         << "quicksort" << endl;*/

    cout << "Ascending or descending?" << endl
         << "1.Ascending" << endl
         << "2.Descending" << endl;

    int choice;
    cin >> choice;

    bool order = false;

    switch (choice) {
        case 1:
            order = true;
            break;
        case 2:
            order = false;
            break;
        default:
            break;
    }

    //insertionSort(array,order,len);
    mergeSort(array,order,len);
    //selectionSort(array,order,len);

    //bubbleSort(array, len);

    //cout << "biggest is" << array[biggest] << endl;
    return 0;
}