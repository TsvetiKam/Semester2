#ifndef RAILWAY_SCHEDULE_H_
#define RAILWAY_SCHEDULE_H_
#include "Train.h"
#include "QuickTrain.h"
#include "DirectTrain.h"
#include "ExpressTrain.h"
#include "Station.h"
#include "Line.h"

class RailwaySchedule {
private:

	Train** trains;
	int trainCount;
	Station* stations;
	int stationCount;
	Line* lines;
	int lineCount;

	void del();
	void copy(const RailwaySchedule& other);

public:
	RailwaySchedule();
	RailwaySchedule(const RailwaySchedule& other);
	RailwaySchedule& operator=(const RailwaySchedule& other);
	~RailwaySchedule();

	void addTrain(Train* train);
	void addStation(Station& station);
	void addLines(Train train);


};


#endif
