#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
using namespace std; 

#include "stack.h" 


//Operator functions
int add(int num1, int num2);
int sub(int num1, int num2);
int mult(int num1, int num2);
int divid(int num1, int num2);
int remain(int num1, int num2);

//Other Functions
void menu(Stack <int> &dc, string &op);
void input(Stack<int> &dc, string &op);
void task(Stack<int>&dc, string &op);

//Printing
void print(Stack<int> &dc); // all items in the stack
void printTop(Stack<int> &dc);
void printPop(Stack<int> &dc);

//Main Functions
void clear(Stack<int> &dc);
void reverse(Stack<int> &dc);
void addingPop(Stack<int> &dc);
void subPop(Stack<int> &dc);
void multPop(Stack<int> &dc);
void divPop(Stack<int> &dc);
void remainPop(Stack<int> &dc);
void dubPop(Stack<int> &dc);

int main()
{
	Stack<int> dc;
	string op;
	menu(dc, op); 	
	return 0; 
}

//Menu 
void menu(Stack<int> &dc, string &op)
{
	int k =0;
	int p;
	input(dc, op);
     while(std:: cin)
     {
	task(dc,op);
	input(dc, op);		


      }

} 
// Tasks
// Preforms the task like adding, substracting, reversing the top two values and so on. 
 void task(Stack<int> &dc, string &op)
{
 	int a;  
	for(int i = 0; i < op.length(); i++)
        {
               if(op[i] == 'p' || op[i] == 'P')// prints top
                {
                        printTop(dc);
                }
                else if(op[i] == 'f' || op[i] == 'F')// prints whole stack
                {
                        print(dc);
                }
              else if(op[i] == 'n' || op[i] == 'N') // prints top and pops
                {
                        printPop(dc);
                }
                else if(op[i] == 'c' || op[i] == 'c')//Clears
                {
                        clear(dc);
                 }
                else if(op[i] == 'd' || op[i] == 'D')// duplicates value
                {
                        dubPop(dc);
                }
                else if(op[i] == 'r' || op[i] == 'R')// reveres stack
                {
                        reverse(dc);
                }
                else if(op[i] == '+')// adds
                {
                        addingPop(dc);
                }
                else if(op[i] == '-')// sub
                {
                        subPop(dc);

                }
                else if(op[i] == '*')// multiplcation
                {
                        multPop(dc);
                }
                else if(op[i] == '/')// division
                {
                        divPop(dc);
                }
		else if(op[i] == '%')// Finding the remained
                {
                        remainPop(dc);
                }
		else if(!isspace(op[i]))
		{
			cout<< " Unknown task inputted, input 1 for a new input or 0 to perform the tasks following the unkown task "<< endl; 
			cin >> a;
			if(a==1)
				break;
		}
        }
	op = ' ';
 		

}

//print the whole stack of value
void print(Stack<int> &dc)
{
	try{
	int i =0;
	Stack<int> cp = dc;
	while(!cp.isEmpty())
	{
		cout <<cp.top() << " " ;
		cp.pop();	
	}
	cout << endl;
	 }
      catch(Underflow obj)
      {
	cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. "<< endl;

      }

}

// Print top value
void printTop(Stack<int> &dc)
{
	try{
	cout << dc.top() << endl ;
	 }
      catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }

}

//Print top and pop
void printPop(Stack<int> &dc)
{
	try{
	cout<< dc.top();
	dc.pop();
	 }
      catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }

}


//input vaules
void input(Stack<int> &dc, string &op)
{
	string in;	
	getline(cin, in); 
	string myNum;
	int num, k;
 
  try{ // catches for overflow of the stack 
	for(int i =0; i< in.length() ; i++)
	{
		// if the value input needs to be negative. 
		if(in[i] == '_')
		{
			myNum= in[i+1];
			num = -1 * (atoi(myNum.c_str()));
			dc.push(num);
			i++;
		}
		//otherwise
		else{
			// if location is a digit
			if(isdigit(in[i]))
			{	//if task come right before a digit
				if(!isdigit(in[i-1]) && !isspace(in[i-1]))
                                {
                                        task(dc, op);
					
                                }

				// if there is not a digit following the current loaction
				if(!isdigit(in[i+1]))
				{
					myNum = in[i];
					num = atoi(myNum.c_str());
					dc.push(num);
				}
				//if a digit follows the current location
				else
				{ 
					  k =i;
  					 while( isdigit(in[k+1]))
       					 {
                				k++;
        				}
					myNum = in.substr(i , (k+1));
        				num = atoi(myNum.c_str());
        				dc.push(num);
					i = k;
				}
					

			}
			// otherwise
			else if(!isspace(in[i]))	
			{
				myNum = in[i];
				op += myNum;			
			}	
		}	
	}
      }
      catch( Overflow obj)
      {
	cout<< "Exception -- The stack for the values is full, preforma task!" ; 		
      }


}

