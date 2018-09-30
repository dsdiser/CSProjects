// File: PerfectHT.cpp
//
// UMBC CMSC 341 Fall 2017 Project 5
//
// Implementation of HashFunction, SecondaryHT & PerfectHT classes.
//
// Version: 2017-11-16
//

#include <stdexcept>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std ;

#include "PerfectHT.h"
#include "primes.h"


// =====================================================================
// HashFunction class implementation 
// =====================================================================


// By default do not print info to screen
//
bool HashFunction::m_debug = false ;


// Constructor.
// The constructor picks the smallest prime # larger than n
// for the table size. Default value of n defined in header.
//  
// Initializes other hash function parameters randomly.
//
HashFunction::HashFunction(int n /* =100*/ ) {

   // note: maxPrime defined in prime.h
   //
   if (n > maxPrime) throw out_of_range("HashTable size too big.\n") ;

   m_tsize = findPrime(n) ;
   m_factor = ( rand() % (m_tsize - 1) ) + 1 ;
   m_shift =  rand() % m_tsize ;
   m_multiplier = 33 ;  // magic number from textbook
   m_reboots = 0 ;

}


// Function that maps string to unsigned int.
// Return value can be much larger than table size.
// Uses m_multiplier data member.
// Return value must be unsgined for overflow to work correctly.
//
unsigned int HashFunction::hashCode(const char *str) const {

   unsigned int val = 0 ; 

   int i = 0 ;
   while (str[i] != '\0') {
      val = val * m_multiplier + str[i] ;
      i++ ;
   }
   return val ; 
}


// Getter for table size
//
int HashFunction::tableSize() const {
   return m_tsize ;
}


// Overloaded () operator that makes this a "functor" class.
// Returns the slot in the hash table for str.
// Uses the MAD method: h(x) = (ax + b) % m where 
// the parameters are:
//   a = m_factor
//   b = m_shift
//   m = m_tsize
//
unsigned int HashFunction::operator() (const char *str) const {
   return ( m_factor * hashCode(str) + m_shift ) % m_tsize ;
}


// Pick new parameters for MAD method and the hashCode function.
// Note: can change table size.
//
void HashFunction::reboot() {
  //increment the number of reboots
  m_reboots += 1;
  if(m_reboots % 3 == 0)
    m_multiplier += 2;
  if(m_reboots % 5 == 0)
    m_tsize = findPrime(m_tsize+1);
  int temp = m_factor;
  //make a new factor
  while(temp == m_factor)
    temp = (rand() % (m_tsize-1)) + 1;
  m_factor = temp;
  temp = m_shift;
  //make a new shift number
  while(temp == m_shift)
    temp = rand() % m_tsize;
  m_shift = temp;
  //print out numbers if debug is on
  if(m_debug){
    cout << "---- reboot #" << m_reboots << ":  " 
	 << "m_tsize = " << m_tsize << " m_multiplier = " << m_multiplier
	 << " m_factor = " << m_factor << " m_shift = " << m_shift << endl; 
  }
}


// Set random seed for the random number generator.
// Call once at the start of the main program.
// Uses srand() and rand() from cstdlib which is
// shared with other code. For compatibility with
// C++98, it does not have a private random number 
// generator (e.g., mt19337).
//
void HashFunction::setSeed(unsigned int seed) {
   srand(seed) ;
}


// Find the smallest prime number larger than m.  

int HashFunction::findPrime(int m){
  if(m > maxPrime)
    throw out_of_range("too large"); 
  int begin = 0;
  int end = numPrimes-1;
  //locates the current prime in the array then returns the prime right after it
  while (begin <= end){
    int mid = begin + (end-begin)/2;
    //finds next mid
    if ((primes[mid] >= m) and (m > primes[mid-1]))
      //cout << m <<" " << primes[mid] << endl;
      return primes[mid];  
    // If x greater, ignore left half  
    if (primes[mid] < m) 
      begin = mid + 1; 
    // If x is smaller, ignore right half 
    else
      end = mid - 1; 
  } 
  //failed
  cout << "failed" << endl;
  return -1;
}



// =====================================================================
// SecondaryHT class implementation 
// =====================================================================


// By default do not print debugging info 
bool SecondaryHT::m_debug = false ;


