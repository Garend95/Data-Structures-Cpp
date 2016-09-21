#include<iostream>

using namespace std;
void swap(int first, int second, int array[])
{
    int third = array[first];
    array[first] = array[second];
    array[second] = third;
}

int findLargestNumIndex(int array[], int size)
{
    int largest = array[0];
    int index = 0;


    for(int x = 1; x < size; x++)
    {
        if(largest < array[x]) {
            largest = array[x];
            index = x;
        }
    }

    return index;
}

int main (){

    cout << "hello" << endl;

    int array[] = {6,1,5,2,4,14};
    int len = sizeof(array)/sizeof(array[0]);
    //cout << "size is " << len << endl;
    for (int x = len ; x >= 1; x--)
        {
            int biggest = findLargestNumIndex(array , x);
            swap(biggest ,x-1 ,array);
        }

    for(int i = 0; i < len; i++)cout << array[i] << endl;


    //cout << "biggest is" << array[biggest] << endl;
    return 0;
}