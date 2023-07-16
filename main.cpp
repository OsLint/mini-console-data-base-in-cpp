#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
    int id;
    string name;
    string surname;
    short age;
    string phoneNumber;
};

int personCounter = 0;
vector<Person> persons;

void requireEnter();
void addPerson();
void showPersons();
void saveFile();
void loadFile();
void searchDataBase();
void deletePerson();

int main() {


    char choice;
    do {

        cout << "Data Base has: " << personCounter << " persons saved." << endl;
        cout << "Menu:" << endl;
        cout << "1. Add person." << endl;
        cout << "2. Show persons." << endl;
        cout << "3. Save Data base to file." << endl;
        cout << "4. Load Data base from file." << endl;
        cout << "5. Delete person from data base." << endl;

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                addPerson();
                break;
            case '2':
                showPersons();
                break;
            case '3':
                saveFile();
                break;
            case '4':
                loadFile();
                break;
            case '5' :
                searchDataBase();
                break;
            case '6':
                 deletePerson();
                break;

        }
        requireEnter();
        system("clear"); // change to "cls" on windows
    } while (choice != 27);


    return 0;
}

void requireEnter() {
    cout << "Press Enter to continue. " << endl;
    cin.ignore();
}


void addPerson() {

    Person newPerson;

    newPerson.id = personCounter;

    cout << "Enter Name: ";
    cin >> newPerson.name;
    cout << "Enter surname: ";
    cin >> newPerson.surname;
    cout << "Enter Age: ";
    cin >> newPerson.age;
    cout << "Enter phone number: ";
    cin >> newPerson.phoneNumber;

    cout << "Added new person." << endl;

    persons.push_back(newPerson);

    personCounter++;
}

void showPersons() {
    if (personCounter != 0) {
        for (int i = 0; i < personCounter; ++i) {
            cout << "Person index: " << persons[i].id << endl;
            cout << "Person name: " << persons[i].name << endl;
            cout << "Person surname: " << persons[i].surname << endl;
            cout << "Person age: " << persons[i].age << endl;
            cout << "Person phone number: " << persons[i].phoneNumber << endl << endl;
        }
    } else {
        cout << "Data Base is Empty." << endl;
    }
}

void saveFile() {
    ofstream file("dataBase.txt");

    if (file.is_open()) {
        if(personCounter > 0){
            file << personCounter << endl;
            for (int i = 0; i < personCounter; ++i) {
                file << persons[i].name << endl;
                file << persons[i].surname << endl;
                file << persons[i].age << endl;
                file << persons[i].phoneNumber << endl;
            }
            cout << "File saved" << endl;
        }else {
            cout << "Data base is empty file not saved" << endl;
        }

        file.close();
    } else {
        cout << "File not opened properly." << endl;
    }


}

void loadFile(){
    ifstream  file("dataBase.txt");

    if(file.is_open()){

        file >> personCounter;

        for (int i = 0; i < personCounter; ++i) {
            Person newPerson;
            newPerson.id = personCounter;
            file >> newPerson.name;
            file >> newPerson.surname;
            file >> newPerson.age;
            file >> newPerson.phoneNumber;
            persons.push_back(newPerson);
            personCounter++;
        }


        file.close();
    }else {
        cout << "File not opened properly." << endl;
    }

}

void searchDataBase() {
    if (personCounter != 0) {
        int id;
        cout << "Enter Index of person: " << endl;
        cin >> id;


        for (int i = 0; i < personCounter; ++i) {
            if(persons[i].id == id){
                cout << "Person index: " << persons[i].id << endl;
                cout << "Person name: " << persons[i].name << endl;
                cout << "Person surname: " << persons[i].surname << endl;
                cout << "Person age: " << persons[i].age << endl;
                cout << "Person phone number: " << persons[i].phoneNumber << endl << endl;
            }
        }
    }else {
        cout << "Data Base is Empty." << endl;
    }
}

void deletePerson(){
    if (personCounter != 0) {
        short index;

        cout << "Enter index of person: ";
        cin >> index;

        if (index >= 0 && index < personCounter) {
            persons.erase(persons.begin() + index);
            personCounter--;

            saveFile();
            cout << "Person of index: " << index << " was deleted." << endl;
        } else {
            cout << "Invalid index." << endl;
        }
    } else {
        cout << "Data base is empty." << endl;
    }
}