//Clear
void clear(Stack<int> &dc)
{
	dc.makeEmpty();

}

//Reverse
void reverse(Stack<int> &dc)
{
	try{	
	int temp1, temp2;
	temp1 = dc.top();
	dc.pop();
	temp2 = dc.top();
	dc.pop();

	dc.push(temp1);
	dc.push(temp2);	
	 }
      catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }
      catch( Overflow obj)
      {
        cout<< "Exception -- The stack for the values is full, preforma task!" ;
      }

	
}

//dublicate
void dubPop(Stack<int> &dc)
{
	try{
	int in;
	in = dc.top();
	dc.push(in);
	 }
      catch(Overflow obj)
      {
        cout<< "Exception -- Your stack is Full, and try preforming a task. ";

      }

}

//Adds the top two
void addingPop(Stack<int> &dc)
{
	try{
	int num1 = dc.top();
	dc.pop();
	int num2 = dc.top();	
	dc.pop();

	int in = add(num1, num2);
	dc.push(in);
	}
	     catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }
	catch( Overflow obj)
      {
        cout<< "Exception -- The stack for the values is full, preforma task!" ;
      }


	
}

int add(int num1, int num2)
{
	return num1 + num2;	
}



//Substract
void subPop(Stack<int> &dc)
{
	try{	
	int num1, num2;
	num1 = dc.top();
	dc.pop();
	num2 = dc.top();
	dc.pop();	

	int subt = sub(num1, num2);	
	dc.push(subt);
	}
	 catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }
	catch(Overflow obj)
      {
        cout<< "Exception -- Your stack is Full, and try performing a task 1st ";

      }


}

int sub(int num1, int num2)
{

	return num2 - num1;

}

//Multiples
void multPop(Stack<int> &dc)
{
	try{
	int num1, num2;
	num1 = dc.top();
	dc.pop();
	num2 = dc.top();
	dc.pop();
	
	int multi = mult(num1, num2);
	dc.push(multi);
   	}
	catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }
	catch( Overflow obj)
      {
        cout<< "Exception -- The stack for the values is full, preforma task!" ;
      }
	

}

int mult(int num1, int num2)
{
	return num1 * num2;
}



//Division 
void divPop(Stack<int> &dc)
{
	try{
	int num1, num2;
	num1 = dc.top();
	dc.pop();
	num2 = dc.top();
	dc.pop();	

		if (num1 == 0)
			throw DivisionByZero();
		int div = divid(num1, num2);
		dc.push(div);
	}
	catch(DivisionByZero exc)
	{
		cout<< "Division by zero is not allowed--Re-enter input."<< endl;
	}
	     catch(Underflow obj)
      {
        cout<< "Exception -- Your stack is Empty, and you are trying to preform a task. ";

      }
	catch( Overflow obj)
      {
        cout<< "Exception -- The stack for the values is full, preforma task!" ;
      }

}

int divid(int num1, int num2)
{
	return num2/ num1;
}


//Remainder
void remainPop(Stack<int> &dc)
{
	try{
	int num1, num2;
        num1 = dc.top();
        dc.pop();
        num2 = dc.top();
        dc.pop();


                if (num1 == 0)
                        throw DivisionByZero();
                int rem = remain(num1, num2);
		dc.push(rem);
        }
        catch(DivisionByZero exc)
        {
                cout<< "Division by zero is not allowed--Re-enter input."<< endl;
        }
	catch(Underflow obj)
	{
		cout << "Exception -- The stack is empty, try inputing values 1st"<< endl;		
	}
	catch( Overflow obj)
      {
        cout<< "Exception -- The stack for the values is full, preforma task!" ;
      }


}

int remain(int num1, int num2)
{
	return num2 % num1;
} 


