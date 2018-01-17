#include "Student.h"

Student::Student()
{
  int numStudents = 0;
  float gpa = 0.0;
  cout << "Enter total number of students: ";
  cin >> numStudents;
  m_num = numStudents;
  m_ptr = new float[m_num];
  cout << "Enter GPA of student." << endl;
  for(int i = 0; i < m_num; i++)
    {
      cout << "Student" << i+1 << ": ";
      cin >> gpa;
      m_ptr[i] = gpa;
    }
}

Student::~Student()
{
  delete[] m_ptr;
  m_ptr = NULL;
}

void Student::Display()
{
  cout << endl << "Displaying GPA's" << endl;
  for(int i = 0; i < m_num; i++)
    {
      cout << "Student" << i+1 << ": ";
      cout << m_ptr[i] << endl;
    }
}
