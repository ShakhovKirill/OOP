#include "book.h"
#include <iostream>

void actions::AddBook(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages, unsigned int anID, unsigned int aQuantity, unsigned int anInstances)
{
	catalog_book NewBook(aTitle, anAuthors, anYear, aPublisher, aPages, anID, aQuantity, anInstances);
	Info.push_back(NewBook);
}

void actions::DeleteBook(string aTitle)
{
	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].Title == aTitle)
		{
			Info.erase(Info.begin() + i);
			cout << "Книга " << aTitle << " удалена";
		}
	}

}

void actions::TakenInfo(unsigned int anID)
{
	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].ID == anID)
		{
			cout << "Информация о книге с ID: " << anID << endl;
			cout << "Название книги: " << Info[i].Title << endl;
			cout << "Авторы книги: ";
			for (int j = 0; j < Info[i].Authors.size(); j++)
			{
				cout << Info[i].Authors[j] << ", ";
			}
			cout << endl << "Год выпуска книги: " << Info[i].Year << endl;
			cout << "Издательство книги: " << Info[i].Publisher << endl;
			cout << "Количество страниц: " << Info[i].Pages << endl;
			cout << "Общее количество экземпляров: " << Info[i].Quantity << endl;
			cout << "Количество доступных экземпляров: " << Info[i].Instances << endl;
			cout << "Информация о людях, взявших книгу: " << endl;
			for (int x = 0; x < Info[i].Picked.size(); x++)
			{
				cout << Info[i].Picked[x].ReaderName << ", " << Info[i].Picked[x].DateDay << "." << Info[i].Picked[x].DateMonth << "." << Info[i].Picked[x].DateYear << endl;
			}
		}
	}
}

void actions::BookSearch(string aTitle, string anAuthors)
{
	bool Author;
	for (int i = 0; i < Info.size(); i++)
	{
		for (int j = 0; j < Info[i].Authors.size(); j++)
		{
			if (Info[i].Authors[j] == anAuthors)
			{
				Author = true;
			}
		}
		if ((Info[i].Title == aTitle) && Author)
		{
			cout << "ID указанной книги: " << Info[i].ID << endl;
		}
	}
}

void actions::BookIssuance(string aTitle, string aReaderName, unsigned int issDay, unsigned int issMonth, unsigned int issYear)
{
	reader New;
	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].Title == aTitle)
		{
			if (Info[i].Instances > 0)
			{
				Info[i].Instances--;
				New.ReaderName = aReaderName;
				New.DateDay = issDay;
				New.DateMonth = issMonth;
				New.DateYear = issYear;
				Info[i].Picked.push_back(New);
			}
			else
			{
				cout << "Указанной книги нет в наличии." << endl;
			}
		}
	}

}

void actions::BookReturn(string aTitle, string aReaderName)
{
	for (int i = 0; i < Info.size(); i++)
	{
		if (Info[i].Title == aTitle)
		{
			Info[i].Instances++;
			for (int j = 0; j < Info[i].Picked.size(); j++)
			{
				if (Info[i].Picked[j].ReaderName == aReaderName)
				{
					Info[i].Picked.erase(Info[i].Picked.begin() + j);
				}
			}
		}
		break;
	}

}

void actions::Debtors(unsigned int retDay, unsigned int retMonth, unsigned int retYear)
{
	for (int i = 0; i < Info.size(); i++)
	{
		cout << "Должники по книге " << Info[i].Title << endl;
		for (int j = 0; j < Info[i].Picked.size(); j++)
		{
			if (retYear - Info[i].Picked[j].DateYear >= 2)
			{
				cout << Info[i].Picked[j].ReaderName << endl;
			}
			else if (retYear - Info[i].Picked[j].DateYear == 1)
			{
				if (Info[i].Picked[j].DateMonth < retMonth)
				{
					cout << Info[i].Picked[j].ReaderName << endl;
				}
				else if (Info[i].Picked[j].DateMonth == retMonth)
				{
					if (Info[i].Picked[j].DateDay < retDay)
					{
						cout << Info[i].Picked[j].ReaderName << endl;
					}
				}
			}
		}
	}
}

book::book(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages)
{
	Title = aTitle;
	Authors = anAuthors;
	Year = anYear;
	Publisher = aPublisher;
	Pages = aPages;
}

catalog_book::catalog_book(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages, unsigned int anID, unsigned int aQuantity, unsigned int anInstances) :book(aTitle, anAuthors, anYear, aPublisher, aPages)
{
	ID = anID;
	Quantity = aQuantity;
	Instances = anInstances;
}