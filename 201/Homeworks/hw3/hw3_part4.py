# File: hw3_part4.py
# Author: Daniel Diseroad
# Date: 9/22/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program asks for a day of the month and gives the user the corresponding day of the
# week.
# Collaboration:
# I did not collaborate with anyone on this assignment.
def main():
    monthNum = int(input("Please enter the day of the month: "))
    dayNum = monthNum % 7
    if monthNum < 1 or monthNum >= 31:
        print("The date", monthNum, "is an invalid day.")
    elif dayNum == 1:
        print("Today is a Sunday!")
    elif dayNum == 2:
        print("Today is a Monday!")
    elif dayNum == 3:
        print("Today is a Tuesday!")
    elif dayNum == 4:
        print("Today is a Wednesday!")
    elif dayNum == 5:
        print("Today is a Thursday!")
    elif dayNum == 6:
        print("Today is a Friday!")
    elif dayNum == 0:
        print("Today is a Saturday!")

        
main()
