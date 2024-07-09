#pragma once
#include <iostream>
#include <string>
using namespace std;
class Survivor {
private:
	string survivorName;
	int survivorAge; 
	char survivorStatus; // 'm' = marriage, 's' = single, 'r' = in relationship
public:
	//getters:
	string getName() const { return this->survivorName; }
	int getAge() const { return this->survivorAge; }
	char getStatus() const { return this->survivorStatus; }

	//Setters:
	void setName(string n) { this->survivorName = n; }
	void setAge(int a) { this->survivorAge = a; }
	void setStatus(int s) { this->survivorStatus = s; }
	
	void setSurvivor(string name = "John Doe", int age = 18, char status = 's');

	//Constructors:
	Survivor(string n = "John Doe", int a = 18, char s = 's');
	Survivor(const Survivor& other);
	Survivor(bool flag);

	//Destructors:
	~Survivor() { cout << "The Survivor " << this->survivorName << " is destroyed from address : " << this << endl; };

	void printSurvivor() const;
};
