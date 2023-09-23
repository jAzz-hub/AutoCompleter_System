
#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <filesystem>
#include <stdio.h>
#include <bits/stdc++.h>


#define K 20

using namespace std;
class Heap
{
    public:
    //Atributes:
        string score_ranking[K];
        int size = K;
        vector<pair<int, string>> data;
        int heavy_trades;

        //Constructors:
        Heap();
        Heap(int size, vector<pair<int, string>> data);
        ~Heap();

        // Methods:
        void show();
        void show_sorted();
        void swap(int first, int second);
        void organize(int actually_parent);
        void fill_the_Heap(vector<pair<int, string>> words, unordered_map<string, int> hash);
        void pile_the_Heap();
        void bigger_value_researcher(vector<pair<int, string>> words, unordered_map<string, int> &hash);
        void InsertionSort();

};

Heap everythingForEachInput(string path_to_input, string word_input);

#endif