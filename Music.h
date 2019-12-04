#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class Music
{
private:

	//Name of the song
	string Name;

	//Album of the song
	string Album;

	//Artist of the song
	string Artist;

	//Duration of the song
	int DurMin, DurS;

	//Stores the date of when the song was last used
	string LastUsed;

public:

	//Constructor
	Music();

	Music(string Name, string Album, string Artist, int sec, string LastUsed);

	//Gets and Sets

	////Name
	string getName() { return Name; }
	void setName(string Name) { this->Name = Name; }

	////Album
	string getAlbum() { return Album; }
	void setAlbum(string Album) { this->Album = Album; }

	////Artist
	string getArtist() { return Artist; }
	void setArtist(string Artist) { this->Artist = Artist; }

	////Duration
	string getDuration();
	void setDur(int sec);

	////LastUsed
	string getUsed() { return LastUsed; }
	void setUsed();
	void setUsed(string LastUsed) { this->LastUsed = LastUsed; }

	//Destructor
	~Music();
};