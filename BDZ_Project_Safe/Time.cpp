#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

bool Time::isValidTime(const char * time) {
	char h[3];
	h[0] = time[0];
	h[1] = time[1];
	h[2] = '\0';

	char m[3];
	m[0] = time[4];
	m[1] = time[5];
	m[2] = '\0';

	char s[3];
	s[0] = time[8];
	s[1] = time[9];
	s[2] = '\0';

	return (isValidHour(h) && isValidMinute(m) && isValidSecond(s));
}

bool Time::isValidHour(const char * hour) {
	int x = atoi(hour);
	return (x >= 0 && x <= 23);
}

bool Time::isValidMinute(const char * minute) {
	int x = atoi(minute);
	return (x >= 0 && x <= 59);
}

bool Time::isValidSecond(const char * second) {
	int x = atoi(second);
	return (x >= 0 && x <= 59);
}

Time::Time() : hour(0), minutes(0), seconds(0),
Hour("00"), Minutes("00"), Seconds("00"), isValid(true) {}

Time::Time(const char * time) {
	if (isValidTime(time)) {
		char h[3];
		h[0] = time[0];
		h[1] = time[1];
		h[2] = '\0';

		char m[3];
		m[0] = time[4];
		m[1] = time[5];
		m[2] = '\0';
		char s[3];

		s[0] = time[8];
		s[1] = time[9];
		s[2] = '\0';

		setHour(h);
		setMinutes(m);
		SetSeconds(s);
		isValid = true;
	}
	else {
		std::cout << "Error. Invalid time." << std::endl;
		isValid = false;
	}

}

void Time::setHour(char * hour) {
	if (isValidHour(hour)) {
		strcpy_s(this->Hour, 3, hour);
		this->hour = atoi(hour);
	}
	else {
		std::cout << "Error. //setHour()" << std::endl;
	}
}

void Time::setMinutes(char * minutes) {
	if (isValidMinute(minutes)) {
		strcpy_s(this->Minutes, 3, minutes);
		this->minutes = atoi(minutes);
	}
	else {
		std::cout << "Error. //setMinutes()" << std::endl;
	}
}

void Time::SetSeconds(char * seconds) {
	if (isValidSecond(seconds)) {
		strcpy_s(this->Seconds, 3, seconds);
		this->seconds = atoi(seconds);
	}
	else {
		std::cout << "Error. //setSeconds()" << std::endl;
	}
}

void Time::SetHour(int hour) {
	if (hour >= 0 && hour <= 9) {
		this->Hour[0] = '0';
		this->Hour[1] = (char)hour + '0';
		this->Hour[2] = '\0';
		this->hour = hour;
	}
	else if (hour < 24) {
		this->Hour[0] = (char)(hour / 10) + '0';
		this->Hour[1] = (char)(hour % 10) + '0';
		this->Hour[2] = '\0';
		this->hour = hour;
	}
	else {
		std::cout << "Invalid hour // SetHour(int)" << std::endl;
	}
}

void Time::SetMinutes(int minutes) {
	if (minutes >= 0 && minutes <= 9) {
		this->Minutes[0] = '0';
		this->Minutes[1] = (char)minutes + '0';
		this->Minutes[2] = '\0';
		this->minutes = minutes;
	}
	else if (minutes < 60) {
		this->Minutes[0] = (char)(minutes / 10) + '0';
		this->Minutes[1] = (char)(minutes % 10) + '0';
		this->Minutes[2] = '\0';
		this->minutes = minutes;
	}
	else {
		std::cout << "Invalid minutes // SetMinutes(int)" << std::endl;
	}
}

void Time::setSeconds(int seconds) {
	if (seconds >= 0 && seconds <= 9) {
		this->Seconds[0] = '0';
		this->Seconds[1] = (char)seconds + '0';
		this->Seconds[2] = '\0';
		this->seconds = seconds;
	}
	else if (seconds < 60) {
		this->Seconds[0] = (char)(seconds / 10) + '0';
		this->Seconds[1] = (char)(seconds % 10) + '0';
		this->Seconds[2] = '\0';
		this->seconds = seconds;
	}
	else {
		std::cout << "Invalid seconds // setSeconds(int)" << std::endl;
	}
}

int Time::getHourNum() const {
	return hour;
}

const char * Time::getHourStr() const {
	return Hour;
}

int Time::getMinutesNum() const {
	return minutes;
}

const char * Time::getMinutesStr() const {
	return Minutes;
}

int Time::getSecondsNum() const {
	return seconds;
}

const char * Time::getSecondsStr() const {
	return Seconds;
}