// Create a secondary hash table using the char * strings
// stored in "words". Makes copy of each item in words.
//
SecondaryHT::SecondaryHT(vector<const char *> words) {
   //
   // Keep trying until a table with no collisions is found
   // 
   // wrap debugging statements in "if (m_debug) { ... }"
   //
   // remember that calling HashFunction::reboot() can change 
   // the table size!
   //
   // use strdup to copy char * strings
   //
  m_size = words.size();
  hash = HashFunction(m_size*m_size);
  m_attempts = 0;
  bool doneHash = false;
  //makes a correctly sized hash table with no collisions
  while(m_attempts <= maxAttempts and !doneHash){
    m_attempts += 1;
    bool* hashes = new bool[hash.tableSize()];
    //initialize all values in array to be false
    for(int i = 0; i < hash.tableSize(); i++){
      hashes[i] = false;
    }
    bool failedHash = false;
    //checks for possible collisions in boolean array
    for(int i = 0; i < m_size; i++){
      int hashedTo = hash(words[i]);
      //collision not found
      //cout <<"hashed to: "<< hashedTo << endl;
      if(hashes[hashedTo] == false)
	hashes[hashedTo] = true;
      //collision found
      else{
	failedHash = true;
	break;
      }
    }
    //if the hash was a success
    if(!failedHash)
      doneHash = true;
    //if the hash was a failure
    else{
      //if too many attempts
      if(m_attempts > maxAttempts){ 
	delete [] hashes;
	throw very_unlucky("Too many attempts at secondary table!");
      }
      hash.reboot();
    }
    delete [] hashes;
  }
  //creates the hash table and populates it using the hashcode
  T2 = new char*[hash.tableSize()];
  //initializes to null pointers
  for(int i = 0; i < hash.tableSize(); i++)
    T2[i] = NULL;
  //populates the array
  for(int i = 0; i < m_size; i++){
    int hashedTo = hash(words[i]);
    T2[hashedTo] = strdup(words[i]);
  }
}


// Copy constructor. Remember to strdup.
//
SecondaryHT::SecondaryHT(const SecondaryHT& other) {
  hash = other.hash;
  m_size = other.m_size;
  m_attempts = other.m_attempts;
  //initializes and populates T2
  T2 = new char*[hash.tableSize()];
  for(int i = 0; i < hash.tableSize(); i++){
    if(other.T2[i] == NULL)
      T2[i] = NULL;
    else
      T2[i] = strdup(other.T2[i]);
  }
}


// Destructor. Use free() to free strings.
//
SecondaryHT::~SecondaryHT() {
  //use free to free the strings
  for(int i = 0; i < hash.tableSize(); i++)
    if(T2[i] != NULL)
      free(T2[i]);
  delete [] T2;
}


// Assignment operator. Remember to use strdup() and free()
//
const SecondaryHT& SecondaryHT::operator=(const SecondaryHT& rhs) {
  m_size = rhs.m_size;
  m_attempts = rhs.m_attempts;
  //freeing previous memory
  for(int i = 0; i < hash.tableSize(); i++)
    if(T2[1] != NULL)
      free(T2[i]);
  delete [] T2;
  hash = rhs.hash;
  //initializes and populates T2
  T2 = new char*[hash.tableSize()];
  for(int i = 0; i < hash.tableSize(); i++){
    if(rhs.T2[i] == NULL)
      T2[i] = NULL;
    else
      T2[i] = strdup(rhs.T2[i]);
  }
  return *this;
}


// returns whether given word is in this hash table.
//
bool SecondaryHT::isMember (const char *word) const {

   int slot = hash(word) ;

   assert ( 0 <= slot && slot < hash.tableSize() ) ;

   if (T2[slot] == NULL) return false ;

   if ( strcmp(word, T2[slot]) != 0 ) return false ;

   return true ; 
}


// getter. Actually, the hash function has the size.
//
int SecondaryHT::tableSize() const {
   return hash.tableSize() ;
}


// Pretty print for debugging
//
void SecondaryHT::dump() const {
   cout << "=== Secondary Hash Table Dump: ===\n" ;
   cout << "Table size = " << hash.tableSize() << endl ;
   cout << "# of items = " << m_size << endl ;
   cout << "# of attempts = " << m_attempts << endl ;
 
   for (int i=0 ; i < hash.tableSize() ; i++) {
      cout << "T2[" << i << "] = " ;
      if (T2[i] != NULL) cout << T2[i] ;
      cout << endl ;
   }

   cout << "==================================\n" ;
}



// =====================================================================
// PerfectHT class implementation 
// =====================================================================


// by default, do not print debugging info
//
bool PerfectHT::m_debug = false ;


