#include <iostream>

using namespace std;

class Fernseher
{
    bool eingeschaltet;
    int programm;
    int lautstaerke;

public:
    void init();
    void fernseherEinAus();
    void programmWaehlen(int aenderung);
    void lautstaerkeHerauf();
    void lautstaerkeHerunter();
    void fernseherStatusAusgeben();
    void programmWahlAusgeben();
    void lautstaerkeAusgeben();

};



void Fernseher::init()
{
    eingeschaltet = false;
    programm = 1;
    lautstaerke = 5;
}

void Fernseher::fernseherEinAus()
{
    eingeschaltet = eingeschaltet ? false:true;
}

void Fernseher::programmWaehlen(int aenderung)

{
   if (eingeschaltet)
   {
       // Programmauswahl von 0 bis 100 möglich
       if (aenderung< 1 || aenderung > 100)
           cout << "\nUngueltige Programmauswahl\n";
       else
           programm = aenderung;
    }
}

void Fernseher::lautstaerkeHerauf()
{
   if (eingeschaltet)
   {
       int max = 10;  // Maximumlautstärke ist 10

       lautstaerke += 1;
       if (lautstaerke > max)
           lautstaerke = 10;
   }
}

void Fernseher::lautstaerkeHerunter()
{
   if (eingeschaltet)
   {
       int min = 0; // Minimumlautstärke ist 0

       lautstaerke -= 1;
       if (lautstaerke < min)
           lautstaerke = 0;
   }
}

void Fernseher::fernseherStatusAusgeben()
{
    if (eingeschaltet)
        cout << "\n Fernseher ist eingeschaltet\n";
    else
        cout  << "\n Fernseher ist ausgeschaltet\n";
}

void Fernseher::programmWahlAusgeben()
{
    if (eingeschaltet)
        cout << "\nProgramm: " << programm << " ist ausgewaehlt\n";

}

void Fernseher::lautstaerkeAusgeben()
{

    if (eingeschaltet)
         cout << "\nLautstaerke: " << lautstaerke << '\n';
}





int main()
{
    // Instanz für den Fernseher dynamisch über einen Zeiger erstellen
    Fernseher* fernseher1;
    fernseher1 = new Fernseher();
    fernseher1->init();

    // Fernseher einschalten und Status ausgeben






    delete (fernseher1);
    return 0;
}
