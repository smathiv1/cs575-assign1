//============================================================================
// Name        : CS575_Contacts.cpp
// Author      : Sivakumar Mathivanan
// Version     :
// Copyright   : All rights reserved 2018
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
 * Function Prototype Declarations
 */
void createDirectory(char*);
void sortDirectory();
void searchDirectory(char*);
void deleteEntry(char*);
void insertEntry(char*, char*);

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

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
