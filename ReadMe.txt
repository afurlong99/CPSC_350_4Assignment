# Aleksei Furlong
# 2297345
# furlong@chapman.edu
# List of Sources:
DLinkedList.h: Class that doublylinkedlist and connected template classes
main.cpp: Class with main function to run code
Student.h: getters and setters for waitTime,windowTime,avgWindowTime and arrivalTime
Simulation.h: includes reader, stat and simulator functions
testmain.cpp: opening files
Window.h: getters and setters for setisAvailable, getisAvailable,getidle and setidle

# Issue 1: When assigning students to window, students are not chose
simulataneously When arrival time is the same as the student are processed at
one tick at a time. In essense simultaenous allocation of students was my only
issue .Inserted print statement through code for debugging process in order to
show correct processing of students.

List of References:
Gary Zeri = Chapman CPSC tutor
Natanael Alpay = Chapman CPSC tutor
Saman Kashanchi = Assignment Partner
Template Classes:https://www.cplusplus.com/doc/oldtutorial/templates/
