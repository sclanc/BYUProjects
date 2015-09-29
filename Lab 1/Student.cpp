// Project 1
// Author: Sean Clancy

#include "Student.h"

Student::Student(int studentidin, string studentnamein, string studentaddressin, string studentphonein)
{
	studentphone=studentphonein;
	studentname=studentnamein;
	studentaddress=studentaddressin;
	studentid=studentidin;
}

vector<Student> student::infile()
{
	vector<Student> students;
	int studentidin;
    string studentaddressin;
    string studentphonein;
    string studentnamein;

	ifstream in;
	in.open(argv[1]);
	if(in.is_open)
	{
		while(!in.eof())
		{
			getline(in, studentidin);
			getline(in, studentnamein);
			getline(in, studentaddressin);
			getline(in, studentphonein);
			student newstudent(int studentidin, string studentnamein, string studentaddressin, studentphonein)
			students.pushback(newstudent);
		}
		in.close;
	}
return students;
}

