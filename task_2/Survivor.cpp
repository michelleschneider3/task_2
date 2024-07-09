#include "Survivor.h"

void Survivor::setSurvivor(string name, int age, char status) {
	this->setName(name);
	this->setAge(age);
	this->setStatus(status);
}

Survivor::Survivor(string n, int a, char s) {
	this->setSurvivor(n, a, s);
}

Survivor::Survivor(const Survivor& other) {
	this->setSurvivor(other.getName(), other.getAge(), other.getStatus());
}

Survivor::Survivor(bool flag) {
	if (flag) 
		this->setSurvivor("John Doe", 30, 'm');
	else 
		this->setSurvivor("tommas edison", 70, 's');
}

void Survivor::printSurvivor() const {
	cout << "Survivor's name: " << this->getName() << endl;
	cout << "Survivor's age: " << this->getAge() << endl;
	if (this->getStatus() == 'r')
		cout << "Survivor status: In relationship" << endl;
	else if (this->getStatus() == 'm')
		cout << "Survivor status: married" << endl;
	else
		cout << "Survivor status: Single" << endl;
	cout << "-----------------------------------------" << endl;
}

