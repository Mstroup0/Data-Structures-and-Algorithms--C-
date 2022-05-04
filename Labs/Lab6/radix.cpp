#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int maxELementLength(const vector <int> &v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int> &L, int k);
vector <int> QueuesToArray(vector<queue<int> >&QA, int NumVals);
void RadixSort(vector<int>& L, int NumDigits);
void PrintVector (const vector <int> &L);



int main()
{
	vector<int> L;
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);	
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	
	//PrintVector(L);

	//cout << GetDigit(95, 0);

		
	RadixSort (L, 7);
	PrintVector(L);
}

int maxELementLength(const vector <int> &v)
{
	int value = v.back();	
	int count=0;
	while(value != 0)
	{
		value = value/10;
		count++;
	}

	return count;
}

int GetDigit(int number, int k)
{
	int value = (int)(number/pow(10, (k))) % 10;
	return value;
}
vector<queue<int> > ItemsToQueues(const vector<int> &L, int k)
{
		vector< queue<int> > QA(10);
		
	
		for (int i = 0; i < QA.size(); i ++)
		{
			for (int j =0; j < L.size(); j++)
			{
				if( i == GetDigit(L.at(j) , k))
				{
					QA.at(i).push(L.at(j));
				}
			}									

		}		


		
		return QA;		
}
vector <int> QueuesToArray(vector<queue<int> >&QA, int NumVals)
{
	vector <int> L;
	
	for(int i =0; i < QA.size(); i++)
	{
		while(!QA.at(i).empty())
		{
		 	L.push_back((QA.at(i)).front());	
			QA.at(i).pop();

		}	

	}	
		

	return L; 
}

void RadixSort(vector<int>& L, int NumDigits)
{
	vector<queue<int> > QA(10);
	for(int k= 0; k <NumDigits; k++)
	{
		QA = ItemsToQueues(L, k);
		L = QueuesToArray(QA, NumDigits);

	}
}

void PrintVector (const vector <int> &L)
{
	for (int i = 0 ; i < L.size(); i++)
	{
		cout << L.at(i) << " " ;

	}

}

