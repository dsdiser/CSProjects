# File:    capitals.py
# Started: by Dr. Gibson
# Author:  Daniel Diseroad
# Date:    11/15/16
# Section: 28
# E-mail:  ddiser1@umbc.edu
# Description:
#   This file contains python code that reads in a list of
#   states and their capitals, stores it in a dictionary,
#   and then allows the user to list all options (states),
#   or to show the capital of a specified state.
# Collaboration: During lab, collaboration between students is allowed,
#                although I understand I still must understand the material
#                and complete the assignment myself. 

QUIT     = "exit"
SHOW_ALL = "list"


# convertToDict() takes in the filename and converts to a dict
# Input:          a file object
# Output:         a dictionary containing the file contents
def convertToDict(fileContents):
    dict1 = {}
    state = []
    # write the rest of the function (including the return)
    for line in fileContents:
        state = line.strip().split(",")
        dict1[state[0]]=state[1]
    return dict1
def main():
    dict1 = {}
    stateCapFile = open("stateCaps.txt")
    # a function call to convertToDict goes here
    dict1 = convertToDict(stateCapFile)
    stateCapFile.close()

    print("Welcome to the State Capital Lookup System")
    # message with all the prompts for the user
    msg = "\n\tPlease enter the state you want the capital of.\n" + \
        "\t(Use '" + SHOW_ALL + "' for choices, or '" + \
        QUIT + "' to quit): "
    states = dict1.keys()
    choice = input(msg)
    while choice!=QUIT:
        checker = choice in dict1
        if(choice == SHOW_ALL):
            for state in states:
                print(state)
        else:
            if checker:
                print("The capital of",choice,"is",dict1[choice])
            else:
                print("Sorry,",choice,"is not a state")
        choice = input(msg)
    print("Thank you for using the State Capital Lookup System!")
main()

    

