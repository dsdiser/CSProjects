# File: hw2_part3.py
# Author: Daniel Diseroad
# Date: 9/15/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# A basic shopping list application.
# Collaboration:
# Collaboration was not allowed on this assignment.

def main():
    item1 = str(input("What would you like to buy first?"))
    print("You are buying", item1)
    amount1 = int(input("How many would you like to buy?"))
    item2 = str(input("What would you like to buy second?"))
    print("You are buying", item2)
    amount2 = int(input("How many would you like to buy?"))
    item3 = str(input("What would you like to buy third?"))
    print("You are buying", item3)
    amount3 = int(input("How many would you like to buy?"))
    totalNumber = amount1+amount2+amount3
    print("You are buying " + str(totalNumber) + " items:")
    print(amount1, item1)
    print(amount2, item2)
    print(amount3, item3)
main()
