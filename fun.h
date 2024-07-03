#pragma once
struct Struktura
{
	float m_float;
	char m_char;
};
Struktura* alokuj(int&, Struktura*);
void dealokujTab(Struktura* );
void zapisDoPliku(const char*, Struktura*);
Struktura* odczytZPliku(const char*, int&);
