//Stephen Chassie
#ifndef TABLE_H
#define TABLE_H

#include "FileSystem.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Table is for a data file to be read in, flat and index files are created, then they are used as a record
//where user inputs a year and the information pertaining to that year is printed to the screen.
class Table : public Filesys
{
	public:
		Table(string diskname, int blocksize, int numberofblocks, string flatfile, string indexfile);
		int buildTable(string input_file);
		int search(string value);
	private:
		string flatfile;
		string indexfile;
		int numberofrecords;
		int indexSearch(string value);
};
#endif

