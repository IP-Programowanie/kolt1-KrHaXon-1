#include "Wybor.h"
#include "fun.h"
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszczać pomiędzy #ifdef a #endif. 
*/

#ifdef Kol_1


int main()
{
	Struktura nowa;
	nowa.m_char = 'H';
	nowa.m_float = 3.14;
	int rozmiar = 75;
	int rozmiar2 = 40;
	int rozmiar3 = 35;
	Struktura* tab = alokuj(rozmiar, &nowa);
	Struktura* tab2 = alokuj(rozmiar2, &nowa);
	Struktura* tab3 = alokuj(rozmiar3, &nowa);
	zapisDoPliku("tablicaDoZapisu.txt", tab);
	zapisDoPliku("najmniejszaTablica.txt", tab3);
	Struktura* odczytanaNajwieksza = odczytZPliku("tablicaDoZapisu.txt", rozmiar);
	Struktura* odczytanaNajmniejsza = odczytZPliku("najmniejszaTablica.txt", rozmiar3);
	for (int i = 0; i < rozmiar; i++)
	{
		if (tab[i].m_char != odczytanaNajwieksza[i].m_char || tab[i].m_float != odczytanaNajwieksza[i].m_float)
		{
			cerr << "Tablice nie sa identyczne!!" << endl;
		}
	}
	for (int i = 0; i < rozmiar3; i++)
	{
		if (tab3[i].m_char != odczytanaNajmniejsza[i].m_char || tab3[i].m_float != odczytanaNajmniejsza[i].m_float)
		{
			cerr << "Tablice nie sa identyczne!!" << endl;
		}
	}
	dealokujTab(tab);
	dealokujTab(tab2);
	dealokujTab(tab3);
	dealokujTab(odczytanaNajmniejsza);
	dealokujTab(odczytanaNajwieksza);
}

#endif
