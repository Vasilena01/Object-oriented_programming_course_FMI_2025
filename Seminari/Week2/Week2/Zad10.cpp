#include "Zad10.h"

const char* getFileName()
{
    char filename[GLOBAL_CONSTANTS::FILENAME_SIZE];
    std::cin >> filename;
    return filename;
}

void copyFileToFile(const char* src, const char* dest)
{
    std::ifstream sourceFile(src);
    if (!sourceFile.is_open()) {
        return;
    }

    std::ofstream destinationFile(dest);
    if (!destinationFile.is_open()) {
        return;
    }

    char buff[GLOBAL_CONSTANTS::SIZE];
    while (sourceFile.getline(buff, sizeof(buff)))
    {
        destinationFile << buff << '\n';
    }

    sourceFile.close();
    destinationFile.close();
}

ElectiveCourse& extractCourseInfo(const char* buff)
{
    ElectiveCourse newCourse;
    int index = 0;
    char temp[GLOBAL_CONSTANTS::SIZE];

    extractField(buff, temp, index);
    newCourse.id = std::atoi(temp);

    extractField(buff, newCourse.name, index);

    extractField(buff, temp, index);
    newCourse.category = getCategory(temp);

    extractField(buff, temp, index);
    newCourse.creditsCount = std::atoi(temp);

    extractField(buff, temp, index);
    newCourse.examType = getExamType(temp);

    return newCourse;
}

ElectiveCourse* getDataFromFile(const char* filename, unsigned& coursesCount)
{
    ElectiveCourse* courses = new ElectiveCourse[GLOBAL_CONSTANTS::MAX_COURSES_SIZE];
    std::ifstream file(filename);

    if (!file.is_open())
        return nullptr;

    char buff[1024];
    file.getline(buff, sizeof(buff));

    while (file.getline(buff, sizeof(buff)))
    {
        ElectiveCourse newCourse = extractCourseInfo(buff);
        courses[coursesCount++] = newCourse;
    }

    return courses;
}

void saveCoursesToFile(const char* filename, const ElectiveCourse* courses, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        saveCourseToFile(filename, courses[i]);
    }
}

void saveCourseToFile(const char* filename, const ElectiveCourse& course)
{
    std::fstream file(filename, std::ios::in | std::ios::out);
    if (!file.is_open())
        return;

    std::ofstream tempFile("temp.csv");
    if (!tempFile.is_open())
        return;
    // Check if course already exists in file
    if (containsCourse(file, course.id))
    {
        file.seekp(0, std::ios::beg);
        char buff[GLOBAL_CONSTANTS::SIZE];

        while (file.getline(buff, sizeof(buff))) {
            int index = 0;
            char temp[GLOBAL_CONSTANTS::SIZE];

            extractField(buff, temp, index);
            int id = std::atoi(temp);

            if (id == course.id) {
                tempFile << course.id << ','
                    << course.name << ','
                    << getCategoryId(course.category) << ','
                    << course.creditsCount << ','
                    << course.examType << '\n';
            }
            else {
                tempFile << buff << '\n';
            }
        }
    }
    else
    {
        // Check if the file is empty
        file.seekp(0, std::ios::end);
        if (file.tellp() == 0)
        {
            tempFile << "id, name, category, creditsCount, examType\n";
        }

        tempFile << course.id << ','
            << course.name << ','
            << getCategoryId(course.category) << ','
            << course.creditsCount << ','
            << course.examType << '\n';
    }

    copyFileToFile(filename, "temp.csv");
}

void removeCourseById(const char* filename, unsigned id)
{
    std::fstream file(filename, std::ios::in | std::ios::out);
    if (!file.is_open())
        return;

    std::ofstream tempFile("temp.csv");
    if (!tempFile.is_open())
        return;

    file.seekp(0, std::ios::beg);
    char buff[GLOBAL_CONSTANTS::SIZE];

    while (file.getline(buff, sizeof(buff))) {
        int index = 0;
        char temp[GLOBAL_CONSTANTS::SIZE];

        extractField(buff, temp, index);
        int currid = std::atoi(temp);

        if (currid == id) {
            continue;
        }
        else {
            tempFile << buff << '\n';
        }
    }

    copyFileToFile(filename, "temp.csv");
}

