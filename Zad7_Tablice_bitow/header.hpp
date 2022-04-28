#include <iostream>
#include<cstdint>
using namespace std;
namespace obliczenia
{
    class tabbit {
        typedef uint64_t slowo; // komorka w tablicy
        static const int rozmiarSlowa=8*sizeof(slowo); // rozmiar slowa w bitach
        friend istream & operator >> (istream &we, tabbit &tb);
        friend ostream & operator << (ostream &wy, const tabbit &tb);
        class ref // klasa pomocnicza do adresowania bitów
        {
                tabbit *tablicabit;
                int indeks;
            public:
                ref(tabbit *tb,int indeks);
            public:
                void wypisz();
                bool operator=(bool);
        };
        protected:
            int dl; // liczba bitów
            slowo *tab; // tablica bitów
        public:
            // wyzerowana tablica bitow [0...rozm]
            explicit tabbit(int rozm);
            // tablica bitów [0...rozmiarSlowa] zainicjalizowana wzorcem
            explicit tabbit(slowo tb);
            // destruktor
            ~tabbit();
            tabbit(const tabbit &tb); // konstruktor kopiujący
            tabbit(tabbit &&tb); // konstruktor przenoszący
            tabbit& operator = (const tabbit &tb); // przypisanie kopiujące
            tabbit& operator = (tabbit &&tb); // przypisanie przenoszące
            tabbit(std::initializer_list<bool> bits); // lista inicjalizacyjna
        private:
            bool czytaj(int i) const; // metoda pomocnicza do odczytu bitu
            bool zapisz(int i, bool b); // metoda pomocnicza do zapisu bitu
        public:
            // indeksowanie dla stałych tablic bitowych
            bool operator [] (int i) const;
            // indeksowanie dla zwykłych tablic bitowych
            ref operator [] (int i);
            ref wypisz (tabbit tb);
            inline int rozmiar() const; // rozmiar tablicy w bitach
        public:
        // operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
            tabbit& operator | (tabbit b);
            tabbit& operator |= (tabbit b);
            tabbit& operator & (tabbit b);
            tabbit& operator &= (tabbit b);
            tabbit& operator ^ (tabbit b);
            tabbit& operator ^= (tabbit b);
            tabbit& operator ! ();
    };
}
