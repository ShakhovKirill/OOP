#include <iostream>
using namespace std;

const int LNAME = 25;

class STUDENT {

private:
	// закрытые члены класса
	char name[LNAME];				// имя
	int age;						// возраст
	float grade;					// рейтинг
public:
	STUDENT()
{
	for (int i = 0; i < 25; i++)
	{
		name[i] = 0;				//конструктор класса
	}
	age = 0;
	grade = 0;
}
	//открытые члены класса
	char * GetName() {
		return name;				// получение имени
	}
	
	int GetAge() const {
		return age;					// получение возраста
	}								
	
	float GetGrade() const {
		return grade;				// получение рейтинга
	} 
	
	void SetName(char* valueName)
	{
		int n = 0;
		while (*valueName != '\0')
		{
			this->name[n] = *valueName;	// установка имени
			valueName++;
			n++;
		}
	}							
	
	void SetAge(int valueAge) {
		age = valueAge;				// установка возраста
	}									
	
	void SetGrade(float valueGrade) {
		grade = valueGrade;			// установка рейтинга
	}									
	
	void Set(char *valueName, int valueAge, float valueGrade) {
		int c = 0;
		while (*valueName != '\0')
		{
			this->name[c] = *valueName;				// установка всех трех полей
			valueName++;
			c++;
		}
		age = valueAge;
		grade = valueGrade;
	}
		
	
	void Show() {
		cout << "Имя студента : " << name << endl;
		cout << "Возраст студента : " << age << endl;		// отображение информации о студенте
		cout << "Рейтинг студента : " << grade << endl;
	}                             
};

int main()
{
	setlocale(LC_ALL, "Russian");
	STUDENT FirstStudent;
	char name[25];
	int age;
	float grade;
	cout << "Введите имя студента длинной не более 24 символов: ";
	cin >> name;
	cout << endl << "Введите возраст студента: ";
	cin >> age;
	cout << endl << "Введите рейтинг студента: ";
	cin >> grade;
	FirstStudent.SetName(name);
	FirstStudent.SetAge(age);
	FirstStudent.SetGrade(grade);
	cout << "-------------" << endl << "Вывод через геттеры:" << endl;
	cout << "Имя студента: " << FirstStudent.GetName() << endl;
	cout << "Возраст студента: " << FirstStudent.GetAge() << endl;
	cout << "Рейтинг студента: " << FirstStudent.GetGrade() << endl;
	cout << "-------------" << endl << "Работа метода Show:" << endl;
	FirstStudent.Set(name, age, grade);
	FirstStudent.Show();

}