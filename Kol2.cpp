#include "Wybor.h"
#include <cassert>
using namespace std;

/*
* Uwaga: Zadania kod rozwiazania zaania umieszcza� pomi�dzy #ifdef a #endif.
*/

#ifdef Kol_2
class W�a�ciciel
{

};
class Samoch�d
{
protected:
    char m_numerRejestracyjny[10];
    int m_stanLicznika;
    bool m_stanDopuszczenia;
    W�a�ciciel* m_w�asciciel;
    static Samoch�d* m_instancjaWzorcowa;
    double m_WAR_POCZ = 15000;
public:
    Samoch�d() {
        if (m_instancjaWzorcowa == nullptr) 
        {
            throw runtime_error("Brak instancji wzorcowej");
        }
        *this = *m_instancjaWzorcowa;
    }
    Samoch�d(const char* rej, int stan_licz, bool stan_dopuszcz, W�a�ciciel* wlasciciel)
    {
        setNumerRejestracyjny(rej);
        setStanLicznika(stan_licz);
        setStanDopuszczenia(stan_dopuszcz);
        setW�a�ciciel(wlasciciel);
    }
    void setNumerRejestracyjny(const char* rej)
    {
        strcpy_s(m_numerRejestracyjny, rej);
    }
    void setStanLicznika(int stan_licz)
    {
        assert(stan_licz > 0);
         m_stanLicznika = stan_licz;
    }
    void setStanDopuszczenia(bool stan_dopuszcz)
    {
        m_stanDopuszczenia = stan_dopuszcz;
    }
    void setW�a�ciciel(W�a�ciciel* wlasciciel)
    {
        m_w�asciciel = wlasciciel;
    }
    char* getNumerRejestracyjny() { return m_numerRejestracyjny; }
    int getStanLicznika() { return m_stanLicznika; }
    bool getStanDopuszczenia() { return m_stanDopuszczenia;; }
    W�a�ciciel* getW�a�ciciel() { return m_w�asciciel; }

    static void setInstancjaWzorcowa(Samoch�d* instancja) {
        m_instancjaWzorcowa = instancja;
    }
    static Samoch�d* getInstancjaWzorcowa() {
        return m_instancjaWzorcowa;
    }
    virtual double obliczZasieg() {
        if (!m_stanDopuszczenia) 
        {
            throw runtime_error("Samoch�d niedopuszczony do jazdy");
        }
        return 800.0;
    }
    virtual operator double()
    {
        if (m_stanDopuszczenia == true)
        {
            double wartosc = (m_WAR_POCZ - (0.2 * (double)m_stanLicznika) * 1.0);
            if (wartosc > 400)
            {
                return wartosc;
            }
            else
            {
                return 400.0;
            }
        }
        else
        {
            double wartosc = (m_WAR_POCZ - (0.2 * (double)m_stanLicznika) * 0.2);
            if (wartosc > 400)
            {
                return wartosc;
            }
            else
            {
                return 400.0;
            }
        }
    }
    bool operator!=(const Samoch�d& sam)
    {
        return (abs(this->m_stanLicznika - sam.m_stanLicznika) > 20) || (this->m_stanDopuszczenia != sam.m_stanDopuszczenia);
    }

};
Samoch�d* Samoch�d::m_instancjaWzorcowa = nullptr;
class Samoch�dElektryczny : public Samoch�d
{
protected:
    int m_stanBaterii;
public:
    Samoch�dElektryczny(const char* rej, int stan_licz, bool stan_dopuszcz, W�a�ciciel* wlasciciel, int stan_baterii) : Samoch�d(rej, stan_licz, stan_dopuszcz, wlasciciel)
    {
        setStanBaterii(stan_baterii);
    }
    void setStanBaterii(int stan_baterii)
    {
        assert(stan_baterii >= 0 && stan_baterii <= 100);
        m_stanBaterii = stan_baterii;
    }
    int getStanBaterii() { return m_stanBaterii; }
    double obliczZasieg() override
    {
        if (!m_stanDopuszczenia)
        {
            throw runtime_error("Samoch�d niedopuszczony do jazdy");
        }
        return (2.5 * m_stanBaterii);
    }
    operator double() override
    {
        if (m_stanDopuszczenia == true)
        {
            double wartosc = (m_WAR_POCZ - (0.2 * (double)m_stanLicznika) * 1.0);
            if (wartosc > 400)
            {
                return wartosc - (wartosc * 0.3);
            }
            else
            {
                return 400.0;
            }
        }
        else
        {
            double wartosc = (m_WAR_POCZ - (0.2 * (double)m_stanLicznika) * 0.2);
            if (wartosc > 400)
            {
                return wartosc - (wartosc * 0.3);
            }
            else
            {
                return 400.0;
            }
        }
    }
};
int main()
{
    W�a�ciciel W�adek, Mirek, Janusz;
    char tab[8] = "SY-0987";
    char tab2[9] = "STA-1234";
    Samoch�d sam(tab, 25000, true, &W�adek);
    cout << sam.getNumerRejestracyjny() << endl;
    Samoch�dElektryczny samElektryk(tab2, 35000, true, &Mirek, 86);
    cout << samElektryk.getStanBaterii() << endl;
    cout << "Zasieg samochodu zwyklego: " << sam.obliczZasieg() << endl;
    cout << "Zasieg samochodu elektrycznego: " << samElektryk.obliczZasieg() << endl;
    cout << "Wartosc zwyklego samochodu: " << static_cast<double>(sam) << endl;
    Samoch�d sam2("KR-5678", 25021, true, &Janusz);
    if (sam != sam2) 
    {
        cout << "Samochody sa rozne" << endl;
    }
    else 
    {
        cout << "Samochody sa identyczne" << endl;
    }
}

#endif
