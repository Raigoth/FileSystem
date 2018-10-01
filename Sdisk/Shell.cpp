//Stephen Chassie
#include "Shell.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
//setup shell, filesystem, and Sdisk
Shell::Shell(string filename, int blocksize, int numberofblocks) : Filesys(filename, blocksize, numberofblocks)
{
	return;
}

int Shell::dir()// lists all files
{
	vector<string> flist = ls();
	for (int i = 0; i < flist.size(); i++)
	{
		cout << i+1 << ": " << flist[i] << endl;
	}
	return 1;
}

int Shell::add(string file)// add a new file using input from the keyboard
{
	int check = newfile(file);	
	if (check == 0)
	{
		cout << "Can not add file: " << file << endl;
		return 0;
	}	
	string buffer;
	vector<string> blocks;
	getline(cin, buffer);
	blocks = block(buffer, getblocksize());	
	for (int i = 0; i < blocks.size(); i++)
	{
		addblock(file, blocks[i]);
	}
	return 1;
}

int Shell::del(string file)// deletes the file
{
	int fblock = getfirstblock(file);	
	if(fblock == -1)
	{
		cout << "Can not delete file: " << file << endl;
		return 0;
	}
	while(fblock != 0)
	{
		int next = nextblock(file, fblock);
		delblock(file, fblock);
		fblock = next;
	}
	rmfile(file);
	cout << "Deleted file: " << file << endl;
	return 1;
}

int Shell::type(string file)//lists the contents of file
{
	string buffer;
	int fblock = getfirstblock(file);
	if (fblock == -1)
	{
		cout << "File: " << file << " does not exist" << endl;
		return 0;
	}
	while (fblock != 0)
	{
		string tbuffer;
		readblock(file, fblock, tbuffer);
		buffer += tbuffer;
		fblock = nextblock(file, fblock);
	}
	cout << "File: " << file << " contains: \n" << buffer << "\n" << buffer.length() << endl;
	return 1;
}

int Shell::copy(string file1, string file2)//copies file1 to file2
{
	int fblock = getfirstblock(file1);
	if (fblock == -1)
	{
		cout << "No such file: " << file1 << endl;
		return 0;
	}
	newfile(file2);
	while (fblock != 0)
	{
		string buffer;
		readblock(file1, fblock, buffer);
		addblock(file2, buffer);
		fblock = nextblock(file1, fblock);
	}
	return 1;
}
