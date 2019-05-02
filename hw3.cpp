/**
 * CISC 2200: Data Structures
 * HW3: Questions 1, 2, 4, 5
 *
 * This program has functions for questions 1, 2, 4, and 5 of hw3 and implements each one in the main function. 
 *
 * @author Noah Baughman
 * @date 11/9/2018
 * @file hw3.cpp
**********************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <sstream> 
#include <algorithm>

using namespace std;

/**
 *	This functions tests two strings including (){}[], and tests whether the
 *	string is valid by using stacks.
 *
 *	@param string str, the string of brackets
 *	@return whether the string is valid or not
*/
bool isValid(string str){
	int size = str.length();
	stack<char> p;
	for(int i=0; i < size; i++){
		char cha = str.at(i);
		p.push(cha);
	}

	while(p.size() != 0){
		char ch = p.top();
		if( ch == ')'){
			p.pop();
			ch = p.top();
			if(ch != '('){
				return false;
			}
		p.pop();
		}
		if( ch == ']'){
			p.pop();
			ch = p.top();
			if(ch != '['){
				return false;
			}
		p.pop();
		}
		if( ch == '}'){
			p.pop();
			ch = p.top();
			if(ch != '{'){
				return false;
			}
		p.pop();
		}
	
	}	
	return true;
}


/**
 *	This function tests whether two strings that include backspaces are equal using stacks. 
 *
 *	@param string str1, the first string
 *  @param string str2, the second string
 *	@return whether the strings are equal 
*/
bool inputMatch(string str1, string str2){
	int size1 = str1.length();
	int size2 = str2.length();

	stack<char> a;
	stack<char> b;

	for(int i=0; i < size1; i++){
		char ch1 = str1.at(i);
		if(ch1 != '<'){
			a.push(ch1);
		}
		else{
			a.pop();
		}
	}
	for(int i=0; i < size2; i++){
		char ch2 = str2.at(i);
		if(ch2 != '<'){
			b.push(ch2);
		}
		else{
			b.pop();
		}
	}

	if(a == b){
		return true;
	}
	else{
		return false;
	}
}


/**
 *	This string simplifies a unix path while using stack and string stream
 *
 *	@param string path, the original unix path
 *	@return the simplified unix path
*/
string simplifyPath(string path) {
    stack<string> dir;
    string res = "", val;
    istringstream ss(path);
    while(getline(ss, val, '/')){
        if(val.size() == 0 || val == ".")
            continue;
        if(val == "..") {
            if(!dir.empty())
                dir.pop();
        } 
        else{
            dir.push(val);
        }
    }
        
    if(dir.empty())
        return "/";
        
    while(!dir.empty()){
        res = "/" + dir.top() + res;
        dir.pop();
        }
    return res;
}


/**
*	This function prints the elements of a given integer array.
*
*	@param int arr[], an array of integers
*	@param int size, the size of the given array
*/
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
    cout << arr[i] << " "; 
	}
	cout << endl;
}


/**
*	This function sorts an array in wave form where arr[0] <= arr[1] >= arr[2] <= arr[3]....
*
*	@param int arr[], an array of integers
*	@param int size, the size of the given array
*/
void waveSort(int arr[], int size){
	bool flag = true;
	for(int i=0; i<=size-2; i++){
		if(flag){
			if (arr[i] > arr[i+1])
				swap(arr[i], arr[i+1]);
		}
		else{
			if (arr[i] < arr[i+1]) 
                swap(arr[i], arr[i+1]);
		}
		flag = !flag;
	}
		

}

/**
* The usual main function with test cases and displays results for each function 
*/
int main(){
// Implementation of isValid() function
	string valid = "(){}[]";
	string valid1 = "))[]";
	string valid2 = "{]()";
	bool val = isValid(valid);
	cout << "The following string " << valid << " is" << endl;
	if( val == true){
		cout << "valid" << endl;
	}
	else{
		cout << "invalid" << endl;
	}
	bool val1 = isValid(valid1);
	cout << "The following string " << valid1 << " is:" << endl;
	if( val1 == true){
		cout << "valid" << endl;
	}
	else{
		cout << "invalid" << endl;
	}

// Implementation of inputMatch() function
	string one = "a<bc";
	string two = "abc<";
	string three = "abcde<<";
	string four = "abcd<e<";
	bool equal = inputMatch(one, two);
	cout << "\nThe input streams " << one << " and " << two << " are:" << endl;
	if(equal == true){
		cout << "equal" << endl;
	}
	else{
		cout << "not equal" << endl;
	}
	bool equal1 = inputMatch(three, four);
	cout << "The input streams " << three << " and " << four << " are:" << endl;
	if(equal1 == true){
		cout << "equal" << endl;
	}
	else{
		cout << "not equal" << endl;
	}

//Implementation of simplifyPath() function
	string str = "/a/./b/../../c/";
    string result = simplifyPath(str);
    cout << "\nThe Unix path " << str << " simplified is: " << result << endl;

// Implementation of waveSort() function
	int arr[] = {3, 5, 2, 1, 6, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "\nThe array ";
	printArray(arr,size);
	cout << "sorted in wave form is: ";
	waveSort(arr, size);
	printArray(arr, size);


	return 0;
}