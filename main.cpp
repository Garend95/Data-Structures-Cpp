#include<iostream>
#include <cstring>

using namespace std;
void swap(int first, int second, int array[])
{
    //cout << "we'll now swap " << array[first] << " with " << array[second] << endl;
    int third = array[first];
    array[first] = array[second];
    array[second] = third;
}


int findLargestNumIndex(int array[], int size, bool ascending)
{
      int index = 0;

     //cout << "the size is " <<  size << endl;
     int largest = array[0];

     for (int x = 1; x < size; x++) {

         if (largest < array[x]) {
             largest = array[x];
             index = x;
         }
     }


    return index;
}

void selectionSort (int array[], bool ascending, int size)
{
    int len = size;


        for (int x = len; x > 1; x--) {

            int biggest = findLargestNumIndex(array, x, ascending);
            swap(biggest, x - 1, array);
        }

    //setting up descending with loop was confusing, this will obviously affect the algorithm efficiency
    if(!ascending)for(int q = 0, r = len-1; q < r; q++ , r--)
        {
            swap(q,r,array);
            cout << "this ran" << endl;
        }
    for(int i = 0; i < len; i++)cout << array[i] << endl;
};

void bubbleSort (int array[], bool ascending, int size)
{
    bool sorted = false;
    if(ascending){
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
    }else
    {
        int pass = 0;
        while(!sorted && (pass < size-1))
        {
            sorted = true;
            for(int i = size - 1; i > pass; i--)
            {
                int nextIndex = i - 1;
                if( array[i] > array[nextIndex])
                {
                    sorted = false;
                    swap(i , nextIndex, array);
                }
            }

            pass++;
        }
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

int* merge(int array1[], int array2[], int size1, int size2 )
{
    int pointer1 = 0;
    int pointer2 = 0;
    int tempArrayIndex = 0;
    int tempArray[size1+size2];


    while(size1 != 0 && size2 != 0)
    {
        if(array1[pointer1]  > array2[pointer2])
        {
            tempArray[tempArrayIndex] = array2[pointer2];
            tempArrayIndex++, pointer2++, size2--;

        }
        else
        {
            tempArray[tempArrayIndex] = array1[pointer1];
            tempArrayIndex++, pointer1++, size1--;
        }
    }
    while(size1 != 0)
    {
        tempArray[tempArrayIndex] = array1[pointer1];
        tempArrayIndex++, pointer1++, size1--;
    }
    while(size2 != 0)
    {
        tempArray[tempArrayIndex] = array2[pointer2];
        tempArrayIndex++, pointer2++, size2--;
    }
    return tempArray;
}
int* mergeSort(int array[], bool ascending, int size) {

    //for (int m = 3; m < 3+size; m++)cout << array[m] << " would be " << m << endl;
    if (size != 1) {
        int firstHalf = size / 2;
        //cout << "fhsize " << firstHalf << endl;

        int secondHalf = size - firstHalf;
        //cout << "shsize " << secondHalf << endl;

        int a1[firstHalf] = {};
        for (int i = 0; i < firstHalf; i++)a1[i] = array[i];

        //cout << "first half is" << endl;
        //for (int m = 0; m < firstHalf; m++)cout /*<< "when m is " << m << " a1 is " */<< a1[m] << endl;

        int a2[secondHalf] = {};
        for (int j = 0; j < secondHalf; j++) a2[j] = array[firstHalf + j];

        //cout << "secondHalf is " << endl;
        //for (int l = 0; l < secondHalf; l++)cout << "when m is " << l << " a2 is " << a2[l] << endl;
        //cout << "we will now merge a1 with size" << firstHalf << endl;
        mergeSort(a1, ascending, firstHalf);
        //cout << "we will now merge a2 with size" << secondHalf << endl;
        mergeSort(a2, ascending, secondHalf);
        return merge(a1,a2,firstHalf,secondHalf);
        }

    }

int main (){



    //int array[] = {6,1,5,2,4,14,9};
    int array[] = {1,2,3,4};
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
    //selectionSort(array,order,len);
    //mergeSort(array,order,len);
    //int result[len];
    //copy(begin(mergeSort(array,order,len)),end(mergeSort(array,order,len)), begin(result));
    //for(int n = 0; n < len; n++)cout << mergeSort(array,order,len) << endl;
    bubbleSort(array, order ,len);

    //cout << "biggest is" << array[biggest] << endl;
    return 0;
}