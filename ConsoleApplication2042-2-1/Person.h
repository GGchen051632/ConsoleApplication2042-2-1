#pragma once
#include <string>
using namespace std;

class Person
{
private:
	string id;
	string lastName;
	string firstName;
	string gender;
	string birthDate;

public:
	// Constructor, «Øºc¤l, «Øºc¨ç¼Æ
	Person(const string& id, const string& lastName, const string& firstName, const string& gender, const string& birthDate);
	Person();

	// Getter, ¨ú­È¨ç¼Æ
	string getId() const;
	string getLastName() const;
	string getFirstName() const;
	string getGender() const;
	string getBirthDate() const;

	// Setter, ³]­È¨ç¼Æ
	void setId(const string& id);
	void setLastName(const string& lastName);
	void setFirstName(const string& firstName);
	void setGender(const string& gender);
	void setBirthDate(const string& birthDate);

	void display() const;
};