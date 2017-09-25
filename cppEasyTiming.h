 *      Author: Jeff Quaintance
 *      About: Super simple RAII class to provide a very easy to use timer.  Construct 
 *        object to start your timer and use the getTime method to get the time
 *        between your getTime call and the start time.  If you want to reset 
 *		    your start time use the reset method to set it back to the current time.

#ifndef CLSEASYTIMER_H
#define CLSEASYTIMER_H

#include <sys/time.h>

class clsEasyTimer {
public:
	// ctor & dtor
	clsEasyTimer()
  { 
    this->reset();  
  };
	virtual ~clsEasyTimer();
	
	// Methods
	double getTime()
  {
    struct timeval currentTime;
    gettimeofday(&currentTime, nullptr);					// Get the current time

    double dReturn; 
    dReturn = currentTime.tv_sec - this->startTime.tv_sec;	// subtract the start time from the current time
    dReturn *= 1000000L;									// Multiply our value by 1000000L to get our seconds into milliseconds
    dReturn += currentTime.tv_usec;							// Add the milliseconds to this value
    dReturn -= this->startTime.tv_usec;						// Subtract the start time milliseconds from our value
    dReturn /= 1000000L;									// Divide by 1000000L to get our end value in seconds

    return dReturn;
  };
	void reset()
  {
    this->startTime = (struct timeval){0};
	  gettimeofday(&(this->startTime), nullptr); 
  };
private:
	struct timeval startTime;
};

#endif /* CLSEASYTIMER_H */
