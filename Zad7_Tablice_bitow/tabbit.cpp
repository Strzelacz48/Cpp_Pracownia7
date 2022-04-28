#include<algorithm>
#include<cstring>
#include "header.hpp"
namespace obliczenia
{
// wyzerowana tablica bitow [0...rozm]
tabbit::tabbit(int rozmiar)
{
    if(rozmiar<=0)
    {
        throw("Zostala podana zla wielkosc talicy");
    }
    dl=rozmiar;
    //rozmiarSlowa=rozmiar;
    if(rozmiar%64!=0)
    {
        tab= new slowo [(rozmiar/64)+1];
        for(int i=0;i<(rozmiar/64)+1;i++)
        {
            tab[i]=0;
        }
    }
    else
    {
        tab= new slowo[rozmiar/64];
        for(int i=0;i<rozmiar/64;i++)
        {
            tab[i]=0;
        }
    }
}// tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
tabbit::tabbit(std::initializer_list<bool> bits) : tabbit((int)bits.size())
{
    int i=rozmiar();
    for(bool b : bits)
    {
        zapisz(--i,b);
    }
}
tabbit::tabbit(slowo tb)
{
    tab=new slowo[1];
    tab[0]=tb;
    dl=0;
    while(tb!=0)
    {
        dl++;
        tb/=2;
    }
    //rozmiarSlowa=dl;
}
// destruktor
tabbit::~tabbit()
{
    delete[]tab;
}
tabbit::tabbit(const tabbit &tb)// konstruktor kopiujący
{
    //rozmiarSlowa=tb.rozmiarSlowa();
    dl=tb.dl;
    int pom=(dl-1+rozmiarSlowa)/rozmiarSlowa;
    tab= new slowo[pom];
    for(int i=0;i<pom;i++)
        {
            tab[i]=tb.tab[i];
        }
}
tabbit::tabbit(tabbit &&tb) // konstruktor przenoszący
{
    std::swap(tab,tb.tab);
    std::swap(dl,tb.dl);
    //std::swap(rozmiarSlowa,tb.rozmiarSlowa);
    /*for(int i=0;i<dl/64;i++)
    {
        std::swap(tab[i],tb.tab[i]);
    }*/
}
tabbit& tabbit::operator = (const tabbit &tb) // przypisanie kopiujące
{
    if(&tb==this)
    {
        return *this;
    }
    dl=tb.dl;
    //rozmiarSlowa=tb.rozmiarSlowa
    //a=new double[n+1];
    delete[]tab;
    int pom=(dl-1+rozmiarSlowa)/rozmiarSlowa;
    tab= new slowo[pom];
    for(int i=0;i<pom;i++)
    {
        tab[i]=tb.tab[i];
    }
    return *this;;
}
tabbit& tabbit::operator = (tabbit &&tb) // przypisanie przenoszące
{
    if(&tb==this)
    {
        return *this;
    }
    std::swap(dl,tb.dl);
    //std::swap(rozmiarSlowa,tb.rozmiarSlowa);
    std::swap(tab,tb.tab);
    return *this; ;
}
bool tabbit::czytaj(int i) const // metoda pomocnicza do odczytu bitu
{
    if(i>dl)
    {
        throw("Proba odwolania sie do elementu poza tablica");
    }
    if(i%64==0)
    {
        if((tab[i/64])&0x1)
            return 1;
        return 0;
    }
    else
    {
        slowo temp=tab[i/64];
        temp>>i%64;
        if(temp&0x1)
            return 1;
        return 0;
    }
}
bool tabbit::zapisz(int i, bool b) // metoda pomocnicza do zapisu bitu
{
    if(i>dl)
    {
        throw("Proba odwolania sie do elementu poza tablica");
    }
    if(i%64==0)
    {
        if(b)
            tab[i/64]|=0x1;
        else
            tab[i/64]&=0xFFFFFFFFFFFFFFFE;
    }
    else
    {
        if(b)
        {
            slowo temp=0x1<<i%64;
            tab[i/64]|=temp;
        }
        else
        {
            slowo temp=(0xFFFFFFFFFFFFFFFF)^(0x1<<i%64);
            tab[i/64]&=temp;
        }
    }
    return 1;
}
//void tabbit::zapisz(int i, bool b)
// indeksowanie dla stałych tablic bitowych
inline int tabbit::rozmiar() const
{
    return dl;
}
tabbit& tabbit::operator | (tabbit b)
{
    tabbit temp=tabbit(dl);
    if(dl>b.dl)
    {        temp=*this;
        for(int i=0;i<=dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]|b.tab[i];
        }
    }
    else
    {
        temp=b;
        for(int i=0;i<=b.dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]|tab[i];
        }
    }
    return temp;
}
tabbit& tabbit::operator |= (tabbit b)
{
    if(dl>b.dl)
    {
        //tabbit temp(this);
        for(int i=0;i<=dl/64;i++)
        {
            tab[i]=tab[i]|b.tab[i];
        }
    }
    else
    {
        tabbit temp(b);
        for(int i=0;i<=b.dl/64;i++)
        {
            tab[i]=tab[i]|b.tab[i];
        }
    }
    return *this;
}
tabbit& tabbit::operator & (tabbit b)
{
    tabbit temp=tabbit(dl);
    if(dl>b.dl)
    {        temp=*this;
        for(int i=0;i<=dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]&b.tab[i];
        }
    }
    else
    {
        temp=b;
        for(int i=0;i<=b.dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]&tab[i];
        }
    }
    return temp;
}
tabbit& tabbit::operator &= (tabbit b)
{
    if(dl>b.dl)
    {
        //tabbit temp(this);
        for(int i=0;i<=dl/64;i++)
        {
            tab[i]=tab[i]&b.tab[i];
        }
    }
    else
    {
        tabbit temp(b);
        for(int i=0;i<=b.dl/64;i++)
        {
            tab[i]=tab[i]&b.tab[i];
        }
    }
    return *this;
}
tabbit& tabbit::operator ^ (tabbit b)
{
    tabbit temp=tabbit(dl);
    if(dl>b.dl)
    {        temp=*this;
        for(int i=0;i<=dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]^b.tab[i];
        }
    }
    else
    {
        temp=b;
        for(int i=0;i<=b.dl/64;i++)
        {
            temp.tab[i]=temp.tab[i]^tab[i];
        }
    }
    return temp;
}
tabbit& tabbit::operator ^= (tabbit b)
{
    if(dl>b.dl)
    {
        //tabbit temp(this);
        for(int i=0;i<=dl/64;i++)
        {
            tab[i]=tab[i]^b.tab[i];
        }
    }
    else
    {
        tabbit temp(b);
        for(int i=0;i<=b.dl/64;i++)
        {
            tab[i]=tab[i]^b.tab[i];
        }
    }
    return *this;
}
tabbit& tabbit::operator ! ()
{
    tabbit temp=tabbit(dl);
    for(int i=0;i<=dl/64;i++)
    {
        temp.tab[i]=!temp.tab[i];
    }
    return temp;
}
istream & operator >> (istream &we, tabbit &tb)
{
    for(int i=tb.dl-1;i>=0;i--)
    {
       we>>tb.tab[i];
    }
    return we;
}
ostream & operator << (ostream &wy, const tabbit &tb)
{
    for(int i=0;i<=tb.dl/64;i++)
    {
       wy<<tb.tab[i]<<" ";
    }
    return wy;
}
bool tabbit::operator [] (int i) const
{
    if(i<0 || i>=dl)
    {
        throw("Proba odwolania sie do elementu poza tablica");
    }
    return czytaj(i);
}

tabbit::ref::ref(tabbit *tb, int i)
{
    tablicabit=tb;
    indeks=i;
}

void tabbit::ref::wypisz()
{
    for(int i=0;i<tablicabit->rozmiar();i++)
    {
        if(i==64)
            cout<<" ";
        cout<<tablicabit->czytaj(i);
    }
}

bool tabbit::ref::operator=(bool a)
{
    return tablicabit->zapisz(indeks,a);
}


tabbit::ref tabbit::operator [] (int i)
{
    if(i<0 || i>=dl)
    {
        throw("Proba odwolania sie do elementu poza tablica");
    }
    return {this,i};
}

}
