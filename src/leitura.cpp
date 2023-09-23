
#include "leitura.hpp"

void erase_the_output_file(string nameOfFile)
{
    ofstream arquivo(nameOfFile, ios::out);
    if(arquivo.is_open())
    {
        arquivo<<"Tipo de Árvore |\t Amostra de entrada |\t palavra de entrada |\t palavra \t|\tnúmero de repetições ";
        arquivo.close();
    }
}

void write_the_trees(AVLT avl, BTree b, string nameOfFile, string nameOfInputs, string nameOfSample)
{
    
    avl.inOrdemToOutput(avl.selfCopy,nameOfFile,nameOfInputs, nameOfSample);
    usleep(500000);
    shared_ptr<BT> tempPtr = make_shared<BT>(b.T);
    b.inOrdemToOutput(tempPtr,nameOfFile,nameOfInputs, nameOfSample);
}



void make_the_trees(Heap h, string nameOfInputs, string nameOfSample)
{

    AVLT avlT;
    BTree bT;

    for(size_t index = 0 ; index<h.data.size(); index ++)
    {
        
        bT.firstCheck_Insert_Node(NodeB(h.data.at(index).first, h.data.at(index).second));
        avlT.Insert_Node(&avlT.selfCopy, h.data.at(index).first, h.data.at(index).second, 0);
    }
    write_the_trees(avlT, bT, "./dataset/outputs.txt", nameOfInputs, nameOfSample);

    delete avlT.selfCopy;
}

void LerEntradasPorAmostra(Entradas_e_Amostras Dataframe)
{
    Heap h;
    int i=0;
    erase_the_output_file("./dataset/outputs.txt");
    for(int arquivo=0;arquivo<NUMOFFILES;arquivo++)
    {    
        i++;
        
        for(size_t palavra = 0; palavra<Dataframe.entradas.size();palavra++)
        {        
            h = everythingForEachInput(Dataframe.amostras[arquivo], Dataframe.entradas[palavra]);
            make_the_trees(h, Dataframe.entradas[palavra], Dataframe.amostras[arquivo]);
        }
//         necessidade
// sobre

    }
}