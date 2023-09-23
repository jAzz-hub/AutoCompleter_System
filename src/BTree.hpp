#ifndef BTREE_H
#define BTREE_H

#include "AVL.hpp"

using namespace std;

class NodeB
{
    public:
        int ocurrencies;
        string key;

        NodeB();
        NodeB(int ocurrencies, string key);
        void setKey(int ocurrencies);
        void setValue(string key);
        // ~NodeB();

};

class BT
{
    public:
        NodeB sub_root;
        shared_ptr<BT> left_branch , right_branch;

        BT();
        BT(NodeB root);
};

class BTree
{
    public:
        //Atributos
        BT T;
        
        //Construtores:
        BTree();
        BTree(NodeB N);

        //Métodos:
        bool empty();


        void firstCheck_Insert_Node(NodeB N);
        void Insert_Node(shared_ptr<BT> &T, NodeB N);


        void In_Ordem(shared_ptr<BT> T);

        void Right_DFS(shared_ptr<BT> &T, shared_ptr<BT> auxT);
        void Remove_Node(shared_ptr<BT> &T, string key);

};


#endif