#include "Heap.hpp"


/// @brief Constructor of Heap Class
Heap::Heap()
{
    this->size = K;
    this->heavy_trades = 0;
}


/// @brief Constructor of Heap Class with parameters:
/// @param size size of Heap Data Structure
/// @param data already filled Heap
Heap::Heap(int size, vector<pair<int, string>> data)
{
    this->size = size;
    this->data = data;
    this->heavy_trades = 0;
}

Heap::~Heap()
{
}

/// @brief Function that sort the Heap Data Structure using Insertion Sort algorithm
void Heap::InsertionSort()
{
    for(unsigned short int i = 1 ; i<data.size() ; i++)
    {
        int marker = i;

        while( marker > 0 && (this->data.at(marker - 1).first > this->data.at(marker).first))
        
        {
            swap(marker, marker - 1);
            marker -= 1;
        }
    }
}


/// @brief Show the Heap Data Structured sorted by InsertionSort() function
void Heap::show_sorted()
{
    cout<<endl<<endl<<"°-º~o~OO~OOO_Heap Ordenado_OOO~OO~o~º-°"<<endl<<endl<<endl;

    this->InsertionSort();    

    for(unsigned long int i = 0;i<data.size();i++)
    {
        if(i<9)
        cout<<i+1<<"º  nó - "<<this->data.at(i).first<<"\t"<<this->data.at(i).second<<endl;
        else
        cout<<i+1<<setw(2)<<"º nó - "<<this->data.at(i).first<<"\t"<<this->data.at(i).second<<endl;
    }
    
    // cout<<endl<<endl;

}


/// @brief Show the Heap Data Structure elements in way that is disposed inside that structure 
void Heap::show()
{
    cout<<endl<<endl<<"°-O~o~o~O_Heap Original_O~o~°~o-o"<<endl;
    // cout<<endl<<endl;
    for(unsigned long int i = 0;i<data.size();i++)
    {
        if(i<9)
        cout<<i+1<<"º  nó - "<<this->data.at(i).first<<"\t"<<this->data.at(i).second<<endl;
        else
        cout<<i+1<<setw(2)<<"º nó - "<<this->data.at(i).first<<"\t"<<this->data.at(i).second<<endl;
    }
    // cout<<endl<<endl;
}


/// @brief Trade the place of 2 elements which were inside Heap Data Structure
/// @param first Index of first element
/// @param second Index of second element
void Heap::swap(int first, int second)
{

    pair<int, string> aux = this->data.at(first);
    this->data.at(first) = this->data.at(second);
    this->data.at(second) = aux;

}


/// @brief execute swap() at Parent Node and one of their Son's if the Parent value is bigger than one of their son's value
/// @param actually_parent Index of an element that represent a parent node of Heap Data Structure on actually iteration
void Heap::organize(int actually_parent)
{
   
    if( (this->data.at(actually_parent).first > this->data.at(actually_parent*2).first ) )
    {
        swap(actually_parent, (actually_parent * 2));
        this->heavy_trades++;
    }
    else if( this->data.at(actually_parent).first  > this->data.at(actually_parent*2+1).first ) /*if(this->data[actually_parent] > this->data[(actually_parent*2) + 1])*/
    {   
        swap(actually_parent, (actually_parent * 2) + 1);
        this->heavy_trades++;
    }
    else return;
    
}


/// @brief runs throuth the Heap by the half of it untill the begin executing organize() function with actually index as parameter
/// @cite step considered the actually index while the structure is covered
void Heap::pile_the_Heap()
{
    int step = this->size/2 - 1;

    while (step>=0)
    {
        organize(step);
        step--;
    }
}


/// @brief fulfill the Heap Data Structure with the number of ocurrences of each word recorded in hash
/// @param words vector of pair with words and their ocurrences
/// @param hash unordered_map with words as key and number of ocurrences in input file as value
void Heap::fill_the_Heap(vector<pair<int, string>> words, unordered_map<string, int> hash)
{
    int counter = 0;
    for(int i = 0;i<K;i++)
    {
        this->data.push_back({hash[words.at(i).second], words.at(i).second});
        counter++;
    }
}


/// @brief calls pile_the_Heap() once, then cover the Heap Data Structure executing pile_the_Heap() before checking if theres a bigger value than the weaker inside the Heap
/// @cite if there's a bigger value it would be recorded in Heap
/// @param words vector of pair with words and their ocurrences
/// @param hash unordered_map with words as key and number of ocurrences in input file as value
void Heap::bigger_value_researcher(vector<pair<int, string>> words, unordered_map<string, int> &hash)
{

    vector<string> a;

    // cout<<endl;
    this->pile_the_Heap();

    for(long unsigned int i = K;i<hash.size();i++)   
    {

        if(this->data.at(0).first<hash[words.at(i).second])
        {
            this->data.at(0) = {hash[words.at(i).second], words.at(i).second};
        }
        this->pile_the_Heap();
    }
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
}



// ============================= ============= ============= ============= ===================================

// ============================= Funções Que Não Pertencem À Classe Heap =====================================

// ============================= ============= ============= ============= ===================================



