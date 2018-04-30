#ifndef STUDENT_H_
#define STUDENT_H_
#include "Human.h"

class Student: public Human {
private:
	int FN;
public:
	Student();
	Student(char* name, int age, double weight, char gender, int FN);
	Student(const Student& other);
	~Student();
	Student& operator=(const Student& other);
	void setFN(int FN);
	int getFN() const;
	void sayHello();

};

#endif