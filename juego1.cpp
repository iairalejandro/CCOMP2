#include <iostream>
#include <vector>

using namespace std;

void imprimirTablero(const vector<vector<char>>& tablero, int* puntajeX, int* puntajeO) {
    cout << endl;
    cout << "  ";
    for (int i = 0; i < tablero.size(); ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < tablero.size(); ++i) {
        cout << i << " ";
        for (int j = 0; j < tablero[i].size(); ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Puntaje X: " << *puntajeX << endl;
    cout << "Puntaje O: " << *puntajeO << endl;
    cout << endl;
}

bool esPosicionValida(int x, int y, int tamano) {
    return x >= 0 && x < tamano && y >= 0 && y < tamano;
}

bool hacerJugada(vector<vector<char>>& tablero, int x, int y, char jugador, int* puntajeX, int* puntajeO, bool& primeraJugada) {
    if (esPosicionValida(x, y, tablero.size()) && tablero[x][y] == '.') {
        if (!primeraJugada) {
            bool adyacente = false;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; ++i) {
                int nx = x + *(dx + i);
                int ny = y + *(dy + i);
                if (esPosicionValida(nx, ny, tablero.size()) && tablero[nx][ny] != '.') {
                    adyacente = true;
                    break;
                }
            }
            if (!adyacente) {
                cout << "Debes colocar tu simbolo de manera adyacente a una de las fichas existentes." << endl;
                return false;
            }
        }
        tablero[x][y] = jugador;
        if (jugador == 'X') {
            (*puntajeX)++;
        } else {
            (*puntajeO)++;
        }
        primeraJugada = false;
        return true;
    } else {
        cout << "Posicion invalida. Intentalo de nuevo." << endl;
        return false;
    }
}

void cambiarFichas(vector<vector<char>>& tablero, int x, int y, char jugador, int* puntajeX, int* puntajeO) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; ++i) {
        int nx = x + *(dx + i);
        int ny = y + *(dy + i);
        bool cambiar = false;
        while (esPosicionValida(nx, ny, tablero.size()) && tablero[nx][ny] != '.' && tablero[nx][ny] != jugador) {
            nx += *(dx + i);
            ny += *(dy + i);
            cambiar = true;
        }
        if (esPosicionValida(nx, ny, tablero.size()) && tablero[nx][ny] == jugador && cambiar) {
            nx = x + *(dx + i);
            ny = y + *(dy + i);
            while (tablero[nx][ny] != jugador) {
                tablero[nx][ny] = jugador;
                if (jugador == 'X') {
                    (*puntajeX)++;
                    (*puntajeO)--;
                } else {
                    (*puntajeO)++;
                    (*puntajeX)--;
                }
                nx += *(dx + i);
                ny += *(dy + i);
            }
        }
    }
}

bool juegoTerminado(const vector<vector<char>>& tablero) {
    for (int i = 0; i < tablero.size(); ++i) {
        for (int j = 0; j < tablero[i].size(); ++j) {
            if (tablero[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    const int TAMANO = 7;
    vector<vector<char>> tablero(TAMANO, vector<char>(TAMANO, '.'));

    char jugador = 'X';
    int puntajeX = 0, puntajeO = 0;
    int* ptrPuntajeX = &puntajeX;
    int* ptrPuntajeO = &puntajeO;
    bool primeraJugada = true;

    while (!juegoTerminado(tablero)) {
        imprimirTablero(tablero, ptrPuntajeX, ptrPuntajeO);
        int x, y;
        cout << "Turno del jugador " << jugador << ". Introduce las coordenadas (xy): ";
        char coordenada;
        cin >> coordenada;
        x = coordenada - '0';
        cin >> coordenada;
        y = coordenada - '0';

        if (hacerJugada(tablero, x, y, jugador, ptrPuntajeX, ptrPuntajeO, primeraJugada)) {
            cambiarFichas(tablero, x, y, jugador, ptrPuntajeX, ptrPuntajeO);
            jugador = (jugador == 'X') ? 'O' : 'X';
        }
    }

    imprimirTablero(tablero, ptrPuntajeX, ptrPuntajeO);

    if (puntajeX > puntajeO) {
        cout << "El jugador X ha ganado con " << puntajeX << " puntos." << endl;
    } else if (puntajeO > puntajeX) {
        cout << "El jugador O ha ganado con " << puntajeO << " puntos." << endl;
    } else {
        cout << "¡Ha habido un empate!" << endl;
    }

    return 0;
}
