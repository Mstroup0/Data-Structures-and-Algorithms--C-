#include <queue>
#include <iostream>
using namespace std;

void insertNames(priority_queue<string> & b);
void Print(priority_queue<string> & b);

int main()
{
	priority_queue<string> pq;	
	cout<< "Inserts 10 names: " << endl;
	insertNames(pq);	

	cout << "List of Names:" << endl;
	Print(pq);
	
return 0; 
}

void insertNames(priority_queue<string> &b)
{
	string c;
	for(int i = 0; i < 10; i++)
	{
		getline(cin, c);
		b.push(c);
	} 	

}

void Print(priority_queue<string> &b)
{
	while(! b.empty())
	{
		cout<< b.top()<< endl;
		b.pop();
	}
}

