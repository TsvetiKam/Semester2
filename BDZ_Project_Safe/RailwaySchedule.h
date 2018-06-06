#ifndef RAILWAY_SCHEDULE_H_
#define RAILWAY_SCHEDULE_H_
#include "Line.h"

class RailwaySchedule {
private:

	Line* lines;
	int lineCount;

	void del();
	void copy(const RailwaySchedule& other);

public:
	RailwaySchedule();
	RailwaySchedule(const RailwaySchedule& other);
	RailwaySchedule& operator=(const RailwaySchedule& other);
	~RailwaySchedule();

	void addLine(const Line& l);

	int getLineCount() const;

	void print() const;
};


#endif
