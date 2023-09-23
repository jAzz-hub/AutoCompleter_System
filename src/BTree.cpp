

#include "BTree.hpp"

NodeB::NodeB()
{
    this->ocurrencies  = -1;
    this->key = "-1";    
}

NodeB::NodeB(int ocurrencies, string key)
{
    this->ocurrencies = ocurrencies;
    this->key = key;
}

void NodeB::setKey(int ocurrencies)
{
    this->ocurrencies = ocurrencies;
}
void NodeB::setValue(string key)
{
    this->key = key;
}

BT::BT()
{
    this->left_branch = NULL;
    this->right_branch = NULL;
    this->sub_root = NodeB();
}

BT::BT(NodeB root)
{
    this->left_branch = NULL;
    this->right_branch = NULL;
    this->sub_root = root;
}

BTree::BTree()
{
    this->T = BT();
}

BTree::BTree(NodeB N)
{
    this->T = BT(N);
}

bool BTree::empty()
{
    return (this->T.sub_root.ocurrencies == -1);
}


void BTree::Insert_Node(shared_ptr<BT> &T, NodeB N)
{
    
    if (T == NULL)
    {   
        T = make_shared<BT>(N);
    } 
    else 
    {

        if(N.ocurrencies < T->sub_root.ocurrencies)
        {
            Insert_Node(T->left_branch, N);
        }
        if(N.ocurrencies > T->sub_root.ocurrencies)
        {
            Insert_Node(T->right_branch, N);
        }
    }
}

void BTree::firstCheck_Insert_Node(NodeB N)
{
    
    if (this->empty()) 
    {
        this->T = BT(N);

    } 
    else 
    {
        
        if(N.ocurrencies < this->T.sub_root.ocurrencies)
        {

            Insert_Node(this->T.left_branch , N);
        }
        if(N.ocurrencies > this->T.sub_root.ocurrencies)
        {

            Insert_Node(this->T.right_branch , N);
        }
    }
}


/// @brief Função que mostra elementos de uma árvore de forma ordenada devido ao desempilhamento ao fim de uma recursividade
/// @param T Ponteiro para a árvore
void BTree::In_Ordem(shared_ptr<BT> T)
{
    if(!(T==NULL))
    {
        In_Ordem(T.get()->left_branch);
        printf("%d\t", T.get()->sub_root.ocurrencies);
        In_Ordem(T.get()->right_branch);
    }
}


void BTree::Right_DFS(shared_ptr<BT> &T, shared_ptr<BT> auxT)
{ 

	if (T.get()->right_branch != NULL){ 
		Right_DFS(T.get()->right_branch, auxT);
		return;
  }
  	
  auxT = T;
  T = T.get()->left_branch;
} 


