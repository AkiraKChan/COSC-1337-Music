#include "DataBase.h"
#include "Music.h"
#include <iostream>
#include <ios>
#include <string>
#include <fstream>
using namespace std;

void DataBase::addMusic()
{
	if (size == SongCount)
		resize();
	//temporary variables to fill in
	string temp = "";
	int sec = 0;

	cout << "Please enter the name of the song:" << endl;
	getline(cin, temp);
	music[SongCount].setName(temp);//setting the song name

	cout << "Enter the name of the album for this song" << endl;
	getline(cin, temp);
	music[SongCount].setAlbum(temp);//setting the album name

	cout << "Now enter the artist's name:" << endl;
	getline(cin, temp);
	music[SongCount].setArtist(temp);//setting the artist names

	cout << "Enter how long (in seconds) this song is" << endl;
	cin >> sec;
	music[SongCount].setDur(sec);//setting the duration of the song in secconds
	cin.ignore();
	if (!cin) {
		cin.clear();
		cin.ignore(100000000, '\n');
		music[SongCount].setDur(0);
	}
	cout << endl << endl;
	music[SongCount].setUsed();//passively setting when the song is used

	SongCount++;//adding to the song count
}

void DataBase::viewDataBase()
{
	for (int i = 0; i < SongCount; i++)
	{//for loop to view the songs and their information
		cout << "Song: " << music[i].getName() << endl;
		cout << "By " << music[i].getArtist() << endl;
		cout << "From the album " << music[i].getAlbum() << endl;
		cout << "With duration " << music[i].getDuration() << endl;
		cout << "And it was last used " << music[i].getUsed() << endl << endl;
	}
}

void DataBase::resize()
{
	Music *newMusic = new Music[size * 2];

	for (int j = 0; j < size; j++)
	{
		newMusic[j] = music[j];
	}
	size = size * 2;

	delete[] music;
	music = newMusic;
}

void DataBase::addSong(ifstream & musicFile)
{
	while (!musicFile.eof()) {
		if (SongCount != size) {
			
			string Name, Album, Artist, LastUsed;
			int sec;

			musicFile >> Name;
			doSpace(Name);
			music[SongCount].setName(Name);
			musicFile >> Album;
			doSpace(Album);
			music[SongCount].setAlbum(Album);
			musicFile >> Artist;
			doSpace(Artist);
			music[SongCount].setArtist(Artist);
			musicFile >> sec;
			music[SongCount].setDur(sec);
			musicFile >> LastUsed;
			music[SongCount].setUsed(LastUsed);
			SongCount++;
		}
		else
			resize();
	}
}

void DataBase::dumpSong(ofstream & dumpFile)
{
	for (int i = 0; i < SongCount; i++)
	{
		//undoSpace(music[i].getName());
		//dumpFile << music[i].getName();
	}
}

void DataBase::doSpace(string & l)
{
	for (int i = 0; i < l.length(); i++) {
		if (l[i] == '_')
			l[i] = ' ';
	}
}

void DataBase::undoSpace(string & l)
{
	for (int i = 0; i < l.length(); i++) {
		if (l[i] == ' ')
			l[i] = '_';
	}
}

void DataBase::findSName(string mus)//search by song name
{
	string target = mus;//a temp string for the substring search
	for (int index = 0; index < SongCount; index++)//for loop to check the entire array
	{
		if (music[index].getName().substr(0, target.length()) == mus)
		{
			cout << music[index].getName() << " by " << music[index].getArtist() << " from the album: " << music[index].getAlbum() << endl;
			cout << "Duration: " << music[index].getDuration() << ". Last Used: " << music[index].getUsed() << endl << endl;
		}

		else//if the song name is not found
			cout << "This song could not be found" << endl;

	}
}

void DataBase::findAName(string alb)//search by album name
{
	string target = alb;
	for (int index = 0; index < SongCount; index++)
	{
		if (music[index].getAlbum().substr(0, target.length()) == alb)
		{
			cout << music[index].getName() << " by " << music[index].getArtist() << " from the album: " << music[index].getAlbum() << endl;
			cout << "Duration: " << music[index].getDuration() << ". Last Used: " << music[index].getUsed() << endl << endl;
		}
		else//in case the album is not found
			cout << "This album could not be found" << endl;
	}
}

void DataBase::findArName(string nam)//find by artist name
{
	string target = nam;
	for (int index = 0; index < SongCount; index++)
	{
		if (music[index].getArtist().substr(0, target.length()) == nam)
		{
			cout << music[index].getName() << " by " << music[index].getArtist() << " from the album: " << music[index].getAlbum() << endl;
			cout << "Duration: " << music[index].getDuration() << ". Last Used: " << music[index].getUsed() << endl << endl;
		}
		else//in case the artist is not found
			cout << "This artist could not be found" << endl;
	}
}

void DataBase::sortSongs()
{
	//sorting array
	for (int max = SongCount - 1; max > 0; max--)
	{
		for (int index = 0; index < max; index++)
		{
			if (music[index].getName() > music[index + 1].getName())
			{
				swap(music[index], music[index + 1]);
			}
		}
	}

	for (int i = 0; i < SongCount; ++i)
	{//displaying the current array after sorting
		cout << "Title: " << music[i].getName() << endl;
		cout << "Song by " << music[i].getArtist() << endl;
		cout << "From the album " <<music[i].getAlbum() << endl;
		cout <<  "Lasts " << music[i].getDuration() << endl;
	}
}

void DataBase::sortAlbums()
{
	//sorting array
	for (int max = SongCount - 1; max > 0; max--)
	{
		for (int index = 0; index < max; index++)
		{
			if (music[index].getAlbum() > music[index + 1].getAlbum())
			{
				swap(music[index], music[index + 1]);
			}
		}
	}

	for (int i = 0; i < SongCount; ++i)
	{//displaying the current array after sorting
		cout << "Title: " << music[i].getName() << endl;
		cout << "Song by " << music[i].getArtist() << endl;
		cout << "From the album " << music[i].getAlbum() << endl;
		cout << "Lasts " << music[i].getDuration() << endl;
	}
}

void DataBase::sortArtists()
{
	//sorting array
	for (int max = SongCount - 1; max > 0; max--)
	{
		for (int index = 0; index < max; index++)
		{
			if (music[index].getArtist() > music[index + 1].getArtist())
			{
				swap(music[index], music[index + 1]);
			}
		}
	}

	for (int i = 0; i < SongCount; ++i)
	{//displaying the current array after sorting
		cout << "Title: " << music[i].getName() << endl;
		cout << "Song by " << music[i].getArtist() << endl;
		cout << "From the album " << music[i].getAlbum() << endl;
		cout << "Lasts " << music[i].getDuration() << endl;
	}
}

void DataBase::sortLength()
{
	//sorting array
	for (int max = SongCount - 1; max > 0; max--)
	{
		for (int index = 0; index < max; index++)
		{
			if (music[index].getDuration() > music[index + 1].getDuration())
			{
				swap(music[index], music[index + 1]);
			}
		}
	}

	for (int i = 0; i < SongCount; ++i)
	{//displaying the current array after sorting
		cout << "Title: " << music[i].getName() << endl;
		cout << "Song by " << music[i].getArtist() << endl;
		cout << "From the album " << music[i].getAlbum() << endl;
		cout << "Lasts " << music[i].getDuration() << endl;
	}
}

void DataBase::swap(Music &mu1, Music &mu2)
{
	Music temp = mu1;
	mu1 = mu2;
	mu2 = temp;
}

DataBase::DataBase()
{
	music = new Music[10];
}

DataBase::~DataBase()
{
}
