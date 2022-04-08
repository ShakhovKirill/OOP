#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include <string>

using namespace std;

struct reader
{
    string ReaderName;
    unsigned int DateDay, DateMonth, DateYear;
};

class book
{
public:
    string Title;
    vector <string> Authors;
    unsigned  int Year;
    string Publisher;
    unsigned int Pages;
    book(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages);
};

class catalog_book : public book
{
public:
    unsigned int ID;
    unsigned int Quantity;
    unsigned int Instances;
    vector <reader> Picked;
    vector <string> Debtors;
    catalog_book(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages, unsigned int anID, unsigned int aQuantity, unsigned int anInstances);
};

class actions
{
private:
    vector <catalog_book> Info;
public:
    void AddBook(string aTitle, vector <string> anAuthors, unsigned  int anYear, string aPublisher, unsigned int aPages, unsigned int anID, unsigned int aQuantity, unsigned int anInstances);
    void DeleteBook(string aTitle);
    void TakenInfo(unsigned int anID);
    void BookSearch(string aTitle, string anAuthors);
    void BookIssuance(string aTitle, string aReaderName, unsigned int issDay, unsigned int issMonth, unsigned int issYear);
    void BookReturn(string aTitle, string aReaderName);
    void Debtors(unsigned int retDay, unsigned int retMonth, unsigned int retYear);

};

#endif