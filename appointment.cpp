
//Appointment class definition

#include "appointment.h"
#include <iomanip>
#include <cstring> 
#include <iostream>
using namespace std;

char* Appointment::getSubject() const
{
	return subject;
}
void Appointment::print() const
{
  startTime->print();
  endTime->print();
	int length = strlen(subject);
	if(length < 16)
  	cout << setw(16) << left << subject << location << endl;
	else
		cout << setw(length + 1) << left << subject << location << endl;
}
void Appointment::read()
{
	char *ptr;
  ptr = strtok(NULL, ",");
  subject = new char[strlen(ptr) + 1];
  strcpy(subject, ptr);
  startTime->read();
  endTime->read();
  ptr = strtok(NULL, ",");
  location = new char[strlen(ptr) + 1];
  strcpy(location, ptr);
}
Appointment::Appointment()
{
  startTime = new Time();
  endTime = new Time();
  subject = NULL;
  location = NULL;
}
Appointment::~Appointment()
{
  delete [] subject;
  delete [] location;
}
bool Appointment::compareSubject(const char* comparedSubject) const
{
  return !strcmp(comparedSubject, subject);
}
Appointment& Appointment::operator=(const Appointment &a)
{
  *startTime = *(a.startTime);
  *endTime = *(a.endTime);

  if(subject != NULL)
  {
    delete [] subject;
    subject = NULL;
  }  
	if(a.subject != NULL)
  {
      subject = new char[strlen(a.subject) + 1];
      strcpy(subject, a.subject);
  }
  if(location  != NULL)
  {
    delete [] location;
		location = NULL;
  }  
	if(a.location != NULL)
  {
     location = new char[strlen(a.location) + 1];
     strcpy(location, a.location);
  }

  return *this;
}

