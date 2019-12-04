#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Music.h"
using namespace std;

class DataBase
{
private:

	//Sets pointer to an array of music objects
	Music * music;

	//Sets the default size of the array to 10
	int size = 10;

	//Counter of the current number of songs in the array
	int SongCount = 0;

public:

	//functions for the bellow prototypes are in Playlist.cpp

	void addMusic();

	void viewDataBase();

	void findSName(string mus);//function to find a song by name 

	void findAName(string alb);//function to find a song by album

	void findArName(string name);//function to find a song by artist

	void resize();
	
	//File Stuff


	void addSong(ifstream &musicFile);

	void dumpSong(ofstream &dumpFile);

	static void doSpace(string &l);

	static void undoSpace(string &l);

	// Other Stuff

	int getSize() { return size; }

	int getcount() { return SongCount; }

	void sortSongs();

	void sortAlbums();

	void sortArtists();

	void sortLength();

	void swap(Music &mu1, Music &mu2);//function to swap songs

	DataBase();

	DataBase(Music song) {
		music = new Music[10];
		music[SongCount] = song;
		SongCount++;
	}

	~DataBase();
};

