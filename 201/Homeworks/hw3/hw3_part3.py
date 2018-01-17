# File: hw3_part3.py
# Author: Daniel Diseroad
# Date: 9/22/16
# Section: 28
# E-mail: ddiser1@umbc.edu
# Description:
# This program asks the user for the temperature in Kelvin or Celsius and tells the user
# whether water is a liquid, gas, or solid at that temperature.
# Collaboration:
# I did not collaborate with anyone on this assignment.

def main():
    tempNum = float(input("Please enter the temperature: "))
    tempScale = input("Please enter 'C' for Celsius, or 'K' for Kelvin: ")
    if tempScale == "C":
        if tempNum <= 0:
            print("At this temperature, water is a (frozen) solid.")
        elif tempNum > 0 and tempNum < 99.99:
            print("At this temperature, water is a liquid.")
        else:
            print("At this temperature, water is a gas.")
    else:
        if tempNum <= 273.16:
            print("At this temperature, water is a (frozen) solid.")
        elif tempNum > 273.16 and tempNum < 373.16:
            print("At this temperature, water is a liquid.")
        else:
            print("At this temperature, water is a gas.")
main()
