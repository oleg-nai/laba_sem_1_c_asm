#include <iostream>
#include <cstring>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;


struct temp
{
	int s1;
	double s2;
};

int main()
{
	setlocale(LC_ALL, "rus");

	char* str1;
	char* str2;

	char* str_1; // новый массив с разделителями "пробел"
	str_1 = new char[256];



	str1 = new char[256];
	str2 = new char[256];
	string path = "input.txt";
	ifstream file;
	file.open(path);
	if (!file.is_open()) //1. Из файла input.txt считать строку.
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		file >> str1;
	}
	cout << "То, что в файле: " << str1 << endl;

	file.close();
	// 	2. Строку разбить на лексемы, лексемы записать в отдельнай массив. Разделители между лексемами:,;
	cout << "\nВведите разделитель :,;     ";
	cin.getline(str2, 256);


	str_1[1] = '\0';



	// для 4!!!
	char* str_2;
	str_2 = new char[256];

	for (int i = 0; i < strlen(str1); i++) // копирует из str в str_2 именно так, а не str_1 = str1
	{
		str_2[i] = str1[i];
		if (i == strlen(str1) - 1)
		{
			str_2[i + 1] = '\0';
		}
	}








	char* pch;

	pch = strtok(str1, str2);	// Функция strtok выполняет поиск лексем в строке string
	int as = 1;
	while (pch != NULL)			// пока есть лексемы
	{
		if (as == 1)
		{
			str_1[0] = '\0';
		}
		// в pch 1-ая лексема
		if (as != 1)
		{
			strcat(str_1, pch); // склеивает строки
		}
		strcat(str_1, " ");
		pch = strtok(NULL, str2); // берет следующее значение в строке
		as++;
	}
	cout << "Новый массив с нормальной строкой c пробелом: " << str_1 << endl;

	// 3. Среди лексем найти лексемы, вещественные числа- записать в динамический массив, посчитать сумму.



	int num;
	int* mas;
	mas = new int[255];

	int i = 0;
	int kol_vo = 0;


	pch = strtok(str_1, " ");	// Функция strtok выполняет поиск лексем в строке string
	while (pch != NULL)			// пока есть лексемы
	{
		num = atoi(pch);
		if (num == 0)
		{
			cout << pch << " - не число!" << endl;
		}
		else
		{
			mas[i] = num;
			cout << "число - " << mas[i] << " - Записано! " << endl;
			kol_vo++;
			i++;
		}
		pch = strtok(NULL, " "); // берет следующее значение в строке
	}

	for (int l = 0; l < i; l++)
	{
		cout << mas[l] << endl;
	}

	int sum = 0;
	for (int j = 0; j < i; j++)
	{
		sum += mas[j];
	}
	cout << "Сумма равна " << sum << endl;




	// 4. В строке найти подстроки, которые начинаются на  символы u-x, а конец подстроки совпадает с концом строки.





	pch = strtok(str_2, ",:;");	// Функция strtok выполняет поиск лексем в строке string

	while (pch != NULL)			// пока есть лексемы
	{
		for (int i = 0; i < strlen(pch); i++)
		{
			int l = strlen(pch);
			if (pch[i] == 'u' || pch[i] == 'v' || pch[i] == 'w' || pch[i] == 'x')
			{
				if (pch[l] == 'u' || pch[l] == 'v' || pch[l] == 'w' || pch[l] == 'x')
				{
					cout << "В char - " << pch << "первая и последняя буквы совпадают" << endl;
				}
			}
			else
			{
				cout << " Это слово не  подходид под условие - " << pch << endl;
			}
		}
		pch = strtok(NULL, str2); // берет следующее значение в строке
	}


	//5. В динамической матрице размерности N*N- заполнить единицами главную и побочную диагональ, остальные элементы- 0.  

	int** arr;

	int n, m;
	cout << "Введите n: ";
	cin >> n;
	cout << "\n==========================\n";
	m = n;

	arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j || i + j == n - 1)
			{
				arr[i][j] = 1;
			}
			else
				arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;

	}

	//6. Записать результаты в файл(любой пункт из 2 - 5).
	ofstream file_1;
	file_1.open(path);

	if (!file_1.is_open()) //1. Из файла input.txt считать строку.
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Идет запись в файл!";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				file_1 << arr[i][j] << " ";
			}
			file_1 << endl;

		}
	}

	file_1.close();

	//Ввести массив ( размерность=2) структур с консоли, структура содержит целое и вещественное число. Вывести массив структур.

	temp first;
	first.s1 = 154;
	first.s2 = 51.453;
	for (int i = 0; i < 2; i++)
	{
		cout << first.s1 << first.s2;
}
}



//
//struct temp
//{
//	int s1;
//	double s2;
//};