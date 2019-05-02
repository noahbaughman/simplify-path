/** 
 * CISC 2200: Data Structures
 * Project 1: Computing Powers
 *
 * This program computes and displays a power function in 3 different ways
 * iterately, recursively, and by divide and conquer
 *
 * @author Noah Baughman
 * @date Oct 14, 2018
 * @file proj2.cc
 *
 **********************************************************************/

#include <iostream>
using namespace std;

// function prototypes

template <class T>
T power1(T x, unsigned int n, unsigned int& mults);

template <class T>
T power2(T x, unsigned int n, unsigned int& mults);

template <class T>
T power3(T x, unsigned int n, unsigned int& mults);

template <class T>
void printReport(T base, unsigned int pow, 
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2, 
                 unsigned int mults3);

/**
 * The usual main function.
 * 
 * It computes the powers 2<sup><em>i</em></sup> for
 * <em>i=</em>0,1,2,..,32 via all three methods, reporting the number
 * of multiplications needed for each method.  (Note what happens for
 * 2^32.)  It then does likewise for 0.5<sup><em>i</em></sup>, but now
 * with <em>i=</em>0,1,2,...64
 *
 */
int main()
{
   unsigned int mults1, mults2, mults3;
   cout << "Test for integer base:\n";
   for (unsigned int pow = 0; pow <= 32; pow++) {
      unsigned int base = 2;
      unsigned int result1 = power1(base, pow, mults1);
      unsigned int result2 = power2(base, pow, mults2);
      unsigned int result3 = power3(base, pow, mults3);      
      printReport(base, pow, result1, result2, result3, 
                  mults1, mults2, mults3);
   }
   cout << "\nTest for floating-point base:\n";
   for (unsigned int pow = 0; pow <= 64; pow++) {
      double base = 0.5;
      double result1 = power1(base, pow, mults1);
      double result2 = power2(base, pow, mults2);
      double result3 = power3(base, pow, mults3);      
      printReport(base, pow, result1, result2, result3, 
                  mults1, mults2, mults3);
   }
}

/**
 * Iterative function to compute the power x to the n.
 *
 * @param x, the base number 
 * @param n, the power to which the base is applied 
 * @param mults, the amount of multiplications used to solve the power function
 * @return The T which contains the base, power, reesult and number of multiplications
 */
template <class T>
T power1(T x, unsigned int n, unsigned int& mults){
    mults = 0;
    if(n==0){
      return 1;
    }
    if(n==1){
      return x;
    }
    else{
      T power = x;
      int i = 2;
      while(i<=n){
        power = power * x;
        mults++;
        i++;
      }
      return power;
    }
   return 1;
}

/**
 * Recursive function to compute the power x to the n.
 *
 * @param x, the base number 
 * @param n, the power to which the base is applied 
 * @param mults, the amount of multiplications used to solve the power function
 * @return The T which contains the base, power, reesult and number of multiplications
 */
template <class T>
T power2(T x, unsigned int n, unsigned int& mults)
{
    mults =0;
    if(n==0){
      return 1;
    }
    if(n==1){
      return x;
    }
    else{
      T power = x * power2(x, n-1, mults);
      mults++;
      return power;
      
    }
    return 1;
}

/**
 * Divide and conquer function to compute the power x to the n.
 *
 * @param x, the base number 
 * @param n, the power to which the base is applied 
 * @param mults, the amount of multiplications used to solve the power function
 * @return The T which contains the base, power, reesult and number of multiplications
 */
template <class T>
T power3(T x, unsigned int n, unsigned int& mults)
{
   
    mults = 0;
    if(n==0){
      return 1;
    }
    if(n==1){
      return x;
    }
    else{
      if(n % 2 == 0){
        T power = power3(x, n/2, mults);
        mults++;
        return power * power;
      }
      else{
        T power = power3(x, n/2, mults);
        mults += 2;
        return power * power * x;
      }
    }
   return 1;
}

/**
 * Report the results of three different exponentiation calculations.
 *
 * @param base, the base for power function
 * @param pow, the power to which base is raised
 * @param result1, the result of power function from interative method
 * @param result2, the result of power function from recursive method
 * @param result3, the result of power function from divide and conquer method
 * @param mults1, the number of multiplications done from iterative method
 * @param mults2, the number of multiplications done from reecursive method
 * @param mults3, the number of multiplications done from divide and conquer method
 */

template <class T>
void printReport(T base, unsigned int pow, 
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2, 
                 unsigned int mults3)
{
   cout << base << "^" << pow << " = ";
   if (result1 == result2 && result2 == result3)
      cout << result1 << ": ";
   else
      cout << "(" << result1 << ", " << result2 << ", " << result3 
           << ") [ERROR!]: ";
   cout << "mults1 = " << mults1 << ", mults2 = " << mults2
        << ", mults3 = " << mults3 << endl;
}