# Person Database :busts_in_silhouette:

This program allows you to manage a database of persons. You can add new persons, view existing persons, save the database to a file, load the database from a file, search for persons by index, and delete persons from the database. :card_file_box:

## Prerequisites :memo:

To run this program, you need to have a C++ compiler installed on your system. The program uses standard C++ libraries and does not require any additional dependencies. :gear:

## Usage :computer:

1. Compile the program using a C++ compiler. For example, you can use the following command with `g++`: :hammer_and_wrench:

```bash
g++ -o persondb main.cpp
```
2. Run the compiled program: :arrow_forward:
```bash
./persondb
```
3. Follow the menu options to perform various operations on the person database. :clipboard:

## Menu Options :bookmark_tabs:
The program provides the following menu options:

1. Add person: Allows you to add a new person to the database. You need to provide the person's name, surname, age, and phone number. :heavy_plus_sign:

2. Show persons: Displays all the persons in the database. It shows the person's index, name, surname, age, and phone number. :eyes:

3. Save Database to file: Saves the current state of the person database to a file named dataBase.txt. :floppy_disk:

4. Load Database from file: Loads the person database from the dataBase.txt file. Any existing data in the database will be replaced. :inbox_tray:

5. Search Database from database buffer: Displays person of choosen index.

6. Delete person from database: Allows you to delete a person from the database based on their index. You need to provide the index of the person you want to delete. :x:

## Data Storage :file_folder:
The person database is stored in memory using a vector of Person objects. Each Person object contains the following information:

ID: An automatically assigned unique identifier for the person.
Name: The person's name.
Surname: The person's surname.
Age: The person's age.
Phone number: The person's phone number.
## File Storage :floppy_disk:
The person database can be saved to and loaded from a file named dataBase.txt. The file format is as follows:
```cpp
<number of persons>
<name>
<surname>
<age>
<phone number>
```
Each person's information is stored sequentially, with each field on a separate line. The number of persons in the database is stored at the beginning of the file.

## Note :information_source:
The program uses the ```system("clear")``` command to clear the console screen. This command is specific to Unix-like systems. If you are running the program on Windows, you need to change it to ```system("cls")``` in the code.
When deleting a person, the program saves the updated database to the file automatically.
The program expects the database file to be present in the same directory as the program executable. If the file is not found, an error message will be displayed.
Feel free to modify and extend this program according to your needs. :hammer_and_wrench:
