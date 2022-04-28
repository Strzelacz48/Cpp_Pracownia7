#include "header.hpp"
using namespace std;
using namespace obliczenia;
//using namespace obliczenia;
int main()
{
    tabbit a(139);
    a[65]=true;
    //cout<<"Wyzerowana tablica : ";
    cout<<a<<"\n";
    for(int i=1;i<=64;i++)
    {
        cout<<i%10<<" ";
    }
    cout<<"\n";
    tabbit t(46); // tablica 46-bitowa (zainicjalizowana zerami)
    tabbit u(45ull); // tablica 64-bitowa (sizeof(uint64_t)*8)
    tabbit v(t); // tablica 46-bitowa (skopiowana z t)
    tabbit w(tabbit{1, 0, 1, 1, 0, 0, 0, 1}); // tablica 8-bitowa
    v[0] = 1; // ustawienie bitu 0-go bitu na 1
    cout<<t<<endl;
    cout<<v<<endl;
    t[45] = true; // ustawienie bitu 45-go bitu na 1
    cout << w << endl;
    bool b = v[1]; // odczytanie bitu 1-go
    //u[45] = u[46] = u[63]; // przepisanie bitu 63-go do 45-go i 46-go
    cout << b << endl;
    cout<<t<<endl; // wyświetlenie zawartości tablicy bitów na ekranie
    cout << "Hello world!" << endl;
    return 0;
}
