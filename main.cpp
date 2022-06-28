/* ####################################################
Einsendeaufgabe 3.4
##################################################### */
// Taschenrechner
#include <iostream>

using namespace std;

float addition(float x, float y)
{
    return(x+y);
}


float subtraktion(float x, float y)
{
    return(x-y);
}


float division(float x, float y)
{
   return(x/y);

}


float multiplikation(float x, float y)
{
    return(x*y);
}


int main()
{
  float wert1, wert2;
  char opchar;

  cout << "Geben Sie eine Zahl ein:  ";
  cin >> wert1;

  cout << "\nWaehlen Sie eine Rechenoperation aus:\n";
  cout << " + Addition\n";
  cout << " - Subtraktion\n";
  cout << " / Division\n";
  cout << " * Multiplikation\n\n";
  cin >> opchar;

  cout << "\nGeben Sie noch eine Zahl ein:  ";
  cin >> wert2;

  cout << "\n";

  switch(opchar)
  {
    case '+':
      cout<<wert1<<" + "<<wert2<<" =  "<<addition(wert1,wert2)<<endl;
      break;
    case '-':
      cout<<wert1<<" - "<<wert2<<" =  "<<subtraktion(wert1,wert2)<<endl;
      break;
    case '/':
       if (wert2 == 0)
          cout<<"Die Division durch Null ist nicht definiert!";
       else
          cout<<wert1<< " / "<< wert2<< " =  "<<division(wert1,wert2)<<endl;
      break;
    case '*':
      cout<<wert1<<" * "<<wert2<<" =  "<<multiplikation(wert1,wert2)<<endl;
      break;
  }

  cout << "\n\n";

  return 0;
}
