/**
 * @file proj3.cpp
 * \mainpage
 *
 * CISC 2200, Data Structures<br>
 * Project 3: Recognizing Infix Arithmetic Expressions<p>
 *
 * This code executes functions from infix to prefix by using two stacks of values and operators.
 *
 * @author Noah Baughman
 * @date   11/11/2018
 */

/*
 * includes
 */
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;

/**
 * The type of data in the ValueType defined data structures is int.
 */
using ValueType = int;

/**
 * @class IllegalExprException
 * Exception class thrown by illegal infix expression
 */
class IllegalExprException : public runtime_error
{
    // your code should go here
    // you only need the constructor
    // don't forget to document it
};

/*
 * function prototypes, with doxygen docs
 */

/**
 * Determine the value of an infix expression
 *
 * @param expr a string, supposedly representing an infix expression
 * @return the value of <code>expr</code>
 * @throw IllegalExprException if <code>expr</code> is not a legal infix
 * expression 
 * @throw ZeroDivideException if <code>expr</code> involves a division
 * by zero
 */
ValueType processExpression(const string& expr) throw (IllegalExprException);

/**
 * Determines if response asking for help is valid expression and asks again for help if not.
 *
 * @param response a char, representing whether or not they need help
 * @return bool whether response is valid.
 */
bool isValidResponse(char response);

/**
 * Determines if response asking for help Yes or No.
 *
 * @param response a char, representing whether or not they need help
 * @return bool whether reesponse is yes or no.
 */
bool isYesResponse(char response);

/**
 * Determines the precendence of different operator characters
 *
 * @param op a char, representing a operator such as +,-,*,/
 * @return int, the number represents the preeceendence of operator where the larger the int the higher the precedence.
 */
int precedence(char op);

/**
 * Asks if the user needs help
 */
bool provideHelpIfNecessary();

/**
 * executes the expression by collecting the integers and opeerations for the result
 *
 * @param valStack, stack with the values in the expression
 * @param opStack, stack with the operators in expression
 */
void execute(stack<ValueType>& vals, stack<char>& ops) 
    throw (IllegalExprException);

/**
 * Actually executes operation based on operator.
 *
 * @param operand1, valuetypee defined as int, the integer in expression
 * @param operand2, valuetypee defined as int, the integer in expression
 * @param operation, char, the character of the opeerator
 * @return Valuetype, int, the result of operation
 */
ValueType doOperation(ValueType operand1, char operation, ValueType operand2)
    throw (IllegalExprException);

/**
 * The usual main function
 */
int main(void)
{
    bool h = provideHelpIfNecessary();


    while(h){
    cout << "Expression? " ; 
    string expr;                  // holds the supposed expression
    getline(cin, expr);
    if (expr.length() == 0)
        break;
    try {
        ValueType result = processExpression(expr);
        cout << result << endl;
    } catch (exception& ex) {
        cerr << ex.what() << endl;
    }
    } // end while
    cout << endl;
} // end main

bool provideHelpIfNecessary()
{
    cout << "Do you need help (Y/N)? ";
    char help;
    cin >> help;
    cin.ignore();
    return isValidResponse(help);
} // end provideHelpIfNecessary

ValueType processExpression(const string& expr) throw (IllegalExprException)
{
    stack<ValueType> vals;
    stack<char> ops;
    for(int i=0; i < expr.length(); i++){ 
        if(expr[i] == ' ') 
            continue; 

        else if(isdigit(expr[i])){ 
            ValueType a = expr[i] - '0';
            vals.push(a);
        }           
 
        else if(expr[i] == '('){ 
            ops.push(expr[i]); 
        } 


        else if(expr[i] == ')') 
        { 
            while(ops.top() != '(') 
            { 
                int val2 = vals.top(); 
                vals.pop(); 
                
                int val1 = vals.top(); 
                vals.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                vals.push(doOperation(val1, op, val2)); 
            }   
            ops.pop(); 
        } 
        else{ 
            if(ops.empty())
                ops.push(expr[i]);
            else if(precedence(expr[i]) > precedence(ops.top()))
                ops.push(expr[i]);
            else{
                while(!ops.empty() && (precedence(expr[i]) <= precedence(ops.top()))){
                    int val2 = vals.top(); 
                    vals.pop(); 
                    
                    int val1 = vals.top(); 
                    vals.pop(); 
                      
                    char op = ops.top(); 
                    ops.pop(); 
                      
                    vals.push(doOperation(val1, op, val2));                     
                }
                ops.push(expr[i]);
            }
        } 
    }
        
   
    execute(vals, ops);

    return vals.top();
} // end processExpression

bool isValidResponse(char response)
{
    char res = response;
    if(res != 'Y' && res != 'N'){
        cout << "Response must be 'Y' or 'N'." << endl;
        provideHelpIfNecessary();
    }
    return isYesResponse(res);
} // end isValidResponse

bool isYesResponse(char response)
{
    if(response == 'Y'){
        return true;
    }

    return false;
} // end isYesResponse

int precedence(char op)
{
    if ( op == '+' || op == '-'){
        return 1;
    }
    if (op == '*' || op == '/'){
        return 2;
    }
    return 0;
} // end precedence

void execute(stack<ValueType>& vals, stack<char>& ops)
    throw (IllegalExprException)
{
    while(!ops.empty()){
        int operand2 = vals.top();
        vals.pop();
        int operand1 = vals.top();
        vals.pop();
        char op = ops.top();
        ops.pop();
        vals.push(doOperation(operand1, op, operand2));
    }
} // end execute

ValueType doOperation(ValueType operand1, char operation, ValueType operand2)
    throw (IllegalExprException)
{
    int result;
    if(operation == '+'){
        result = operand1 + operand2;
    }
    else if (operation == '-'){
        result = operand1 - operand2;
    }
    else if( operation == '*'){
        result = operand1 * operand2;
    }
    else if(operation == '/'){
        result = operand1/operand2;
    }

    return result;
} // end doOperation