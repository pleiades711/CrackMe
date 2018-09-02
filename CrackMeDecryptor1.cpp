#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	string cozum;
	cout << "Decrypt edeceginiz string:\n";
	string sif;
	cin >> sif;

	//DEÞÝFRELEME ALGORÝTMASI
	int satirUzunlugu = 0; // string uzunlugu
	int kaydirma = -1; // kaydirilacak deger
	int *asciiDegeri;
	char *sifreleme;
	int iterasyon = 1;

	satirUzunlugu = sif.length() - 1;
	asciiDegeri = new int[sif.length()]; // karakter sayisina gore bir array hazirliyoruz
	sifreleme = new char[sif.length()];
	for (int i = 0; i <= satirUzunlugu; i++) // her karakter icin bir loop calisiyor
	{
		asciiDegeri[i] = (int)sif[i];
		asciiDegeri[i] += kaydirma;
		sifreleme[i] = (char)asciiDegeri[i];
		cozum += sifreleme[i]; // cikis (output)
		if (iterasyon == 5) {
			kaydirma++;
			iterasyon = 1;
		}
		else {
			iterasyon++;
			kaydirma--;
		}
	}
	//DEÞÝFRELEME ALGORÝTMASI BÝTÝÞÝ

		cout << "\nCozulmus sifre:\n";
		cout << cozum;

		getchar();
		getchar();
		return 0;
	}

