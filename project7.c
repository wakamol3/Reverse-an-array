/* COP 2220 (machover_program7.c) - larger program
//Ike Machover, 4/10/2023 and Using arrays, functions and loop to run a program that gets a word, manipulates the word and returns the word in different forms and gets all the vowels in the word. */
#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>



//fnction prototypes here
// 
//input/output: character array
//A function that greets the user and gets the first name of the user
void Greeting(char name[]);

//input/output: character array
//A function that gets a word from the user
void GetWord(char inputWord[]); //character array

//input/output: 2 character arrays
//A function that makes a copy of a word
//and changes a the copy word to all lowercase letters
void LowerWord(char inputWord[], char lowerCopy[]);

//input/output: character array (string)
//display the number of a.s and list the index locations
//display the number of e.s and list the index locations
//display the number of i.s and list the index locations
//display the number of o.s and list the index locations
//display the number of u.s and list the index locations
//return the total number of vowel in the array
int CountVowels(char lowerCopy[]);

//input/output:2 character arrays
//reverses a word
void ReverseTheWord(char LowerCopy[], char reverseWord[]);

int main()
{
	//declare 4 character arrays
	char inputWord[25];
	char lowerCopy[25];
	char reverseWord[25];
	char firstName[30];
	char quit;
	int vowelCount = 0;

	//greet the user and get the first name

	Greeting(firstName);


	printf("\n%s,\nWould you like to enter a word Y (YES) or Q (to QUIT) ? ", firstName);
	scanf(" %c", &quit);

	while (quit != 'Q' && quit != 'q')
	{
		if (quit == 'Y' || quit == 'y')
		{//get the word

			GetWord(inputWord);
			//make the lowercase word
			LowerWord(inputWord, lowerCopy);
			//reverse the lowercase word
			ReverseTheWord(lowerCopy, reverseWord);

			printf("\nPrinting the words in the main function:\n\n");
			printf("original word:\t% s\nlowercase:\t% s\nreverse:\t% s\n", inputWord, lowerCopy, reverseWord);

			vowelCount = CountVowels(lowerCopy);
			//print the total vowel count
			printf("\nTotal number of vowels is %d\n", vowelCount);
			printf("\n----------------------------------------");
			//again while loop update
			printf("\n%s,\nWould you like to enter a word Y (YES) or Q (to QUIT) ? ", firstName);
			scanf(" %c", &quit);
		}
		else
		{
			printf("\nPlease enter Y or Q ");
			scanf(" %c", &quit);
		}
	}
	printf("\nThank you, %s, have a great day!\n", firstName);
	return 0;
}
//A function that greets the user
void Greeting(char firstName[])
{
	printf("What is your first name? ");
	scanf(" %s", firstName); //USE %s with a space and no &
	printf("\n*** Welcome to the character array practice program ***\n");
}
//A function that gets a word from the user
void GetWord(char inputWord[]) //character array
{
	printf("\nEnter a word ");
	scanf(" %s", inputWord);
}
//A function that makes a copy of a word
//and changes a the copy word to all lowercase letters
void LowerWord(char inputWord[], char lowerCopy[])
{
	int i, length;
	length = strlen(inputWord);
	//loop to create the lowercase copy word
	for (i = 0; i < length; i++)
	{
		lowerCopy[i] = tolower(inputWord[i]);
	}
	lowerCopy[length] = '\0'; //remember to add null
}
//reverse a word
//reverses a word
void ReverseTheWord(char LowerCopy[], char reverseWord[])
{
	int j;
	//use strlen
	int len = strlen(LowerCopy);
	//use a loop
	for (j = 0; j < len; j++)
		//assign the reverse of the LowerCopy
		reverseWord[j] = LowerCopy[len - j - 1];
	//remember to add the null character
	reverseWord[j] = '\0';
}
//input: character array (string)
//display the number of a.s and list the index locations
//display the number of e.s and list the index locations
//display the number of i.s and list the index locations
//display the number of o.s and list the index locations
//display the number of u.s and list the index locations
//return the total number of vowel in the array
int CountVowels(char lowerCopy[])
{
	int i;
	int len = (int)strlen(lowerCopy);
	int total = 0, aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;//add variabls to count e,i,o,and u
	for (i = 0; i < len; i++)
	{
		if (lowerCopy[i] == 'a')
		{
			aCount++;
			total++;
			printf("\nThere is an 'a' located at index %d\n", i);
		}
		//add conditions for the other vowels
		if (lowerCopy[i] == 'e')
		{
			eCount++;
			total++;
			printf("\nThere is an 'e' located at index %d\n", i);
		}
		if (lowerCopy[i] == 'i')
		{
			iCount++;
			total++;
			printf("\nThere is an 'i' located at index %d\n", i);
		}
		if (lowerCopy[i] == 'o')
		{
			oCount++;
			total++;
			printf("\nThere is an 'o' located at index %d\n", i);
		}
		if (lowerCopy[i] == 'u')
		{
			uCount++;
			total++;
			printf("\nThere is an 'u' located at index %d\n", i);
		}
	}
	printf("\n The total number of a's is %d\n", aCount);
	//add the printf statements for the other vowels
	printf("\n The total number of e's is %d\n", eCount);
	//add the printf statements for the other vowels
	printf("\n The total number of i's is %d\n", iCount);
	//add the printf statements for the other vowels
	printf("\n The total number of o's is %d\n", oCount);
	//add the printf statements for the other vowels
	printf("\n The total number of u's is %d\n", uCount);
	//add the printf statements for the other vowels

	printf("\nPrinting the total number of vowels in the main function: \n\n");
	return total;
}