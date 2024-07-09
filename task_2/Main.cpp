#include "Tribe.h"
#include "Survivor.h"
#include <iostream>

bool isValidNumber(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

void main() {
	string name;
	char maxSurvivorsStr[10]; // נניח שהמספר לא יעלה על 10 תווים
	int maxSurvivors;

	cout << "Enter the name of the first tribe: " << endl;
	cin >> name;

	do {
		cout << "Enter the maximum number of survivors: " << endl;
		cin >> maxSurvivorsStr;
		if (!isValidNumber(maxSurvivorsStr)) {
			cout << "Invalid input. Please enter a valid number." << endl;
		}
	} while (!isValidNumber(maxSurvivorsStr));

	maxSurvivors = atoi(maxSurvivorsStr);
	Tribe firstTribe(name, maxSurvivors);
}



