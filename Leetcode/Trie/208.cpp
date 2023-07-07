/* https://leetcode.com/problems/implement-trie-prefix-tree/description/ */
 class Trie {
    struct Node{
        Node* linker[26];
        bool flag ;
        bool containesKey (char c){
            return linker[c-'a']!=NULL;
        }
        void putKey(char c,Node* node){
            linker[c-'a'] = node;
        }
        Node* getKey(char c){
            return linker[c-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };
public:

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containesKey(word[i])){
                node->putKey(word[i],new Node());
            }
            node =node->getKey(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containesKey(word[i])){
                return false;
            }
            node=node->getKey(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containesKey(prefix[i])){
                return false;
            }
            node=node->getKey(prefix[i]);
        }
        return true;
    }
};