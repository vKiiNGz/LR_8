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


using namespace std;
struct book
{
	int number;
	char author[100];
	char title[100];
	int year;
	char pubhouse[100];
	int pages;
};
book* new_struct(int &kolvo, book* arr, book* arrcopy)
{   int i;
		printf("how many additional structures do you want to introduce?");
		printf("\n");
		int add;
		scanf("%d", &add);
		book* newarr = new book[kolvo + add];
		for (i = 0; i < kolvo; i++)
		{
		newarr[i].number = arrcopy[i].number;
		strcpy(newarr[i].author, arrcopy[i].author);
		strcpy(newarr[i].title, arrcopy[i].title);
		newarr[i].year = arrcopy[i].year;
		strcpy(newarr[i].pubhouse, arrcopy[i].pubhouse);
		newarr[i].pages = arrcopy[i].pages;
		}
		for (i = kolvo; i < kolvo + add; i++)
		{
			printf("book number: ");
			scanf("%d", &newarr[i].number);
			printf("enter author name: ");
			scanf("%s", &newarr[i].author);
			printf("enter the title of the book: ");
			scanf("%s", &newarr[i].title);
			printf("enter the year of publication of the book: ");
			scanf("%d", &newarr[i].year);
			printf("enter publisher: ");
			scanf("%s", &newarr[i].pubhouse);
			printf("enter the number of pages: ");
			scanf("%d", &newarr[i].pages);
		}
		kolvo += add;
		return newarr;
	}
void check_struct(int &kolvo, book* arr)
{
	int i;
	printf("struct number..book number..author..title..year of publication..publisher..number of pages");
	printf("\n");		
	for (i = 0; i < kolvo; i++) 
	{
	printf("%d", i);
	printf("\t\t");
	printf("%d", arr[i].number);
	printf("\t\t");
	printf("%s", arr[i].author);
	printf("\t");
	printf("%s", arr[i].title);
	printf("\t");
	printf("%d", arr[i].year);
	printf("\t\t");
	printf("%s", arr[i].pubhouse);
	printf("\t\t");
	printf("%d", arr[i].pages);
	printf("\n");
	}
}
book* del_struct(int &kolvo, book* arr)
{ 
	   
	int i;
	 printf("Enter the structure number to delete");
	 printf("\n");
	 int numb;
	 scanf("%d", &numb);	
	 book* newbase = new book[kolvo - 1];
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
book* change_struct(int &kolvo, book* arr, book* arrcopy)
{
	int i;
	printf("Enter the structure number to change");
	printf("\n");
	int numb;
	scanf("%d", &numb);
	for (i = 0; i < kolvo; i++) 
	{
		if(i == numb)
		{	
			printf("book number: ");
			scanf("%d", &arr[i].number);
			arrcopy[i].number = arr[i].number;
			printf("enter author name: ");
			scanf("%s", &arr[i].author);
			strcpy(arrcopy[i].author, arr[i].author);
			printf("enter the title of the book: ");
			scanf("%s", &arr[i].title);

			strcpy(arrcopy[i].title, arr[i].title);
			printf("enter the year of publication of the book: ");
			scanf("%d", &arr[i].year);
			arrcopy[i].year = arr[i].year;;
			printf("enter publisher: ");
			scanf("%s", &arr[i].pubhouse);
			strcpy(arrcopy[i].pubhouse, arr[i].pubhouse);
			printf("enter the number of pages: ");
			scanf("%d", &arr[i].pages);
			arrcopy[i].pages = arr[i].pages;
		}
	}
}
void sort_struct(int &kolvo, book* arr, book* arrcopy)
{ 
	int i, j, temp, step, ch;
	for (step = kolvo / 2; step > 0; step /= 2) 
	{
		for (i = step; i < kolvo; i++) 
		{
			temp = arr[i].year;
			ch = i;
			for (j = i; j >= step; j -= step) 
			{
				if (temp >= arr[j - step].year) 
				{
					break;    
				}
				swap (arr[j], arr[j - step]);
			}
		}	
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int kolvo, i;
	printf("enter the number of structures: ");
	scanf("%d", &kolvo);

	book* arr = new book[kolvo];
	book* arrcopy = new book[kolvo];
	for (i = 0; i < kolvo; i++)
	{
			printf("book number: ");
			scanf("%d", &arr[i].number);
			arrcopy[i].number = arr[i].number;
			printf("enter author name: ");
			scanf("%s", &arr[i].author);
			strcpy(arrcopy[i].author, arr[i].author);
			printf("enter the title of the book: ");
			scanf("%s", &arr[i].title);

			strcpy(arrcopy[i].title, arr[i].title);
			printf("enter the year of publication of the book: ");
			scanf("%d", &arr[i].year);
			arrcopy[i].year = arr[i].year;;
			printf("enter publisher: ");
			scanf("%s", &arr[i].pubhouse);
			strcpy(arrcopy[i].pubhouse, arr[i].pubhouse);
			printf("enter the number of pages: ");
			scanf("%d", &arr[i].pages);
			arrcopy[i].pages = arr[i].pages;
	}

  int move = 1;
  while (move != 0)
	  {
		  printf("Add new struct - 1");
		  printf("\n");
		  printf("Delete struct - 2");
		  printf("\n");
		  printf("Check struct - 3");
		  printf("\n");
		  printf("Sort struct - 4");
		  printf("\n");
		  printf("Change struct - 5");
		  printf("\n");
		  printf("Execution of the task by variant - 6");
		  printf("\n");
		  printf("Exit - 0");
		  printf("\n");
		  scanf("%d", &move);
		  switch (move) 
		  {
			case 1:
			arr = new_struct(kolvo, arr, arrcopy);
			arrcopy = arr;
			break;
			case 2:
			arr = del_struct(kolvo, arr);
			arrcopy = arr;
			break;
			case 3:
			check_struct(kolvo, arr);
			break;
			case 4:
			sort_struct(kolvo, arr, arrcopy);
			arrcopy = arr;
			break;
			case 5:
			change_struct(kolvo, arr, arrcopy);
			arrcopy = arr;
			break;
			case 6:
			sort_struct(kolvo, arr, arrcopy);
			arrcopy = arr;
			int yea;
			printf("Enter a year to see books published after that year");
			printf("\n");
			scanf("%d", &yea);
			i = 0;
			while (i < kolvo && arr[i].year <= yea)
			{
			i++;
			}
			if (arr[i].year > yea) 
			{
				yea = i;
			 	printf("struct number..book number..author..title..year of publication..publisher..number of pages");
				printf("\n");		
				for (i = yea; i < kolvo; i++) 
				{
				printf("%d", i);
				printf("\t\t");
				printf("%d", arr[i].number);
				printf("\t\t");
				printf("%s", arr[i].author);
				printf("\t");
				printf("%s", arr[i].title);
				printf("\t");
				printf("%d", arr[i].year);
				printf("\t\t");
				printf("%s", arr[i].pubhouse);
				printf("\t\t");
				printf("%d", arr[i].pages);
				printf("\n");
				}	
			}
			break;
          default:
			  break;
		  }
	  }     
	return 0;
}
