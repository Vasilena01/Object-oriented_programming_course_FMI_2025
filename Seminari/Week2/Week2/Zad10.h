#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

namespace GLOBAL_CONSTANTS
{
    constexpr int ELECTIVE_COURSE_NAME_SIZE = 20;
    constexpr int FILENAME_SIZE = 50;
    constexpr int MAX_COURSES_SIZE = 1000;
    constexpr int SIZE = 1024;
}

enum Category
{
    OKN = 1,
    M,
    PM,
    PR,
    OTHER
};

enum ExamType
{
    EXAM = 1 << 0,
    COURSE_PROJECT = 1 << 1,
    TEST = 1 << 2
};

struct ElectiveCourse
{
    unsigned id;
    char name[GLOBAL_CONSTANTS::ELECTIVE_COURSE_NAME_SIZE];
    Category category;
    unsigned creditsCount;
    unsigned char examType;
};

const char* getFileName();
void copyFileToFile(const char* src, const char* dest);
ElectiveCourse& extractCourseInfo(const char* buff);
ElectiveCourse* getDataFromFile(const char* filename, unsigned& coursesCount);
void saveCourseToFile(const char* filename, const ElectiveCourse* course);
void removeCourseById(const char* filename, unsigned id);
unsigned getCategoryId(const Category& category);
Category getCategory(const char* category);
void printCategory(const Category& category);
unsigned char getExamType(const char* type);
void printExamType(unsigned char type);
void extractField(const char* line, char* output, int& index);
bool containsCourse(std::fstream& file, unsigned searchedId);
void printCourse(const ElectiveCourse& course);
void printCourseById(ElectiveCourse* courses, unsigned& coursesCount, unsigned id);
void printCoursesByCategory(ElectiveCourse* courses, unsigned& coursesCount, const Category& category);
void printCourseWithCreditsInInterval(ElectiveCourse* courses, unsigned& coursesCount, unsigned minval, unsigned maxval);
void input10();