
# note to csp31b students:
# Whatever you need, just uncomment it from here
#
# ok bye


### LAB 04 ###
#add_executable (Class-CSP31B "Lab04/Question1/Lab04.cpp"  "Lab04/Question1/Triangle.h" "Lab04/Question1/GeometricObject.h" "Lab04/Question1/GeometricObject.cpp" "Lab04/Question1/Triangle.cpp" "Lab04/Question2/Main.cpp") # QUESTION 1
#add_executable (Class-CSP31B "Lab04/Question2/Main.cpp" "Lab04/Question2/Person.h" "Lab04/Question2/Person.cpp" "Lab04/Question2/MyDate.h" "Lab04/Question2/Student.h" "Lab04/Question2/Employee.h" "Lab04/Question2/FacultyMember.h" "Lab04/Question2/FacultyMember.cpp" "Lab04/Question2/Employee.cpp" "Lab04/Question2/Student.cpp" "Lab04/Question2/Staff.h" "Lab04/Question2/Staff.cpp") # QUESTION 2
### END OF LAB 04 ###


##LAB 05##
#add_executable (Class-CSP31B "Lab05/Question1/Main.cpp") # QUESTION 1
#add_executable (Class-CSP31B "Lab05/Question2/Main.cpp" "Lab05/Question2/Account.h" "Lab05/Question2/MyDate.h" "Lab05/Question2/Checking.h" "Lab05/Question2/Saving.h") # QUESTION 2
## END OF LAB 05 ##


## LAB 06
#add_executable (Class-CSP31B "Lab06/Question1/Main.cpp "Lab06/Question2/Main.cpp"")
#add_executable (Class-CSP31B "Lab06/Question2/Main.cpp")
## END OF LAB 06



## LAB 07
#add_executable (Class-CSP31B "Lab07/Question1/Main.cpp")
#add_executable (Class-CSP31B "Lab07/Question2/Main.cpp")
## END OF LAB 07

## LAB 08
#add_executable (Class-CSP31B "Lab08/Question1/Main.cpp" "Lab08/Question1/LinkedList.h" "Lab08/Question1/LinkedList.cpp")
## END OF LAB 08

## LAB 09
#add_executable (Class-CSP31B "Lab09/Question1/Main.cpp"  )
## END OF LAB 09

## LAB 10
#add_executable (Class-CSP31B "Lab10/Question1/Main.cpp" "Lab10/Question1/bst.h" "Lab11/Question1/Main.cpp")
## END OF LAB 10

## LAB 11
#add_executable (Class-CSP31B "Lab11/Question2/Main.cpp")
## END OF LAB 11


## LAB 12
add_executable (Class-CSP31B "Lab12/Question1/Main.cpp")
## END OF LAB 12

# MISC
#add_executable (Class-CSP31B "MISC/Main.cpp" "MISC/BST.h")
# END OF MISC

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Class-CSP31B PROPERTY CXX_STANDARD 20)
endif()

