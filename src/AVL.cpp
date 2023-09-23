



#include "AVL.hpp"


// NodeAVL::NodeAVL()
// {
//     this->ocurrencies  = -1;
//     this->key = -1;  
//     this->weight = 0;
// }

// NodeAVL::NodeAVL(int ocurrencies, int key, int weight)
// {
//     this->ocurrencies = ocurrencies;
//     this->key = key;
//     this->weight = weight;
// }

// void NodeAVL::setKey(int ocurrencies)
// {
//     this->ocurrencies = ocurrencies;
// }
// void NodeAVL::setValue(int key)
// {
//     this->key = key;
// }
// void NodeAVL::setWeight(int weight)
// {
//     this->weight = weight;
// }

AVLT::AVLT()
{
    this->left_branch = nullptr;
    this->right_branch = nullptr;
    this->ocurrencies = -1;
    this->key = -1;
    this->weight = 0;
}

AVLT::AVLT(int ocurrencies, string key, int weight)
{
    this->ocurrencies = ocurrencies;
    this->key = key;
    this->weight = weight;
    this->left_branch = nullptr;
    this->right_branch = nullptr;
}

// AVLT::~AVLT(AVLT *T)
// {
//     if(T!=nullptr)
//     {
//         ~AVLT(T->right_branch);
//         ~AVLT(T->left_branch);
//     }
//     delete T;
// }


AVLT::~AVLT()
{
    delete left_branch;
    delete right_branch;
}


// void AVLTree::Clear_AVL(AVLT **t){
//     if(t != nullptr){
//         Clear_AVL(t->left);
//         Clear_AVL(t->right);
//         delete t;
//     }
// }




bool AVLT::empty()
{
    // return (this->T.sub_root.key == -1);
    return ( (this->ocurrencies == -1));
}


int AVLT::weightScan(AVLT **T)
{
    
    if(*T == nullptr){
        
        return -1;
    }
    else
    
        return ( (*T)->weight );


}

int AVLT::maxWeight(int first, int second)
{
    if (first>second) return first; else return second;
}

int AVLT::weightsReazon(AVLT **T) 
{
    return (weightScan( &(*T)->right_branch) - weightScan(&(*T)->left_branch));
}

void AVLT::RRight(AVLT **T)
{
    AVLT *auxT;
    auxT = (*T)->left_branch;
    
    (*T)->left_branch = auxT->right_branch;
    auxT->right_branch = (*T);

    (*T)->weight = maxWeight(weightScan(&(*T)->left_branch), weightScan(&(*T)->right_branch)) + 1;
    auxT->weight = maxWeight(weightScan(&auxT->left_branch), (*T)->weight) + 1;
    
    (*T) = auxT;
}

void AVLT::RLeft(AVLT **T)
{
    AVLT *auxT;
    auxT =  (*T)->right_branch; 

    (*T)->right_branch = auxT->left_branch;
    auxT->left_branch = (*T);

    (*T)->weight = maxWeight(weightScan( &(*T)->left_branch), weightScan(&(*T)->right_branch)) + 1;
    auxT->weight= maxWeight(weightScan(&auxT->left_branch), (*T)->weight ) + 1;

    (*T) = auxT;
}

void AVLT::RightThenLeft(AVLT **T)
{
    RLeft(&(*T)->left_branch);
    RRight(T);
}

void AVLT::LeftThenRight(AVLT **T)
{
    RRight(&(*T)->right_branch);
    RLeft(T);
}

void AVLT::Insert_Node( AVLT **T, int ocurrencies,string key,int weight)
{

    if ( ((*T) == NULL) || ((*T)->ocurrencies == -1) ) 
    {   
        (*T) = new AVLT(ocurrencies, key, weight);
    }

    else 
    {


        if(ocurrencies < (*T)->ocurrencies)
        {
            
            Insert_Node( &(*T)->left_branch, ocurrencies, key, weight);
            if(weightScan( &(*T)->left_branch) - weightScan( &(*T)->right_branch)==2)
            {
                ocurrencies < (*T)->left_branch->ocurrencies ? RRight(T) : RightThenLeft(T); 
            }
        }

        if( ocurrencies > (*T)->ocurrencies)
        {
            
            Insert_Node( &(*T)->right_branch, ocurrencies, key, weight);
            if(weightScan( &(*T)->right_branch) - weightScan(&(*T)->left_branch)==2)
            {
                ocurrencies > (*T)->right_branch->ocurrencies ? RLeft(T) : LeftThenRight(T);
            }
        }
        
    }

    (*T)->weight = maxWeight(weightScan( &(*T)->left_branch), weightScan(&(*T)->right_branch)) + 1;
}

/// @brief Função que mostra elementos de uma árvore de forma ordenada devido ao desempilhamento ao fim de uma recursividade
/// @param T Ponteiro para a árvore
void AVLT::inOrdem(AVLT *T)
{
    if(!(T==NULL))
    {
        inOrdem(T->left_branch);
        printf("%d\t", T->ocurrencies);
        inOrdem(T->right_branch);
    }
}

void AVLT::inOrdemWithoutPrint(AVLT *T)
{
    if(!(T==NULL))
    {
        inOrdemWithoutPrint(T->left_branch);
        inOrdemWithoutPrint(T->right_branch);
    }
}


void AVLT::inOrdemToOutput(AVLT *T, string nameOfFile, string nameOfInput, string nameOfSample)
{
    ofstream arquivo(nameOfFile, ios::app);

    arquivo << "\n\t\tAVL   \t\t\t"<<nameOfSample<<"\t\t\t"<<nameOfInput<<"\t\t\t";
    if(!(T==NULL))
    {
        inOrdemWithoutPrint(T->left_branch);
        arquivo << T->key<<"\t\t"<<"\t\t\t"<<T->ocurrencies;
        inOrdemWithoutPrint(T->right_branch);
    }
}

void AVLT::preOrdem(AVLT *T)
{
    if(!(T==NULL))
    {
        printf("%d\t", T->ocurrencies);
        inOrdem(T->left_branch);
        inOrdem(T->right_branch);
    }
}

void AVLT::posOrdem(AVLT *T)
{
    if(!(T==NULL))
    {
        inOrdem(T->left_branch);
        inOrdem(T->right_branch);
        printf("%d\t", T->ocurrencies);
    }
}

