#include "header.hpp"
void ref::wypisz(tabbit tb)
{
    for(int i=0;i<tb.rozmiar();i++)
    {
        if(i==64)
            cout<<" ";
        cout<<tb.czytaj(i);
    }
}
bool ref::operator [] (int i)
{
    return czytaj(i);
}
