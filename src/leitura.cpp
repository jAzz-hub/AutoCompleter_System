
#include "leitura.hpp"

void write_the_trees(AVLT avl, BTree b)
{

}

void make_the_trees(Heap h)
{

    AVLT avlT;
    BTree bT;

    for(size_t index = 0 ; index<h.size; index ++)
    {
        
        bT.firstCheck_Insert_Node(NodeB(h.data.at(index).first, h.data.at(index).second));
        avlT.Insert_Node(&avlT.selfCopy, h.data.at(index).first, h.data.at(index).second, 0);
    }
    write_the_trees(avlT, bT);

    delete avlT.selfCopy;
}

void LerEntradasPorAmostra(Entradas_e_Amostras Dataframe)
{
    Heap h;
    int i=0;
    for(int arquivo=0;arquivo<NUMOFFILES;arquivo++)
    {    
        i++;

        
        for(size_t palavra = 0; palavra<Dataframe.entradas.size();palavra++)
        {        
            h = everythingForEachInput(Dataframe.amostras[arquivo], Dataframe.entradas[palavra]);
            make_the_trees(h);
        }
//         necessidade
// sobre

    }
    cout<<i;
}