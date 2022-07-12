/*	######################################################
    Einsendeaufgabe 5.2
    ###################################################### */

#include <iostream>
//für die intelligenten Zeiger
#include <memory>
using namespace std;

//Die Struktur für die Listenelemente
struct listenelement
{
    string daten;
    shared_ptr<listenelement> next;
    shared_ptr<listenelement> last;  // *** Melegh
};

//Eine Funktion zum Anhängen von Elementen an die Liste
void anhaengen(string datenneu, shared_ptr<listenelement> listenanfang)
{
    //ein lokaler Hilfszeiger, um in der Liste wandern zu können
    shared_ptr<listenelement> hilfszeiger;
    //den Hilfszeiger an den Anfang der Liste setzen
    hilfszeiger = listenanfang;

    //Durch die Liste gehen, bis das letzte Element erreicht ist
    while (hilfszeiger->next != nullptr)
        hilfszeiger = hilfszeiger->next;
    //ein neues Element an das Ende der Liste anhängen
    hilfszeiger->next = make_shared<listenelement>();

    // die Adresse des Vorgängerelements aufnehmen
    hilfszeiger->next->last = hilfszeiger;   // *** Melegh

    //den Hilfszeiger auf das neue Element setzen
    hilfszeiger = hilfszeiger->next;
    //die Daten in das neue Element eintragen
    hilfszeiger->daten = datenneu;
}

//Eine Funktion zum Ausgeben aller Elemente
void ausgeben(shared_ptr<listenelement> listenanfang)
{
    cout << "Liste von Anfang an: " << '\n';
    cout << "-------------------- " << '\n';
    //Ein lokaler Hilfszeiger, um in der Liste wandern zu können
    shared_ptr<listenelement> hilfszeiger;
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
// die Liste rückwärts – also vom letzten Element beginnend bis zum Anfang – ausgibt
void ausgebenRueckwaerts(shared_ptr<listenelement> listenanfang)  // *** Melegh
{
    cout << "\nListe vom Ende an: " << '\n';
    cout << "-------------------- " << '\n';

    //Ein lokaler Hilfszeiger, um in der Liste wandern zu können
    shared_ptr<listenelement> hilfszeiger;
    //den Hilfszeiger auf den Anfang der Liste setzen
    hilfszeiger = listenanfang;

    //Durch die Liste gehen, bis das letzte Element erreicht ist
    while (hilfszeiger->next != nullptr)
        hilfszeiger = hilfszeiger->next;

    // das letzte Element ausgeben
    cout << hilfszeiger->daten << '\n';


    // Solange der Anfang der Liste noch nicht erreicht ist:
    while(hilfszeiger->last != nullptr)
    {
        // den Hilfszeiger hilfszeiger auf das vorige Element setzen
        hilfszeiger = hilfszeiger->last;
        // Daten ausgeben
        cout << hilfszeiger->daten << '\n';

     }
}

int main ()
{
    //ein intelligenter Zeiger auf den Anfang der Liste
    //er muss vom Typ shared_ptr sein
    shared_ptr<listenelement> listenanfang = make_shared<listenelement>();

    //Daten in das erste Element schreiben
    listenanfang->daten = "Element 1";

    //und jetzt weitere Elemente erzeugen
    anhaengen("Element 2", listenanfang);
    anhaengen("Element 3", listenanfang);
    anhaengen("Element 4", listenanfang);

    //die Liste ausgeben
    ausgeben(listenanfang);

    // die Liste rückwärts ausgeben
    ausgebenRueckwaerts(listenanfang);  // *** Melegh

    return 0;
}
