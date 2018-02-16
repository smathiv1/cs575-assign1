//============================================================================
// Name        : CS575_Contacts.cpp
// Author      : Sivakumar Mathivanan
// Version     :
// Copyright   : All rights reserved 2018
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<math.h>

using namespace std;

/*
 * Global variables declaration - Start
 */
struct record
{
	string sFirstName;
	string sLastName;
	string sPhone;
};
using stSingleRec = record;

// Entire records
struct directory
{
	record* m_records;
};

int total_size;

/*
 * Function display : display records.
 *
 * input : phonebook; structure with record struct as element.
 *
 * output : print all record values on console
 */
void display(directory *pDir)
{
	for(int i =  0; i < total_size; i++)
	{
		cout << " " << pDir -> m_records[i].sFirstName << " " << pDir -> m_records[i].sLastName << ", " << pDir -> m_records[i].sPhone << endl;
	}
}

/*
 * Function create : creates the directory
 *
 * input : filepath where input file is present; directory if it is already present.
 *
 * output : created/updated directory.
 */
// Read the name and contact from file and store them in structure members
void create(string sFilePath, directory *pDir)
{
	fstream inFile(sFilePath);
	string line;
	int index = 0;
	int iTmp = 0;
	string sTmp = "\0";

	while(getline(inFile, line))
	{
		// First name
		iTmp = line.find(" ");
		line = line.substr(iTmp+1);
		iTmp = line.find(" ");
		pDir -> m_records[index].sFirstName = line.substr(0, iTmp);
		sTmp = line.substr(iTmp + 1);
		//cout << "pDir -> m_records[index].sFirstName - " << pDir -> m_records[index].sFirstName << endl;

		// Last name
		iTmp = sTmp.find(",");
		pDir -> m_records[index].sLastName = sTmp.substr(0, iTmp);
		sTmp = sTmp.substr(iTmp + 2);
		//cout << "pDir -> m_records[index].sLastName - " << pDir -> m_records[index].sLastName << endl;

		// Phone number
		pDir -> m_records[index].sPhone = sTmp;
		//cout << "pDir -> m_records[index].sPhone - " << pDir -> m_records[index].sPhone << endl;

		index++;
	}

}

void merge(directory *pDir, int left, int middle, int right)
{
	int l_size = middle - left + 1;
	int r_size = right - middle;
	int i1 = 0;
	int i2 = 0;


	directory dLeft;
	directory dRight;

	dLeft.m_records = new record[l_size];
	dRight.m_records = new record[r_size];

	// Storing elements less than middle in newly created array
	for(int i = 0; i < l_size; i++)
	{
		dLeft.m_records[i].sFirstName = pDir -> m_records[left + i].sFirstName;
		dLeft.m_records[i].sLastName = pDir -> m_records[left + i].sLastName;
		dLeft.m_records[i].sPhone = pDir -> m_records[left + i].sPhone;
	}

	// Storing elements greater than middle in newly created array
	for(int i = 0; i < r_size; i++)
	{
		dRight.m_records[i].sFirstName = pDir -> m_records[middle + 1 + i].sFirstName;
		dRight.m_records[i].sLastName = pDir -> m_records[middle + 1 + i].sLastName;
		dRight.m_records[i].sPhone = pDir -> m_records[middle + 1 + i].sPhone;
	}

	// Merge sort core algorithm
	int i = left;
	while ((i1 < l_size) && (i2 < r_size))
	{
		if (dLeft.m_records[i1].sLastName <= dRight.m_records[i2].sLastName)
		{
			if(dLeft.m_records[i1].sLastName == dRight.m_records[i2].sLastName){
				cout<<"Last Names are equal, merge sorting by first name"<<endl;
				cout<<"Phone number in LHS in first if condition= "<<dLeft.m_records[i1].sPhone<<endl;
				cout<<"Phone number in RHS in first if condition= "<<dRight.m_records[i2].sPhone<<endl;
				if(dLeft.m_records[i1].sFirstName <= dRight.m_records[i2].sFirstName)
				{
					if(dLeft.m_records[i1].sFirstName == dRight.m_records[i2].sFirstName){
						cout<<"Both First names and last names are equal!"<<endl;
						cout<<"Phone number in LHS in second if condition= "<<dLeft.m_records[i1].sPhone<<endl;
						cout<<"Phone number in RHS in second if condition= "<<dRight.m_records[i2].sPhone<<endl;//value in if condition is checked here.
						//call randomized quick sort for both strings.
					}
					pDir -> m_records[i].sFirstName = dLeft.m_records[i1].sFirstName;
					pDir -> m_records[i].sPhone = dLeft.m_records[i1].sPhone;
				}
				else{
					pDir -> m_records[i].sFirstName = dRight.m_records[i1].sFirstName;
					pDir -> m_records[i].sPhone = dRight.m_records[i1].sPhone;
				}
			}
			pDir -> m_records[i].sLastName = dLeft.m_records[i1].sLastName;
			pDir -> m_records[i].sFirstName = dLeft.m_records[i1].sFirstName;
			pDir -> m_records[i].sPhone = dLeft.m_records[i1].sPhone;
			i1++;

			cout<< "i1 ="<<i1<<endl;
			cout<<"pDir -> m_records[i].sLastName "<<pDir -> m_records[i].sLastName<<endl;
			cout<<"pDir -> m_records[i].sFirstName "<<pDir -> m_records[i].sFirstName<<endl;
			cout<<"pDir -> m_records[i].sPhone "<<pDir -> m_records[i].sPhone<<endl;
		}
		else
		{
			pDir -> m_records[i].sLastName = dRight.m_records[i2].sLastName;
			pDir -> m_records[i].sFirstName = dRight.m_records[i2].sFirstName;
			pDir -> m_records[i].sPhone = dRight.m_records[i2].sPhone;
			i2++;

			cout<< "i2 ="<<i2<<endl;
			cout<<"pDir -> m_records[i].sLastName "<<pDir -> m_records[i].sLastName<<endl;
			cout<<"pDir -> m_records[i].sFirstName "<<pDir -> m_records[i].sFirstName<<endl;
			cout<<"pDir -> m_records[i].sPhone "<<pDir -> m_records[i].sPhone<<endl;
		}
		i++;
	}

	while (i1 < l_size)
	{
		pDir -> m_records[i].sLastName = dLeft.m_records[i1].sLastName;
		pDir -> m_records[i].sFirstName = dLeft.m_records[i1].sFirstName;
		pDir -> m_records[i].sPhone = dLeft.m_records[i1].sPhone;
		i1++;
		i++;
	}

	while (i2 < r_size)
	{
		pDir -> m_records[i].sLastName = dRight.m_records[i2].sLastName;
		pDir -> m_records[i].sFirstName = dRight.m_records[i2].sFirstName;
		pDir -> m_records[i].sPhone = dRight.m_records[i2].sPhone;
		i2++;
		i++;
	}

}

