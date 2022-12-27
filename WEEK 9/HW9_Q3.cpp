#include <iostream>
using namespace std;

void printArray(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int newArrSize = 0; // outgoing array size container
    int* temp = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0) {   // if positive
            temp[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    outPosArrSize = newArrSize; // Updating via call-by-reference
    return temp; // returns the base address of the +num array
}
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int newArrSize = 0;
    int* temp = new int[arrSize];
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            temp[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    *outPosArrSizePtr = newArrSize; // Updating via pointer
    return temp; // returns the base addr of the +num array
}
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int newArrSize = 0;
    int* temp = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            temp[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    outPosArr = temp; // updating the pointer via call-by-ref
    outPosArrSize = newArrSize; // updating the size via call-by-ref
}
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int newArrSize = 0;
    int* temp = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            temp[newArrSize] = arr[i];
            newArrSize++;
        }
    }
    *outPosArrPtr = temp; // updating via pointer pointing to the base addr
    *outPosArrSizePtr = newArrSize; //updating via pointer
}


typedef int* IntPtr;

int main(){
    const int arrSize = 6;
    int arr[arrSize] = { 3,-3, -1, 0, 6, 4 };

    cout << "Original Array: \n";
    printArray(arr, arrSize);
    cout << endl;

    //====================================================
    cout << "A) getPosNums1\n";
    int arrOneSize = 0;

    int* arrOne = getPosNums1(arr, arrSize, arrOneSize);
    printArray(arrOne, arrOneSize);
    delete[] arrOne;
    arrOne = NULL;
    cout << endl;
    
    
    //====================================================
    cout << "B) getPosNums2\n";
    int arrTwoSize = 0;

    int* arrTwo = getPosNums2(arr, arrSize, &arrTwoSize);
    printArray(arrTwo, arrTwoSize);
    delete[] arrTwo;
    arrTwo = NULL;
    cout << endl;
    
    
    //====================================================
    cout << "C) getPosNums3\n";
    int newSizeThree = 0;
    int* arrThreeSizePtr = &newSizeThree;
    int* arrThree = new int[arrSize];

    getPosNums3(arr, arrSize, arrThree, *arrThreeSizePtr);
    printArray(arrThree, newSizeThree);
    delete[] arrThree;
    arrThree = NULL;
    cout << endl;

    //====================================================
    cout << "D) getPosNums4\n";
    int newSizeFour = 0;
    int* newSizeFourPtr = &newSizeFour;
    int* arrFour = new int[arrSize];
    int** arrFourPtr = &arrFour;    // arrFourPtr points to arrFour which points to the addr of the base array

    getPosNums4(arr, arrSize, arrFourPtr, newSizeFourPtr);
    printArray(*arrFourPtr, newSizeFour);
    delete[] arrFour;
    arrFour = NULL;

    return 0;
}
