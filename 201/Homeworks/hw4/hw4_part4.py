# File: hw4_part4.py
# Author: Daniel Diseroad
# Date: 9/29/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program simulates the up and down movement of a hailstone in a storm.
# Collaboration:
# Collaboration was not allowed on this assignment.

def main():
    height = int(input("Please enter the starting height of the hailstone: "))
    while height != 1:
        print("Hail is currently at height",height)
        if height % 2 ==0:
            height //= 2
        else:
            height = (height*3) + 1
    print("Hail stopped at height", height)
main()
