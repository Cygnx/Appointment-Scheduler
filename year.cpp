
//year.cpp Year class definition

#include "year.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>

using namespace std;

Year::Year()
{
  count = 0;
  size = 30;
  days = new Day[size];
}//Year constructor

Year::~Year()
{
  delete [] days;
}//Year deconstructor

void Year::addDate(int mo, int d)
{
  int i, j;
  if(count + 1 >= size)
  {
    Day *temp = new Day[size * 2];

    for(i = 0; i < size; i++)
      temp[i] = days[i];

    delete [] days;
   days = temp;
   size *= 2;
  }//if resize needed

  for(i=0; i < count; i++)
    if(days[i].compareDate(mo, d) > 0)
      break;

  for(j = count - 1; j >= i; --j)
    days[j + 1] = days[j];

  days[i].setNewDate(mo, d);
}//addDate()

int Year::findDate(short mo, short d)	
{
  int i;
  
  for(i = 0; i < count; i++)
    if(!(days[i].compareDate(mo, d)))
      return i;
  //for through days array
  
  return count;
}//findDate()

void Year::read(){
  char line[256];
  int month, day, pos;
  stringstream ss;

  ifstream inf("appts.csv");
  inf.getline(line, 256);		//skip header
  while(inf.getline(line, 256))
  {
    ss.str(strtok(line, "/"));
    ss >> month;
    ss.clear();
    ss.str(strtok(NULL, "/"));
    ss >> day;
    ss.clear();
    strtok(NULL, ",");
    
    pos = findDate(month, day);
    if(pos == count)
    {
      addDate(month, day);
      count++;
      pos = findDate(month, day);
    }
    days[pos].read();
  }//while still reading data
  
  inf.close();
}//read()

void Year::searchDate(int mo, int d) const
{
 // int month, day;
  bool found = false;
  
  for(int i = 0; i < count; i++)
    if(days[i].getMonth() == mo && days[i].getDay() == d)
    {
      cout << "Start End   Subject         Location" << endl;
      days[i].print(-1);
      found = true;
      break;
    }  // if date matches

  if(!found)
    cout << "There are no appointments for that date." << endl;

  cout << endl;

  
}//searchDate()

void Year::searchSubject(char *subject) const
{
  bool found = false;
  for(int i = 0; i < count; i++)
    for(int j = 0;j < days[i].getApptCount();j++)
      if(!days[i].compareSubject(subject, j))
      {
	if(!found)
	  cout << "Date                           Start End   Subject         Location" <<endl ;
        days[i].print(j);
	found = true;
      }
  if(!found)
    cout << subject << " was not found as a subject in the calendar." << endl;

  cout << endl; 
}//searchSubject()
