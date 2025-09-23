#include "student_database.h"

void addStudent(std::vector<Student>& database, const Student& student) {
    database.push_back(student);
}

std::vector<Student> findStudents(const std::vector<Student>& database, const std::string& query) {
    std::vector<Student> results;
    for (const auto& student : database) {
        if (student.name == query || student.major == query) {
            results.push_back(student);
        }
    }
    return results;
}