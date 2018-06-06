#ifndef EXPRESS_TRAIN_H_
#define EXPRESS_TRAIN_H_
#include "Train.h"
#include "DirectTrain.h"
#include "QuickTrain.h"

class ExpressTrain :  public QuickTrain, public DirectTrain {
private:
	virtual void print(std::ostream& out) const;
	virtual void read(std::istream& in);
public:
	ExpressTrain();
	ExpressTrain(const unsigned int* wagonPlaces, unsigned int wagonsCount, double speed, 
				 double coefficient, int priority);

	virtual Train* clone() const;

	virtual void addStation(Station& s);

	friend std::ostream& operator<<(std::ostream& out, ExpressTrain& train); // * полиморфизъм
	friend std::istream& operator>>(std::istream& in, ExpressTrain& train);
};

#endif;