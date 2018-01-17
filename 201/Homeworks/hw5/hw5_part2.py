# File: hw5_part2.py
# Author: Daniel Diseroad
# Date: 10/6/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program creates a box with dimensions determined by the user.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    widthBox = int(input("Please enter the width of the box: "))
    heightBox = int(input("Please enter the height of the box: "))
    symbolOutline = input("Please enter a symbol for the box outline: ")
    symbolFill = input("Please enter a symbol for the box fill: ")
    #the different lines that can be printed are made here.
    upperRow = symbolOutline*widthBox
    filler = symbolFill * (widthBox-2)
    middleRow = symbolOutline + filler + symbolOutline
    print(upperRow)
    index = 0
    #this for loop goes through the inside of the box, printing lines that need to be printed
    for index in range(0,heightBox-1):
        if (index+2)< heightBox:
            print(middleRow)
            index += 1
            if (index+2)== heightBox:
                print(upperRow)
        if heightBox == 2:
                print(upperRow)
main()
