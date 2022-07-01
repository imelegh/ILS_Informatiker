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
    cout<< "\nGeben Sie bitte die Daten der Kiste Nr: "<< kisteNummer << " ein:\n\n";
    cout<<"Breite: ";
    cin>>aKiste.breite;
    cout<<"Hoehe:  ";
    cin>>aKiste.hoehe;
    cout<<"Laenge:  ";
    cin>>aKiste.laenge;
    cout<<"\nDie Daten fuer die Kiste mit Nummer: " << kisteNummer << " wurde eingetragen.\n\n";

    return aKiste;
}


void auslesen(kiste fLager[], int zeiger)
{

    cout<<"\nBreite:\t"<<fLager[zeiger].breite<<"\n";
    cout<<"Hoehe:\t"<<fLager[zeiger].hoehe<<"\n";
    cout<<"Laenge:\t"<<fLager[zeiger].laenge<<"\n";


}


int volumen (kiste aKiste)
{
int volWert;
volWert = aKiste.hoehe * aKiste.breite * aKiste.laenge;
return volWert;
}



// Funktion für die Suche nach der Index des Elementes des Feldes.

int sucheKiste(kiste fLager[], int kisteNummer)
{
    int zeiger = 0;
    bool gefunden = false;
    do
    {
           if (fLager[zeiger].kNummer == kisteNummer)
              gefunden = true;
           else
               zeiger++;
    } while ((zeiger < lagerGroesse) && !gefunden);

    if (gefunden == false)
        zeiger = -1;  // wenn kein Treffer output ist -1

    return zeiger;


}

int main()
{

    // Für den Lager ein Feld mit Elementen Typ kiste erstellen

    kiste lager[lagerGroesse];

    // Die Kistenummer auf 0 initialisieren.

    for (int i=0; i<lagerGroesse; i++)
        lager[i].kNummer = 0;

   // Auswahlmenü

    bool menuzeigen = true;
    int index;
    do
    {
        short unsigned int menuWahl;
        cout<<"\n\nLagerverwaltung\n";
        cout<<"===============\n\n";
        cout<<"1. Eingabe einer neuen Kiste\n";
        cout<<"2. Loeschen der Daten einer vorhandenen Kiste\n";
        cout<<"3. Aendern der Daten einer vorhandenen Kiste\n";
        cout<<"4. Anzeigen der Daten einer vorhandenen Kiste\n";
        cout<<"5. Liste, die die Daten aller vorhandenen Kisten anzeigt\n";
        cout<<"6. Austreten vom Program\n\n";
        cout<<" Geben Sie die Nummer der Funktion ein:  ";
        cin>>menuWahl;

        switch(menuWahl)
        {
        case 1:

            // Kistenummer 0 ist für leeren Platz in dem Feld lager, -1 bedeutet die Suche nach einen leeren Platz war unerfolgreich

           index = sucheKiste(lager,0);
           if (index != -1)
           {
              int kisteNummer;
              bool vorhanden = false;
              do
              {
                cout << "\n\nBitte geben Sie eine positive Zahl fuer die Nummer der Kiste: ";
                cin >> kisteNummer;

                if (sucheKiste(lager, kisteNummer) == -1)
                {
                    vorhanden = false;
                    lager[index] = einlesen(kisteNummer);


                }
                else
                {
                    cout << "\nDie Kistenummer ist schon vorhanden, waehlen Sie eine andere Zahl aus!\n";
                    vorhanden = true;
                 }
              } while (vorhanden);

           }

            break;
        case 2:


            break;
        case 3:
            break;
        case 4:
            int kisteNummer;
            cout << "\nBitte geben Sie die Nummer der Kiste ein: ";
            cin >> kisteNummer;
            index = sucheKiste(lager, kisteNummer);
            if (index != -1)
            {
                cout << "\nDie Daten fuer die Kiste mit Nummer " << kisteNummer << ": \n";
                auslesen(lager, index);
            }
            else
                cout << "\nKeine Kiste mit dieser Nummer wurde gefunden.\n\n";
            break;

        case 5:
            break;
         case 6:
            menuzeigen = false;
            cout<<"\nAuf Wiedersehen! (aus dem Konsol auszutreten druecken Sie ENTER)\n";
            break;
        default:
            cout << "Sie haben keine gueltige Auswahl getroffen!\n";

        }
    } while (menuzeigen);

    // Suche ob es Platz gibt







    return 0;
}

