# File:    nums.py
# Started: by Dr. Gibson
# Author:  Daniel Diseroad
# Date:    10/25/16
# Section: 28
# E-mail:  ddiser1@umbc.edu 
# Description:
#   This file contains python code that uses functions to 
#   allow a user to get basic information about a number
#   they've entered.

MIN_VAL = -1000000
MAX_VAL =  1000000

# evenOrOdd() takes in a number and returns whether it's even or odd
# Input:      number, an integer
# Output:     a string -- either "even" or "odd" should be returned
def evenOrOdd(number):
    if number%2==0:
        return "even"
    else:
        return "odd"

# posNegZero() takes in a number and returns its sign
# Input:      num, an integer
# Output:     a string -- either "negative", "positive", or "zero" 
#                         should be returned
def posNegZero(num):
    if num>0:
        return "positive"
    elif num<0:
        return "negative"
    else:
        return "zero"

# getValidInt() takes in a minn and maxx, and gets a number from the
#               user between those two numbers (inclusive)
# Input:      minn and maxx, two integers
# Output:     an integer, between minn and maxx inclusive
def getValidInt(minn, maxx):
    message = "Please enter a number between " + str(minn) + " and " + \
        str(maxx) + " (inclusive): "

    newInt = int(input(message))
    while newInt< minn or  newInt> maxx:
        newInt= int(input(message))
    # while loop exited, return the user's choice
    return newInt




def main():

    print("Welcome to the number program!")

    userNum = getValidInt(MIN_VAL, MAX_VAL)

    # call the posNegZero function and print out the result to the user
    #########################################################
    sign = posNegZero(userNum)
    # your code to call the function posNegZero() goes here #
    #########################################################
    print("The number", userNum, "is", sign)

    # call the evenOrOdd function and print out the result to the user
    ########################################################
    result = evenOrOdd(userNum)
    # your code to call the function evenOrOdd() goes here #
    ########################################################
    print("The number", userNum, "is", result)

    # say goodbye and exit the program
    print("Thank you for using the number program!  Come again!")


main()


