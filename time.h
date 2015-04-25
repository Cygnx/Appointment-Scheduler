
#ifndef TIME_H
#define TIME_H

class Time {
  public:
    Time();		//Time constructor
    ~Time();			//Time destructor
    short getHour() const;	//return hour
    short getMinute() const;	//return minute
    void setHour(short hr);	//set private hour
    void setMinute(short min);	//set private minute
    void print() const;		//print time in format
    void read();		//read into hour, minute times
  private:
    short hour;
    short minute;
};//class Time

#endif
