# File:        graduation.py
# Author:      Daniel Diseroad
# Date:        11/8/16
# Section:     28
# E-mail:      ddiser1@umbc.edu
# Description: This program uses a text file to get information about students and output it into another txt file
# Collaboration: During lab, collaboration between students is allowed,
#                although I understand I still must understand the material
#                and complete the assignment myself. 

def main():
    roster = open("roster.txt","r")
    announcements = open("announcements.txt","w")
    valeGpa = []
    valeN = []
    for line in roster:
        degree, gpa, lastN, firstN = line.split(";")
        firstN = firstN[:-1]
        name = firstN + " " + lastN
        valeGpa.append(gpa)
        valeN.append(name)
        line = name + " is graduating with a degree in " + degree + "\n"
        print(line)
        announcements.write(line)
    highest,index = 0,0
    for i in range(len(valeGpa)):
        if float(valeGpa[i]) > highest:
            highest = float(valeGpa[i])
            index = i
    print("The student with the highest GPA is", valeN[index],"with an",valeGpa[index])
    roster.close()
    announcements.close()
main()
