# File:        polite.py
# Author:      Daniel Diseroad
# Date:        9/27/16
# Section:     28
# E-mail:      ddiser1@umbc.edu
# Description: This program will tell the user whether they are polite or "utterly rude!"
# Collaboration: During lab, collaboration between students is allowed,
#                although I understand I still must understand the material
#                and complete the assignment myself.
def main():
    word = input("Please enter a word: ")
    if word == "please" or word== "thanks" or word== "pardon":
        print("Your manners are impeccable!")
    else:
        print("How utterly rude!")
main()
