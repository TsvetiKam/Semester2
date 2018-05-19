#ifndef TIME_H_TIME
#define TIME_H_TIME

class Time {
private:
	int hour;
	int minutes;
	int seconds;
	char Hour[3];
	char Minutes[3];
	char Seconds[3];
	bool isValidTime(const char * time);
	bool isValidHour(const char * hour);
	bool isValidMinute(const char * minute);
	bool isValidSecond(const char * second);
public:
	bool isValid;
	Time();
	Time(const char * time);

	void setHour(char * hour);
	void setMinutes(char * minutes);
	void SetSeconds(char * seconds);
	void SetHour(int hour);
	void SetMinutes(int minutes);
	void setSeconds(int secondes);

	int getHourNum() const;
	const char* getHourStr() const;

	int getMinutesNum() const;
	const char* getMinutesStr() const;

	int getSecondsNum() const;
	const char* getSecondsStr() const;


};


#endif
