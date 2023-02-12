#include<iostream>
#include<string>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode*root;
    Trie(){
        root = new TrieNode('\0');
    }
    // Creating Insert Function
    void insertWord(string word){
        insertUtil(root,word);
    }
    void insertUtil(TrieNode*root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        // find index
        int index = word[0]-'A'; // assumtion all word in Captial letter
        TrieNode*child; 
        if(root->children[index]!=NULL){ // present
            child = root->children[index]; // aage badha do
        }
        else // absent
        {
            child = new TrieNode(word[0]); // create node
            root->children[index] = child; // aage badha do
        }
        // Recursion Call
        insertUtil(child,word.substr(1));
    }

    // Create Serach function
    bool searchWord(string word){
        return searchUntil(root,word);
    }
    bool searchUntil(TrieNode*root,string word){
        // Base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'A';
        TrieNode*child;
        if(root->children[index]!=NULL){ // present
            child = root->children[index];
        }
        else{
            return false;
        }
        // Recursion Call
        return searchUntil(child,word.substr(1));
    }
};

int main(){
    Trie*t = new Trie();
    t->insertWord("GAUTAM");
    cout<<"Present or Not : "<<t->searchWord("GAUTAM")<<endl;
    return 0;

}