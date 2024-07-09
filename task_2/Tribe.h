#pragma once
#include "Survivor.h"
class Tribe {
private:
	string tribeName;
	int maxSurvivors;
	int numSurvivors;
	Survivor** survivorsArray; // מערך של מצביעים זה **

public:
	//getters:
	string getName() const { return this->tribeName; }
	int getMaxSurvivers() const { return this->maxSurvivors; }
	char getNumSurvivors() const { return this->numSurvivors; }
	Survivor** getSurvivorsArray() const { return this->survivorsArray; }

	//Setters:
	void setTribeName(string n) { this->tribeName = n; }
	void setMaxSurvivors(int max) { this->maxSurvivors = max; }
	void setNumSurvivors(int num) { this->numSurvivors = num; }
	
	void setTribe(string tribeName, int maxSurvivor);

	Tribe(string tribeName = "Unknown", int maxSurvivor = 0);
	~Tribe();

	void printMenu();
	void printTribe() const;
	void addSurvivorToTribe(string name, int age, char status);
	void removeSurvivorFromTribe(string tribeName);
	int findSurvivorByName(string n);
};