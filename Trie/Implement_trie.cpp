/* Trie is class/ struct 
 Trie{
     int a[26];  // 0-a,1-b,2-c....
     bool flag   // when word complete we mark last node flag as true
}

*/

#include<bits//stdc++.h>
using namespace std;

struct Node {
    Node* linker[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }


    
}
class Trie{
    private:Node* root;
    
    public:
        Trie(){
            root = new Node();
        }
        /* Insert word into the trie */
        // tc -> O(len)
        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                // Moves to the reference trie
                node->get(word[i]);
            }

            node->setEnd();
        }
        /* Return if the word is in the trie */
        // Tc -  O(len)
        bool search(string word){
            Node* ndoe = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }

        /** Returns if there is any word in the trie that starts with the given string **/
        // Tc - O(n)
        bool startsWith(string prefix){
            Node* node = root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node= node->get(word[i]);
            }
            return true;
        }
}