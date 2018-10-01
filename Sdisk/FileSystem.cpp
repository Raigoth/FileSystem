//Stephen Chassie
#include "FileSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//Filesys Class functions
Filesys::Filesys(string diskname, int numberofblocks, int blocksize) : Sdisk(diskname, numberofblocks, blocksize)
{	
	cout << "blocksize: " << blocksize << " diskname: " << diskname << " numberofblocks: " << numberofblocks << endl;
	rootsize = //sets up the root size
	fatsize = //sets up the fat size

	string buffer;
	getblock(1, buffer);
	if(buffer[0] == '#')
	{	//need to create filesystem
		cout << "Filesystem doesn't exist" << endl;
		for (int i = 1; i <= rootsize; i++)
		{
			//sets up how many files can be input and displays them as XXXXX since files we create
			//are only going to be 5 chars long.
		}
		
		fat.push_back(fatsize+2);
		fat.push_back(1);
		for (int i = 1; i <= fatsize; i++)
		{
			fat.push_back(1);			
		}
		
		for (int i =  fatsize + 2; i < getnumberofblocks(); i++)
		{
			fat.push_back(i + 1);			
		}
		fat[getnumberofblocks() - 1] = 0;

		fssynch();
	}
	else
	{	//file system exists
		//read the file system into root and FAT so the information can be used
		cout << "Filesystem exists" << endl;
		string buffer1, buffer2, file, temp;
		int fb;

		getblock(1, buffer1);		
		for (int i = 0; i < fatsize; i++)
		{
			temp = "";
			getblock(i + 2, temp);
			buffer2 += temp;
		}

		cout << buffer2 << " is buffer2 which is the FAT" << endl;
		istringstream rstream;
		istringstream fastream;
		rstream.str(buffer1);
		fastream.str(buffer2);
		string temp1;
		int temp2;

		for (int i = 0; i < rootsize; i++)
		{
			//Gets the files and their first blocks from the Sdisk so that the user can
			//change or add information.
		}
				
		for (int i = 0; i < getnumberofblocks(); i++)
		{
			//Gets the fat blocks and information that the files have.
		}
	}
}

int Filesys::fsclose()
{
	//File System's Close
}

int Filesys::fssynch()
{
	//File System's Synch Function
	//Synchs the root and fat to the Sdisk for saving the information.	
}

int Filesys::newfile(string file)
{
	//This function allows the user to create a new file that can have information input.
	//If that named file exists it will inform user and prevent them from creating a
	//file with the same name.
	//If the there is no more room on the Sdisk then it will inform user and let them
	//no the disk is full.	
}

int Filesys::rmfile(string file)
{
	//This function allows the user to remove a file requested as long as that file is 
	//on the disk or else it will notify user that the file does not exist.	
}

int Filesys::getfirstblock(string file)
{
	//This function gets the first block of the requested file unless the requested file
	//does not exist.
}

bool Filesys::checkblock(int bnum, string file)
{
	//This function checks the blocks to see if it is empty or not.	
}

int Filesys::addblock(string file, string block)
{
	//This function allows user to input information into blocks until full or has reached the amount
	//of space required. Once it is done it will synch to the disk.	
}

int Filesys::delblock(string file, int blocknumber)
{
	//This function allows user to delete blocks of information in files unless there is not information
	//in the block requested. If the block is not empty it will remove the block and then it will update
	//the freelist so the block can be reused and synch to disk.	
}

int Filesys::readblock(string file, int blocknumber, string& buffer)
{
	//This function will read the block and the information in it.
	if (!(checkblock(blocknumber, file)))
	{
		cout << "Can't read block: " << blocknumber << " in file: " << file << endl;
		return 0;
	}
	else
	{
		getblock(blocknumber, buffer);
	}
	return 1;
}

int Filesys::writeblock(string file, int blocknumber, string buffer)
{
	//This function will write to the block the information input.
	if (!(checkblock(blocknumber, file)))
	{
		cout << "Can't write block: " << blocknumber << " in file: " << file << endl;
		return 0;
	}
	else
	{
		putblock(blocknumber, buffer);
	}
	return 1;
}

int Filesys::nextblock(string file, int blocknumber)
{
	//This function gets the next block
	int nblock = 0;
	if (!(checkblock(blocknumber, file)))
	{
		cout << "Can't find next block: " << blocknumber << " in file: " << file << endl;
		return 0;
	}
	else
	{
		nblock = fat[blocknumber];
	}
	return nblock;
}

vector<string> Filesys::ls()
{
	//This function will get all the files
	vector<string> flist;
	for (int i = 0; i < filename.size(); i++)
	{
		if (filename[i] != "XXXXX")
		{
			flist.push_back(filename[i]);
		}
	}
	return flist;
}

vector<string> block(string buffer, int b)
{
	//This function contains the number of blocks along with how they are setup and read.
	//Block size in the snippets is 258 and the number of blocks is 128.
	vector<string> blocks;
	int numberofblocks = 0;

	if (buffer.length() % b == 0)
	{
		numberofblocks = buffer.length() / b;
	}
	else
	{
		numberofblocks = (buffer.length() / b) + 1;
	}

	string tempblock;
	for (int i = 0; i<numberofblocks; i++)
	{
		tempblock = buffer.substr(b*i, b);
		blocks.push_back(tempblock);
	}

	int lastblock = blocks.size()- 1;
	for (int i = blocks[lastblock].length(); i<b; i++)
	{
		blocks[lastblock] += "#";
	}

	return blocks;
}
