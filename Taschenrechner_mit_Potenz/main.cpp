/* ####################################################
Einsendeaufgabe 3.5
##################################################### */

#include <iostream>

using namespace std;

// um mit großen Gleitkommazahlen rechnen zu können Datatype: double (–1,79 · 10^308 bis 1,79 · 10^308)

double addition(double x, double y)
{
    return(x+y);
}


double subtraktion(double x, double y)
{
    return(x-y);
}


double division(double x, double y)
{
   return(x/y);

}


double multiplikation(double x, double y)
{
    return(x*y);
}

double potenz(double x, int y)
// der Exponent (y): wievielmal soll die Schleife laufen, Typ: int ausreichend
{
    double ergebnis = x;
    int i = 1;
    if (y == 0)
        ergebnis = 1;
    else
        while(i<y)
        {
            ergebnis = ergebnis * x;
            i++;
         }
    return(ergebnis);

}

int main()
{
  double wert1, wert2;
  char opchar;

  cout << "Geben Sie eine Zahl ein:  ";
  cin >> wert1;

  cout << "\nWaehlen Sie eine Rechenoperation aus:\n";
  cout << " + Addition\n";
  cout << " - Subtraktion\n";
  cout << " / Division\n";
  cout << " * Multiplikation\n";
  cout << " ^ Potenz mit ganzzahligem positiven Exponenten\n\n";
  cin >> opchar;

  cout << "\nGeben Sie noch eine Zahl ein:  ";
  cin >> wert2;

  cout << endl;

  cout.precision(16);

  switch(opchar)
  {
    case '+':
      cout<<"\n"<<wert1<<" + "<<wert2<<" =  "<<addition(wert1,wert2)<<endl;
      break;

    case '-':
      cout<<"\n"<<wert1<<" - "<<wert2<<" =  "<<subtraktion(wert1,wert2)<<endl;
      break;

    case '/':
       if (wert2 == 0)
          cout<<"\n"<<"Die Division durch Null ist nicht definiert!";
       else
          cout<<"\n"<<wert1<< " / "<< wert2<< " =  "<<division(wert1,wert2)<<endl;
       break;

    case '*':
      cout<<"\n"<<wert1<<" * "<<wert2<<" =  "<<multiplikation(wert1,wert2)<<endl;
      break;

    case '^':
      // explicit Typumwandlung wegen Konvertierung in den niedriegeren Typ double --> int
      cout<<"\n"<<wert1<<" ^ "<<wert2<<" =  "<<potenz(wert1,static_cast<int>(wert2))<<endl;
      break;
    }

  cout << "\n\n";

  return 0;
}