unsigned getCategoryId(const Category& category)
{
    switch (category)
    {
    case Category::OKN: return 1; break;
    case Category::M: return 2; break;
    case Category::PM: return 3; break;
    case Category::PR: return 4; break;
    default: return 5; break;
    }
}

Category getCategory(const char* category)
{
    int categoryId = std::atoi(category);
    switch (categoryId)
    {
    case 1: return Category::OKN; break;
    case 2: return Category::M; break;
    case 3: return Category::PM; break;
    case 4: return Category::PR; break;
    default: return Category::OTHER; break;
    }
}

void printCategory(const Category& category)
{
    switch (category)
    {
    case Category::OKN: std::cout << "OKN"; break;
    case Category::M: std::cout << "M"; break;
    case Category::PM: std::cout << "PM"; break;
    case Category::PR: std::cout << "PR"; break;
    default: std::cout << "OTHER"; break;
    }
}

unsigned char getExamType(const char* type)
{
    unsigned char numType = std::atoi(type);
    unsigned char resType = 0;
    int mask = 1;

    if (mask & numType)
    {
        resType |= ExamType::EXAM;
    }
    mask <<= 1;

    if (mask & numType)
    {
        resType |= ExamType::COURSE_PROJECT;
    }
    mask <<= 1;

    if (mask & numType)
    {
        resType |= ExamType::TEST;
    }

    return resType;
}

void printExamType(unsigned char type)
{
    int mask = 1;

    if (mask & type)
    {
        std::cout << "Exam" << " ";
    }
    mask <<= 1;

    if (mask & type)
    {
        std::cout << "Course Project" << " ";
    }
    mask <<= 1;

    if (mask & type)
    {
        std::cout << "Test";
    }
}

void extractField(const char* line, char* output, int& index)
{
    int i = 0;
    while (line[index] != ',' && line[index] != '\0')
    {
        output[i++] = line[index++];
    }

    output[i] = '\0';
    if (line[index] == ',')
    {
        index++;
    }
}

bool containsCourse(std::fstream& file, unsigned searchedId)
{
    file.seekp(0, std::ios::end);
    if (file.tellp() == 0)
        return false;

    file.seekp(0, std::ios::beg);
    char buff[GLOBAL_CONSTANTS::SIZE];
    file.getline(buff, sizeof(buff));
    while (file.getline(buff, sizeof(buff)))
    {
        int index = 0;
        char temp[GLOBAL_CONSTANTS::SIZE];

        extractField(buff, temp, index);
        int id = std::atoi(temp);
        if (id == searchedId)
            return true;
    }
    return false;
}

void printCourse(const ElectiveCourse& course)
{
    std::cout << course.id << " " << course.name << " ";
    printCategory(course.category);
    std::cout << course.creditsCount << " ";
    printExamType(course.examType);
}

void printCourseById(ElectiveCourse* courses, unsigned& coursesCount, unsigned id)
{
    for (int i = 0; i < coursesCount; i++)
    {
        if (courses[i].id == id)
        {
            printCourse(courses[i]);
            break;
        }
    }
}

void printCoursesByCategory(ElectiveCourse* courses, unsigned& coursesCount, const Category& category)
{
    for (int i = 0; i < coursesCount; i++)
    {
        if (courses[i].category == category)
        {
            printCourse(courses[i]);
            std::cout << std::endl;
        }
    }
}

void printCourseWithCreditsInInterval(ElectiveCourse* courses, unsigned& coursesCount, unsigned minval, unsigned maxval)
{
    for (int i = 0; i < coursesCount; i++)
    {
        int currCredits = courses[i].creditsCount;
        if (currCredits >= minval && currCredits <= maxval)
        {
            printCourse(courses[i]);
            std::cout << std::endl;
        }
    }
}

void input10()
{
    const char filename[GLOBAL_CONSTANTS::FILENAME_SIZE] = "izbiraemi.csv";
    ElectiveCourse courses[3] = {
        {1, "Mathematics", Category::M, 5, ExamType::EXAM},
        {2, "Programming", Category::PR, 6, ExamType::COURSE_PROJECT | ExamType::TEST},
        {3, "Physics", Category::OKN, 4, ExamType::EXAM | ExamType::TEST}
    };

    saveCoursesToFile(filename, courses, 3);
}