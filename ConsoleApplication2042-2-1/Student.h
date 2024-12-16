#pragma once
#include "Person.h"
#include "Utility.h"

class Student : public Person
{
private:
	string studentId;
	Department department;
	ClassName className;

public:
	Student(const string& id, const string& lastName, const string& firstName, const string& gender, const string& birthDate, const string& studentId, Department department, ClassName className);

	//Getter, ¨ú­È¨ç¼Æ
	string getStudentId() const;
	Department getDepartment() const;
	ClassName getClassName() const;

	//Setter, ³]­È¨ç¼Æ
	void setStudentId(const string& studentId);
	void setDepartment(Department department);
	void setClassName(ClassName className);

	void display() const;
};