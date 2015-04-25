#ifndef YEAR_H
#define YEAR_H

#include "day.h"

class Year {
  public:
    Year();
    ~Year();
    void addDate(int, int);
    int findDate(short, short);
    void read();
    void searchDate(int, int) const;
    void searchSubject(char*) const;
  private:
    Day *days;
    int count, size;
};//class Year


#endif
