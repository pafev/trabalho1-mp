#include "./romano.hpp"

#include <cstring>
#include <map>
#include <iostream>

// Copyright 2024 Paulo Fernando Vilarim

bool existeAlgarismoRomano(const char algarismo) {
    return algarismo == 'I' || algarismo == 'V' ||
           algarismo == 'X' || algarismo == 'L' ||
           algarismo == 'C' || algarismo == 'D' ||
           algarismo == 'M';
}


bool maisDe3AlgarismosRepetidos(
    const int index,
    const int tamanhoNum,
    const char *num
) {
    if (tamanhoNum > 3 && index < tamanhoNum - 3) {
        return num[index] == num[index + 1] &&
               num[index] == num[index + 2] &&
               num[index] == num[index + 3];
    }
    return false;
}


bool algarismosRedundantes(const int currentValor, const int nextValor) {
    if (nextValor != 0) {  // se current nao e o ultimo algarismo
        int valorResultante = currentValor < nextValor ?
                              -currentValor + nextValor :
                              currentValor + nextValor;

        return valorResultante == 5 || valorResultante == 10 ||
               valorResultante == 50 || valorResultante == 100 ||
               valorResultante == 500 || valorResultante == 1000;
    } else {
        // se current e o ultimo algarismo, nao tem redundancia
        return false;
    }
}


int converteRomanoArabico(const char *numRomano) {
    std::map<char, int> mapRomanoArabico = {
        {'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500},
        {'M', 1000}
    };

    int tamanhoNumRomano = strlen(numRomano),
        currentCharRomano,
        nextCharRomano,
        currentValorRomano,
        nextValorRomano,
        numArabico = 0;

    for (int i = 0; i < tamanhoNumRomano; i++) {
        currentCharRomano = numRomano[i];
        nextCharRomano = i < tamanhoNumRomano - 1 ? numRomano[i + 1] : '_';
        currentValorRomano = mapRomanoArabico[currentCharRomano];
        nextValorRomano = mapRomanoArabico[nextCharRomano];

        if (  // sequencia de validacoes por algarismo
            !existeAlgarismoRomano(currentCharRomano) ||
            algarismosRedundantes(currentValorRomano, nextValorRomano) ||
            maisDe3AlgarismosRepetidos(i, tamanhoNumRomano, numRomano)
        ) {
            return -1;
        } else {
            numArabico += currentValorRomano < nextValorRomano ?
                          -currentValorRomano :
                          currentValorRomano;
        }
    }

    return numArabico < 3001 ? numArabico : -1;
}
