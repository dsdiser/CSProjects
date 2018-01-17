# File: hw2_part1.py
# Author: Daniel Diseroad
# Date: 9/15/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# Finds the total cost to buy and ship a large order of books from an online bookstore.
# Collaboration:
# Collaboration was not allowed on this assignment.





def main():
    price = float(input("What is the price of the book?"))
    quantity = int(input("How many copies do you want?"))
    subtotal = price * quantity
    tax = subtotal * 0.06
    shipping = quantity * 6.95
    total = subtotal + tax + shipping
    print("The total cost is $", total)

main()
