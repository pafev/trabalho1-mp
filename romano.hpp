#ifndef ROMANO_HPP_
#define ROMANO_HPP_

// Copyright 2024 Paulo Fernando Vilarim


// converte numero romano em numero arabico
// utiliza as funcoes auxiliares acima
int converteRomanoArabico(const char * numRomano);


// funcoes auxiliares:

// verifica se o algarismo recebido é um símbolo válido
bool existeAlgarismoRomano(const char algarismo);


// verifica se existe  mais de 3 algarismos consecutivos repetidos
// verifica a repetição do algarismo de index passado na função
bool maisDe3AlgarismosRepetidos(
    const int index,
    const int tamanhoNum,
    const char *num
);


// verifica se os valores passados podem ser representados em 1 símbolo
bool algarismosRedundantes(const int currentValor, const int nextValor);

#endif  // ROMANO_HPP_
