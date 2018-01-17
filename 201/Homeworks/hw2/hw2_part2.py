# File: hw2_part2.py
# Author: Daniel Diseroad
# Date: 9/15/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# Finds the number of dollars and cents from a float.
# Collaboration:
# Collaboration was not allowed on this assignment.

def main():
    price = float(input("What is the price?"))
    dollars = int(price)
    cents = int((price - dollars) * 100)
    print("The number of dollars is:", dollars)
    print("The number of cents is:", cents)
main()
    
