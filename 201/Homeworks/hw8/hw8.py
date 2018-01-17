# File: hw8.py
# Author: Daniel Diseroad
# Date: 11/17/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program simulates the sorting hat from the Harry Potter series.
# Collaboration:
# I did not collaborate with anyone on this assignment.

import random

# printOneHouse() prints out the members of one house
# Input: The dictionary of houses and members and the house that is wanted to print out
# Output: print statements
def printOneHouse(hogwarts,houseWanted):
    houses = hogwarts.keys()
    counter = 0
    for i in houses:
        if i == houseWanted:
            print("The members of the House of",houseWanted,"are:")
            for i in hogwarts[houseWanted]:
                print(i)
        #makes sure the input is valid
        else:
            counter+=1
            if counter == len(houses):
                print("There is no house by the name of",houseWanted)

# printOneHouse() prints out the members of all houses
# Input: The dictionary of houses and members
# Output: print statements from printOneHouse()
def printAllHouses(hogwarts):
    houses = hogwarts.keys()
    for i in houses:
        printOneHouse(hogwarts,i)

# houseSort() sorts a person into one of the houses
# Input: The dictionary of houses and members
# Output: a dictionary; representing the members and what house they belong to
def houseSort(hogwarts):
    keys = hogwarts.keys()
    houses = []
    for i in keys:
        houses.append(i)
    #the odds stated by the homework prompt, a float
    chance = (len(houses)+1)/(2*len(houses))
    randomNum = random.random()
    name = input("What is the person's name? ")
    name = " "+name
    houseWanted = input("What house do they prefer? ")
    houses.remove(houseWanted)
    #lets the member into their preferred house or not based on a random float comparison
    if randomNum<= chance:
        hogwarts[houseWanted].append(name)
        print(name,"was sorted into house",houseWanted)
        return hogwarts
    else:
        houseChosen = random.choice(houses)
        hogwarts[houseChosen].append(name)
        print(name,"was sorted into house",houseChosen)
        return hogwarts

# readFile() reads a file of members and forms them into a dictionary based on their house
# Input: a file of members
# Output:  a dictionary; representing the members and what house they belong to
def readFile(file):
    hogwarts = {}
    houseCheck = ""
    for line in file:
        house,name = line.strip().split(",")
        #either makes a new key and list for the member or adds the member to an existing 
        #house list
        if (house in hogwarts):
            hogwarts[house].append(name)
        else:
            hogwarts[house] = [name]
    return hogwarts

# menuPrinter() prints out the menu of options
# Input: none
# Output:  a print statement with menu options
def menuPrinter():
    prompt= ("Please make a choice from the menu:\n" \
             "1 - Print a single house\n" \
             "2 - Print all the houses\n" \
             "3 - Sort a new person into a house\n" \
             "4 - Exit the program\n")
    print(prompt)

def main():
    fileName = input("Please enter filename to load from: ")
    file = open(fileName)    
    hogwarts = readFile(file)
    choice = 0
    #keeps going until user decides to stop
    while choice!=4:
        print("\n        -------------------------------------\n")
        menuPrinter()
        choice = int(input("Please enter a number between 1 and 4 (inclusive): "))
        #makes sure the choice is valid
        while choice <1 or choice>5:
            print("That is not a valid number.")
        if choice == 1:
            houseWanted = input("What house's members would you like to print? ")
            printOneHouse(hogwarts, houseWanted)
        elif choice == 2:
            printAllHouses(hogwarts)
        elif choice == 3:
            houseSort(hogwarts)
        elif choice == 4:
            print("Thank you for using the Great Houses Program")
main()
