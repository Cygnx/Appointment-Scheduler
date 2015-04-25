

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "year.h"

using namespace std;

int getChoice();				
void getDate(int *month, int *day);	
void getSubject(char *subject);

int getChoice()
{
  int choice;

  do
  {
    cout << "Calendar Menu\n0. Done.\n1. Search for date.\n";
    cout << "2. Search for subject.\n\nYour choice >> ";
    cin >> choice;
    if(choice < 0 || choice > 2)
      cout << "\nChoice must be between 0 and 2.\nPlease try again.\n\n";
  } while(choice < 0 || choice > 2);

  return choice; // eat end of line
} // getChoice()

void getDate(int *month, int *day)
{
  char s[80], s2[80], *ptr;

  do
  {
    *month = *day = 0;
    cout << "\nPlease enter the month and day (mm/dd) >> ";
    cin >> s;
    strcpy(s2, s);
    ptr = strtok(s2,"/");

    if(ptr)
    {
      *month = atoi(ptr);
      ptr = strtok(NULL, ",");
      if(ptr)
        *day = atoi(ptr);
    }

    if(*month < 1 || *month > 12 || *day < 1 || *day > 31)
      cout << s << " is not a valid date.\nPlease try again.\n\n";
  } while(*month < 1 || *month > 12 || *day < 1 || *day > 31);

}

void getSubject(char *subject)
{
  cout << "\nPlease enter the subject >> ";
  cin.getline(subject, 80);
  cin.getline(subject, 80);
}//getSubject()

int main()
{
  Year *year = new Year();
  int choice, month, day;
  char subject[80];

  year->read();

  choice = getChoice();

  while(choice != 0)
  {
    if(choice == 1)
    {
      getDate(&month, &day);
      year->searchDate(month, day);
    }
    else // choice == 2
    {
      getSubject(subject);
      year->searchSubject(subject);
    }
    choice = getChoice();
  } // while choice not Done
  
  return 0;
} // main()

