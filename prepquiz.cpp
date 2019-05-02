#include <iostream>
#include <string>

using namespace std;


int sum_of_digit(int n) { 
    if (n == 0) 
       return 0; 
    return (n % 10 + sum_of_digit(n / 10)); 
} 

int sumOfArray(int arr[], int n){
    if(n <= 0){
        return 0;
    }
    return sumOfArray(arr, n-1) + arr[n-1];
}

void printArray(int arr1[], int n){
    for (int i = 0; i < n; i++){
    cout << arr1[i] << " "; 
    }
}

int maxOfArray(int arr[], int length){
    if(length == 1){
        return 0;
    }
    return max(maxOfArray(arr, length -1), arr[length-1]);
}

int max(int a, int b){
    if( a < b){
        return a;
    }
    else{
        return b;
    }
}

bool stringPal(string word, int a, int b){
    if(a == b){
        return true;
    }
    char ch1 = word.at(a);
    char ch2 = word.at(b);
    if(ch1 != ch2){
        return false;
    }
    if(a < b+1){
        return stringPal(word, a+1, b-1);
    }
    return true;
}


  
// Driven Program to check above 
int main() { 
    int num = 12345; 
    int result = sum_of_digit(num); 
    cout << "\nThe sum of the digits of the number " << num
         << " is " << result << endl;

    int arr[] = {1, 3, 4, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = sumOfArray(arr,n);
    cout << "\nThe sum of the elements in the array: "; 
    printArray(arr, n);
    cout << " is " << sum << endl;

    int maxi = maxOfArray(arr,n);
    cout << "\nThe largest value in the array: ";
    printArray(arr, n);
    cout << " is " << maxi << endl;

    string word;
    cout << "Enter word: " << endl;
    cin >> word;

    int length = word.length();
    bool pal = stringPal(word, 0, length-1);
    if(pal == true){
        cout << "\nThis word is a palindrome." << endl;
    }
    else{
        cout << "\nWord is not a palindrome." << endl;
    }




    
    return 0; 
};