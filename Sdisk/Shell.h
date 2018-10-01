//Stephen Chassie
#ifndef SHELL_H
#define SHELL_H

#include "FileSystem.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Setup for personalized shell for the user to use the File System and Sdisk
class Shell : public Filesys
{
	public:
		Shell(string filename, int blocksize, int numberofblocks);
		int dir();// lists all files
		int add(string file);// add a new file using input from the keyboard
		int del(string file);// deletes the file
		int type(string file);//lists the contents of file
		int copy(string file1, string file2);//copies file1 to file2
};
#endif
