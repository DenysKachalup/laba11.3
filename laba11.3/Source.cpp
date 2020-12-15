#include<iostream>	
#include<iomanip>
#include<Windows.h>
#include<string>
#include <fstream>


using namespace std;

enum Spec { KN, INF, MT, PH };
string specStd[] = { "Компютерні науки","Інформатика","Математика","Фізика" };

struct Student
{
	string prizv;
	int kurs;
	Spec special;
	short Phis;
	short math;
	int bal;
	union
	{
		short progr;
		short chisl;
		short pedag;
	};
};
void print(Student* s, const int n)
{
	cout << "============================================================================================" << endl;
	cout << "| № | Прізвище | Курс | Спеціальність| Матем. | Фізика | Програмування | Чис.мет. | Педаг. |" << endl;
	cout << "============================================================================================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(3) << i + 1 << "| " << setw(8)
			<< s[i].prizv << " |" << setw(6) << s[i].kurs << "|" << setw(14)
			<< specStd[s[i].special] << "|" << setw(8) << s[i].math << "|" << setw(8) << s[i].Phis << "|";
		switch (s[i].special)
		{
		case KN:
			cout << setw(15) << s[i].progr << "|" << setw(10) << " " << "|" << setw(8) << " " << "|" << endl;
			break;
		case INF:
			cout << setw(15) << " " << "|" << setw(10) << s[i].chisl << "|" << setw(8) << " " << "|" << endl;
			break;
		case MT:
		case PH:
			cout << setw(15) << " " << "|" << setw(10) << " " << "|" << setw(8) << s[i].pedag << "|" << endl;
			break;
		}
		//<< setw(15) << s[i].progr << "|" << setw(10) << s[i].chisl << "|" << setw(9) << s[i].pedag << "|" << endl;
	}


	cout << "============================================================================================" << endl;



}
void print1(Student* s, int mas[], const int n)
{
	cout << "============================================================================================" << endl;
	cout << "| № | Прізвище | Курс | Спеціальність| Матем. | Фізика | Програмування | Чис.мет. | Педаг. |" << endl;
	cout << "============================================================================================" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(3) << i + 1 << "| " << setw(8)
			<< s[mas[i]].prizv << " |" << setw(6) << s[mas[i]].kurs << "|" << setw(14)
			<< specStd[s[mas[i]].special] << "|" << setw(8) << s[mas[i]].math << "|" << setw(8) << s[mas[i]].Phis << "|";
		switch (s[mas[i]].special)
		{
		case KN:
			cout << setw(15) << s[mas[i]].progr << "|" << setw(10) << " " << "|" << setw(8) << " " << "|" << endl;
			break;
		case INF:
			cout << setw(15) << " " << "|" << setw(10) << s[mas[i]].chisl << "|" << setw(8) << " " << "|" << endl;
			break;
		case MT:
		case PH:
			cout << setw(15) << " " << "|" << setw(10) << " " << "|" << setw(8) << s[mas[i]].pedag << "|" << endl;
			break;
		}
		//<< setw(15) << s[i].progr << "|" << setw(10) << s[i].chisl << "|" << setw(9) << s[i].pedag << "|" << endl;
	}


	cout << "============================================================================================" << endl;



}
void Creat(Student* s, const int n)
{
	int spec;
	for (int i = 0; i < n; i++)
	{
		cout << "Номер студента: " << i + 1 << endl;
		cin.get();
		cin.sync();

		cout << "Прізвище: "; getline(cin, s[i].prizv);
		cout << "Курс: "; cin >> s[i].kurs;
		cout << "Спеціальність: ( 0 - Компютерні науки, 1 - Інформатика, 2 - Математика, 3 - Фізика): ";
		cin >> spec;
		s[i].special = (Spec)spec;
		cout << "Оцінка з математики: "; cin >> s[i].math;
		cout << "Оцінка з фізики: "; cin >> s[i].Phis;

		switch (s[i].special)
		{
		case KN:
			cout << "Оцінка з програмуванння: "; cin >> s[i].progr;
			break;
		case INF:
			cout << "Оцінка з чисельних методів: "; cin >> s[i].chisl;
			break;
		case MT:
		case PH:
			cout << "Оцінка з педагогіки: "; cin >> s[i].pedag;
			break;
		}
		cout << endl;
	}
}
void Bal(Student* s, const int n)
{
	int min = s[0].math;

	for (int i = 0; i < n; i++)
	{

		int b = (s[i].math + s[i].Phis + s[i].progr) / 3;
		s[i].bal = b;
	}

}
void Sort(Student* s, const int n)
{
	Student tmp;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if ((s[j].bal < s[j + 1].bal) || ((s[j].bal == s[j + 1].bal) && s[j].prizv < s[j + 1].prizv)
				|| (s[j].bal == s[j + 1].bal) && s[j].prizv == s[j + 1].prizv && s[j].kurs < s[j + 1].kurs)
			{
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
}
int* Sort1(Student* s, const int n)
{
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		mas[i] = i;
	int i, j, v;
	for (i = 1; i < n; i++)
	{
		v = mas[i];
		for (j = i - 1; j >= 0 && ((s[mas[j]].bal < s[v].bal) || ((s[mas[j]].bal == s[v].bal) && s[mas[j]].prizv < s[v].prizv)
			|| (s[mas[j]].bal == s[v].bal) && s[mas[j]].prizv == s[v].prizv && s[mas[j]].kurs < s[v].kurs); j--)
		{
			mas[j + 1] = mas[j];
		}
		mas[j + 1] = v;
	}
	return mas;
}
int BinarSearch(Student* s, const int n, string a, Spec special, int bals)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i].prizv == a && s[i].special == special && s[i].bal == bals)
			return i;
	}
	return -1;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int q;
	int n;
	cout << "Введіть кількість студентів: "; cin >> n;
	cout << endl;

	Student* s = new Student[n];
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		mas[i] = i;

	string prizv;
	int kurs;
	Spec special;
	int k;



	int bals;
	int menu1;
	do
	{
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - фізично впорядкувати даних" << endl;
		cout << " [4] - індексне впорядкування даних" << endl;
		cout << " [5] - бінарний пошук "
			<< endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menu1;
		cout << endl << endl << endl;

		switch (menu1)
		{
		case 1:
			Creat(s, n);
			Bal(s, n);
			break;
		case 2:
			print(s, n);
			break;
		case 3:
			Sort(s, n);
			break;
		case 4:

			print1(s, Sort1(s, n), n);
			break;
		case 5:
		{
			cin.get();
			cin.sync();
			string a;

			cout << "Введіть прізвище: "; getline(cin, a);
			cout << "Введіть курс( 0 - Компютерні науки, 1 - Інформатика, 2 - Математика, 3 - Фізика): ";
			cin >> k;
			special = (Spec)k;
			cout << "Введіть середній бал: "; cin >> bals;

			if (BinarSearch(s, n, a, special, bals) == -1)
				cout << "Не знайдено" << endl;
			else
				cout << "Знайдено" << endl;
		}
		break;
		default:
			cout << "Ви ввели не правильне значення";

		}
	} while (menu1 != 0);





	return 0;
}
