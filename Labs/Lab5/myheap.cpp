#include <iostream>
using namespace std;

#include "BinaryHeap.h"
void fillHeap(BinaryHeap<char> &b);

int main()
{
	BinaryHeap <char> PQ(50);
	fillHeap(PQ);
	PQ.deleteMin();
	
	PQ.printLtSubtree();
	cout << endl;
	
	cout << "height: " << PQ.Height()<< endl;
	
	cout << "Max: " << PQ.findMax() ;
	
	
return 0;
}


void fillHeap(BinaryHeap<char> &b)
{
	for(int a= 65; a < 75; a++)
		b.insert(char(a));

}

