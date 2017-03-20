#include "Clock.h"
#include <iostream>

Clock::Clock(): val_hours(0), val_minutes(0), val_seconds(0)
{
}

Clock::Clock(unsigned short hours, unsigned short minutes, unsigned short seconds): val_hours(hours), val_minutes(minutes), val_seconds(seconds)
{
}

Clock::~Clock()
{
}

unsigned short Clock::hours()
{
	return val_hours;
}

unsigned short Clock::minutes()
{
	return val_minutes;
}

unsigned short Clock::seconds()
{
	return val_seconds;
}

void Clock::setHour(unsigned short hour, unsigned short minute, unsigned short second)
{
	this->val_hours = hour;
	this->val_minutes = minute;
	this->val_seconds = second;
}

void Clock::printHour()
{
	std::cout << this->val_hours << ':' << this->val_minutes << ':' << this->val_seconds << std::endl;
}

bool Clock::operator==(const Clock& clock2)
{
	return ((this->val_hours == clock2.val_hours) && (this->val_minutes == clock2.val_minutes) && (this->val_seconds == clock2.val_seconds));
}

bool Clock::operator<(const Clock& clock2)
{
	bool result = false;

	if (this->val_hours <= clock2.val_hours)
	{
		if (this->val_minutes <= clock2.val_minutes)
		{
			if (this->val_seconds < clock2.val_seconds)
			{
				result = true;
			}
		}
	}

	return result;
}
