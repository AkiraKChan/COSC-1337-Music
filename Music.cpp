#include "Music.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

//constructors
Music::Music()
{
}

Music::Music(string Name, string Album, string Artist, int sec, string LastUsed)
{
	setName(Name);
	setAlbum(Album);
	setArtist(Artist);
	setDur(sec);
	setUsed(LastUsed);
}

string Music::getDuration()
{
	string times = "";
	times += to_string(DurMin);
	times += ":";
	if (DurS < 10)
		times += "0";
	times += to_string(DurS);
	return times;
}

void Music::setDur(int sec)
{
	DurMin = sec / 60;
	DurS = sec % 60;
}

void Music::setUsed()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	LastUsed = to_string(now->tm_mon + 1) + "/";
	LastUsed += to_string(now->tm_mday);
	LastUsed += "/";
	LastUsed += to_string(now->tm_year + 1900);
}

Music::~Music()
{
}
