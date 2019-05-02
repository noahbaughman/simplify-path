#include <iostream>

using namespace std;

int sumArray(int arr[], int length){
	if(length<=0){
		return 0;
	}
	return sumArray(arr, length-1) + arr[length-1];
}

int max(int a, int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int largest(int arr[], int length){
	if(length == 0){
		return 0;
	}
	return max(largest(arr, length-1), arr[length-1]);

}

int main(){
	int arr[] = {12, 15, 2, 1};
	int sum = sumArray(arr, sizeof(arr)/sizeof(arr[0]));
	cout << sum  << endl;

	int large = largest(arr, sizeof(arr)/sizeof(arr[0]));
	cout << large << endl;


	return 0;
}