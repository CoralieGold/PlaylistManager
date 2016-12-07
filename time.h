#ifndef TIME_H
#define TIME_H


class Time
{
private:
    int seconds;
    int minutes;
    int hours;

public:
    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;

    void setSeconds(int value);
    void setMinutes(int value);
    void setHours(int value);
    void setTime(const int &seconds, const int &minutes, const int &hours);

    Time(int seconds, int minutes, int hours);
    Time();
};

#endif // TIME_H
