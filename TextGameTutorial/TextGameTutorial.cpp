// TextGameTutorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string command;

	while (true)
	{
		command.clear();
		cout << "What shall I do? ";
		getline(cin, command);
		cout << "Your raw command was " << command << endl;
	}

	return 0;
}
