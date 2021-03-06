# File:        palindrome.py
# Author:      Daniel Diseroad
# Date:        10/11/16
# Section:     28
# E-mail:      ddiser1@umbc.edu
# Description: This program checks for palindromes in the user's input.
# Collaboration: During lab, collaboration between students is allowed,
#                although I understand I still must understand the material
#                and complete the assignment myself. 

def main():
    palindrome = input("Enter a string: ")
    palinLower = palindrome.lower()
    palinReverse = ""
    for i in range(len(palindrome)-1,-1,-1):
        palinReverse = palinReverse + palinLower[i]
    if (palinLower == palinReverse):
        print(palindrome, "is a palindrome")
    else:
        print(palindrome, "is not a palindrome")

main()
