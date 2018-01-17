#include "Sequencer.h"
/*****************************************
 ** File:    Sequencer.cpp
 ** Project: CMSC 202 Project 3, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    3/29/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the Sequencer class for project 3
 ** this class reads from a file and contains
 ** the main menu.
 **
 **
 ********************************************/

//Sequencer
//Starts the program and calls various functions
Sequencer::Sequencer(string fileName)
{
  m_fileName = fileName;
  DNA dna = DNA();
  m_dna = dna;
  readFile();
  mainMenu();
}

//~Sequencer
//Deallocates any dynamically allocated memory not already deallocated(none)
Sequencer::~Sequencer()
{

} 

//readFile
//Reads strand of DNA in from a file and populates a linked list
void Sequencer::readFile()
{
  string line = "";
  ifstream dnaFile;
  dnaFile.open(m_fileName.c_str());
  //gets the payload and adds it to the linked list through the DNA class
  while(getline(dnaFile,line))
    {
      const char *payload = line.c_str();
      m_dna.InsertEnd(payload[0]);
    }
}

//mainMenu
//Main menu of the program, calls various functions and exits when done
void Sequencer::mainMenu()
{
  int userChoice = 0;
  bool endGame = true;
  cout << "New Sequencer loaded" << endl;
  while(endGame)
    {
      cout << "\nWhat would you like to do?:\n1. Display Sequencer (Leading Strand)\n"
	   << "2. Display Sequencer (Base Pairs)\n3. Inventory Basic Amino Acids\n"
	   << "4. Sequence Entire DNA Strand\n5. Exit" << endl;
      while((userChoice < 1) or (userChoice > 5))
	cin >> userChoice;
      cout << endl;
      switch(userChoice)
	{
	case 1:
	case 2:
	  m_dna.Display(userChoice);
	  break;
	case 3:
	  m_dna.Display(1);
	  m_dna.NumAmino("Tryptophan","TGG");
	  m_dna.NumAmino("Phenylalanine","TTT");
	  break;
	case 4:
	  m_dna.Sequence();
	  break;
	case 5:
	  endGame = false;
	  break;
	}
      userChoice = 0;
    }
}
