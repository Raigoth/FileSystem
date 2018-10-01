//Stephen Chassie
#include "Table.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
//uses a flatfile and an index file to sort through records
Table::Table(string filename, int numberofblocks, int blocksize, string flatfile, string indexfile) : Filesys(filename, numberofblocks, blocksize)
{
	this->flatfile = flatfile;
	this->indexfile = indexfile;
	cout << flatfile << " flat file " << indexfile << " index file " << endl;
	newfile(flatfile);
	newfile(indexfile);
	buildTable("data.txt");//builds table off of this data file
	return;
}

int Table::buildTable(string inputfile)
{
	string rec, key;
	int blockId;
	ostringstream ostream;	
	ifstream infile;
	infile.open(inputfile);

	getline(infile, rec);
	while (infile.good())
	{
		//gets the data file and makes sure it is there and okay to open.
		//key is then set up for the first string that is in the line.
		//blocks are then created for the information.
		//gets block id tied to the key then grabs next line until the whole file has been read.		
	}
	
	//for the end of the table so that it is marked
	ostream << "XXXXX" << " " << 0 << " ";
	string buffer1 = ostream.str();

	vector<string> blocks = block(buffer1, getblocksize());
	for (int i = 0; i < blocks.size(); i++)
	{
		//adds blocks to index file based off of the amount of blocks needed
	}
	return 1;
}

//search through the blocks on the flatfile and display the information based off of the key
int Table::search(string key)
{
	int block = indexSearch(key);
	if (block == -1)
	{
		cout << "record not found!" << endl;
		return 0;
	}
	else
	{
		string buffer;
		readblock(flatfile, block, buffer);
		cout << buffer;
	}
	return 1;
}

//gets the blocks from the index file based of the key for the information
int Table::indexSearch(string key)
{
	string buffer;
	int fblock = getfirstblock(indexfile);
	while (fblock != 0)
	{
		//gets all the information in the index file and adds it to the buffer
	}
	istringstream istream;
	istream.str(buffer);

	string k;
	int b;
	istream >> k >> b;
	//loop until last record, no more records
	while (k != "XXXXX")
	{
		if (k == key)
		{
			return b;
		}
		istream >> k >> b;
	}
	return -1;
}

