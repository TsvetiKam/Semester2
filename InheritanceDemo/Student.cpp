#include "stdafx.h"
#include "Student.h"
#include <iostream>

Student::Student() : Human() {
	FN = 0;
}

Student::Student(char * name, int age, double weight, char gender, int FN) 
	: Human(name, age, weight, gender) {
	this->FN = FN;
}

Student::Student(const Student & other) : Human(other) {
	this->FN = other.FN;
}

Student::~Student() {
	Human::~Human();
}

Student & Student::operator=(const Student & other) {
	if (this != &other) {
		Human::operator=(other);
		FN = other.FN;
	}
	return *this;
}

void Student::setFN(int FN) {
	this->FN = FN;
}

int Student::getFN() const {
	return FN;
}

void Student::sayHello() {
	Human::sayHello();
	std::cout << "I am a student." << std::endl;
}
