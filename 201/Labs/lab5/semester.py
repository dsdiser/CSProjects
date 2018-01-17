# File:    semester.py
# Started: by Dr. Gibson
# Author:  Daniel Diseroad
# Date:    10/4/16
# Section: 28
# E-mail:  ddiser1@umbc.edu 
# Description:
#   This file contains python code that asks the user for their
#   courses, then goes through the list and asks them for their
#   raw grade for each course, removes the course from the list, 
#   and calculates and prints their average grade for the semester.

def main():

    # constant for the sentinel value, and an empty list to start
    COURSE_SENTINEL = "NONE"
    courseList = []

    # populate the course list
    course = input("What course did you take? ('NONE' to stop): ")

    #### YOU NEED TO PUT A WHILE LOOP HERE
    while(course != COURSE_SENTINEL):
        # save the course and ask for another
        courseList.append(course)
        course = input("What course did you take? ('NONE' to stop): ")
    
    # create variables to help calculate the student's average
    listLen = len(courseList)
    gradeTotal = 0
    # go through the course list; continue while the list is not empty
    while(len(courseList) !=0):
        # ask about their grade for each course and save it to the total
        prompt = "What raw grade did you get in " + courseList[0]+ "? "
        grade = float(input(prompt))
        gradeTotal += grade
        # remove() the course from the list
        courseList.remove(courseList[0])
    
    # calculate their average raw grade
    average = gradeTotal / listLen

    # print out their average raw grade
    print("In the", listLen, "courses you took, you recieved a", average, "as your average raw grade.")

main()
