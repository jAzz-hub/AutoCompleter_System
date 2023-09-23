#include "Palavras.hpp"
/// @brief Função que lê entrada considerando que cada linha contenha uma das palavras de entrada necessárias
/// @return 
vector<string> WordsReader()
{
    vector<string> lista_de_entradas;
    int counter = 0;
    char ch[100];
    char* path = (char*)"./dataset/input.txt";
    FILE *pointerToFile = fopen(path, "r");
     

    if(pointerToFile!=NULL) 
    {
        string word;
        while (fgets(ch,100,pointerToFile))
        {
            word = ch;
            lista_de_entradas.push_back(word);
            counter+=1;            
        }
    }
    fclose(pointerToFile);
    return lista_de_entradas;
}
