#ifndef HUMAN_H_
#define HUMAN_H_

class Human {
protected:
	char* name;
	int age;
	double weight;
	char gender;

private:
	void del();
	void copy(const Human & other);

public:
	Human();
	Human(char* name, int age, double weight, char gender);
	Human(const Human & other);
	~Human();
	Human& operator=(const Human & other);
	char* getName() const;
	int getAge() const;
	double getWeight()const;
	char getGender() const;
	void setName(const char* name);
	void setAge(const int age);
	void setWeight(const double weight);
	void setGender(const char gender);
	void sayHello();



};

#endif