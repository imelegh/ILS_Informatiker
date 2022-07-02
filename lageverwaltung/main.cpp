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

int kistenNummer;
int zeiger;
bool menuzeigen = true;
int zaehler;

// Funktion für die Eingabe der Grunddateien einer Kiste (ohne Volumen)

kiste einlesen(int kistenNummer)
{
    kiste aKiste;
    aKiste.kNummer = kistenNummer;
    cout<< "\n\nDaten der Kiste Nr: "<< kistenNummer << " eingeben:\n";
    cout<< "---------------------------------\n";
    cout<<"Breite: ";
    cin>>aKiste.breite;
    cout<<"Hoehe:  ";
    cin>>aKiste.hoehe;
    cout<<"Laenge:  ";
    cin>>aKiste.laenge;
    cout<<"\nDie Daten fuer die Kiste mit Nummer " << kistenNummer << " wurde eingetragen.\n\n";

    return aKiste;
}

// Funktion für Ausgabe der Dateien einer Kiste (Volumen ist errechnet)

void auslesen(kiste fLager[], int zeiger)
{

    cout<<"\nBreite:\t"<<fLager[zeiger].breite<<"\n";
    cout<<"Hoehe:\t"<<fLager[zeiger].hoehe<<"\n";
    cout<<"Laenge:\t"<<fLager[zeiger].laenge<<"\n";
    cout<<"Volumen:  "<<fLager[zeiger].laenge * fLager[zeiger].hoehe * fLager[zeiger].laenge<<"\n";


}

// Funktion für die Suche nach der Index des Elementes des Lagers mit der Angabe der Kistennummer.

int sucheKiste(kiste fLager[], int kistenNummer)
{
    int zeiger = 0;
    bool gefunden = false;
    do
    {
           if (fLager[zeiger].kNummer == kistenNummer)
              gefunden = true;
           else
               zeiger++;
    } while ((zeiger < lagerGroesse) && !gefunden);

    if (gefunden == false)
        zeiger = -1;  // wenn kein Treffer output ist -1

    return zeiger;


}

// Funktion für die Eingabe einer Kiste mit Hilfe der Funktion einlesen()

void eingabe(kiste fLager[], int kistenNummer)
{
    bool vorhanden = false;
    do
    {
      cout << "\n\nBitte geben Sie eine positive Zahl fuer die Nummer der Kiste: ";
      cin >> kistenNummer;

      // Prüfen ob es eine Kistennummer mit dem angegeben Wert schon gibt (-1 bedeutet es gibt keine Kiste mit dieser Nummer)

      if (sucheKiste(fLager, kistenNummer) == -1)
      {
          vorhanden = false;
          fLager[zeiger] = einlesen(kistenNummer);

      }
      else
      {
          cout << "\nDie Kistennummer ist schon vorhanden, waehlen Sie eine andere Zahl aus!\n\n";
          vorhanden = true;
       }
    } while (vorhanden);
}


// Funktionen für die Auswahlmenü

void eingeben(kiste *);
void loeschen(kiste *);
void ausgeben(kiste *);
void aendern(kiste *);
void auflisten(kiste *);





int main()
{


    // Für den Lager ein Feld mit Elementen Typ kiste erstellen

    kiste lager[lagerGroesse];

    // Die Kistennummer auf 0 initialisieren.

    for (int i=0; i<lagerGroesse; i++)
        lager[i].kNummer = 0;

   // Auswahlmenü

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
               eingeben(lager);
            break;
        case 2:
               loeschen(lager);
            break;
        case 3:

               aendern(lager);
            break;

        case 4:
               ausgeben(lager);
            break;
        case 5:
               auflisten(lager);
            break;
         case 6:
            menuzeigen = false;
            cout<<"\nAuf Wiedersehen! (aus dem Konsol auszutreten druecken Sie ENTER)\n\n";
            break;
        default:
            cout << "Sie haben keine gueltige Auswahl getroffen!\n";
        }
    } while (menuzeigen);

      return 0;
}

// Funktion für Eingaben

void eingeben(kiste fLager[])
{
    // kistenNummer 0 ist für leeren Platz in dem Feld fLager, -1 bedeutet die Suche nach einen leeren Platz war unerfolgreich

   zeiger = sucheKiste(fLager,0);
   if (zeiger != -1)
   {
      bool vorhanden = false;
      do
      {
        cout << "\n\nBitte geben Sie eine positive Zahl fuer die Nummer der Kiste: ";
        cin >> kistenNummer;

        // Prüfen ob es eine Kistennummer mit dem angegeben Wert schon gibt (-1 bedeutet es gibt keine Kiste mit dieser Nummer)

        if (sucheKiste(fLager, kistenNummer) == -1)
        {
            vorhanden = false;
            fLager[zeiger] = einlesen(kistenNummer);


        }
        else
        {
            cout << "\nDie Kistennummer ist schon vorhanden, waehlen Sie eine andere Zahl aus!\n\n";
            vorhanden = true;
         }
      } while (vorhanden);

    }
}


// Funktion für Löschen

void loeschen(kiste fLager[])
{

    cout << "\nZu loeschen bitte geben Sie die Nummer der Kiste ein : ";
    cin >> kistenNummer;
    zeiger = sucheKiste(fLager, kistenNummer);
    if (zeiger != -1)
    {
       fLager[zeiger].kNummer = 0;
       cout << "\nDie Kiste mit Nummer: " << kistenNummer << " wurde geloescht.\n";
    }
    else
        cout << "\nKeine Kiste mit dieser Nummer wurde gefunden.\n\n";
}


// Funktion für Ausgeben


void ausgeben(kiste fLager[])
{
    cout << "\nBitte geben Sie die Nummer der Kiste ein: ";
    cin >> kistenNummer;
    zeiger = sucheKiste(fLager, kistenNummer);
    if (zeiger != -1)
    {
        cout << "\n\nDie Daten fuer die Kiste mit Nummer " << kistenNummer << ": \n";
        cout << "-------------------------------------";
        auslesen(fLager, zeiger);
    }
    else
        cout << "\nKeine Kiste mit dieser Nummer wurde gefunden.\n";
}


// Funktion für Ändern

void aendern(kiste fLager[])
{
    cout << "\nBitte geben Sie die Nummer der Kiste ein: ";
    cin >> kistenNummer;

    // Vor der Änderung werden die Daten der Kiste ausgegeben
    ausgeben(fLager);

    cout <<"\n Jetzt die neue Daten eingeben:\n";
    cout << "-----------------------------\n";
    eingabe(fLager, kistenNummer);

    cout << "\nDie Daten der Kiste wurden geaendert.\n";
}


// Funtion für Auflisten

void auflisten(kiste fLager[])
{
    zaehler = 0;
    cout << "\n\nListe der vorhandenen Kisten:\n";
    cout << "=============================\n\n";
    for (int i = 0; i<lagerGroesse; i++)
       if (fLager[i].kNummer !=0 )
       {
            zaehler++;
            cout << "\nKistennummer: " << fLager[i].kNummer << "\n";
            cout << "----------------------";
            auslesen(fLager, i);
        }

     cout << "\nEs wurde " << zaehler << " Kiste(n) gefunden.\n";

}
