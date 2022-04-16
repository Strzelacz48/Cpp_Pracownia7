#include "header.hpp"
// wyzerowana tablica bitow [0...rozm]
tabbit::tabbit(int rozmiar)
{
    dl=rozmiar;
    rozmiarSlowa=rozmiar;
    if(rozmiar%64!=0)
    {
        tab[(rozmiar/64)+1];
        for(int i=0;i<(rozmiar/64)+1;i++)
        {
            tab[i]=0;
        }
    }
    else
    {
        tab[rozmiar/64];
        for(int i=0;i<rozmiar/64;i++)
        {
            tab[i]=0;
        }
    }
}// tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
tabbit::tabbit(slowo tb)
{
    tab[1];
    tab[0]=tb;
    while(tb!=0)
    {
        dl++;
        tb/=2;
    }
    rozmiarSlowa=dl;
}
// destruktor
tabbit::~tabbit()
{
    delete[]tab;
}
tabbit::tabbit(const tabbit &tb)// konstruktor kopiujący
{
    rozmiarSlowa=tb.rozmiarSlowa();
    dl=tb.dl;
    if(rozmiarSlowa%64!=0)
    {
        tab[(rozmiarSlowa/64)+1];
        for(int i=0;i<(rozmiarSlowa/64)+1;i++)
        {
            tab[i]=tb.tab[i];
        }
    }
    else
    {
        tab[rozmiarSlowa/64];
        for(int i=0;i<rozmiarSlowa/64;i++)
        {
            tab[i]=tb.tab[i];
        }
    }
}
tabbit::tabbit(tabbit &&tb); // konstruktor przenoszący
{
    swap(dl,tb.dl);
    swap(rozmiarSlowa,tb.rozmiarSlowa);
    for(int i=0;i<dl;i++)
    {
        swap(tab[i],tb.tab[i]);
    }

}
tabbit::tabbit& operator = (const tabbit &tb); // przypisanie kopiujące
{
    if(&tb==this)
    {
        return *this;
    }
    dl=tb.dl;
    rozmiarSlowa=tb.rozmiarSlowa
    //a=new double[n+1];
    for(int i=0;i<dl;i++)
    {
        tab[i]=tb.tab[i];
    }
    return *this;;
}
tabbit::tabbit& operator = (tabbit &&tb); // przypisanie przenoszące
{
    if(&tb==this)
    {
        return *this;
    }
    swap(dl,tb.dl);
    swap(rozmiarSlowa,tb.rozmiarSlowa);
    swap(tab,tb.tab);
    return *this; ;
}