// Create a Perfect Hashing table using the first n strings 
// from the words array.
//
PerfectHT::PerfectHT (const char *words[], int n) {

   // Implement constructor for PerfectHT here.
   //
   // You will need an array of vectors of char * strings.
   // Something like;
   //
   //    vector<const char *> *hold = new vector<const char *>[m] ;
   //
   // Each hold[i] is a vector that holds the strings
   // that hashed to slot i. Then hold[i] can be passed
   // to the SecondaryHT constructor.
   //
  hash = HashFunction(n);
  vector<const char *> *hold = new vector<const char *>[hash.tableSize()] ;
  //populates array of words 
  for(int i = 0; i < n; i++){
    int hashedTo = hash(words[i]);
    hold[hashedTo].push_back(words[i]);
  }
  PHT1 = new char*[hash.tableSize()];
  PHT2 = new SecondaryHT*[hash.tableSize()];
  //initializes arrays to null
  for(int i = 0; i < hash.tableSize(); i++){
    PHT1[i] = NULL;
    PHT2[i] = NULL;
  }
  //populates arrays correctly
  for(int i = 0; i < hash.tableSize(); i++){
    if(hold[i].size() != 0){
      //populates the array based on how many strings are in each vector
      if(hold[i].size() > 1)
	PHT2[i] = new SecondaryHT(hold[i]);
      else
	PHT1[i] = strdup(hold[i][0]);
    }
  }
  //deallocates memory
  delete [] hold;
}


// Copy constructor. Use strdup or SecondaryHT copy constructor.
//
PerfectHT::PerfectHT(const PerfectHT& other) {
  hash = other.hash;
  PHT1 = new char*[hash.tableSize()];
  PHT2 = new SecondaryHT*[hash.tableSize()];
  //copies PHT1 and PHT2
  for(int i = 0; i < hash.tableSize(); i++){
    if(other.PHT1[i] != NULL)
      PHT1[i] = strdup(other.PHT1[i]);
    else
      PHT1[i] = NULL;
    if(other.PHT2[i] != NULL)
      PHT2[i] = new SecondaryHT(*other.PHT2[i]);
    else
      PHT2[i] = NULL;
  }
}


// Destructor. Remember to use free() for strdup-ed strings.
//
PerfectHT::~PerfectHT() {
  for(int i = 0; i < hash.tableSize(); i++)
    if(PHT2 != NULL)
      delete PHT2[i];
  for(int i = 0; i < hash.tableSize(); i++)
    if(PHT1[i] != NULL)
      free(PHT1[i]);
  delete [] PHT1;
  delete [] PHT2;
}


// Assignment operator. Use strdup() and free() for strings.
//
const PerfectHT& PerfectHT::operator=(const PerfectHT& rhs) {
  //clears old memory
  for(int i = 0; i < hash.tableSize(); i++)
    if(PHT2 != NULL)
      delete PHT2[i];
  for(int i = 0; i < hash.tableSize(); i++)
    if(PHT1 != NULL)
      free(PHT1[i]);
  //clearing old memory
  delete [] PHT1;
  delete [] PHT2;

  hash = rhs.hash;
  PHT1 = new char*[hash.tableSize()];
  PHT2 = new SecondaryHT*[hash.tableSize()];
  //copies PHT1 and PHT2
  for(int i = 0; i < hash.tableSize(); i++){
    if(rhs.PHT1[i] != NULL)
      PHT1[i] = strdup(rhs.PHT1[i]);
    else
      PHT1[i] = NULL;
    if(rhs.PHT2[i] != NULL)
      PHT2[i] = new SecondaryHT(*rhs.PHT2[i]);
    else
      PHT2[i] = NULL;
  }
  return *this;
}


// Returns whether word is stored in this hash table.
//
bool PerfectHT::isMember(const char * str) const {
   int slot = hash(str) ; 

   if (PHT1[slot] == NULL && PHT2[slot] == NULL) return false ;

   if (PHT1[slot] != NULL) return strcmp(str,PHT1[slot]) == 0 ;

   return PHT2[slot]->isMember(str) ;
}


// Pretty print for debugging.
//
void PerfectHT::dump() const {
   int m = hash.tableSize() ;   

   cout << "------------- PerfectHT::dump()  -------------\n" ;
   cout << "table size = " << hash.tableSize() << endl ;
   cout << endl ;
   for (int j=0 ; j < m ; j++) {
      cout << "[" << j << "]:  " ;
      if (PHT1[j] != NULL) cout << PHT1[j] ;
      if (PHT2[j] != NULL) {
         cout << endl ;
         PHT2[j]->dump() ;
      }
      cout << endl ;
   }

   cout << "----------------------------------------------\n" ;
}
