
#ifndef DAY_H
#define DAY_H
#include "dayofweek.h"
#include "appointment.h"
class Day {
  public:
    Day(); 
    ~Day();
    int compareSubject(char* sub, int apptNum);
    short getDay()  const;
    short getMonth() const;
    short getApptCount() const;
    void setNewDate(short, short); 
    int compareDate(short, short) const; 
    void print(int) const; 
    void read();
    Day& operator=(const Day &d);
  private:
    Appointment *appts[8];
    short day;
    short month;
    short apptCount;
};
#endif
