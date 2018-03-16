// TextGameTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum class Direction { None = -1, North, East, South, West, All };
enum class Room { None = -1, Sportshop, Casino, Carpark, Lobby, Restaurant, Corridor, Storeroom, Pool, Garden, Pond, Pumproom, All };

vector<string> section_command(string command);
string trim(string str, string whitespace = " \t");
string replaceChar(string str, char oldChar, char newChar);

int main()
{
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

string trim(string str, string whitespace)
{
	const auto strBegin = str.find_first_not_of(whitespace);

	// No content in string
	if (strBegin == string::npos) return "";

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

string replaceChar(string str, char oldChar, char newChar)
{
	replace(str.begin(), str.end(), oldChar, newChar);
	return str;
}