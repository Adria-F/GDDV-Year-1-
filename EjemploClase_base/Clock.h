#ifndef __CLOCK__
#define __CLOCK__

class Clock
{
public:
	
	Clock();
	Clock(unsigned short hours, unsigned short minutes, unsigned short seconds);
	~Clock();

	unsigned short hours();
	unsigned short minutes();
	unsigned short seconds();

	void setHour(unsigned short hour, unsigned short minute, unsigned short second);
	void printHour();

	bool operator==(const Clock& clock2);
	bool operator<(const Clock& clock2);

private:
	
	unsigned short val_hours;
	unsigned short val_minutes;
	unsigned short val_seconds;
};

#endif //__CLOCK__