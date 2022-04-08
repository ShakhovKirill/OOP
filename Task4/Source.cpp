#include "book.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	actions user;
	int variant;
	string BookName, Name, Publisher;
	unsigned int Day, Month, Year, ID, Pages, Quantity, Instances, Number;
	vector <string> Authors;

	do
	{
		system("cls");
		cout << "1 " << "Добавьте книгу" << endl;
		cout << "2 " << "Удалите книгу" << endl;
		cout << "3 " << "Вывод информации по книге и читателям, взявшим книгу (по идентификатору книги)" << endl;
		cout << "4 " << "Поиск книги в каталоге по названию и по автору с выдачей идентификатора" << endl;
		cout << "5 " << "Выдача книги читателю" << endl;
		cout << "6 " << "Возврат книги читателем" << endl;
		cout << "7 " << "Вывод списка читателей, не вернувших книги в течение года" << endl;
		cout << "8 " << "Выход" << endl;

		cin >> variant;
		system("cls");
		switch (variant)
		{
		case 1:
			cout << "Введите название книги: \n";
			cin >> BookName;
			cout << "\nВведите количество авторов книги:\n";
			cin >> Number;
			cout << "\nВведите автора книги:\n";
			for (int i = 1; i <= Number; i++)
			{
				cin >> Name;
				Authors.push_back(Name);
			}
			cout << "\nВведите год издательства книги:\n";
			cin >> Year;
			cout << "\nВведите издательство книги:\n";
			cin >> Publisher;
			cout << "\nВведите количество страниц книги:\n";
			cin >> Pages;
			cout << "\nВведите ID книги:\n";
			cin >> ID;
			cout << "\nВведите общее количество книг:\n";
			cin >> Quantity;
			cout << "\nВведите количество свободных книг:\n";
			cin >> Instances;
			cout << endl;
			user.AddBook(BookName, Authors, Year, Publisher, Pages, ID, Quantity, Instances);
			system("cls");
			Authors.clear();
			break;
		case 2:
			cout << "Введите данные об удаляемой книге\n" << "Введите название книги: \n";
			cin >> BookName;
			cout << endl;
			user.DeleteBook(BookName);
			break;
		case 3:
			cout << "Введите ID книги\n";
			cin >> ID;
			cout << endl;
			user.TakenInfo(ID);
			break;
		case 4:
			cout << "Введите данные о возвращаемой книге\n" << "Введите название книги: \n";
			cin >> BookName;
			cout << "Введите автора\n";
			cin >> Name;
			cout << endl;
			user.BookSearch(BookName, Name);
			break;
		case 5:
			cout << "Введите данные о возвращаемой книге\n" << "Введите название книги: \n";
			cin >> BookName;
			cout << "Введите имя: ";
			cin >> Name;
			cout << "Введите сегодняшнюю дату(отдельно день, месяц и год)\n";
			cin >> Day >> Month >> Year;
			cout << endl;
			user.BookIssuance(BookName, Name, Day, Month, Year);
			break;
		case 6:
			cout << "Введите данные о возвращаемой книге\n" << "Введите название книги: \n";
			cin >> BookName;
			cout << "Введите имя возвращающего: ";
			cin >> Name;
			cout << endl;
			user.BookReturn(BookName, Name);
			break;
		case 7:
			cout << "Введите сегодняшнюю дату(отдельно день, месяц и год)\n";
			cin >> Day >> Month >> Year;
			cout << endl;
			user.Debtors(Day, Month, Year);
			break;

		}
		if (variant != 8)
		{
			system("pause");
		}
	} while (variant != 8);
	return 0;
}