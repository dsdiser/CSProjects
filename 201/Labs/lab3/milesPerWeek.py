# File: milesPerWeek.py 
# Author: Daniel Diseroad 
# Date: 9/20/16
# Section: 28 
# E-mail: ddiser1@umbc.edu 
# Description: This program assists the user in finding the number of miles they drive per week to work. 
# Collaboration: During lab, collaboration between students is allowed, although I understand I still must
# understand the material and complete the assignment myself. 

def main():
    milesToWork = float(input("How many miles do you drive each way to work?"))
    daysDriven = int(input("How many days do you drive to work each week?"))
    CAR_SPEED = 57
    totalMiles = (milesToWork * daysDriven) * 2
    hoursSpent = totalMiles / CAR_SPEED
    print("You drive " , totalMiles," miles per week.")
    print("At " , CAR_SPEED , " mph, you spend " , hoursSpent , " hours commuting in the car each week.")
main()

