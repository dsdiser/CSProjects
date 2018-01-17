# File: games.py
# Author: Daniel Diseroad
# Date: 10/16/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description: This program helps the user and their friends decide what game to play
# Collaboration: During lab, collaboration between
# students is allowed, although I understand I still
# must understand the material and complete the
# assignment myself.

def main():
    games = ["Twister", "Dodgeball", "Capture the Flag",
             "Hide and Seek", "Croquet", "Ring Toss", "Ping Pong"]
    #This for loop prints out the available games to play, starting with 1 instead of 0
    for i in range(len(games)):
        print((i+1), "-", games[i])
    choice  = 1
    choiceList = [0] * len(games)
    #This sentinel loop lets the users vote on what games they want to play and only uses
    #valid numbers
    while (choice!= 0):
        choice = int(input("What game would you like to play? "))
        if(choice>0 and choice<len(choiceList)+1):
            choiceList[choice-1] +=1
    #This for loop prints out the votes of the individual games one by one
    for i in range(len(games)):
        print(games[i],"has",choiceList[i],"votes")
main()
