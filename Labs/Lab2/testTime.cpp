#include "time.h"
#include <iostream>
using namespace std;

int main()
{
	Time myTime(9,30,0);
	myTime.Write();	
	myTime.WriteAmPm();
	
	myTime.Set(8,0,0);
	myTime.WriteAmPm();
	myTime.Mealtime();
	
	cout<<endl<<endl;
	Time Schedules[10];
	for(int i=0; i<10; i++)
	{
		Schedules[i].Set(11,0,0);
		Schedules[i].WriteAmPm();
	}

	return 0;
}
