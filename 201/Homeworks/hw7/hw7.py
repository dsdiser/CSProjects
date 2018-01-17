# File: hw7.py
# Author: Daniel Diseroad
# Date: 10/30/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program contains 7 separate functions that assist the user with handling ints.
# Collaboration:
# I did not collaborate with anyone on this assignment.

CHOICE_1 = 1
CHOICE_2 = 2
CHOICE_3 = 3
CHOICE_4 = 4
CHOICE_5 = 5
#createIntList() creates a list of integers of any size based on the user's needs
#Input:          an integer to be used as a sentinel value
#Output:         a list of integer values
def createIntList(sentinel):
    sentString = str(sentinel)
    prompt = "Enter a number to add to the list, or "+sentString+" to stop. "
    newNum = int(input(prompt))
    intList = []
    while(newNum != sentinel):
        intList.append(newNum)
        newNum = int(input(prompt))
    return intList

#getValidInt() takes a minimum and maximum and makes sure the number inputted is between
#                the two
#Input:          integers to be used as a min and max
#Output:         an integer
def getValidInt(min, max):
    prompt = "Please enter a number between "+str(min)+" and "+str(max)+" (inclusive): "
    num = int(input(prompt))
    while num > max or num < min:
        num = int(input(prompt))
    return num

#printMenu() prints out menu options for the user
#Input:          none
#Output:         printed string
def printMenu():
    print("Please make a choice from the menu:\n",
          CHOICE_1, "- Create a list\n", CHOICE_2,
          "- Check if list is all same\n",CHOICE_3,
          "- Check if list is all different\n", CHOICE_4, "- Check if",
          "list is sorted\n", CHOICE_5, "- Exit the program")

#allTheSame() determines whether the contents of a list are identical
#Input:          a list
#Output:         a boolean
def allTheSame(numbers):
    if(numbers[1:] == numbers[:-1]):
        return True
    return False

#allDifferent() determines whether the contents of a list are different
#Input:          a list
#Output:         a boolean
def allDifferent(numbers):
    counter = 0
    for i in numbers:
        for j in numbers:
            if i==j:
                counter+=1
    if counter==len(numbers):
        return True
    return False

#sorted() determines whether a list is sorted from smallest to largest
#Input:          a list
#Output:         a boolean
def sorted(numbers):
    counter = 0
    for i in range(len(numbers)-1):
        if numbers[i]> numbers[i+1]:
            counter+=1
    if counter == 0:
        return True
    return False

def main():
    printMenu()
    choice = getValidInt(CHOICE_1,CHOICE_5)
    intList = []
    result=False
    #this while loop goes the the program's process as long as the user doesn't input 5 to
    #stop the program. It calls the functions as needed.
    while(choice != CHOICE_5):
        if(choice == CHOICE_1):
             sentinel = int(input("What do you want the sentinel value to be? "))
             intList = createIntList(sentinel)
        elif(choice == CHOICE_2):
            result = allTheSame(intList)
            if result == True:
                print("The list",intList,"is all the same element")
            else:
                print("The list",intList,"is not all the same element")
        elif(choice == CHOICE_3):
            result = allDifferent(intList)
            if result == True:
                print("The list",intList,"is all unique elements")
            else:
                print("The list",intList,"is not all unique elements")
        elif(choice == CHOICE_4):
            result = sorted(intList)
            if result == True:
                print("The list",intList,"is sorted")
            else:
                print("The list",intList,"is not sorted")
        print("----- ----- ----- ----- ----- -----\n")
        printMenu()
        choice = getValidInt(CHOICE_1,CHOICE_5)
main()
