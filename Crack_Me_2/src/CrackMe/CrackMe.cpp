#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <sstream>


using namespace std;

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{

	return alphanum[rand() % stringLength];
}

int random(int n, int m) {
	return rand() % (m - n + 1) + n;
}

string IntToString(int a)
{
	ostringstream tmp;
	tmp << a;
	return tmp.str();
}

int main() {
	cout << "\t    TURK HACK TEAM\n\t    --------------\n";
	cout << "\tCrack Me No2 | Pleiades\n\t=======================\n\n";
	bas:
	srand(time(0));
	std::string Str;
	for (unsigned int i = 0; i < 30; ++i)
	{
		Str += genRandom();

	}
	std::string Str2;
	for (unsigned int c = 0; c < 10; ++c)
	{
		Str2 += genRandom();

	}
	int num = random(1453135, 31510357);
	string Str3 = IntToString(num);
	string a;
	cout << "Sifreyi giriniz: ";
	cin >> a;
	if (a == Str + Str2 + Str3) {
		cout << "Tebrikler! Sifreyi buldunuz!\n";
		getchar();
		getchar();
		return 0;
	}
	else {
		cout << "Sifre yanlis. Lutfen tekrar deneyin.\n------------------------------------\n\n";
		goto bas;
	}
}
