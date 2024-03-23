#include <iostream>
using namespace std;


int main()
{
    int num, uni, dec, cent, mill;
    cout << "Ingrese un numero a convertir de 1 hasta 9999: ";
    cin >> num;

    if ((num < 1) || (num > 9999)) {
        cout << "Solo numeros entre los indicados" << endl;
        return 0;
    }

    uni = num % 10;
    num /= 10;
    dec = num % 10;
    num /= 10;
    cent = num % 10;
    num /= 10;
    mill = num % 10;
    num /= 10;


    switch (mill) {
        case 1: cout << "M"; break;
        case 2: cout << "MM"; break;
        case 3: cout << "MMM"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VM"; break;
        case 7: cout << "VMM"; break;
        case 8: cout << "VMMM"; break;
        case 9: cout << "IX"; break;

    }
    switch (cent) {
        case 1: cout << "C"; break;
        case 2: cout << "CC"; break;
        case 3: cout << "CCC"; break;
        case 4: cout << "CD"; break;
        case 5: cout << "D"; break;
        case 6: cout << "DC"; break;
        case 7: cout << "DCC"; break;
        case 8: cout << "DCCC"; break;
        case 9: cout << "CM"; break;

    }
    switch (dec) {
        case 1: cout << "X"; break;
        case 2: cout << "XX"; break;
        case 3: cout << "XXX"; break;
        case 4: cout << "XL"; break;
        case 5: cout << "L"; break;
        case 6: cout << "LX"; break;
        case 7: cout << "LXX"; break;
        case 8: cout << "LXXX"; break;
        case 9: cout << "XC"; break;

    }
    switch (uni) {
        case 1: cout << "I"; break;
        case 2: cout << "II"; break;
        case 3: cout << "III"; break;
        case 4: cout << "IV"; break;
        case 5: cout << "V"; break;
        case 6: cout << "VI"; break;
        case 7: cout << "VII"; break;
        case 8: cout << "VIII"; break;
        case 9: cout << "IX"; break;

    }



}
