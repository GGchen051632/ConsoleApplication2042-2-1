#include <string>
#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Record.h"
#include "Utility.h"
#include "ConsoleApplication2042-2-1.h"
#include <unordered_map>
using namespace std;

// 全域變數
vector<Student> students;
vector<Teacher> teachers;
vector<Course> courses;
vector<Record> records;

// 函式宣告
void initializeData();
void displayMenu();
void listStudents();
void listCourses();
void listTeachers();
void listRecords();

int main()
{
    initializeData();
    displayMenu();
    return 0;
}

void initializeData()
{
    // 新增5筆課程資料
    courses.push_back(Course("C001", "C++ Programming", "這門課程教授C++程式語言"));
    courses.push_back(Course("C002", "Java Programming", "這門課程教授Java程式語言"));
    courses.push_back(Course("C003", "Python Programming", "這門課程教授Python程式語言"));
    courses.push_back(Course("C004", "C# Programming", "這門課程教授C#程式語言"));
    courses.push_back(Course("C005", "Visual Basic Programming", "這門課程教授Visual Basic程式語言"));

    // 新增5筆學生資料
    students.push_back(Student("S001", "陳", "小明", "男", "1999-01-01", "S001", Department::ComputerSciece, ClassName::_1A));
    students.push_back(Student("S002", "林", "小華", "男", "1999-02-02", "S002", Department::ElectricalEngineering, ClassName::_1A));
    students.push_back(Student("S003", "黃", "小美", "女", "1999-03-03", "S003", Department::InformationManagement, ClassName::_1B));
    students.push_back(Student("S004", "張", "小強", "男", "1999-04-04", "S004", Department::ComputerSciece, ClassName::_2A));
    students.push_back(Student("S005", "李", "小花", "女", "1999-05-05", "S005", Department::ElectronicEngineering, ClassName::_2B));

    // 新增2筆老師資料
    vector<Course> teacher1_courses = { courses[0], courses[1], courses[2] };
    teachers.push_back(Teacher("T001", "王", "大富", "男", "1980-7-1", "T001", Department::ComputerSciece, ClassName::_1A, teacher1_courses));
    vector<Course> teacher2_courses = { courses[3], courses[4] };
    teachers.push_back(Teacher("T002", "李", "大貴", "男", "1985-5-5", "T002", Department::InformationManagement, ClassName::_1B, teacher2_courses));

    // 新增10筆選課紀錄
    records.push_back(Record("S001", "C001"));
    records.push_back(Record("S001", "C002"));
    records.push_back(Record("S002", "C001"));
    records.push_back(Record("S002", "C003"));
    records.push_back(Record("S003", "C002"));
    records.push_back(Record("S003", "C003"));
    records.push_back(Record("S004", "C003"));
    records.push_back(Record("S004", "C004"));
    records.push_back(Record("S005", "C004"));
    records.push_back(Record("S005", "C005"));
}

void displayMenu()
{
    int choice;
    do {
        cout << "=========================" << endl;
        cout << "1. 列出學生資料" << endl;
        cout << "2. 列出課程資料" << endl;
        cout << "3. 列出教師資料" << endl;
        cout << "4. 列出選課紀錄" << endl;
        cout << "0. 退出" << endl;
        cout << "請選擇操作: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "列出學生資料" << endl;
            listStudents();
            break;
        case 2:
            cout << "列出課程資料" << endl;
            listCourses();
            break;
        case 3:
            cout << "列出教師資料" << endl;
            listTeachers();
            break;
        case 4:
            cout << "列出選課紀錄" << endl;
            listRecords();
            break;
        case 0:
            cout << "退出" << endl;
            break;
        default:
            cout << "無效選擇" << endl;
            break;
        }
    } while (choice != 0);
}

void listStudents()
{
    cout << "學生資料總共有 " << students.size() << " 筆" << endl;
    for (const auto& student : students) {
        student.display();
        cout << endl;
    }
}

void listCourses()
{
    cout << "課程資料總共有 " << courses.size() << " 筆" << endl;
    for (const auto& course : courses) {
        course.display();
        cout << endl;
    }
}

void listTeachers()
{
    cout << "教師資料總共有 " << teachers.size() << " 筆" << endl;
    for (const auto& teacher : teachers) {
        teacher.display();
        cout << endl;
    }
}

void listRecords()
{
    cout << "選課紀錄總共有 " << records.size() << " 筆\n" << endl;

    for (const auto& student : students) {
        // 顯示學生的基本資訊
        cout << "學生: " << student.getId() << " "
            << student.getLastName() + student.getFirstName() << endl;
        cout << "選修課程:" << endl;

        bool hasCourses = false;
        for (const auto& record : records) {
            if (record.getStudentId() == student.getId()) {
                hasCourses = true;
                for (const auto& course : courses) {
                    if (record.getCourseId() == course.getCourseId()) {
                        cout << "  課程編號: " << course.getCourseId()
                            << ", 課程名稱: " << course.getCourseName()
                            << ", 描述: " << course.getCourseDescription() << endl;
                    }
                }
            }
        }

        if (!hasCourses) {
            cout << "  該學生尚未選修任何課程。" << endl;
        }
    }
}
