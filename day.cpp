#include "day.h"
#include "dayofweek.h"
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int Day::compareSubject(char* sub, int apptNum)
{
	return(strcmp(appts[apptNum]->getSubject(), sub));
}
short Day::getDay() const
{
	return day;
}
short Day::getMonth() const
{
	return month;
}
short Day::getApptCount() const
{
	return apptCount;
}
int Day::compareDate(short _month, short _date) const
{	
	if(month == _month)
		return day - _date;
	return month - _month;
}
void Day::print(int num) const
{
  if(num == -1)
  {
    for(int i = 0; i < apptCount; i++)	
    {
      appts[i]->print();
    }
  }
  else
  {  
    DayOfWeek _day(month, day);
    _day.read();
    _day.print();
    appts[num]->print();
  }
}
void Day::read()
{
	appts[apptCount] = new Appointment();
	appts[apptCount]->read();
        apptCount++;
}
void Day::setNewDate(short _month, short _day)
{
	month = _month;
	day = _day;

	for(int i = 0 ; i < apptCount; i++)
	{
		delete appts[i];
	}
	apptCount = 0; 
}
Day::Day()
{
}
Day::~Day()
{
	for(int i = 0; i < apptCount; i++)
		delete (appts[i]);
}
Day& Day::operator=(const Day &d)
{
	day = d.day;
	month = d.month;
	int j;	
  for(j = 0; j < apptCount;j++)
    delete appts[j];

	apptCount = d.apptCount;
	
	for(j = 0; j < apptCount ;j++)
	{
		appts[j] = new Appointment();
		*appts[j] = *d.appts[j];
	}
	return *this;
}
