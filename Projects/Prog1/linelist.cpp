
#include <iostream>
#include "linelist.h"

LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 1;
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
}

void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
	while(currLine -> info != topMessage)
	{
		currLine=currLine -> back;
	}
	currLine =  currLine -> next;
	currLineNum = 1;
}

void LineList::goToBottom() 
{
	// Post : Advances currLine to last line
	while(currLine -> info != bottomMessage)
		currLine = currLine -> next;
	
	currLine = currLine -> back;
	currLineNum = getLength() -1;
				
}

void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line
	if(currLine -> info == bottomMessage)
		movePrevLine();
	
	LineNode *Line =  new LineNode;
	Line ->info = newLine; 
	Line -> back = currLine;
	Line -> next = currLine -> next;

	currLine -> next -> back = Line;
	currLine -> next = Line;
	currLine = currLine-> next;
	
	length ++;
	currLineNum++;
}	

void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	LineNode *Line = new LineNode;
	LineNode *Line2 = new LineNode;
	LineNode *del = new LineNode;
	Line = currLine;
	Line2 =currLine;	

	if(Line-> next -> info == bottomMessage)
	{
		Line = currLine -> next;
		Line2 = currLine -> back;
		currLine -> back -> next = Line;
		currLine = Line2;
		currLineNum --;
	}
	else if(Line -> back->info == topMessage)
	{
		Line = currLine -> back;
		Line2 = currLine -> next;
		currLine -> next -> back  = Line;
		currLine = Line2;	
		currLineNum ++; 
	}
	else
	{
		Line = currLine -> next;
		Line2 = currLine -> back;
		currLine -> back -> next = Line;
		currLine -> next -> back = Line2;	
		currLineNum --; 	
	}	
	
	length --;	

}

void LineList::printList() 
{
	int lineNum = 1;
	LineNode *mark = currLine;
	int markNum = currLineNum;

	goToTop();
	LineNode *Line = currLine;
	
	while(Line -> info != bottomMessage )
	{
		cout << lineNum << "> " << Line-> info << endl;
		Line = Line-> next;	
		lineNum++;
		
	}
	currLine = mark;
	currLineNum = markNum;

}

string LineList::getCurrLine() const
{
	return (currLine-> info);	

}

void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine -> next != NULL) && (currLine-> info != bottomMessage))
	{
		currLine = currLine-> next;
		currLineNum++;
	}

}

void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine->back != NULL) && (currLine->info != topMessage))
	{
		currLine = currLine -> back;
		currLineNum --;
	}
}

int LineList::getCurrLineNum() const
{
	return (currLineNum -1);

}

int LineList::getLength() const
{
	return length;
}
