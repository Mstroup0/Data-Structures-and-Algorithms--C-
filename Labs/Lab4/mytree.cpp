
#include <iostream>
#include <string>
#include "bst.h"
using namespace std;


int main()
{

	BinarySearchTree<int> t(0);

	t.insert(6);
	t.insert(2);
	t.insert(8);
	t.insert(1);
	t.insert(4);
	t.insert(3);

	cout<< "Print Tree" << endl;	
	t.printTree();	


	cout<< "PostOrder Tree" << endl;
	t.postOrder();	
	cout<< endl;
	
	cout<< "height = " << t.height()<< endl;
	cout<<"number of Leaves = "  << t.numLeaves()<< endl;

	if(t.isBalanced())
	 	cout << "It's Balanced!" << endl;
	else
		cout<< "It's not Balanced" << endl;

	cout<< endl<< endl << "Adding 9 " << endl << endl


	t.insert(9);
	 cout<< "Print Tree" << endl;
        t.printTree();


        cout<< "PostOrder Tree" << endl;
        t.postOrder();
        cout<< endl;

        cout<< "height = " << t.height()<< endl;
        cout<<"number of Leaves = "  << t.numLeaves()<< endl;

        if(t.isBalanced())
                cout << "It's Balanced!" << endl;
        else
                cout<< "It's not Balanced" << endl;

	
	
	
}
