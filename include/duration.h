#ifndef DURATION_H
#define DURATION_H
#include <cstddef>

#pragma once

class duration
{
public:
    duration();
    duration(int t); 
    int getDuration();
    bool tick();
    bool tick(int dt);
    void setAlarm(int t); 

private:
    // Time is 0 by default
    int time = 0;
    // Alarm is 0 by default
    int alarm = 0;
    // As long as the alarm hasnt been set, alarmHasBeenSet should be false
    bool alarmHasBeenSet = false;
    bool checkAndUpdateAlarm(int check); 
};

#endif