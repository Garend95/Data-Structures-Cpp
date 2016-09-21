#include<iostream>

using namespace std;
void swap(int first, int second, int array[])
{
    int third = array[first];
    array[first] = array[second];
    array[second] = third;
}


int findLargestNumIndex(int array[], int size, bool ascending)
{
      int index = 0;

     if(ascending == true) {
         int largest = array[0];

         for (int x = 1; x < size; x++) {

             if (largest < array[x]) {
                 largest = array[x];
                 index = x;
             }
         }
     }
     else
     {
         int largest = array[size - 1];
         cout << "this loop was run" << endl;
         for (int x = size - 2; x > 0; x--) {

             if (largest < array[x]) {
                 largest = array[x];
                 index = x;
             }
         }
     }

    return index;
}

void selectionSort (int array[], int ascending, int size)
{
    int len = size;
    cout << "size is " << len << endl;
    if(ascending == true) {

        for (int x = len; x >= 1; x--) {

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

    bool formation = false;

    switch (choice) {
        case 1:
            formation = true;
            break;
        case 2:
            formation = false;
            break;
        default:
            break;
    }

    selectionSort(array,formation,len);



    //cout << "biggest is" << array[biggest] << endl;
    return 0;
}