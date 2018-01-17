# File: hw3_part1.py
# Author: Daniel Diseroad
# Date: 9/22/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program tells whether the floating point number inputted is positive, negative, or 
# is equal to zero.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    userNum = float(input("Please enter a floating point number: "))
    if userNum > 0.0:
        print("The number",userNum,"is positive.")
    elif userNum < 0.0:
        print("The number",userNum,"is negative.")
    else:
        print("The number",userNum,"is equal to zero.")
main()
