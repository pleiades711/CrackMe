// THTCrackMe2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

//START OF ALIEN CODE
static const int B64index[256] = { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62, 63, 62, 62, 63, 52, 53, 54, 55,
56, 57, 58, 59, 60, 61,  0,  0,  0,  0,  0,  0,  0,  0,  1,  2,  3,  4,  5,  6,
7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,  0,
0,  0,  0, 63,  0, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51 };

std::string b64decode(const void* data, const size_t len)
{
	unsigned char* p = (unsigned char*)data;
	int pad = len > 0 && (len % 4 || p[len - 1] == '=');
	const size_t L = ((len + 3) / 4 - pad) * 4;
	std::string str(L / 4 * 3 + pad, '\0');

	for (size_t i = 0, j = 0; i < L; i += 4)
	{
		int n = B64index[p[i]] << 18 | B64index[p[i + 1]] << 12 | B64index[p[i + 2]] << 6 | B64index[p[i + 3]];
		str[j++] = n >> 16;
		str[j++] = n >> 8 & 0xFF;
		str[j++] = n & 0xFF;
	}
	if (pad)
	{
		int n = B64index[p[L]] << 18 | B64index[p[L + 1]] << 12;
		str[str.size() - 1] = n >> 16;

		if (len > L + 2 && p[L + 2] != '=')
		{
			n |= B64index[p[L + 2]] << 6;
			str.push_back(n >> 8 & 0xFF);
		}
	}
	return str;
}
//END OF ALIEN CODE


int main()
{
	cout << "\tTURK HACK TEAM\n\tCrack Me No. 3\n";
	cout << "\t   PLEIADES   \n";
	bas:

	string sifre3 = b64decode("YkdWaWJHVmlhUT09", 16);
	string sifre4 = b64decode("ZEc5NmRRPT0=", 12);

	const void * sifre3th = sifre3.c_str();
	const void * sifre4th = sifre4.c_str();

	string sifre1 = b64decode(sifre3th, 12);
	string sifre2 = b64decode(sifre4th, 8);

	string a;
	string b;

	//Debug
	//cout << sifre1;
	//cout << sifre2;
	//Debug end

	cout << "\nSifre-1:\n";
	cin >> a;

	cout << "\nSifre-2:\n";
	cin >> b;


	if (a == sifre1 && b == sifre2) {
			cout << "\n\a\n=====================================\n    Tebrikler, sifreyi cozdunuz! \n(Lutfen sifreyi gizleyerek paylasin.)\n=====================================\n";
			getchar();
			getchar();
			return 0;
	}
	else {
		cout << "\nUzgunum, sifre dogru degil. Tekrar deneyin.\n\n";
		goto bas;
	}
    return 0;
}

