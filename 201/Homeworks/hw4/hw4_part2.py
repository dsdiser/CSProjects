# File: hw4_part2.py
# Author: Daniel Diseroad
# Date: 9/29/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program computes modulus without the mod operator.
# Collaboration:
# Collaboration was not allowed on this assignment.

def main():
    num1 = int(input("Please enter the first number: "))
    num2 = int(input("Please enter the second number: "))
    differenceNum = num1-num2
    while differenceNum > 0:
        differenceNum = differenceNum - num2
    modNum = differenceNum + num2
    print(num1 , " % ",num2," = ", modNum)
main()
