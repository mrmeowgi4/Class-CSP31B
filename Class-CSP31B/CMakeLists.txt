
# note to csp31b students:
# Whatever you need, just uncomment it from here
#
# ok bye


### LAB 04 ###
#add_executable (Class-CSP31B "Lab04/Question1/Lab04.cpp"  "Lab04/Question1/Triangle.h" "Lab04/Question1/GeometricObject.h" "Lab04/Question1/GeometricObject.cpp" "Lab04/Question1/Triangle.cpp" "Lab04/Question2/Main.cpp") # QUESTION 1
#add_executable (Class-CSP31B "Lab04/Question2/Main.cpp" "Lab04/Question2/Person.h" "Lab04/Question2/Person.cpp" "Lab04/Question2/MyDate.h" "Lab04/Question2/Student.h" "Lab04/Question2/Employee.h" "Lab04/Question2/FacultyMember.h" "Lab04/Question2/FacultyMember.cpp" "Lab04/Question2/Employee.cpp" "Lab04/Question2/Student.cpp" "Lab04/Question2/Staff.h" "Lab04/Question2/Staff.cpp") # QUESTION 2
### END OF LAB 04 ###


##LAB 05##
add_executable (Class-CSP31B "Lab05/Question1/Main.cpp") # QUESTION 2
## END OF LAB 05 ##

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Class-CSP31B PROPERTY CXX_STANDARD 20)
endif()

