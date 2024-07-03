#include "fun.h"
#include <cassert>
#include <iostream>

using namespace std;
Struktura* alokuj(int& rozmiar, Struktura* str)
{
	assert(rozmiar > 0);
	rozmiar = rozmiar + 1;
	Struktura* tab = new Struktura[rozmiar];
	for (int i = 0; i < rozmiar; ++i)
	{
		tab[i] = *str;
	}
	tab[0].m_char = (char)(rozmiar << 8) | (rozmiar - 1 & 0xFF);
	return tab + 1;
	delete[](tab + 1);
}
void dealokujTab(Struktura* tab) {
	if (tab != nullptr)
	{
		Struktura* orginalnaTablica = tab - 1;
		delete[] orginalnaTablica;
	}
}
void zapisDoPliku(const char* nazwa_pliku, Struktura* tab)
{
	FILE* plik;
	if (fopen_s(&plik, nazwa_pliku, "w") == 0)
	{
		fprintf(plik, "%d\n", (int)tab[-1].m_char);

		for (int i = 0; i < (int)tab[-1].m_char; i++)
		{
			fprintf(plik, "%f %c\n", tab[i].m_float, tab[i].m_char);
		}
		fclose(plik);

		cout << "Tablica zapisana do txt!" << endl;
	}
	else
	{
		cerr << "Pliku nie udalo sie otworzyc! " << endl;
	}
}
Struktura* odczytZPliku(const char* nazwa_pliku, int& rozmiar)
{
	FILE* plik;
	if (fopen_s(&plik, nazwa_pliku, "r") == 0)
	{
		fscanf_s(plik, "%d\n", &rozmiar);
		Struktura* temp = new Struktura[rozmiar];

		for (int i = 0; i < rozmiar; ++i)
		{
			fscanf_s(plik, "%f %c\n", &temp[i].m_float, &temp[i].m_char);
		}
		Struktura* tab = alokuj(rozmiar, temp);
		fclose(plik);
		cout << "Tablica wczytana z pliku - pomyslnie" << endl;
		delete[] temp;
		return tab;
		delete[] tab;
	}
	else
	{
		cerr << "Pliku nie udalo sie otwrzyc do odczyt!" << endl;
		return 0;
	}
}