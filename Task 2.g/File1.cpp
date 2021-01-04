#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;
struct detail
{
	string name;
	int quantity;
	int workshop_number;
};
detail* new_struct(int &kolvo, detail* arr)
{   int i;
		cout << "how many additional structures do you want to introduce?" << endl;
		int add;
		cin >> add;
		detail* newarr = new detail[kolvo + add];
		for (i = 0; i < kolvo; i++)
		{
		newarr[i].name = arr[i].name;
		newarr[i].quantity = arr[i].quantity;
		newarr[i].workshop_number = arr[i].workshop_number;
		}
		for (i = kolvo; i < kolvo + add; i++)
		{
			cout << "detail name ";
			cin >> newarr[i].name;
			cout << "quantity of details: ";
			cin >> newarr[i].quantity;
			cout << "enter workshop number: ";
			cin >>newarr[i].workshop_number;
		}
		kolvo += add;
		return newarr;
	}

void change_struct(int &kolvo, detail* arr)
{
	int i;
	cout << "Enter the structure number to change" << endl;
	int numb;
	cin >> numb;
	for (i = 0; i < kolvo; i++)
	{
		if(i == numb)
		{
			cout << "detail name: ";
			cin >> arr[i].name;
			cout << "quantity of details: ";
			cin >> arr[i].quantity;
			cout << "enter workshop number: ";
			cin >> arr[i].workshop_number;
		}
	}
}

detail* del_struct(int &kolvo, detail* arr)
{

	 int i, numb;
	 cout << "Enter the structure number to delete" << endl;
	 cin >> numb;
	 detail* newbase = new detail[kolvo - 1];
	 for (int i = 0; i < numb; i++)
	 {
	 newbase[i] = arr[i];
	 }
	 for (int i = numb; i < kolvo - 1; i++)
	 {
	 newbase[i] = arr[i + 1];
	 }
	 kolvo--;
	 return newbase;
}

void check_struct(int &kolvo, detail* arr)
{
	int i;
	cout << "struct number..detail name..quantity of details..workshop number" << endl;
	for (i = 0; i < kolvo; i++)
	{
	cout << i << "\t\t";
	cout << arr[i].name << "\t\t";
	cout << arr[i].quantity << "\t\t\t";
	cout << arr[i].workshop_number << endl;
	}
}


void sort_struct(int &kolvo, detail* arr)
{
	int i, j, temp, step, ch;
	for (step = kolvo / 2; step > 0; step /= 2)
	{
		for (i = step; i < kolvo; i++)
		{
			temp = arr[i].quantity;
			ch = i;
			for (j = i; j >= step; j -= step)
			{
				if (temp <= arr[j - step].quantity)
				{
					break;
				}
				swap (arr[j], arr[j - step]);
			}
		}
	}
}
/*
void task_struct(int &kolvo, detail* arr)
{
	int i, answ;
	sort_struct(kolvo, arr);
	cout << "Enter the number of the required workshop: ";
	cin >> answ;
	fout << "struct number..detail name..quantity of details..workshop number" << endl;
	for (i = 0; i < kolvo; i++)
	{
	if (arr[i].workshop_number == answ)
	 {
	 fout << i << "\t\t";
	 fout << arr[i].name << "\t\t";
	 fout << arr[i].quantity;
	 fout << arr[i].workshop_number << "\t\t";
	 }
	}
}    */
int _tmain(int argc, _TCHAR* argv[])
{
	int kolvo, i;
	string way = "output.txt";
	string wayo = "input.txt";
	ofstream fout;
	fout.open(way);
	ifstream fin;
	fin.open(wayo);
	fin >> kolvo;
	//kolvo = 2;

	detail* arr = new detail[kolvo];
	for (i = 0; i < kolvo; i++)
		{
			fin >> arr[i].name;
			fin >> arr[i].quantity;
			fin >> arr[i].workshop_number;
		}
 int move = 1;
  while (move != 0)
	  {
		  cout << "Add new struct - 1" << endl;
		  cout << "Delete struct - 2" << endl;
		  cout << "Check struct - 3" << endl;
		  cout << "Sort struct - 4" << endl;
		  cout << "Change struct - 5" << endl;
		  cout << "Execution of the task by variant - 6" << endl;
		  cout << "Exit - 0"  << endl;
		  cin >> move;
		  switch (move)
		  {
			case 1:
			arr = new_struct(kolvo, arr);
			break;
			case 2:
			arr = del_struct(kolvo, arr);
			break;
			case 3:
			check_struct(kolvo, arr);
			break;
			case 4:
			sort_struct(kolvo, arr);
			break;
			case 5:
			change_struct(kolvo, arr);
			break;
			case 6:
				int  answ;
				sort_struct(kolvo, arr);
				cout << "Enter the number of the required workshop: ";
				cin >> answ;
				fout << "struct number..detail name..quantity of details..workshop number" << endl;
				for (i = 0; i < kolvo; i++)
				{
				if (arr[i].workshop_number == answ)
				 {
				 fout << i << "\t\t";
				 fout << arr[i].name << "\t\t";
				 fout << arr[i].quantity << "\t\t";
				 fout << arr[i].workshop_number  << endl;
				 }
				}
			break;
		  default:
			  break;
		  }
	  }
	fout.close();
	return 0;
}

