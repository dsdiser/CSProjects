# File: hw3_part2.py
# Author: Daniel Diseroad
# Date: 9/22/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program finds the breed of the user's dog by asking questions about the dog.
# 
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    question1 = input("Is the dog a big dog?")
    if question1 == "no":
        question2 = input("Does the dog have a curly tail?")
        if question2 == "no":
            print("Your dog is a Corgi!")
        else:
            print("Your dog is a Shiba Inu!")
    else:
        question2 = input("Does the dog have a fluffy coat?")
        if question2 == "yes":
            print("Your dog is a Samoyed!")
        else:
            question3 = input("Do the dog's ears stick up?")
            if question3 == "yes":
                print("Your dog is a German Shepard!")
            else:
                print("Your dog is a Borzoi!")
main()
