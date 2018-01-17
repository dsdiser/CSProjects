#include "DNA.h"

/*****************************************
 ** File:    DNA.cpp
 ** Project: CMSC 202 Project 3, Spring 2017
 ** Author:  Daniel Diseroad
 ** Date:    3/29/17
 ** Section: 21
 ** E-mail:  ddiser1@umbc.edu
 **
 ** This file contains the DNA class for project 3
 ** this class creates the linked list and gets 
 ** various information about it.
 **
 **
 ********************************************/

//DNA
//Default constructor for the linked list
DNA::DNA()
{
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

//~DNA
//Default deconstructor for linked list, calls clear
DNA::~DNA()
{
  //just calls the clear function
  Clear();
}

//InsertEnd
//Adds to the end of the linked list
void DNA::InsertEnd(char payload)
{
  Nucleotide* newNucleotide = new Nucleotide();
  newNucleotide->m_payload = payload;
  //if the head is empty, make the new nucleotide the head
  if(IsEmpty())
    m_head = newNucleotide;
  //otherwise, change the tail's m_next to the new tail and change the tail
  else
    m_tail->m_next = newNucleotide;
  //sets the tail to the newest addition and adds one to m_size
  m_tail = newNucleotide;
  m_size += 1;
  newNucleotide->m_next = NULL;
}

//Display
//Displays the linked list based on the option given
void DNA::Display(int numStrand)
{
  Nucleotide* currentNucleotide = m_head;
  char payload;
  if(numStrand == 2)
    cout << "Base Pairs:" << endl;
  //loops the same number of times as the size of the linked list
  for(int i = 0;i < m_size; i++)
    {
      payload = currentNucleotide->m_payload;
      cout << payload;
      //if the base pairs are supposed to be printed out, use a switch statement
      //to print them out
      if(numStrand == 2)
	{
	  switch(payload)
	    {
	    case 'A':
	      cout << "-T" << endl;
	      break;
	    case 'T':
	      cout << "-A" << endl;
	      break;
	    case 'C':
	      cout << "-G" << endl;
	      break;
	    case 'G':
	      cout << "-C" << endl;
	      break;
	    }
	}
      else
	cout << endl;
      currentNucleotide = currentNucleotide->m_next;
    }
  cout << m_size << " nucleotides listed." << endl;
  cout << m_size/TRINUCLEOTIDE_SIZE << " trinucleotides listed." << endl;
}

//NumAmino
//Prints out the number of a type of amino acid in the strand
void DNA::NumAmino(string name, string trinucleotide)
{
  Nucleotide* currentNucleotide = m_head;
  string payloads = "";
  int triCount = 0;
  //loops the same number of times as there are trinucleotides
  for(int i = 0; i < m_size/TRINUCLEOTIDE_SIZE; i++)
    {
      //gets a set of three nucleotides and puts them into a string
      for(int i = 0; i < TRINUCLEOTIDE_SIZE; i++)
	{
	  payloads += currentNucleotide->m_payload;
	  currentNucleotide = currentNucleotide->m_next;
	}
      //if that string is the same as the proposed trinucleotide, up the count by one
      if(payloads.compare(trinucleotide) == 0)
	triCount++;
      payloads = "";
    }
  //print the number of those nucleotides identified
  cout << name << ": " << triCount << " identified" << endl;
}

//Sequence
//Prints out all amino acids in the strand
void DNA::Sequence()
{
  Nucleotide* currentNucleotide = m_head;
  string payloads = "";
  int triCount = 0;
  string* aminoArray = new string[m_size/TRINUCLEOTIDE_SIZE];
  cout << "Amino Acid List:" << endl;
  //loops the same number of times as there are trinucleotides
  for(int i = 0; i < m_size/TRINUCLEOTIDE_SIZE; i++)
    {
      //gets a set of three nucleotides and puts them into a string
      for(int i = 0; i < TRINUCLEOTIDE_SIZE; i++)
        {
          payloads += currentNucleotide->m_payload;
          currentNucleotide = currentNucleotide->m_next;
        }
      //uses translate function to get Amino Acid names and puts them into a dynamic
      //array
      aminoArray[triCount] = Translate(payloads);
      payloads = "";
      triCount +=1;
    }
  //iterates through dynamic array and prints out the Amino Acid names
  for(int i = 0; i < (m_size/TRINUCLEOTIDE_SIZE); i++)
    {
      cout << aminoArray[i] << endl;
    }
  //deletes the dynamic array and sets the pointer to NULL
  delete[] aminoArray;
  aminoArray = NULL;
  cout << "Total Amino Acids Identified: " << m_size/TRINUCLEOTIDE_SIZE << endl;
}

//Translate
//Gives the name of the amino acid associated with the trinucleotide
string DNA::Translate(const string trinucleotide)
{
  if((trinucleotide=="ATT")||(trinucleotide=="ATC")||(trinucleotide=="ATA"))
    return ("Isoleucine");
  else if((trinucleotide=="CTT")||(trinucleotide=="CTC")||
	  (trinucleotide=="CTA")||(trinucleotide=="CTG")||
	  (trinucleotide=="TTA")||(trinucleotide=="TTG"))
    return ("Leucine");
  else if((trinucleotide=="GTT")||(trinucleotide=="GTC")||
	  (trinucleotide=="GTA")||(trinucleotide=="GTG"))
    return ("Valine");
  else if((trinucleotide=="TTT")||(trinucleotide=="TTC"))
    return ("Phenylalanine");
  else if((trinucleotide=="ATG"))
    return ("Methionine");
  else if((trinucleotide=="TGT")||(trinucleotide=="TGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCT")||(trinucleotide=="GCC")||
	  (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGT")||(trinucleotide=="GGC")||
	  (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCT")||(trinucleotide=="CCC")||
	  (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACT")||(trinucleotide=="ACC")||
	  (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="TCT")||(trinucleotide=="TCC")||
	  (trinucleotide=="TCA")||(trinucleotide=="TCG")||
	  (trinucleotide=="AGT")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="TAT")||(trinucleotide=="TAC"))
    return ("Tyrosine");
  else if((trinucleotide=="TGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAT")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAT")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAT")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGT")||(trinucleotide=="CGC")||
	  (trinucleotide=="CGA")||(trinucleotide=="CGG")||
	  (trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="TAA")||(trinucleotide=="TAG")||
	  (trinucleotide=="TGA"))
    return ("Stop");
  else
    cout << "returning unknown" << endl;
  return ("Unknown");
}

//IsEmpty
//Determines whether the linked list is empty
bool DNA::IsEmpty()
{
  //determines based off m_size
  if(m_size == 0)
    return true;
  return false;
}

//SizeOf
//Determines the size of the linked list
void DNA::SizeOf()
{
  Nucleotide* currentNucleotide = m_head;
  int sizeCount = 0;
  //adds one to the size for each node that isn't NULL
  while(currentNucleotide->m_next != NULL)
    sizeCount++;
  m_size = sizeCount;
}

//Clear
//Deallocates any dynamic memory, including the linked list
void DNA::Clear()
{
  Nucleotide* currentNucleotide = m_head;
  //goes through the linked list, deleting every nucleotide from the start to the end
  while(m_head != NULL)
    {
      //changes the head of the linked list
      m_head = currentNucleotide->m_next;
      //deletes the previous head
      delete currentNucleotide;
      //changes the current node to the newest head (will be NULL by the end of the
      //loop
      currentNucleotide = m_head;
    }
  currentNucleotide = NULL;
}
