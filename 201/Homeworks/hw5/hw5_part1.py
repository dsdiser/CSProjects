# File: hw5_part1.py
# Author: Daniel Diseroad
# Date: 10/6/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program creates a modulus table determined by the user.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    modBy = int(input("Please enter the number to mod by: "))
    maxNum = int(input("Please enter how high you'd like to go: "))
    answer = 0
#this for loop figures out the mod of the number through iteration
    for index in range(maxNum+1):
        answer = index % modBy
        print(index,"%", modBy,"=", answer)
main()
