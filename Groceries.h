/*
* Student Name: Xaiver Hickey
* Project: Corner Grocer
* Date: 06/14/2022
*/

#pragma once

#ifndef GROCERIES_H
#define GROCERIES_H

#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Groceries {
	//declaring map
	std::map<std::string, int> mMapOfGroceries;

public:
	// initializing map
	Groceries(std::initializer_list<std::pair<const std::string, int> > mapOfGroceries) :
		mMapOfGroceries(mapOfGroceries) {
	}

	void mapDisplay() { // display map
		for (auto& entry : mMapOfGroceries)
			std::cout << entry.first << " " << std::string(entry.second, '*') << std::endl;
		std::cout << std::endl;
	}

	// setters and getters
	void SetUserInput(int userInput);
	void SetStringInput(string stringInput);
	int GetUserInput() const;
	string GetStringInput() const;

	// setters and getters for option 3 Histogram
	void SetGrocerString(string gString);
	void SetGrocerNum(int gNum);
	string GetGrocerString() const;
	int GetGrocerNum() const;

	// functions for program
	int MainMenu(int userInput);
	void Display();
	void OptionTwo(string stringInput);
	int Histogram(string gString, int gNum);

	// python functions to help languages communicate
	void CallProcedure(string pName);
	int callIntFunc(string proc, string param);
	int callIntFunc(string proc, int param);

private: // private variables
	int input = -1;
	string pyInput = " ";
	string grocerString = " ";
	int grocerNum = -1;
};

#endif /* GROCERIES_H */