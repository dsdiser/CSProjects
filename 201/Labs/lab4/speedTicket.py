# File:        speedTicket.py 
# Author:      Daniel Diseroad 
# Date:        9/27/16
# Section:     28 
# E-mail:      ddiser1@umbc.edu 
# Description: This program will help a police officer calculate the appropriate fine for 
#              driving over the speed limit.
# Collaboration: During lab, collaboration between students is allowed, 
#                although I understand I still must understand the material 
#                and complete the assignment myself. 

def main():

    speedLimit = int(input("Please enter the speed limit in MPH: "))
    currentSpeed = float(input("Please enter the driving speed in MPH: "))
    differenceSpeed = currentSpeed - speedLimit
    print("You were over the speed limit by ", differenceSpeed, " MPH")
    if differenceSpeed < 10:
       print("You recieve no ticket...this time.")
    elif differenceSpeed >= 10 and differenceSpeed <= 25:
       print("You recieve a ticket for a $75 fine.")
    elif differenceSpeed >25 and differenceSpeed < 30:
       print("You recieve a ticket for a $150 fine.")
    elif differenceSpeed >= 30:
       print("You recieve a ticket for a $500 fine, and mandatory court date.")
main()
