# File: hw5_part4.py
# Author: Daniel Diseroad
# Date: 10/6/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program creates a box with dimensions determined by the user.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    bigString = input("First (longer) string: ").lower()
    littleString = input("Second (shorter) string: ").lower()
    lowerString = littleString.lower()
    #this for loop looks at the characters in each string through searching 
    #different groups of characters
    for index in range(len(bigString)):
        for index2 in range(len(bigString)):
            if bigString[index:index2] == lowerString:
                print ("At index",index,"found a slice of", littleString)
main()