/// @brief Convert string characters into lowe case
/// @param target string that would be converted in lower case
/// @return target in lower case
string lower_case(string target)
{
    long unsigned int c = 0;
    string answer = "";
    while(c < target.length())
    {
        answer+=(tolower(target[c]));
        c++;
    }
    return answer;
}


/// @brief Read the Stopwords file fill an unordered_map with content
/// @return unordered_map with Stopwords which should be considered
unordered_map<string, int> readStopWordsFile()
{
    ifstream pointerToFile("./dataset/Stopwords.txt");
    
    unordered_map<string, int> stop_words;
    
    string line;

    while(getline(pointerToFile, line))
    {
        string word = "";

        stop_words.insert({lower_case(line), 1});
    }

    return stop_words;
}


/// @brief Verify if a character belog to the group which should stop build of a word while reading is happen
/// @param something is a character which is been readed by file pointer 
/// @return true if it belongs in group and false if it's not
bool isStopChar(char something)
{

    if (something == '0' || something == '+' || something == '='
     || something == '$' || something == '[' ||  something == ';'
      ||something == ')' ||something == '(' || something == ':'
       || something == '9' || something == '8' || something == '7'
        || something == '6' || something == '5' || something == '4'
         || something == '3' || something == '2' || something == '1'
          ||something == '"' ||something == '\n' || something == '/'
           || something == '\0' ||something == ' ' || something == ','
            ||something == '.' || something == '?' ||something == '!')
    {
        return true;
    }
    else return false;
}


/// @brief Verify if the word is a Stopword 
/// @param word string that contains a word formed in reading
/// @param stop_words unordered_map witch all Stopwords examples
/// @return true if it's a Stopword and false if it's not
bool isStopWord(string word,unordered_map<string, int> stop_words, string input_word)
{
    if((stop_words[lower_case(word)] == 1) || lower_case(word) == lower_case(input_word)) return true;
    else return false;
}


/// @brief Try update or record word key and their value on hash
/// @param word string with word that belongs to input files
/// @param Hash unordered_map that represent the Hash Data Structure on the program
/// @param words vector of pair with words and their ocurrences
void tryHashIt(string word, unordered_map<string, int> &Hash, vector<pair<int, string>> &words)
{
    string c = word;
    if(Hash.find(*(&word))==Hash.end())
    {
        if(word != "\0")
        {
            Hash.insert({word, 1});
            words.push_back({1, word});
        }
    }
    else
    {
        Hash[word]+=1;
    }
}


/// @brief Read input file at specific directory of local machine and return Hash Data Structure
/// @param words vector of pair with words and their ocurrences
/// @param path Way since actually directory until the file input directory on local machine
/// @return Hash Data Structure with words as key and their ocurrences as values
unordered_map<string, int> fileReader(vector<pair<int, string>> &words, string path, string input_word)
{
    ifstream pointerToFile(path);

    unordered_map<string, int> Dictionary;

    unordered_map<string, int> stop_words;


    stop_words = readStopWordsFile();

    if(!pointerToFile)
    {
        cout<<"\n\n\n\t\t-----------------------------------------------ATENÇÃO-------------------------------------------------";
        cout<<"\n\n\t\t\tNão foi possível encontrar ou abrir o arquivo de entrada listado :P!";
        cout<<"\n\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t |/ Sugestão 1 : Verifique se a variável `pathts` existe na linha 7 do arquivo main.cpp"; 
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";       
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t |/Sujestão 2: Verifique se o nome dos elementos dessa variável condiz com o nome dos\n\t\t\t || dos arquivos no diretório .../TopK_Heap/dataset$";       
        cout<<"\n\t\t\t ||";       
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t |/Sujestão 3: Entre em contato comigo no Telegram presente em TopK_Heap/README.md$";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\t\t\t ||";
        cout<<"\n\n\t\t-------------------------------------------------------------------------------------------------------\n\n\n";
        exit(0);
    }

    string line;

    while(getline(pointerToFile, line))
    {
        unsigned short int lenOfString = line.length();
        string word = "";
        

        for(int i = 0; i<lenOfString;i++)
        {         
            if(i == 0)
            {
                if( (!isStopChar(line[i])) && (line[i]!='-'))
                {
                    word+=line[i];
                }
            }

            else
            {
                if(!isStopChar(line[i]) && ((line[i]!='-') && (line[i-1]!='-')))
                {
                    word+=line[i];
                }
            
                else
                {    
                    if(!(isStopWord(word, stop_words, input_word)))
                    {
                        tryHashIt(lower_case(word), Dictionary, words);
                    }
                    word = "";
                }
            }
        }
    }

    return Dictionary;
}


/// @brief Use a path passed as string as parameter to read it and make a Heap Data Structure with most cited elements
/// @param path_to_input Is an string that belogs the path from actually directory to directory of aimed files
Heap everythingForEachInput(string path_to_files, string input_word)
{
    unordered_map<string, int> hashwords;
    vector<pair<int, string>> words;

    hashwords = fileReader(words, path_to_files, input_word);
    

    Heap heap = Heap();


    heap.fill_the_Heap(words, hashwords);

    heap.bigger_value_researcher(words, hashwords);


    heap.pile_the_Heap();

    return (heap);
}
