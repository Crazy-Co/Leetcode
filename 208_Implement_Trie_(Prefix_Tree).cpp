class TrieNode{
public:
    char character;
    TrieNode* children[26];
    bool isTerminal; // to chech whether a word ends at current node

    // constructor
    TrieNode(char character){
        this->character = character;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Trie {
private:

    // utilities using recursion
    // traversal using recursion is slow since it creates call stacks for every fuction call

    // void insertUtil(TrieNode* root, string word){
    //     // base case
    //     if(word.length() == 0){
    //         root->isTerminal = true;
    //         return;
    //     }

    //     int index = word[0] - 'a';
    //     if(root->children[index] == NULL){
    //         root->children[index] = new TrieNode(word[0]);
    //     }

    //     insertUtil(root->children[index], word.substr(1));
    //     return;
    // }

    // bool searchUtil(TrieNode* root, string word){
    //     // base case
    //     if(word.length() == 0){
    //         if(root->isTerminal == true) return true;
    //         else return false;
    //     }

    //     int index = word[0] - 'a';
    //     if(root->children[index] == NULL){
    //         return false;
    //     }

    //     return searchUtil(root->children[index], word.substr(1));
    // }

    // bool wordPrefixUtil(TrieNode* root, string prefix){
    //     // base case
    //     if(prefix.length() == 0){
    //         return true;
    //     }

    //     int index = prefix[0] - 'a';
    //     if(root->children[index] == NULL){
    //         return false;
    //     }

    //     return wordPrefixUtil(root->children[index], prefix.substr(1));
    // }

    // utilities using loops
    // traversal using loops is fast since it uses less memory hence cost effective

    void insertUtil(TrieNode* root, string word){
        TrieNode* t = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';

            if(t->children[index] == NULL){
                t->children[index] = new TrieNode(word[i]);
            }

            t = t->children[index];
        }
        t->isTerminal = true;
    }

    bool searchUtil(TrieNode* root, string word){
        TrieNode* t = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';

            if(t->children[index] == NULL){
                return false;
            }
            
            t = t->children[index];
        }
        if(t->isTerminal == true) return true;
        else return false;
    }

    bool wordPrefixUtil(TrieNode* root, string prefix){
        TrieNode* t = root;
        for(int i=0; i<prefix.length(); i++){
            int index = prefix[i] - 'a';

            if(t->children[index] == NULL){
                return false;
            }
            
            t = t->children[index];
        }
        return true;
    }
    
public:
    TrieNode* root;

    // constructor
    Trie() {
        root = new TrieNode('\0');
    }
    
    // insert word method
    void insert(string word) {
        insertUtil(root, word);
    }
    
    // search word method
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    // word starts with prefix method
    bool startsWith(string prefix) {
        return wordPrefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */