#include "time.h"


int Time::getSeconds() const
{
    return seconds;
}

int Time::getMinutes() const
{
    return minutes;
}

int Time::getHours() const
{
    return hours;
}

void Time::setSeconds(int value)
{
    seconds = value;
}

void Time::setMinutes(int value)
{
    minutes = value;
}

void Time::setHours(int value)
{
    hours = value;
}

void Time::setTime(const int &seconds, const int &minutes, const int &hours) {
    setSeconds(seconds);
    setMinutes(minutes);
    setHours(hours);
}

Time::Time(int seconds, int minutes, int hours)
{
    setTime(seconds, minutes, hours);
}

Time::Time() {

}
