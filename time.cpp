//time.cpp class definitions

#include "time.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Time::Time()
{
}//Time constructor

Time::~Time()
{  
}//Time destructor

short Time::getHour() const
{
  return hour; 
}//getHour()

short Time::getMinute() const
{
  return minute;
}//getMinute()

void Time::setHour(short hr)
{
  hour = hr;
}//setHour()

void Time::setMinute(short min)
{
  minute = min;
}//setMinute()

void Time::print() const
{
  cout << setw(2) << setfill('0') << right << hour << ":"                               << setw(2) << minute << " " << setfill(' ');
}//print()

void Time::read()
{
  short hr, min;
  hr = atoi(strtok(NULL, ":"));
  min = atoi(strtok(NULL, ":"));
  char *ptr = strtok(NULL, ",");

  if(strchr(ptr, 'P') && hr != 12)
    hr += 12;
  else
    if(strchr(ptr, 'A') && hr == 12)
      hr = 0;

  this->setHour(hr);
  this->setMinute(min);
}//read()
