#pragma once
#include <iostream>
#include <unordered_map>
#include "Map.h"
using namespace std;

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
	auto map = Map("Home");
	int choice = -1;
	while (choice != 0) 
	{
		system("cls");
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Go To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice) 
		{
		case 1: cout << "Current Location: " << map.CurrentLocation->DisplayLocationInfo(); break;
		case 2: GoNorth(map); break;
		case 3: GoEast(map); break;
		case 4: GoSouth(map); break;
		case 5: GoWest(map); break;
		case 6: system("cls");  cout << map.GetPathBackToHome() << endl; break;
		case 0: break;
		default: cout << "Enter a valid option"; break;
		}
		system("pause");
	}
	
	return 0;
}

void GoNorth(Map &map)
{
	auto newLocation = map.CurrentLocation->North;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr) 
	{
		int newX = currentX;
		int newY = currentY + 1;
		system("cls");
		cout << "You haven't been here before! Enter a name for this place: ";
		string newName;
		cin.ignore();
		getline(cin, newName);
		newLocation = new Location(newName,newX,newY);
		cout << "This place is now called: " + newName << endl;
		
	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
	}
	
	newLocation->South = map.CurrentLocation;
	map.Move(newLocation);	
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map.CurrentLocation->East;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		system("cls");
		cout << "You haven't been here before! Enter a name for this place: ";
		string newName;
		cin.ignore();
		getline(cin, newName);
		newLocation = new Location(newName, newX, newY);
		cout << "This place is now called: " + newName << endl;

	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
	}
	newLocation->West = map.CurrentLocation;
	map.Move(newLocation);
	return;
}

void GoSouth(Map &map)
{
	auto newLocation = map.CurrentLocation->South;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		system("cls");
		cout << "You haven't been here before! Enter a name for this place: ";
		string newName;
		cin.ignore();
		getline(cin, newName);
		newLocation = new Location(newName, newX, newY);
		cout << "This place is now called: " + newName << endl;

	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
	}
	newLocation->North = map.CurrentLocation;
	map.Move(newLocation);
	return;
}

void GoWest(Map &map)
{
	auto newLocation = map.CurrentLocation->West;
	int currentX = map.CurrentLocation->getXCoord();
	int currentY = map.CurrentLocation->getYCoord();
	if (newLocation == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		system("cls");
		cout << "You haven't been here before! Enter a name for this place: ";
		string newName;
		cin.ignore();
		getline(cin, newName);
		newLocation = new Location(newName, newX, newY);
		cout << "This place is now called: " + newName << endl;

	}
	else
	{
		system("cls");
		cout << "You travel to: " + newLocation->DisplayLocationInfo();
	}
	newLocation->East = map.CurrentLocation;
	map.Move(newLocation);
	return;
}