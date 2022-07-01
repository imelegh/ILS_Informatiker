#include <iostream>

using namespace std;

int lagerGroesse = 50;

// eine Structur für die Kisten erstellen
struct kiste
{
int kNummer;
int breite;
int hoehe;
int laenge;
};

kiste einlesen(int kisteNummer)
{
    kiste aKiste;
    aKiste.kNummer = kisteNummer;
    cout<< "Geben Sie bitte die Daten der Kiste Nr: "<< kisteNummer << " ein:\n";
    cout<<"Breite: ";
    cin>>aKiste.breite;
    cout<<"Hoehe:  ";
    cin>>aKiste.hoehe;
    cout<<"Laenge:  ";
    cin>>aKiste.laenge;

    return aKiste;
}


kiste auslesen(int kisteNummer)
{
    kiste aKiste;

    cout<< "Hier sind die Daten der Kiste Nr. " << kisteNummer << ":\n";

    cout<<"Breite:\t"<<aKiste.breite<<"\n";
    cout<<"Hoehe:\t"<<aKiste.hoehe<<"\n";
    cout<<"Laenge:\t"<<aKiste.laenge<<"\n";

    return aKiste;
}


int volumen (kiste aKiste)
{
int volWert;
volWert = aKiste.hoehe * aKiste.breite * aKiste.laenge;
return volWert;
}

int main()
{

    // Für den Lager ein Feld mit Elementen Typ kiste erstellen

    kiste lager[lagerGroesse];

    // Die Kistenummer auf 0 initialisieren.

    for (int i=0; i<lagerGroesse; i++)
        lager[i].kNummer = 0;

   // Auswahlmenü
    short unsigned int menuWahl;
    cout<<" Geben Sie die Nummer der Funktion ein\n\n";
    cout<<"1. Eingabe einer neuen Kiste\n";
    cout<<"2. Loeschen der Daten einer vorhandenen Kiste\n";
    cout<<"3. Aendern der Daten einer vorhandenen Kiste\n";
    cout<<"4. Anzeigen der Daten einer vorhandenen Kiste\n";
    cout<<"5. Liste, die die Daten aller vorhandenen Kisten anzeigt\n";
    cin>>menuWahl;

    switch(menuWahl)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    default:
        cout << "Sie haben keine gueltige Auswahl getroffen!\n";

    }

    // Suche ob es Platz gibt







    return 0;
}

