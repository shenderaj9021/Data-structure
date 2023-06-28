/* Differec between this ans previous that , in previous implementation we are 
just checking whether the word or word starting with given prefix is present or not.
In this we want to count number of words equal to given word or number of word starting 
with given prefix exist.

Also we will implement erase word

*/

#include<bits//stdc++.h>
using namespace std;


// on the flow for every word's trie increase the countprefix and whenever we ending increase the coutnend;

struct Node {
    Node* links[26];
    int cntEndWith =0;  // Endwith
    int cntPrefix=0;   // Countprefix 

    bool containsKey(char c){
        return (links[ch-'a']!=NULL)
    }
    Node* get(char c){
        return links[ch-'a'];
    }
    void put(char c, Node* node){
        links[ch-'a'] = node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducPrefix(){
        cntPrefix--;
    }
    void getEnd(){
        return cntEndWith;
    }
    void getPrefix(){
        return cntPrefix;
    }
}

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
              
            }
            node= node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(stirng word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node.containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    int countWordsStartingWith(stirng word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node.containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }
    void Erase(string &word){
         Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node.containsKey(word[i])){
                return ;
            }
            node = node->get(word[i]);
            node->reducePrefix();
        }
        return node->deleteEnd();
    }
}