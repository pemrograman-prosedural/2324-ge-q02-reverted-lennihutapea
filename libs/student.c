#include "student.h"
#include <string.h>
#include <stdio.h>


struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender)
{
  struct student_t std;
  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  std.gender=_gender;
  std.dorm = NULL;
  return std;
}

void print_student(struct student_t *_students)
{

  printf("%s|", _students->id);
  printf("%s|", _students->name);
  printf("%s|", _students->year);
  if(_students->dorm == 0)
  {
      if (_students->gender == 0)
    {
      printf("male|unassigned\n");
    }
    else if (_students->gender == 1)
    {
      printf("female|unassigned\n");
    }
  }

  else
  {
    if (_students->gender == 0)
    {
      printf("male|");
      printf("%s\n", _students->dorm->name);
    }
    else if (_students->gender == 1)
    {
      printf("female|");
      printf("%s\n", _students->dorm->name);
    }
  }
}