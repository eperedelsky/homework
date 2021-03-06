﻿#include <iostream>

using namespace std;

int* encoding(char const*, char const*);
char* decoding(int const*, char const*, int);
char* createRule(const char*);
void createRuleTest();
void encodingTests();
void decodingTests();
bool equals(const char*, const char*);
bool equals(const int*, const int*, int);
int getlength(const char*);

int main()
{
	createRuleTest();
	encodingTests();
	decodingTests();
	system("pause");
}

char* createRule(const char* source)
{
	int j = getlength(source), length = j;

	char* rule = new char[length];

	for (int i = 0; i <= length / 2; i++)
	{
		rule[i] = source[j];
		rule[j] = source[i];
		j--;
	}

	/*for (int i = 0; i <= length; i++)
		cout << rule[i];*/

	return rule;
}

int getlength(const char* source)
{
	if (source == nullptr)
	{
		throw std::invalid_argument("String cannot be null!");
	}

	int length = 0;
	while (source[length])
	{
		length++;
	}
	return length;
}

int* encoding(const char* source, const char* rule)
{
	int n = getlength(source) + 1, j;
	int* encode = new int[n];

	for (int i = 0; i < n; i++)
	{
		if (source[i] >= 'A' && source[i] <= 'Z' || source[i] >= 'a' && source[i] <= 'z')
		{
			j = 0;
			while (true)
			{
				if (source[i] == rule[j] || source[i] == rule[j] + 32)
				{
					break;
				}
				j++;
			}
		}
		else
		{
			j = int(source[i]);
		}
		encode[i] = j;
	}

	return encode;
}

char* decoding(const int* source, const char* rule, int n)
{

	char* decode = new char[n];
	for (int i = 0; i < n; i++)
	{
		if(source[i] >= 1 && source [i] <= 26)
		{
			decode[i] = rule[source[i]];
		}
		else
			decode[i] = source[i];
	}

	return decode;
}

bool equals(const char* lhs, const char* rhs)
{
	bool flag = true;
	int i = 0;
	while (rhs[i])
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
		i++;
	}

	return flag;
}

bool equals(const int* lhs, const int* rhs, int n)
{

	int i = 0;

	for (int i = 0; i < n; i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

void createRuleTest()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* actual = createRule(source);
	const char* expected = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	cout << "Test for creation rule " << (equals(expected, actual) ? "Passed." : "Failed.") << endl;
}

void encodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	int* encode = encoding("Learn C++!", rule);

	cout << "Test for encoding " << (equals(encode, new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, 10) ? "Passed." : "Failed.") << endl;

	encode = encoding("Cogito, ergo sum! (Descartes)", rule);

	cout << "Test for encoding " << (equals(encode, new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, 29) ? "Passed." : "Failed.") << endl;

}

void decodingTests()
{
	const char* source = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	const char* rule = createRule(source);

	char* decode = decoding(new int[10]{ 15, 22, 26, 9, 13, 32, 24, 43, 43, 33 }, rule, 10);

	cout << "Test for decoding " << (equals(decode, "LEARN C++!") ? "Passed." : "Failed.") << endl;

	decode = decoding(new int[29]{ 24, 12, 20, 18, 7, 12, 44, 32, 22, 9, 20, 12, 32, 8, 6, 14, 33, 32, 40, 23, 22, 8, 24, 26, 9, 7, 22, 8, 41 }, rule, 29);

	cout << "Test for decoding " << (equals(decode, "COGITO, ERGO SUM! (DESCARTES)") ? "Passed." : "Failed.") << endl;
}