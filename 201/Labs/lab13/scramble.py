# File:    scramble.py
# Started: by Dr. Gibson
# Author:  Daniel Diseroad
# Date:    12/6/16
# Section: 28
# E-mail:  ddiser1@umbc.edu
# Description:
#   This file contains python code that computes all of 
#   the possible combinations of a string's characters.
# Collaboration: During lab, collaboration between students is allowed,
#                although I understand I still must understand the material
#                and complete the assignment myself. 

# permute() is a recursive function that scrambles a string
# Input:    2 strings; the scrambled word so far, 
#                      and the letters left to scramble
# Output:   no output; prints out each completed scramble as it's created
def permute(currentScramble, lettersLeft):

    # if the list of letters remaining is _______, stop recursing
    if len(lettersLeft)==0:
        # and print out the ______ variable to see the result
        print(currentScramble)

    # otherwise
    else:
        # for each letter still available for scrambling
        for letter in lettersLeft:
            # create a copy of the list without the letter
            # this line of code replaces the FIRST 'letter' with a space
            temp  = lettersLeft.replace(letter, "", 1)

            # create a copy of the scrambled word that includes the new letter
            temp2 = currentScramble+letter

            # call the recursive function with the new variables
            permute(temp2,temp)

def main():

    print("Welcome to the Scrambler!")
    word = input("Please enter a string to scramble: ")

    # call the recursive function here
    permute("",word)

    print("Thank you for using the Scrambler!\n")

main()

    

