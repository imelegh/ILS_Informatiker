/* ########################################
Eine einfach verkettete Liste mit Objekten
##########################################*/
#include <iostream>
using namespace std;

//die Klasse
class Listenelement
{
    string daten;
    Listenelement* next;
public:
    void datenSetzen(string datenneu);
    Listenelement* anhaengen(string datenneu);   // *****
    void ausgeben();
    void freigeben();
};

//die Methoden
//die Daten in das Element schreiben
void Listenelement::datenSetzen(string datenneu)
{
    daten = datenneu;
    next = nullptr;
    //nur zur Veranschaulichung
    cout << datenneu << " wurde eingefuegt.\n";
}

//neues Element am Ende der Liste anhängen
Listenelement* Listenelement::anhaengen(string datenneu)  // *****
{

    {
        next = new Listenelement();
        next->daten = datenneu;
        next->next = nullptr;
    }

    //nur zur Veranschaulichung
    cout << datenneu << " wurde eingefuegt.\n";

    return next;
}

//Alle Elemente der Liste ausgeben
void Listenelement::ausgeben()
{
    //den ersten Eintrag ausgeben
    cout << daten << '\n';
    //wenn das Ende nicht erreicht ist, die Methode für next erneut aufrufen
    if (next != nullptr)
        next->ausgeben();
}

//den Speicher freigeben
void Listenelement::freigeben()
{
    //wenn das Ende nicht erreicht ist, die Methode erneut aufrufen
    if (next != nullptr)
    {
        next->freigeben();
        delete(next);
    }
}

int main ()
{
    //ein Zeiger auf den Listenanfang
    Listenelement* listenanfang;
    Listenelement* listenende;  // *****

    //das erste Element per Hand erzeugen
    listenanfang = new Listenelement();
    //Daten in das erste Element schreiben
    listenanfang->datenSetzen("Element 1");

    listenende = listenanfang;         // *****

    //weitere Elemente anhängen
    listenende = listenende->anhaengen("Element 2");   // ****
    listenende = listenende->anhaengen("Element 3");   // ****

    //die Liste ausgeben
    listenanfang->ausgeben();

    //die Liste abbauen und freigeben
    listenanfang->freigeben();
    delete(listenanfang);
    delete(listenende);

    return 0;
}
