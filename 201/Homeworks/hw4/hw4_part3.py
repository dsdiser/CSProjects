# File: hw4_part3.py
# Author: Daniel Diseroad
# Date: 9/29/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program helps the user find an acceptable username for UMBC.
# Collaboration:
# Collaboration was not allowed on this assignment.

MIN_LEN = 2
MAX_LEN = 8
def main():
    username = input("Please enter your username: ")
    userLen = len(username)
    while userLen < MIN_LEN or userLen > MAX_LEN:
        userLen = len(username)
        if userLen < MIN_LEN:
            print("Username is too short, it must be"
                  ,"at least",MIN_LEN,"characters.")
        elif userLen > MAX_LEN:
            print("Username is too long, must be no"
                  ,"longer than", MAX_LEN, "characters.")
        username = input("Please enter a new username: ")
        userLen = len(username)
        if (userLen >= MIN_LEN and userLen < MAX_LEN) and username[-1] != "1":
            print("Usernames under 8 characters"
                 ," must end with a '1'")
            userLen+= 8
    print("Thank you for choosing the username", username)
main()
