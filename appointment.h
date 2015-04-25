
#ifndef APPT_H
#define APPT_H

#include "time.h"

class Appointment {
  public:
    Appointment();
    ~Appointment();
    char* getSubject() const;
    void read(); 
    void print() const;
    bool compareSubject(const char*) const;
    Appointment& operator=(const Appointment&d);
  private:
    Time *startTime;
    Time *endTime;
    char *location;
    char *subject;
  
 };
#endif
