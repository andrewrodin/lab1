#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student
{
	int id;

	string surname;			// фамилия
	string name;			// имя
	string patronymic;		// отчество

	string phone_number;	// номер телефона
	string birth_date;		// дата рождения

	Student (int id)
	{
		this->id = id;
	}
};

class StudGroup
{
public:
	StudGroup();
	~StudGroup();

	void CreateStudList();

	void AddStudent();
	void RemoveStudent();
	void SearchBySurname();
	void ShowAllStudents();
	void SortStudList(int field_num);

	void SaveStudFile(const char *fileName);
	void LoadStudFile(const char *fileName);

private:
	vector<Student> students;

	int getFreeID();

	Student getStudent();
	void showStudList(vector<Student> lst);
};

