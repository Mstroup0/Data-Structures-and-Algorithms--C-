//Mackenzie Stroup
//File: stl.cpp
//date: 1/29/2020

//Libraries
#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

//Method
	void Initialize( vector<int> &i);
	void Print (vector<int> i);
	void Reverse(vector<int>& i);


int main()
{
//Stacks
	stack<string> s1, s2;

	s1.push("Hi");	
	s2.push("Love");
	
	cout<<"compare stacks strings" << endl ;

//Compares stack 1 and stack two
	if((s1.top()).compare((s2.top())) == 0 )
	{
		cout<<"s1 == s2";	
	}
	else if((s1.top()).compare((s2.top()))<0)
	{
		cout<<"s1 < s2";
	}
	else if((s1.top()).compare((s2.top()))>0)
	{
		cout<< "s1 > s2";
	}
	cout<< endl;	
//Vector
	vector<int> v;

//initializes the vector and prints
	cout << "initializes and prints" << endl;	
	Initialize(v);	
	Print(v);
	
//Reverse the objects in the vector and prints
	cout<< "reverses and prints" << endl; 
	Reverse(v);	
	Print(v);

//Sorts vector and prints
	cout<< "sorts and prints"<< endl;
	sort(v.begin(), v.end());
	Print(v);

	return 0;
}

void Initialize( vector<int>& i)
{
	int arr[5];
	cout << "input 5 values"<< endl;	
	for(int k=0; k<5; k++)
	{
		cin >> arr[k];
		i.push_back(arr[k]);
	}

}

void Print (vector<int> i)
{
	for(int k=0; k < i.size(); k++)
	{
		cout << i[k] << " ";
	}
	cout<< endl;

}

void Reverse(vector<int>& i)
{
	
	std::reverse(i.begin(), i.end());// ask if this is fine. 


}
