#include "Tribe.h" 

Tribe::Tribe(string tribeName, int maxSurvivors) {
	this->setTribe(tribeName, maxSurvivors);
	this->printMenu();
}

void Tribe::setTribe(string tribeName, int maxSurvivors) {
	this->setTribeName(tribeName);
	this->setMaxSurvivors(maxSurvivors);
	this->setNumSurvivors(0);
	this->survivorsArray = new Survivor * [maxSurvivors];
	for (int i = 0; i < maxSurvivors; i++)
		this->survivorsArray[i] = NULL;
}

Tribe::~Tribe() {
	cout << "The Tribe " << this->tribeName << " is destroyed from address : " << this << endl;
	for (int i = 0; i < this->numSurvivors; i++)
		delete this->survivorsArray[i];
	delete[] this->survivorsArray;
}

void Tribe::printTribe() const {
	cout << "Tribe details: " << endl;
	cout << "Tribe's name: " << this->tribeName << endl;
	cout << "Tribe's capacity: " << this->maxSurvivors << endl;
	cout << "Number of survivors: " << this->numSurvivors << endl;
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < this->numSurvivors; i++) {
		cout << "Survivor number " << i+1 << ": " << endl;
		this->survivorsArray[i]->printSurvivor();
	}
}

void Tribe::addSurvivorToTribe(string name, int age, char status) {
	this->survivorsArray[this->numSurvivors] = new Survivor(name, age, status);
	this->numSurvivors++;

	cout << "A new survivor is inserted to the tribe." << endl;
}

void Tribe::removeSurvivorFromTribe(string tribeName) {
	int index = this->findSurvivorByName(tribeName);
	if (index == -1) {
		cout << "No survivor with this name, try again later...";
		return;
	}
	delete this->survivorsArray[index];
	for (int i = index; i < numSurvivors - 1; i++)
		this->survivorsArray[i] = this->survivorsArray[i + 1];
	this->survivorsArray[this->numSurvivors - 1] = NULL;
	this->numSurvivors--;
}

string Tribe::findTheYoungestSurvivor() {
	Survivor* youngestSurvivor = this->survivorsArray[0];
	for (int i = 1; i < this->numSurvivors; i++) {
		if (this->survivorsArray[i]->getAge() < youngestSurvivor->getAge()) {
			youngestSurvivor = this->survivorsArray[i];
		}
	}
	return youngestSurvivor->getName();
}

void Tribe::removeTheYoungestSurvivorFromTribe() {
	removeSurvivorFromTribe(findTheYoungestSurvivor());
}

int Tribe::findSurvivorByName(string n) {
	for (int i = 0; i < this->numSurvivors; i++) {
		if (this->survivorsArray[i]->getName() == n)
			return i;
	}
	return -1;
}

bool isValidNumber(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

int maxSurvivorsValidation() {
	char maxSurvivorsStr[10]; // נניח שהמספר לא יעלה על 10 תווים
	int maxSurvivors;

	do {
		cout << "Enter the maximum number of survivors: " << endl;
		cin >> maxSurvivorsStr;
		if (!isValidNumber(maxSurvivorsStr)) {
			cout << "Invalid input. Please enter a valid number." << endl;
		}
	} while (!isValidNumber(maxSurvivorsStr));

	return atoi(maxSurvivorsStr);
}

void Tribe::sortSurvivorsByName() {
	for (int i = 0; i < this->numSurvivors - 1; i++) {
		for (int j = 0; j < this->numSurvivors - i - 1; j ++) {
			if (this->survivorsArray[j]->getName() > this->survivorsArray[j + 1]->getName()) {
				Survivor* temp = this->survivorsArray[j];
				this->survivorsArray[j] = this->survivorsArray[j + 1];
				this->survivorsArray[j + 1] = temp; 
			}
		}
	}
}

void Tribe::printMenu() {
	while (1) {
		int choice;
		char choiceStr[1];
		string name;
		char ageStr[3]; // נניח שהמספר לא יעלה על 3 תווים
		int age;
		char status;
		int index;
		
		cout << "****************************************************" << endl;
		cout << "NENU" << endl;
		cout << "1) Print the tribe" << endl;
		cout << "2) Insert a new survivor" << endl;
		cout << "3) Remove survivor from the tribe" << endl;
		cout << "4) Find a survivor by name" << endl;
		cout << "5) Remove the youngest survivor" << endl;
		cout << "6) Sort survivors by name" << endl;
		cout << "7) Exit" << endl;
		cout << "****************************************************" << endl;

		do {
			cout << "Enter your choice: ";
			cin >> choiceStr;
			if (!isValidNumber(choiceStr)) {
				cout << "Invalid input. Please enter a valid number." << endl;
			}
		} while (!isValidNumber(choiceStr));
		choice = atoi(choiceStr);

		switch (choice) {
		case 1:
			this->printTribe();
			break;
		case 2:
			if (this->numSurvivors == this->maxSurvivors) {
				cout << "No space in the tribe for a new survivor" << endl;
				break;
			}
			cout << "Enter the name: ";
			cin >> name;
			do {
				cout << "Enter the age: ";
				cin >> ageStr;
				if (!isValidNumber(ageStr)) {
					cout << "Invalid input. Please enter a valid number." << endl;
				}
			} while (!isValidNumber(ageStr));
			age = atoi(ageStr);
			cout << "Enter the status (m for married, s for single, r for in relationship): ";
			cin >> status;
			this->addSurvivorToTribe(name, age, status);
			break;
		case 3:
			if (this->numSurvivors == 0) {
				cout << "There is no survivors to remove." << endl;
				break;
			}
			cout << "Enter the survivor's name: ";
			cin >> name;
			this->removeSurvivorFromTribe(name);
			break;
		case 4:
			cout << "Enter the name: ";
			cin >> name;
			index = this->findSurvivorByName(name);
			if (index == -1) {
				cout << "NO survivor such that." << endl;
			} else {
				cout << "Found at index: " << index << endl;
				this->survivorsArray[index]->printSurvivor();
			}
			break;
		case 5: 
			this->removeTheYoungestSurvivorFromTribe();
			break;
		case 6:
			this->sortSurvivorsByName();
			this->printTribe();
			break;
		case 7:
			cout << "Bey bey, see you again soon." << endl;
			return;
		default:
			cout << "Wrong choice, please try again." << endl;
		}
	}
}

void main() {
	string nameFirstTribe;
	string nameSecendTribe;
	int maxSurvivorsFirstTribe;
	int maxSurvivorsSecendTribe;

	cout << "Enter the name of the first tribe: " << endl;
	cin >> nameFirstTribe;
	maxSurvivorsFirstTribe = maxSurvivorsValidation();
	Tribe firstTribe(nameFirstTribe, maxSurvivorsFirstTribe);

	cout << "Enter the name of the secend tribe: " << endl;
	cin >> nameSecendTribe;
	maxSurvivorsSecendTribe = maxSurvivorsValidation();
	Tribe secendTribe(nameSecendTribe, maxSurvivorsSecendTribe);
}

