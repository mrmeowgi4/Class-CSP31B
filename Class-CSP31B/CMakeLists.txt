
# note to csp:
# Whatever you need, just uncomment it from here
#
# ok bye
add_executable (Class-CSP31B "Lab04/Question1/Lab04.cpp"  "Lab04/Question1/Triangle.h" "Lab04/Question1/GeometricObject.h" "Lab04/Question1/GeometricObject.cpp" "Lab04/Question1/Triangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Class-CSP31B PROPERTY CXX_STANDARD 20)
endif()

