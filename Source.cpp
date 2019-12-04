#include "DataBase.h"
#include "Music.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

	DataBase info;//info being the information of the songs
	string tempo;
	int secs = 0;
	int found = 0;//used for the search option
	int foundat = 0;
	char choice;//user menu choice

	ifstream musicFile;
	musicFile.open("music.txt");
	info.addSong(musicFile);

	/*some information for one song
	Name - Giants
	Album - Worlds 2019
	Artist - LoL
	how long it is in seconds - 183*/

	/*since we don't have the file system done yet please
	add some song information for the time being*/


	/*info.addMusic();
	info.addMusic();
	info.addMusic();
	system("cls");*/

/*there is an issue with adding songs after the first one, 
and we are in the progress of working it out*/

	cout << "Here is our prototype for the final project" << endl;
	cout << "Please follow the menu until you are done" << endl;

	do
	{
		cout << "Select an option from the folloing menu" << endl;

		cout << "\n1) Add a song to the database";
		cout << "\n2) View current music database";
		cout << "\n3) Check how many songs are currently in the database";
		cout << "\n\nThe following options show the database in decending order" << endl;
		cout << "\n4) Search for a song name";
		cout << "\n5) Search for an artist";
		cout << "\n6) Search for an album";
		cout << "\n7) Sort the database by songs";
		cout << "\n8) Sort the database by artist names";
		cout << "\n9) Sort the database by albums";
		cout << "\n0) sort the database by the song durations";
		cout << "\nX) Exit song database \n\nOption:";

		cin >> choice;

		choice = toupper(choice);
		switch (choice)
		{
		case '1':
			system("cls");
			info.addMusic();//adding a song to the database
			system("pause");
			break;

		case'2':
			system("cls");
			info.viewDataBase();//display the database so far
			system("pause");
			break;

		case'3':
			system("cls");//display how many songs in the database
			cout << "There are currently " << info.getcount() << " in the database" << endl;
			system("pause");
			break;
			
		//we are having some issues with the searching functions and are working on testing them
		case'4'://the next three are the searching functions
			system("cls");//
			cout << "What is the name of the song?" << endl;
			getline(cin, tempo);
			info.findSName(tempo);

			system("pause");
			break;

		case'5':
			system("cls");
			cout << "What is the name of the artist?" << endl;
			getline(cin, tempo);
			info.findArName(tempo);

			system("pause");
			break;

		case'6':
			system("cls");
			cout << "What is the name of the album?" << endl;
			getline(cin, tempo);
			info.findAName(tempo);

			system("pause");
			break;

		//as of right now we are fairly sure that the sorting functions are working properly in descending order
		//we are in the process of adding a ascending sorting function
		case'7'://the next 4 functions are the sorting
			system("cls");
			info.sortSongs();

			system("pause");
			break;
		
		case'8':
			system("cls");
			info.sortArtists();

			system("pause");
			break;

		case'9':
			system("cls");
			info.sortAlbums();

			system("pause");
			break;

		case'0':
			system("cls");
			info.sortLength();

			system("pause");
			break;
		
		case'X'://closing the program			
			//goto out;
			continue;
		default://in case of incorrect inputs
			cout << "ERROR: INVALID ENTRY" << endl;
			break;
		}
		system("cls");
	} while (choice != 'X');

	//out:
	musicFile.close();

	ofstream dumpFile;
	dumpFile.open("music.txt");


	system("pause");
	return 0;
}