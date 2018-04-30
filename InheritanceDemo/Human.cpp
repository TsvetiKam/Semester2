#include "stdafx.h"
#include "Human.h"
#include <cstring>
#include <iostream>

char * Human::getName() const {
	return name;
}

int Human::getAge() const {
	return age;
}

double Human::getWeight() const{
	return weight;
}

char Human::getGender() const {
	return gender;
}

void Human::setName(const char * name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Human::setAge(const int age){
	this->age = age;
}

void Human::setWeight(const double weight) {
	this->weight = weight;
}

void Human::setGender(const char gender) {
	if (gender == 'm' || gender == 'f') {
		this->gender = gender;
	}
	else {
		throw "Invalid gender.";
	}
}

void Human::sayHello() {
	std::cout << "Hello! My name is " << name << std::endl;
}

void Human::del() {
	delete[] this->name;
}

void Human::copy(const Human& other) {
	setName(other.name);
	setAge(other.age);
	setWeight(other.weight);
	setGender(other.gender);
}

Human::Human() {
	name = NULL;
	age = 0; 
	weight = 0;
	gender = 'f';
}

Human::Human(char * name, int age, double weight, char gender) : age(age), weight(weight), gender(gender) {
	setName(name);
}

Human::Human(const Human & other) {
	copy(other);
}

Human::~Human() {
	del();
}

Human & Human::operator=(const Human & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}
