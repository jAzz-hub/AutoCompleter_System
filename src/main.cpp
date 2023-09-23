
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

    AVLT at = AVLT();


    int n1 = 5;
    string n2 = "vã";
    int n3 = 0;


    int k1 = 3;
    string k2 = "aério";
    int k3 = 0;

    int v1 = 7;
    string v2 = "`";
    int v3 = 0;
    

    int x1 = 2;
    string x2 = "lança perfume";
    int x3 = 0;
    
    int w1 = 4;
    string w2 = "guarda-roupas";
    int w3 = 0;

    int e1 = 6;
    string e2 = "marota";
    int e3 = 0;

    int d1 = 8;
    string d2 = "lamora";
    int d3 = 0;


    at.Insert_Node(&at.selfCopy,n1, n2, n3); //5
        // cout<<endl<<"\t"<<at.selfCopy->ocurrencies;
    
    at.Insert_Node(&at.selfCopy,v1, v2, v3); //7
        // cout<<endl<<"\t"<<at.selfCopy->right_branch->ocurrencies;
    
    at.Insert_Node(&at.selfCopy,e1, e2, e3); //6
        // cout<<endl<<"\t"<<at.selfCopy->left_branch->ocurrencies;

    // cout<<at.selfCopy->right_branch->ocurrencies;

    // cout<<at.selfCopy->left_branch->left_branch->->ocurrencies;

    at.Insert_Node(&at.selfCopy,k1, k2, k3); //3

    at.Insert_Node(&at.selfCopy,x1, x2, x3); //2
    
    at.Insert_Node(&at.selfCopy,w1, w2, w3); //4

    at.Insert_Node(&at.selfCopy,d1, d2, d3); //8

    at.inOrdem(at.selfCopy);
    cout<<endl;
    
    delete at.selfCopy;

    at.selfCopy = new AVLT();
    cout<<endl;

    at.Insert_Node(&at.selfCopy,x1, x2, x3); //2
    
    at.Insert_Node(&at.selfCopy,w1, w2, w3); //4

    at.Insert_Node(&at.selfCopy,d1, d2, d3); //8

    at.inOrdem(at.selfCopy);



}
