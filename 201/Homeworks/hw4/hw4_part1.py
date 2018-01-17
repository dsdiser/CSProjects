# File: hw4_part1.py
# Author: Daniel Diseroad
# Date: 9/29/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program tells the user whether their chosen usernames are too short or too long. It
# also reminds them of an acceptable length of a username.
# Collaboration:
# Collaboration was not allowed on this assignment.

MIN_LEN = 4
MAX_LEN = 12
def main():
    username = input("Please enter your username. ")
    userLen = len(username)
    while userLen < MIN_LEN or userLen > MAX_LEN:
        if userLen < MIN_LEN:
            print("That username is too short.")
        elif userLen > MAX_LEN:
            print("That username is too long.")
        print("The username must be between"
              , MIN_LEN,"and", MAX_LEN,"characters.")
        username = input("Please enter a new username ")
        userLen = len(username)
    print("Thank you for choosing the username", username)
main()
