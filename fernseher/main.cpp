#include <iostream>

using namespace std;

// die Vereinbarung der Klasse

class Fernseher
{
    bool eingeschaltet;
    int programm;
    int lautstaerke;

public:
    void init();
    void schaltenEinAus();
    void programmWaehlen(int aenderung);
    void lautstaerkeHerauf();
    void lautstaerkeHerunter();
};



void Fernseher::init()
{
    eingeschaltet = false;
    programm = 1;
    lautstaerke = 5;
}

void Fernseher::schaltenEinAus()
{
    eingeschaltet = eingeschaltet ? false:true;
    if (eingeschaltet)
        cout << "\n Fernseher ist eingeschaltet\n";
    else
        cout  << "\n Fernseher ist ausgeschaltet\n";
}

void Fernseher::programmWaehlen(int aenderung)

{
   if (eingeschaltet)
   {
       if (aenderung< 1 || aenderung > 100)
           cout << "\nUngueltige Programmauswahl\n";
       else
       {
           programm = aenderung;
           cout << "\nProgramm: " << programm << '\n';
       }
    }

}

void Fernseher::lautstaerkeHerauf()
{
   if (eingeschaltet)
   {
       int max = 10;

       lautstaerke += 1;
       if (lautstaerke > max)
           lautstaerke = 10;
   }

   cout << "\nLatustaerke: " << lautstaerke << '\n';
}

void Fernseher::lautstaerkeHerunter()
{
   if (eingeschaltet)
   {
       int min = 0;

       lautstaerke -= 1;
       if (lautstaerke < min)
           lautstaerke = 0;
   }
   cout << "\nLatustaerke: " << lautstaerke << '\n';
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
