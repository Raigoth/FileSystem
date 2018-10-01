//Stephen Chassie
#include <iostream>
#include <string>
#include "FileSystem.h"
#include "Sdisk.h"
#include "Shell.h"
//would also include the #include "Table.h" if we wanted to turn it into a record system

using namespace std;

int main()
{
	//disk name, blocksize, number of blocks
	Shell shell("disk1", 256, 128);
	
	string s;
	string command = "go";
	string op1, op2;
	//creates a shell for the user to input commands until they decide to type "quit"
	while (command != "quit")
	{
		command.clear();
		op1.clear();
		op2.clear();
		cout << "$";
		getline(cin, s);
		int firstblank = s.find(' ');
		if (firstblank < s.length()) s[firstblank] = '#';
		int secondblank = s.find(' ');
		command = s.substr(0, firstblank);
		if (firstblank < s.length())
		{
			op1 = s.substr(firstblank + 1, secondblank - firstblank - 1);
		}
		
		if (secondblank < s.length())
		{
			op2 = s.substr(secondblank + 1);
		}

		if (command == "dir") //list files
		{
			shell.dir();
		}
		else if (command == "add") //add file and information
		{
			shell.add(op1);
			// The variable op1 is the new file
		}
		else if (command == "del") //delete file and information
		{
			shell.del(op1);
			// The variable op1 is the file
		}
		else if (command == "type") //display information inside file
		{
			shell.type(op1);
			// The variable op1 is the file
		}
		else if (command == "copy") //copy information to a different file
		{
			shell.copy(op1, op2);
			// The variable op1 is the source file and the variable op2 is the destination file.
		}
		else
		{
			cout << "Command does not exist, please try a different command." << endl;
		}
		// for record file system we would add the records command and remove the other commands.
		/*if (command == "records")
		{
			cout << "Search for a record in the database by giving a date then press enter." << endl;
			while (input != "-1")
			{
				cout << "\nWhat record has the date: ";
				cin >> input;
				table.search(input);
			}
		}*/
	}

	return 0;
}
