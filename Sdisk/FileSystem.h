//Stephen Chassie
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Sdisk.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
//Setup for the File System Class
class Filesys : public Sdisk
{
	public:
		Filesys(string diskname, int numberofblocks, int blocksize);
		int fsclose();
		int fssynch();
		int newfile(string file);
		int rmfile(string file);
		int getfirstblock(string file);
		int addblock(string file, string block);
		int delblock(string file, int blocknumber);
		int readblock(string file, int blocknumber, string& buffer);
		int writeblock(string file, int blocknumber, string buffer);
		int nextblock(string file, int blocknumber);
		vector<string> ls();
	private:
		int rootsize;           // maximum number of entries in ROOT
		int fatsize;            // number of blocks occupied by FAT
		vector<string> filename;   // filenames in ROOT
		vector<int> firstblock; // firstblocks in ROOT
		vector<int> fat;             // FAT
		bool checkblock(int bnum, string file);
};

vector<string> block(string buffer, int b);
#endif