/*
 * function	:	sortDirectory
 *
 * Inputs	:	directory Pointer, first record, last record
 *
 * Output	:	void
 */
void sortDirectory(directory *pDir, int left, int right)
{
	int middle = floor((left + right) / 2);

	if (left < right)
	{
		/*
		 * dividing dir into single elements.
		 */
		sortDirectory(pDir, left, middle);
		sortDirectory(pDir, (middle + 1), right);

		merge(pDir, left, middle, right);
		display(pDir);
		cout << endl << endl;
	}
}

int searchDirectory(directory *pDir, string lname, int case_num)
{
	int left = 0;
	int right = total_size - 1;
	int middle = 0;
	int iLoc = 0;

	cout << "Passed lastName = "<<lname<<endl;
	cout << "total_size = "<<total_size<<endl;
	cout << "left = "<<left<<endl;
	cout << "right = "<<right<<endl;

	while(left <= right)
	{
		middle = floor((left + right)/2);
		cout<<"middle in while = "<<middle<<endl;
		if (lname == pDir -> m_records[middle].sLastName)
		{
			iLoc = middle;
			cout<<"iLoc = "<<iLoc<<endl;
			break;
		}
		else if (pDir -> m_records[middle].sLastName < lname)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
		cout << "Left - " << left << "; Right - " << right << endl;
	}

	if (0 == iLoc)
	{
		switch(case_num)
		{
			case 0:
			{
				cout << "Name not found" << endl;
				break;
			}
			case 1:
			{
				return middle;
				break;
			}
			default:
			{
				cout << "In default switch" << endl;
			}
		}
	}
	else
	{
		int iLeft = iLoc;
		int iRight = iLoc;

		cout << "iLoc - " << iLoc<<endl;

		while (1)
		{
			iLeft--;
			if((lname ==pDir -> m_records[iLeft].sLastName) && iLeft > 0)
			{
				continue;
			}
			else
			{
				break;
			}
			cout << iLeft << endl;
		}

		while (1)
		{
			iRight++;
			if((lname == pDir -> m_records[iRight].sLastName) && iRight < total_size)
			{
				continue;
			}
			else
			{
				break;
			}
			cout << iRight << endl;
		}


		for (int i = iLeft + 1; i <= iRight - 1; i++)
		{
			cout << "Found at " << i + 1 << endl;
			cout << "Name - " << pDir -> m_records[i].sFirstName << " " << pDir -> m_records[i].sLastName << ", " << pDir -> m_records[i].sPhone << endl;
		}
		return 1;
	}

}

