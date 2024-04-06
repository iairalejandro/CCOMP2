#include <iostream>
#include <iomanip>

using namespace std;

// Función para determinar si un año es bisiesto
bool esBisiesto(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Función para obtener el número de días en un mes
int diasEnMes(int month, int year) {
    switch (month) {
        case 1: // Enero
        case 3: // Marzo
        case 5: // Mayo
        case 7: // Julio
        case 8: // Agosto
        case 10: // Octubre
        case 12: // Diciembre
            return 31;
        case 4: // Abril
        case 6: // Junio
        case 9: // Septiembre
        case 11: // Noviembre
            return 30;
        case 2: // Febrero
            return (esBisiesto(year)) ? 29 : 28;
        default:
            return -1; // Mes inválido
    }
}

// Función para obtener el día de la semana en que comienza un mes
int obtenerDiaInicio(int year, int month) {
    // Congru de Zeller
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (2 + ((13 * (month + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    return ((h + 5) % 7) + 1;
}

// Función para imprimir el calendario
void imprimirCalendario(int year, int month) {
    int diasEnSemana = 7;
    int diaInicio = obtenerDiaInicio(year, month); // El día de la semana en que comienza el mes
    int dias = diasEnMes(month, year);

    // Encabezado
    cout << " Calendario " << month << "/" << year << endl;
    cout << "---------------------------" << endl;
    cout << " Dom Lun Mar Mie Jue Vie Sab" << endl;

    // Ajuste para el día de inicio
    for (int i = 1; i < diaInicio; ++i) {
        cout << setw(4) << " ";
    }

    // Imprimir los días del mes
    for (int i = 1; i <= dias; ++i) {
        cout << setw(4) << i;
        if ((i + diaInicio - 1) % diasEnSemana == 0 || i == dias) {
            cout << endl;
        }
    }
}

int main() {
    int year, month;

    // Solicitar al usuario el año y el mes
    cout << "Ingrese el anio: ";
    cin >> year;
    cout << "Ingrese el mes (1-12): ";
    cin >> month;

    // Verificar si el mes es válido
    if (month < 1 || month > 12) {
        cout << "Mes invalido. Debe estar entre 1 y 12." << endl;
        return 1;
    }

    // Imprimir el calendario
    imprimirCalendario(year, month);

    return 0;
}
