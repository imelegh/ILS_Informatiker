/* ######################################################
 * Einsendeaufgabe 5.1
 *  ###################################################### */

// Einfach verkette Liste mit dem Zeiger des Listenendes


#include <iostream>
using namespace std;

//Die Struktur für die Listenelemente
struct listenelement
{
    string daten;
    listenelement* next;

};

//Eine Funktion zum Anhängen von Elementen an die Liste
listenelement* anhaengen(string datenneu, listenelement* listenende)  // *** Melegh
{
    //ein lokaler Hilfszeiger, um in der Liste wandern zu können
    listenelement* hilfszeiger;
    //den Hilfszeiger an das Ende der Liste setzen
    hilfszeiger = listenende;      // *** Melegh
   //ein neues Element an das Ende der Liste anhängen
    hilfszeiger->next = new(listenelement);
    //den Hilfszeiger auf das neue Element setzen
    hilfszeiger = hilfszeiger->next;
    // Zeiger des Listenendes auf das neue Element setzen
    listenende = hilfszeiger;  // *** Melegh
    //die Daten in das neue Element eintragen
    hilfszeiger->daten = datenneu;
    //es gibt keinen Nachfolger, daher wird next auf nullptr gesetzt
    hilfszeiger->next = nullptr;
    return listenende;  // *** Melegh
}

//Eine Funktion zum Ausgeben aller Elemente
void ausgeben(listenelement *listenanfang)
{
    //Ein lokaler Hilfszeiger, um in der Liste wandern zu können
    listenelement* hilfszeiger;
    //den Hilfszeiger auf den Anfang der Liste setzen
    hilfszeiger = listenanfang;
    //das erste Element ausgeben
    cout << hilfszeiger->daten << '\n';
    //Solange das Ende der Liste noch nicht erreicht ist:
    while (hilfszeiger->next != nullptr)
    {
        //den Hilfszeiger hilfszeiger auf das nächste Element setzen
        hilfszeiger = hilfszeiger->next;
        //Daten ausgeben
        cout << hilfszeiger->daten << '\n';
    }
}

//die Liste leeren und Speicher freigeben
void ende(listenelement* listenanfang)
{
    //Ein lokaler Hilfszeiger, um in der Liste wandern zu können
    listenelement* hilfszeiger;
    //Solange noch Elemente in der Liste sind
    while (listenanfang != nullptr)
    {
        //den Hilfszeiger auf das erste Element der Liste
        hilfszeiger = listenanfang;
        //den Zeiger für den Listenanfang auf das nächste Element setzen
        listenanfang = listenanfang->next;
        //den Speicher für das herausgenommene Element freigeben
        delete(hilfszeiger);
    }
}

int main ()
{
    //ein Zeiger auf den Anfang der Liste
    listenelement* listenanfang;
    //ein Zeiger auf das Ende der Liste
    listenelement* listenende;  // *** Melegh
    //das erste Element erzeugen
    listenanfang = new(listenelement);
    // das erste Element wird auch das letzte Element
    listenende = listenanfang;   // *** Melegh
    //Daten in das erste Element schreiben
    listenanfang->next = nullptr;
    listenanfang->daten = "Element 1";

    //und jetzt weitere Elemente erzeugen.
    // das Listenende nach jedem Anhängen ermittelt wird und auch an die Funktion main() zurückgeliefert wird.
    listenende = anhaengen("Element 2", listenende);  // *** Melegh
    listenende = anhaengen("Element 3", listenende);  // *** Melegh
    // der zurücklieferte Wert wird nicht mehr benutzt
    anhaengen("Element 4", listenende);  // *** Melegh


    //die Liste ausgeben
    ausgeben(listenanfang);
    //die Liste wieder abbauen
    ende(listenanfang);

    return 0;
}
