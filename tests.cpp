#include "gtest/gtest.h"
#include "student_database.h"
#include <vector>

class StudentDatabaseTest : public ::testing::Test {
protected:
  void SetUp() override {
    db.clear();
    student1 = {"Ivan", 20, "CS", 4.5};
    student2 = {"Maria", 22, "Physics", 4.8};
    student3 = {"Peter", 20, "CS", 4.2};
  }

  std::vector<Student> db;
  Student student1;
  Student student2;
  Student student3;
};

TEST_F(StudentDatabaseTest, AddStudentToEmptyDatabase) {
  ASSERT_EQ(db.size(), 0); 
  addStudent(db, student1);
  ASSERT_EQ(db.size(), 1); 
  EXPECT_EQ(db[0].name, "Ivan"); 
}

TEST_F(StudentDatabaseTest, FindStudentByName) {
  addStudent(db, student1);
  addStudent(db, student2);
  
  std::vector<Student> results = findStudents(db, "Maria");
  ASSERT_EQ(results.size(), 1);
  EXPECT_TRUE(results[0] == student2);
}

TEST_F(StudentDatabaseTest, FindStudentsByMajor) {
  addStudent(db, student1);
  addStudent(db, student2);
  addStudent(db, student3);

  std::vector<Student> results = findStudents(db, "CS");
  ASSERT_EQ(results.size(), 2);
  EXPECT_TRUE(results[0] == student1);
  EXPECT_TRUE(results[1] == student3);
}

TEST_F(StudentDatabaseTest, FindInEmptyDatabase) {
  std::vector<Student> results = findStudents(db, "Ivan");
  EXPECT_TRUE(results.empty());
}

TEST_F(StudentDatabaseTest, FindNonExistentStudent) {
  addStudent(db, student1);
  std::vector<Student> results = findStudents(db, "Alex");
  EXPECT_TRUE(results.empty());
}

TEST_F(StudentDatabaseTest, SearchIsCaseSensitive) {
  addStudent(db, student1); 
  std::vector<Student> results = findStudents(db, "cs"); 
  EXPECT_TRUE(results.empty()); 
}

TEST_F(StudentDatabaseTest, FindByNameWhenNameMatchesMajor) {
    Student student4 = {"CS", 25, "AI", 5.0};
    addStudent(db, student1); 
    addStudent(db, student4); 

    std::vector<Student> results = findStudents(db, "CS");
    ASSERT_EQ(results.size(), 2);
    EXPECT_TRUE(results[0] == student1);
    EXPECT_TRUE(results[1] == student4);
}