
#ifndef PALAVRAS_H
#define PALAVRAS_H
#include "AVL.hpp"

#define NUMOFFILES 6

vector<string> WordsReader();
struct Entradas_e_Amostras
{
    vector<string> entradas = WordsReader();
    // Palavra *Palavras = (Palavra*) malloc( numOfInputs() * sizeof(Palavra));
    string amostras[NUMOFFILES] = { "./dataset/filosofia.txt", "./dataset/filosofia2.txt", "./dataset/globalizacao.txt", "./dataset/politica.txt", "./dataset/ti.txt", "./dataset/ti2.txt"};
};


#endif