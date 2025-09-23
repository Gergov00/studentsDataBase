#include "student_database.h"

void addStudent(std::vector<Student> &database) {
  Student student;
  std::cout << "Введите имя студента: ";
  std::cin >> student.name;
  std::cout << "Введите возраст студента: ";
  std::cin >> student.age;
  std::cout << "Введите специальность студента: ";
  std::cin >> student.major;
  std::cout << "Введите средний балл студента: ";
  std::cin >> student.gpa;

  database.push_back(student);
  std::cout << "Студент добавлен в базу данных.\n";
}

void print_sudent(const Student &student) {
  std::cout << "Имя: " << student.name << "\n";
  std::cout << "Возраст: " << student.age << "\n";
  std::cout << "Специальность: " << student.major << "\n";
  std::cout << "Средний балл: " << student.gpa << "\n\n";
}

void displayStudents(const std::vector<Student> &database) {
  std::cout << "Список студентов:\n";
  for (const Student &student : database) {
    print_sudent(student);
  }
}

void search_by_name_or_specialty(const std::vector<Student> &database) {
  std::cout << "Введите имя студента или специальность: ";
  std::string target;
  std::cin >> target;
  std::vector<Student> result;
  for (const Student &student : database) {
    if (student.name == target || student.major == target) {
      result.push_back(student);   
    }
  }
  displayStudents(result);
}