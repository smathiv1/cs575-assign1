//============================================================================
// Name        : CS575_Contacts.cpp
// Author      : Sivakumar Mathivanan
// Version     :
// Copyright   : All rights reserved 2018
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct sDirEntry{
	int iIndex;
	string sFirstName;
	string sLastName;
	string sPhoneNumber;
};
using sDirRecord=sDirEntry;
/*
 * Function Prototype Declarations
 */
void createDirectory(char*);
void sortDirectory();
void searchDirectory(char*);
void deleteEntry(char*);
void insertEntry(char*, char*);

void createDirectory(char*){
	/*
	 * TODO reading input.csv file using inputFileStream.
	 * As of now, added hard-coded inputs for testing purposes.
	 *
	 */
	string line;
	ifstream inFile ("input.csv");
	if (inFile.is_open())
	{
		while ( getline (inFile,line) )
		{
			cout << line << '\n';
		}
		inFile.close();
	}

	else cout << "Unable to open file";
}
int main() {
	int iOption = 1;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "Creating the phone directory.." << endl;

	void createDirectory();

	while(0 != iOption){
		cout << "Please provide an option" <<endl;
		cout << "Insert\t\t(press 1)"<<endl;
		cout << "Search\t\t(press 2)"<<endl;
		cout << "Delete\t\t(press 3)"<<endl;
		cout << "Show Directory\t(press 4)"<<endl;
		cin >> iOption;
		switch(iOption){
		case 1:
			cout << "Insert" << endl;
			continue;
		case 2:
			cout << "Search" << endl;
			continue;
		case 3:
			cout << "Delete" << endl;
			continue;
		case 4:
			cout << "Show Directory" << endl;
			continue;
		default:
			cout << "Enter a valid option! Exiting" <<endl;
			exit(1);
		}
	}

	return 0;
}

/*
void createDirectory(char* filePath​){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("/etc/motd", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		printf("Retrieved line of length %zu :\n", read);
		printf("%s", line);
	}

	fclose(fp);
	if (line)
		free(line);

}

void sortDirectory(){

}

void searchDirectory(char* name)​{

}

void deleteEntry(char* name){

}

void insertEntry(char* name, char* phone_number){

}
*/
