# File: hw6.py
# Author: Daniel Diseroad
# Date: 10/22/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program contains 4 separate functions that assist the user with handling ints.
# Collaboration:
# Collaboration was not allowed on this assignment.

#summation()  calculates the total of a list of integers through addition
#Input:       a list of integers; of any size
#Output:      the total of all of the numbers added together; the sum
def summation(intList):
    total = 0
    for i in intList:
        total += i
    return total

#multiply()   calculates the product of all the list items multiplied together
#Input:       a list of integers; of any size
#Output:      the total of all the numbers multiplied together; the product
def multiply(intList):
    total = 1
    if(len(intList)==0):
        total = 0
    else:
        for i in intList:
            total *= i
    return total

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

def main():
    listNum = int(input("How many lists do you want? "))
    #This loop runs through and creates, multiplies, and summates the list the user makes.
    for i in range(listNum):
        print("You are making list number",(i+1))
        sentinel = int(input("What do you want the sentinel value to be? "))
        intList = createIntList(sentinel)
        summationNum = summation(intList)
        productNum = multiply(intList)
        print("For the list", intList)
        print("The summation is",summationNum,"\nThe product is",productNum)
main()
