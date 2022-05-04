#include <iostream> 
using namespace std;

	bool dublicate(double *ptr, double *ptr2);
	bool sameLocation(double *ptr, double *ptr2);

int main()
{
	double *ptr1 = new double;
	double *ptr2 = new double;
	double value1= .5;
	double value2 = 1.5;
	double value3 = 2.5;
	
	*ptr1 = value1;
	*ptr2 = .5;
	
	cout<<"1 is true and 0 is for false." << endl;
	cout<< "Test 1" << endl;

	cout << "Same value: " << dublicate(ptr1, ptr2) << endl; 
	cout << "Same address: " << sameLocation(ptr1, ptr2) << endl;
	
	cout<< "Test 2" << endl;
	*ptr1 = value2;
	*ptr2 = value3;

	cout << "Same value: " << dublicate(ptr1, ptr2) << endl; 
	cout << "Same address: " << sameLocation(ptr1, ptr2) << endl;


	cout<< "Test 3" << endl;

	delete ptr2;
	ptr1 = ptr2;

	cout << "Same value: " << dublicate(ptr1, ptr2) << endl; 
	cout << "Same address: " << sameLocation(ptr1, ptr2) << endl;

	return 0; 

}

bool dublicate (double *ptr, double *ptr2)
{
	bool fin;
	if(*ptr == *ptr2)
		fin = true;
	else 
		fin = false;
	
	return fin;	
}

bool sameLocation(double *ptr, double *ptr2)
{
	bool fin; 
	if (ptr == ptr2)
		fin= true;
	else 
		fin = false;


	return fin;

}


