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
    void lautstaerkeHerauf(int aenderung);
    void lautstaerkeHerunter(int aenderung);
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

// Lautstärke schrittweise erhöhen

void Fernseher::lautstaerkeHerauf(int aenderung)
{
   if (eingeschaltet)
   {
       int max = 10;  // Maximumlautstärke ist 10

       if (lautstaerke + aenderung > max)
           lautstaerke = 10;
       else
           lautstaerke += aenderung;

   }
}

// Lautstärke schrittweise vermindern

void Fernseher::lautstaerkeHerunter(int aenderung)
{
   if (eingeschaltet)
   {
       int min = 0; // Minimumlautstärke ist 0

       if (lautstaerke - aenderung < min)
           lautstaerke = 0;
       else
           lautstaerke -= aenderung;
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

    fernseher1->fernseherEinAus();
    fernseher1->fernseherStatusAusgeben();

    // Programm ändern und Programmauswahl ausgeben

    fernseher1->programmWaehlen(10); // Fernsehprogramm 10 auswählen
    fernseher1->programmWahlAusgeben();

    // Falsches Programm ausgewählt

    fernseher1->programmWaehlen(101);
    fernseher1->programmWahlAusgeben();

    // Lautstärke erhöhen und ausgeben

    fernseher1->lautstaerkeHerauf(10);
    fernseher1->lautstaerkeAusgeben();

    // Laustärke reduzieren und ausgeben

    fernseher1->lautstaerkeHerunter(8);
    fernseher1->lautstaerkeAusgeben();

    // Fernseher ausschalten und Status ausgeben

    fernseher1->fernseherEinAus();
    fernseher1->fernseherStatusAusgeben();

    // Zeiger freigeben

    delete (fernseher1);

    return 0;
}
