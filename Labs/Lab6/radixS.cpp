#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string> 
using namespace std;

int maxELementLength(const vector <string> &v);
int GetDigit(string word, int k);
vector<queue<string> > ItemsToQueues(const vector<string> &L, int k);
vector <string> QueuesToArray(vector<queue<string> >&QA, int NumVals);
void RadixSort(vector<string>& L, int NumDigits);
void PrintVector (const vector <string> &L);



int main()
{
	string a[] = {"zebra", "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};	
	vector<string> L(a, a+10);

	RadixSort(L, 10);
	PrintVector(L);

}


int maxELementLength(const vector <string> &v)
{
        
        int count= v.back().size();
        

        return count;
}

int GetDigit(string word, int k)
{	
	if(k > word.size()-1)
		return 0;
	else{
        	char in = word.at(k);
		int value = (int)in;
        	return value;
	}
}
vector<queue<string> > ItemsToQueues(const vector<string> &L, int k)
{
                vector< queue<string> > QA(128);


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
vector <string> QueuesToArray(vector<queue<string> >&QA, int NumVals)
{
        vector <string> L;

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

void RadixSort(vector<string>& L, int size)
{
        vector<queue<string> > QA(126);
        for(int k= 0; k <size; k++)
        {
                QA = ItemsToQueues(L, k);
                L = QueuesToArray(QA, size);

        }
}

void PrintVector (const vector <string> &L)
{
        for (int i = 0 ; i < L.size(); i++)
        {
                cout << L.at(i) << " " ;

        }

}

