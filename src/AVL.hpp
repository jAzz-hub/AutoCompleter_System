#ifndef AVL_H
#define AVL_H

#include"Heap.hpp"
#include"BTree.hpp"

using namespace std;

class AVLT
{
    public:
       //Atributos:
            AVLT *selfCopy = nullptr;
            AVLT *left_branch, *right_branch;
            int ocurrencies;
            string key;
            int weight;

        //Construtores:
        AVLT();
        AVLT(int ocurrencies, string key, int height);
        ~AVLT();
        // ~AVLT();

        bool empty();
        int weightScan(AVLT **T);
        
        int maxWeight(int first, int second);
        int weightsReazon(AVLT **T);

        void RRight(AVLT **T);
        void RLeft(AVLT **T);

        void RightThenLeft(AVLT **T);
        void LeftThenRight(AVLT **T);
        
        void Insert_Node( AVLT **T, int ocurrencies,string key,int weight);

        void inOrdem(AVLT *T);
        void inOrdemWithoutPrint(AVLT* T);
        
        void inOrdemToOutput(AVLT *T, string nameOfFile, string nameOfInput, string nameOfSample);
            
        void preOrdem(AVLT *T);
            
        void posOrdem(AVLT *T);
            
};
#endif