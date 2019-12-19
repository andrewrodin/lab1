#include "stdafx.h"
#include "StudGroup.h"

#include <Windows.h>

int Menu();
int Menu_sort();

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const char *fileName = "stud_list.txt";
	StudGroup studGroup;
	int d = 0;

	do
	{
		d = Menu();
		switch (d)
		{
		case 1:
			studGroup.CreateStudList();
			break;
		case 2:
			studGroup.SaveStudFile(fileName);
			break;
		case 3:
			studGroup.LoadStudFile(fileName);
			break;
		case 4:
			studGroup.ShowAllStudents();
			break;
		case 5:
			studGroup.SearchBySurname();
			break;
		case 6:
			studGroup.AddStudent();
			break;
		case 7:
			studGroup.RemoveStudent();
			break;
		case 8:
			studGroup.SortStudList(Menu_sort());
			break;
		case 0:
			cout << "Выход" << endl;
			break;
		default:
			cout << "Выбранный пункт не существует, повторите ввод" << endl;
			break;
		}
		system("Pause");
	}
	while (d != 0);
	
    return 0;
}

int Menu()
{
	system("cls");
	cout << "Выберите операцию:" << endl;
	cout << "1. Создать новый список" << endl;
	cout << "2. Сохранить список в файл" << endl;
	cout << "3. Загрузить список из файла" << endl;
	cout << "4. Вывод списка в консоль" << endl;
	cout << "5. Поиск по фамилии" << endl;
	cout << "6. Добавить студента" << endl;
	cout << "7. Удалить студента" << endl;
	cout << "8. Сортировка" << endl;
	cout << "0. Выход" << endl;
	cout << "> ";

	int d;
	cin >> d;
	return d;
}

int Menu_sort()
{
	system("cls");
	cout << "Выберите поле для сортировки:" << endl;
	cout << "1. ID" << endl;
	cout << "2. Фамилия" << endl;
	cout << "3. Имя" << endl;
	cout << "4. Отчество" << endl;
	cout << "5. Дата рождения" << endl;
	cout << "> ";

	int d;
	cin >> d;
	return d;
}