record* insertEntry(directory *pDir, string entry)
{
	string sFirstName, sLastName, sPhone;
	int iTmp;
	string sTmp;

	iTmp = entry.find(" ");
	sFirstName = entry.substr(0, iTmp);
	sTmp = entry.substr(iTmp + 1);

	// Extracting and storing last name
	iTmp = sTmp.find(",");
	sLastName = sTmp.substr(0, iTmp);
	sTmp = sTmp.substr(iTmp + 2);

	// Extracting and storing contact
	sPhone = sTmp;

	cout<< "FirstName = "<<sFirstName<<"LastName = "<<sLastName<<" Phone = "<<sPhone<<endl;
	exit(1);

	int iEntryLoc = searchDirectory(pDir, sLastName, 1);
	cout << "iLoc - " << iEntryLoc << endl;

	directory dUpdDir;
	cout << "Total_size = "<<total_size <<endl;
	total_size++;
	dUpdDir.m_records = new record[total_size];

	for (int i = 0; i < total_size; i++)
	{
		if (i == iEntryLoc)
		{
			dUpdDir.m_records[i].sLastName = sLastName;
			dUpdDir.m_records[i].sFirstName = sFirstName;
			dUpdDir.m_records[i].sPhone = sPhone;
		}
		else if (i < iEntryLoc)
		{
			dUpdDir.m_records[i].sLastName = pDir -> m_records[i].sLastName;
			dUpdDir.m_records[i].sFirstName = pDir -> m_records[i].sFirstName;
			dUpdDir.m_records[i].sPhone = pDir -> m_records[i].sPhone;
		}
		else
		{
			dUpdDir.m_records[i].sLastName = pDir -> m_records[i - 1].sLastName;
			dUpdDir.m_records[i].sFirstName = pDir -> m_records[i - 1].sFirstName;
			dUpdDir.m_records[i].sPhone = pDir -> m_records[i - 1].sPhone;
		}
	}

	//free(&pDir -> m_records);
	pDir -> m_records = dUpdDir.m_records;
	return pDir -> m_records;

}

int main(int argc, char* argv[])
{
	directory dirPhoneBook;
	string sInputData,line;

	int total_lines = 0;
	fstream inFile;
	int iOption;
	bool isExit = false;
	string search_name;
	string new_entry;

	for (int i = 1; i < argc; i++)
	{
		sInputData += argv[i];
		//cout << sInputData << endl;
	}


	goto file_read_skip;

	// Goto command for wrong input file name
	file_read:
	cout << "Enter the file name to read from: ";
	cin >> sInputData;

	file_read_skip:
	inFile.open(sInputData);

	while(getline(inFile,line))
	{
		total_lines++;
	}
	inFile.close();

	dirPhoneBook.m_records = new record[total_lines];	// Dynamic records allocation

	if (total_lines > 0)	// Proper input file calls the create function
	{
		total_size = total_lines;
		create(sInputData, &dirPhoneBook); 	// Adding individual records to the array
		sortDirectory(&dirPhoneBook, 0, (total_lines-1));	// Merge sort
	}
	else	// Throws error and requests new entry for file name
	{
		cout << "Input file is either empty or wrong file name" << endl;
		goto file_read;
	}

	while(!isExit)
	{
		cout << endl;
		wrong_input:
		cout << "Please provide options: " << endl;
		cout << "Insert\t\t(press 1)" << endl << "Search\t\t(press 2)" << endl << "Delete\t\t(press 3)" << endl << "Show Directory\t(press 4)" << endl << "Exit (press 5)" << endl;
		cin >> iOption;
		switch(iOption)
		{
			case 1:
			{
				cout << "Enter the name of the person - (FirstName LastName, Phone Number) - ";
				cin >> new_entry;
				dirPhoneBook.m_records = insertEntry(&dirPhoneBook, new_entry);
				break;
			}
			case 2:
			{
				cout << "Enter the last name to search - ";
				cin >> search_name;
				searchDirectory(&dirPhoneBook, search_name, 0);
				break;
			}
			case 3:
			{
				break;
			}
			case 4:
			{
				// Printing individual record info. Mostly to be pushed into another function in future
				display(&dirPhoneBook);
				break;
			}
			case 5:
			{
				isExit = true;
				break;
			}
			default:
			{
				cout << endl << "Enter only from the given options" << endl;
				goto wrong_input;
				break;
			}
		}
	}
	return 0;
}
