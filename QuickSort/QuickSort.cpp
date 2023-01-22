// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int partition(int* array, unsigned lowIndex, unsigned highIndex);
void quickSort(int* array, unsigned lowIndex, unsigned highIndex);
int main()
{
    int array[9] = {15,28,69,40,27,89,138,12,31};
    quickSort(array, 0, 8);
    for (int value:array) {
        cout << value << "\t";
    }
    cout << endl;
    return 0;
}

int partition(int* array, unsigned lowIndex, unsigned highIndex) {
    //1, choose pivot
    unsigned middlePoint = (lowIndex + highIndex) / 2;
    int pivot = array[middlePoint];
    while (1) {
        //2, increment the highIndex and decrement the lowIndex
        while (array[lowIndex] < pivot) {
            lowIndex++;
        }
        while (array[highIndex] > pivot) {
            highIndex--;
        }
        if (lowIndex >= highIndex) {
            return highIndex;
        }
        else {
            //3, swap the high and low index
            int temp = array[lowIndex];
            array[lowIndex] = array[highIndex];
            array[highIndex] = temp;
            lowIndex++;
            highIndex--;
        }
    }
}

void quickSort(int * array, unsigned lowIndex, unsigned highIndex) {
    if (lowIndex >= highIndex) {
        return;
    }
    unsigned lowEndIndex = partition(array, lowIndex, highIndex);
    quickSort(array, lowIndex, lowEndIndex);
    quickSort(array, lowEndIndex+1, highIndex);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
