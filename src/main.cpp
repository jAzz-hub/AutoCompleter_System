
#include "leitura.hpp"

// for i in palavras:
//     for x in arquivos:
//         leitura_sem_a_palavra(x, i); //1 
//         faz_heap_ignorando_a_palavra();// 2
//         faz_as_árvores_com_o_heap(); // 3
//         usa_a_hash_pronta_para_gerar_a_saída(); //4


// 1 - Para cada palavra no arquivo de entradas:
    // 1.1 - Você vai ler o arquivo 1 de texto e gerar um relatório de aparições da palavra para ele .
    // 1.2 - Você vai ler o arquivo 2 de texto e gerar um relatório de aparições da palavra para ele.
    
    // A cada iteração uma saída do seguinte modo deve ser montada:
    //      Palavra     Texto(n)    Texto(n+1)      Número de Ocorrencias em (n)    Número de Ocorrências em (n+1)
    //      Filosofia       0           1                       0                               42
    //      Loin            1           0                       13                              0

    //Árvore AVL Filosofia In: ∄
    //Árvore AVL Filosofia In+1: ...
    //Árvore AVL Loin In: ...
    //Árvore AVL Loin In+1: ∄ 
    
    //Árvore Huffman Filosofia In: ∄
    //Árvore Huffman Filosofia In+1: ...
    //Árvore Huffman Loin In: ...
    //Árvore Huffman Loin In+1: ∄

    //Árvore Binária Filosofia In: ∄
    //Árvore Binária Filosofia In+1: ...
    //Árvore Binária Loin In: ...
    //Árvore Binária Loin In+1: ∄


// 1 - Preencher o vetor Palavras com as Palavras do arquivo input.data.
// 2 - Percorrer Texto 1 e Texto 2 para construção do Heap.
// 3 - Atualizar atributos de palavras do vetor Palavras.


int main()
{
    Entradas_e_Amostras Dataframe;

    LerEntradasPorAmostra(Dataframe);

    
    // delete at.selfCopy;

}
