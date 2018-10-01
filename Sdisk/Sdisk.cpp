//Stephen Chassie
#include <iostream>
#include <string>
#include <fstream>
#include "Sdisk.h"

using namespace std;

Sdisk::Sdisk()
{
	diskname = diskname;
	numberofblocks = getnumberofblocks();
	blocksize = getblocksize();
}

Sdisk::Sdisk(string dName, int nOfBlocks, int bSize)
{
	diskname = dName + ".txt";
	numberofblocks = nOfBlocks;
	blocksize = bSize;
	ifstream infile;
	infile.open(diskname.c_str());

	char x = infile.get();
	if (infile.fail())
	{
		//If disk doesn't exist yet then it will fill the disk with the number of blocks
		//and how big those blocks are with '#' chars
	}
	else
	{
		//open the disk file if it exists.
	}
}

int Sdisk::getblock(int blocknumber, string& buffer)
{
	ifstream infile;
	char c;
	infile.open(diskname.c_str());
	infile.seekg(blocknumber * blocksize);
	for (int i = 0; i < blocksize; i++)
	{
		//get the everything inside the block and add it to the buffer.
	}
	infile.close();
	return 0;
}

int Sdisk::putblock(int blocknumber, string buffer)
{
	fstream iofile(diskname.c_str(), ios::in | ios::out);
	iofile.seekp(blocknumber * blocksize);
	for (int i = 0; i < blocksize; i++)
	{
		//put information inside the block from the buffer
	}
	iofile.close();
	return 0;
}

//gets number of blocks
int Sdisk::getnumberofblocks()
{
	return numberofblocks;
}

//gets blocksize
int Sdisk::getblocksize()
{
	return blocksize;
}
