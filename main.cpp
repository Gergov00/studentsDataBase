#include <iostream>
#include <limits>
#include "student_database.h"

void printStudent(const Student& student) {
    std::cout << "  Имя: " << student.name << "\n";
    std::cout << "  Возраст: " << student.age << "\n";
    std::cout << "  Специальность: " << student.major << "\n";
    std::cout << "  Средний балл: " << student.gpa << "\n\n";
}

void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    std::cout << "--- Список студентов ---\n";
    for (const auto& student : database) {
        printStudent(student);
    }
}

void handleAddStudent(std::vector<Student>& database) {
    Student newStudent;
    std::cout << "Введите имя студента: ";
    std::cin >> newStudent.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> newStudent.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> newStudent.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> newStudent.gpa;

    addStudent(database, newStudent);
    std::cout << "Студент успешно добавлен.\n";
}

void handleSearch(const std::vector<Student>& database) {
    std::cout << "Введите имя или специальность для поиска: ";
    std::string query;
    std::cin >> query;

    std::vector<Student> results = findStudents(database, query);

    if (results.empty()) {
        std::cout << "Студенты не найдены.\n";
    } else {
        std::cout << "--- Результаты поиска ---\n";
        displayStudents(results);
    }
}

int main() {
    std::vector<Student> database;
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Поиск студентов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                handleAddStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                handleSearch(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}