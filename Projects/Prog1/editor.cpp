// Created by Mackenzie Stroup
// 2/7/2020
// File name: editor.cpp
// Project 1 : create a basic file editor, with nodes that are doubly circulary 
//**************************************************************************************
//**************************************************************************************
//Brought in files
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "linelist.h"
using namespace std;


//created Methods
void OpenFile(int argc, char* argv[], LineList& L); // opens the file from the command Line
void SaveFile(char* argv[], LineList& L); //Saves the file on exit (e/E)
void backLine(LineList& L); //Moves back a Line (P/p)
void nextLine(LineList& L); // Moves to next Line (N/n) 
void PrintLine(LineList& L); // Prints Lines (l/L)
void Insert(LineList& L); // inserts at location(i/I)
void deleteLine(LineList& L);// deletes current line(D/d)
void menu(char* argv[], LineList& L); // editing menu 

//Main method
int main(int argc, char* argv[]){
	//Variables
	LineList list;
	// opens file from the command line
	OpenFile( argc, argv, list);
	// menu and editing options
	menu(argv,list);


	return 0; // end of the program. 
}


// Open file and save to list
void  OpenFile(int argc, char* argv[], LineList& L)
{
// Opens and creates  fstream
	fstream infile;
	infile.open(argv[1]);
//variable for the line of string
	string s;

//if the file is able to open run this 
	if(infile.is_open())
	{
	// While there is line run
		while( getline(infile,s))
		{
		// if not the end of the file run this
			if(!infile.eof())
				L.insertLine(s);
		}	
	}
// file is unable to open receives message 
	else cout<< "File could not open" << endl;

//Closes file
	infile.close();
	
}

void menu(char* argv[], LineList& L)
{
// variable for user control
	char in;
//brought in lines are printed
	PrintLine(L);

//Start of the allow editing and user control
	cout<< "Start editing" << endl;
	cout<< L.getCurrLineNum() << "> ";
	cin >> in ;

	int k =1;
//Menu loops will k is equal to 1, changes when e/E is typed 
	while(k =1)
	{

		if(in == 'I' || in == 'i')
		{
			// Insert a insert Line
			Insert(L);				
		}
		else if(in =='L' || in == 'l')
		{
			// Prints Line
			PrintLine(L);
		}
		else if(in == 'P' || in == 'p')
		{
			// go back a line
			backLine(L);
		}
		else if(in == 'N' || in == 'n')
		{
			//go to next line
			nextLine(L);
		}
		else if(in == 'D' || in == 'd')
		{
			//Delete current line
			deleteLine(L);			
		}
		else if(in == 'e' || in == 'E' )
		{
			SaveFile(argv, L);		
			break;
			k==0;
		}
		cout << L.getCurrLineNum() << "> ";
		cin >> in;
	}
	
}


// Save to file
void SaveFile(char* argv[], LineList& L)
{
// creates and opens the fstream class and file
	fstream outfile;
	outfile.open(argv[1]);	

// goes to the top of the list
	L.goToTop();
	string s;// variable for lines

//fills the file from the top of the list to the bottom 
	while (L.getCurrLine() == " - - - Bottom of file - - - ")	
	{	
		s = L.getCurrLine();
		outfile << s << endl;
		L.moveNextLine();
	
	}
	outfile.close();// closes the file
}

//Back a Line
void backLine(LineList& L)
{
	L.movePrevLine();

}

//Next Line (N)
void nextLine(LineList& L)
{
	L.moveNextLine();
}

// Prints new Line (L)
void PrintLine(LineList& L)
{
	L.printList();			
}

//Inserts new Line (I)
void Insert(LineList& L)
{
 
// Asks for the input
	string in;
	cout<< L.getCurrLineNum() << "> "; 
	cin>> in;
	
	L.insertLine(in);
}


//Deletes Line (D)
void deleteLine(LineList& L)
{
	L.deleteLine();	
}
