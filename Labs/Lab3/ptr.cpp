#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

//////////////////////////////////////
//part of 5
struct recType
{
	int age;
	float weight;
	char gender;

};


int main(){

/////////////////////////////////////////////////////////////
//1
	int num =5;

/////////////////////////////////////////////////////////////
//2
	int *intPtr = new int;
	intPtr = NULL; 

/////////////////////////////////////////////////////////////
//3
	//intPtr = &num; // 17
	
/////////////////////////////////////////////////////////////
//4
	*intPtr *= 10;
	cout <<"intPtr points to:	" << *intPtr << endl;
		
/////////////////////////////////////////////////////////////
//5
	recType *recPtr = new recType; // 6 make dynamic memory

/////////////////////////////////////////////////////////
//7
	recPtr -> age = 25;
	recPtr -> weight =190;
	recPtr -> gender = 'M';

/////////////////////////////////////////////////////////////
//8
	recPtr -> age += 5;
	cout<<"Three fileds Pointed to by recPtr:	" <<recPtr -> age << " "<< recPtr -> weight << " " << recPtr -> gender << endl;

/////////////////////////////////////////////////////////////
//9
	delete recPtr;

/////////////////////////////////////////////////////////////
//10
	recPtr =NULL;

/////////////////////////////////////////////////////////////
//11	
	char *strPtr = new char[50];

/////////////////////////////////////////////////////////////	
//12	
	strcpy(strPtr,"Operating Systems");
	cout<< "strPtr points to :	"<<strPtr << endl;

/////////////////////////////////////////////////////////////
//13
	int lowChar =0;
	for(int i =0; i< strlen(strPtr); i++)
	{
		
		if(islower(*(strPtr + i)))
			lowChar ++;
				
	}
	cout << "LowerCase letters pointed to by strPtr:	"<<lowChar << endl;

/////////////////////////////////////////////////////////////
//14
	cout << "Printing strPtr after adding 10: 	"<< strPtr +10  << endl;


/////////////////////////////////////////////////////////////
//15
	strPtr -= 10;
	delete strPtr;
//////////////////////////////////////////////////////////////
//16 compile and test
	
//End
	return 0;
}
