#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <iostream>
#include <string>
#include <vector>

struct Student {
  std::string name;
  int age;
  std::string major;
  double gpa;
};

void addStudent(std::vector<Student> &database);
void print_sudent(const Student &student);
void displayStudents(const std::vector<Student> &database);
void search_by_name_or_specialty(const std::vector<Student> &database);

#endif