#include "duration.h"
#include "assert.h"
#include <stdlib.h>
#include <cstdio>
#include <cstddef>

duration::duration()
{
    time = 0;
    alarm = 0;
    alarmHasBeenSet = false;
}

int duration::getDuration()
{
    return time;
}

duration::duration(int t)
{
    /* precondition*/
    assert(t >= 0);

    /* postcondition*/
    time = t;
}

bool duration::tick()
{
    time++;
    // if tick makes the time value equal to or larger than the alarm, the alarm is reset
    return checkAndUpdateAlarm(time);
}

bool duration::tick(int dt)
{
    /* precondition*/
    assert(dt >= 0);

    time += dt;
    // if tick makes the time value equal to or larger than the alarm, the alarm is reset
    return checkAndUpdateAlarm(time);
}

void duration::setAlarm(int t)
{
    /* preconditions*/
    assert(t > 0);
    if (time > t) {
        printf("\n Alarms can not be set in the past!");
    }
    else
    {
        /* postconditions*/
        alarm = t;
        alarmHasBeenSet = true;
    }
}

bool duration::checkAndUpdateAlarm(int check)
{
    // checks if the new value of "time" is greater than or equal to alarm
    if (check >= alarm)
    {
        alarm = 0;
        alarmHasBeenSet = false;
        return true;
    }
    else
    {
        return false;
    }
}
