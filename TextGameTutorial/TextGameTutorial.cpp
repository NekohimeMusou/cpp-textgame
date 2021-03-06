// TextGameTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// I decided to use scoped enums and to roll the constants up into them.
// The All values should ALWAYS come last; they're for array declarations.
enum class Direction { None = -1, North, East, South, West, All };
enum class RoomName { None = -1, Sportshop, Casino, Carpark, Lobby, Restaurant, Corridor, Storeroom, Pool, Garden, Pond, Pumproom, All };

struct Word
{
	string word;
	int code;
};

struct Room
{
	string description;
	int exits[static_cast<int>(Direction::All)];	// This is why All comes last
};

vector<string> section_command(string command);
string trim(string str, string whitespace = " \t");
string replaceChar(string str, char oldChar, char newChar);
void initRooms(Room rooms[]);

int main()
{
	// Initialize room array
	Room rooms[static_cast<int>(RoomName::All)];
	

	string command;
	bool quitFlag = false;

	while (!quitFlag)
	{
		command.clear();
		cout << "What shall I do? ";
		getline(cin, command);
		cout << "Your raw command was " << command << endl;

		// Handle the command line format
		auto splitCommand = section_command(command);

		string word1, word2;

		if (splitCommand.size() == 0)
		{
			cout << "No command given." << endl;
		}
		else if (splitCommand.size() <= 2)
		{
			word1 = splitCommand[0];
			if (word1 == "QUIT")
			{
				quitFlag = true;
			}
			if (splitCommand.size() == 2)
			{
				word2 = splitCommand[1];
			}
		}
		else
		{
			cout << "Please enter 1-2 words only." << endl;
		}
		// Output the command for debugging
		cout << word1 << " " << word2 << endl;
	}

	return 0;
}

// Take a raw command input by the user, trim whitespace, and tokenize it into a vector
vector<string> section_command(string command)
{
	vector<string> words;

	// Trim whitespace from string
	command = trim(command);

	// Replace tabs with spaces
	command = replaceChar(command, '\t', ' ');

	// Convert string to uppercase
	transform(command.begin(), command.end(), command.begin(), ::toupper);

	// Split command into vector
	istringstream cmd{ command };
	string s;

	while (getline(cmd, s, ' '))
	{
		// Add the word to the vector if it isn't empty
		// This takes care of extra spaces between words too
		if (!s.empty())
		{
			words.push_back(s);
		}
	}

	return words;
}

// Trim the whitespace (or whatever) from the left and right ends of a string.
// PARAMS:
//	str: The string to trim whitespace from
//  whitespace: a string containing the characters that count as whitespace. default value: " \t"
string trim(string str, string whitespace)
{
	const auto strBegin = str.find_first_not_of(whitespace);

	// No content in string
	if (strBegin == string::npos) return "";

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

// Replace every occurrence of oldChar within str with newChar
// PARAMS:
//	str: The string in which to replace characters
//	oldChar: the char to search for and replace
//  newChar: the char to substitute for oldChar
string replaceChar(string str, char oldChar, char newChar)
{
	replace(str.begin(), str.end(), oldChar, newChar);
	return str;
}

// Initialize the list of rooms.
// PRECONDITION: rooms MUST be large enough to hold all rooms. Initialize it with static_cast<int>(RoomName::All).
// PARAMS:
//	rooms: array of rooms to populate
void initRooms(Room rooms[])
{

}