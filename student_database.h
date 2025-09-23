#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <string>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    bool operator==(const Student& other) const {
        return name == other.name && age == other.age &&
               major == other.major && gpa == other.gpa;
    }
};

/**
 * @brief Добавляет готовый объект студента в базу данных.
 * @param database Ссылка на вектор-базу данных.
 * @param student Константная ссылка на объект студента для добавления.
 */
void addStudent(std::vector<Student>& database, const Student& student);

/**
 * @brief Ищет студентов по имени или специальности.
 * @param database Константная ссылка на базу данных для поиска.
 * @param query Строка для поиска (имя или специальность).
 * @return Вектор найденных студентов.
 */
std::vector<Student> findStudents(const std::vector<Student>& database, const std::string& query);

#endif