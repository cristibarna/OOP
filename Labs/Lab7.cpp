#include <iostream>
#include<cassert>
using namespace std;

class Fractie
{
private:
    int m_numarator{ 0 };
    int m_numitor{ 1 };
    static int x;
    static int count;
public:

    static void setx(int x) { 
        Fractie::x = x; 
    }
    static int getx() { 
        return x; 
    }

    static void setcount(int x) { 
        Fractie::count = x; 
    }
    static int getcount() { 
        return count; 
    }
    // Default constructor
    Fractie(int numarator = 0, int numitor = 1)
        : m_numarator(numarator), m_numitor(numitor)
    {
        this->m_numarator = numarator;
        this->m_numitor = numitor;
        Fractie::count++;

        assert(numitor != 0);
    }

    // Copy constructor
    Fractie(const Fractie& copy)
        : m_numarator{ copy.m_numarator }, m_numitor{ copy.m_numitor }
    {
        // nu mai este nevoie de verificarea numitorului pentru ca operatiile se fac asupra a doua obiecte existente - au fost verificate in cadrul constructorului
        cout << "S-a apelat constructorul de copiere.\n";
    }

    // Supraincarcarea operatorului de atribuire:  =
   // Fractie& operator= (const Fractie& fractie);
    //void operator= (const Fractie& fractie);

    Fractie& operator= (const Fractie& fractie); // nu se permite efectuarea copiilor prin asignare!
};

int Fractie::x = 0;
// O alta implementare => void??
int Fractie::count = 0;
/*
void Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie)
        return;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return;
}
*/

// O implementare mai buna - corecta => discutie

Fractie& Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie)
        return *this;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return *this;
}

int main()
{
    Fractie::setx(1);
    cout << Fractie::getx() << endl;
    Fractie::setcount(5);

    Fractie fff{ 1,2 };
    Fractie fff1;
    fff1 = fff;
    Fractie f4 = fff1;

    Fractie _5p3{ 5, 3 };
    Fractie f = _5p3;
    //Fractie::x = 3;
    Fractie ff;      //cine se apeleaza?
    ff = _5p3; //cine se apeleaza?

    Fractie f1{ 5, 3 };
    Fractie f2{ 7, 2 };
    Fractie f3{ 9, 5 };

    f1 = f2 = f3; //asignare inlantuita
    f1 = f2;// = f3; //asignare inlantuita

    f1 = f1; // autoasignare

    cout << Fractie::getcount() << endl;
    return 0;
}