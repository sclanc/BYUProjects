//Project 1 CS2354
// Author: Sean Clancy 

#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "Grades.h"

using namesapce std;

int main(int argc,char* argv[])
{
vector<Student> students; 
students = Student::infile();
return 0;
}