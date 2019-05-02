
/*
 * CISC 2200: Data Structures
 * HW1: Questions 1 & 2
 *
 * This program rotates an array of size n by d elements by using reversal methods
 * And also contains a fuction all zeros to the end of an array 
 *
 * @author Noah Baughman
 * @date 10/2/18
 * @file hw1_array.cpp
*/

#include <iostream>

using namespace std;

/*
    This function pushes all the zeros in an array to the end of the array

    @param arr[] An array and n, the size of the array
 */
void pushZerosToEnd(int arr[], int n){
    int count = 0;  
 
  
    for (int i = 0; i < n; i++){
        if (arr[i] != 0){
            arr[count] = arr[i];
            count++; 
        }
    }
 
  
    while (count < n){
        arr[count++] = 0;
    }
}


 /*
     This function reverses an array or portion of an array

     @param arr[], an array, start, the index of the starting point of reversal, 
            and end, the ending index of reversal
 */
void reverseArray(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
 
/*
    This function rotates an array by d elements by reversing 2 portions of the array then the whole array

    @param arr[], an array, d, the numbers of elements to be rotated, n , the size of the array
*/
void rotate(int arr[], int d, int n){
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}
 
/*
    This fuction prints the rotated array

    @param arr[], the rotated array, size, size of array
*/
void printArray(int arr[], int size){
    cout<< "Rotated array \n";
    for (int i = 0; i < size; i++){
    cout << arr[i] << " "; 
	}

}
 

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int d = 2;
     
    
    rotate(arr1, d, n);
    printArray(arr1, n);

    int arr2[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    pushZerosToEnd(arr2, m);
    cout << "\nArray after pushing all zeros to end of array \n";
    for (int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }
    
     
    return 0;
}
