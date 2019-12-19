StudGroup::StudGroup()
{
}


StudGroup::~StudGroup()
{
	students.clear();
}

void StudGroup::CreateStudList()
{
	students.clear();
	string ans;

	do
	{
		Student ns = getStudent();
		students.push_back(ns);

		cout << "Информация добавлена. Добавить ещё? (да/НЕТ) ";
		cin >> ans;
		std::transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
	} while (ans == "да");
}

void StudGroup::AddStudent()
{
	Student ns = getStudent();
	students.push_back(ns);
	cout << "Информация добавлена" << endl;
}

void StudGroup::RemoveStudent()
{
	int del_id;
	cout << "Введите ID студента, которого хотите удалить: ";
	cin >> del_id;

	vector<Student>::iterator it = students.begin();
	for (; it != students.end(); it++)
	{
		if (it->id == del_id)
		{
			students.erase(it);
			cout << "Студент удалён" << endl;
			return;
		}
	}
	
	cout << "Студент c заданым ID не найден" << endl;
	return;
}

void StudGroup::SearchBySurname()
{
	string wanted_surname;
	cout << "Введите фамилию искомого студента: ";
	cin >> wanted_surname;

	vector<Student> res_list;
	vector<Student>::iterator it = students.begin();

	for (; it != students.end(); it++)
	{
		if (it->surname == wanted_surname)
			res_list.push_back(*it);
	}

	if (!res_list.empty())
	{
		cout << "Список найденных студентов:" << endl;
		showStudList(res_list);
	}
	else
		cout << "Студенты с указанной фамилией не найдены" << endl;
}

void StudGroup::ShowAllStudents()
{
	showStudList(students);
}

void StudGroup::SortStudList(int field_num)
{
	int size = students.size();
	bool f = false;

	for (int i = 0; i < size - 1; i ++)
	{
		for (int j = 0; j < size - i - 1; j ++)
		{
			switch (field_num)
			{
			case 1:
				f = (students[j].id > students[j + 1].id);
				break;
			case 2:
				f = (students[j].surname > students[j + 1].surname);
				break;
			case 3:
				f = (students[j].name > students[j + 1].name);
				break;
			case 4:
				f = (students[j].patronymic > students[j + 1].patronymic);
				break;
			case 5:
				f = (students[j].birth_date > students[j + 1].birth_date);
				break;
			default:
				break;
			}

			if (f)
				swap(students[j], students[j + 1]);
		}
	}

	cout << "Сортировка выполнена" << endl;
}

void StudGroup::showStudList(vector<Student> lst)
{
	if (lst.empty())
	{
		cout << "Список пуст" << endl;
		return;
	}

	cout << " ID |     Фамилия Имя Отчество     | Дата рождения | Номер телефона " << endl;
	cout << "----|------------------------------|---------------|----------------" << endl;

	vector<Student>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		cout << setw(3) << it->id << " |";
		cout << setw(31) << (it->surname + " " + it->name + " " + it->patronymic + " |");
		cout << setw(14) << it->birth_date << " |";
		cout << setw(15) << it->phone_number << endl;
	}
	cout << endl;
}

void StudGroup::SaveStudFile(const char * fileName)
{
	ofstream studFile;
	studFile.open(fileName);

	vector<Student>::iterator it = students.begin();
	for (; it != students.end(); it++)
	{
		studFile << it->id << " ";
		studFile << it->surname << " ";
		studFile << it->name << " ";
		studFile << it->patronymic << " ";
		studFile << it->birth_date << " ";
		studFile << it->phone_number << endl;
	}

	studFile.flush();
	studFile.close();
	cout << "Сохранение выполнено" << endl;
}

void StudGroup::LoadStudFile(const char * fileName)
{
	ifstream studFile;
	studFile.open(fileName);
	if (!studFile.is_open())
	{
		cout << "Ошибка чтения файла" << endl;
		return;
	}

	students.clear();
	int n_id;

	do
	{
		studFile >> n_id;
		Student st(n_id);

		if (studFile.eof())
			break;

		studFile >> st.surname;
		studFile >> st.name;
		studFile >> st.patronymic;
		studFile >> st.birth_date;
		studFile >> st.phone_number;
		students.push_back(st);
	}
	while (!studFile.eof());

	studFile.close();
	cout << "Из файла прочитано " << students.size() << " записей" << endl;
}

int StudGroup::getFreeID()
{
	bool f = false;
	int n_id = 1;

	while (!f)
	{
		f = true;
		vector<Student>::iterator it = students.begin();

		for (; it != students.end(); it++)
		{
			if (n_id == it->id)
			{
				f = false;
				n_id++;
				break;
			}
		}
	}

	return n_id;
}

Student StudGroup::getStudent()
{
	Student stud(getFreeID());
	cout << "Введите информацию о студенте:" << endl;

	cout << "Фамилия: ";
	cin >> stud.surname;
	cout << "Имя: ";
	cin >> stud.name;
	cout << "Отчество: ";
	cin >> stud.patronymic;
	cout << "Дата рождения (ГГГГ.ММ.ДД): ";
	cin >> stud.birth_date;
	cout << "Номер телефона: ";
	cin >> stud.phone_number;

	return stud;
}
