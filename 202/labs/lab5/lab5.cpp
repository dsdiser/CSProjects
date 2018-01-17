#include "File.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void populateDirectory(vector<File>& newDirectory);
// fill vector - fills file info
// @param vector<File>& - files in directory
void printDirectory(vector<File>& newMyFile);
//printDirectory - prints the information of the files in the directory
//@param const vector<File>& files in directory 

int main () {
	//Creates a new directory of files
  vector<File> myDirectory;
	//Populates the vector
  populateDirectory(myDirectory);
  //Prints the contents of the vector
  printDirectory(myDirectory);
  return 0;
}

void populateDirectory(vector<File>& newDirectory) {
  
  //Write this function
  //Needs to ask how many files
  //Gets file name, file type, and file size
  //Uses the overloaded constructor for the file
  //Needs to add files to the directory vector
  int fileNum, fileSize;
  string fileName, fileType;
  File nullFile;
  cout << "How many files do you have?" << endl;
  cin >> fileNum;
  if(cin.peek() == '\n')
    cin.ignore();
  for(int i = 0; i<fileNum;i++)
    newDirectory.push_back(nullFile);
  for(unsigned int i = 0; i < newDirectory.size(); i++)
    {
      cout << "What is file " << i+1 << "'s name?" << endl;
      cin >> fileName;
      cout << "What is file " << i+1 << "'s type?" << endl;
      cin >> fileType;
      cout << "What is file " << i+1 << "'s size?" << endl;
      cin >> fileSize;
      if(cin.peek() == '\n')
	cin.ignore();
      File file = File(fileName,fileType,fileSize);
      newDirectory[i] = file;
    }
}

void printDirectory(vector<File>& newMyFile){
  //Needs to loop through the directory of files and outputs the information
  for(unsigned int i = 0; i < newMyFile.size(); i++)
    {
      cout << "File #" << i+1 << endl;
      cout << "   File Name: " << newMyFile[i].GetFileName() << endl;
      cout << "   File Type: " << newMyFile[i].GetFileType() << endl;
      cout << "   File Size: " << newMyFile[i].GetFileSize() << endl;
    }
}
