# File: hw5_part3.py
# Author: Daniel Diseroad
# Date: 10/6/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program counts down and also says weird things when the number is divisable by 5 and
# 6.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    #this for loop at the modulus of the different numbers, determining whether it should print something other than the number.
    for startNum in range(101, 0, -1):
        if ((startNum % 5) + (startNum % 6)) == 0:
            print("Thirty days hath September.")
        elif(startNum % 5) == 0:
            print("Where do you see yourself in five years?")
        elif(startNum % 6) == 0:
            print("I'll believe six impossible things before breakfast.")
        else:
            print(startNum)
main()
