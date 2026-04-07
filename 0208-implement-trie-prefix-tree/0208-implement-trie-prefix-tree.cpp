class Tree {
    public:
        Tree* links[26];
        bool isEnd = false;

        Tree() {
            for(int i = 0; i < 26; i++) {
                links[i] = NULL;
            }
        }
};

class Trie {
public:
    Tree* root;
    Trie() {
        root = new Tree();
    }
    void insert(string word) {
        Tree* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(node->links[idx] == NULL) {
                node->links[idx] = new Tree();
            }
            node = node->links[idx];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        Tree* node = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(!node->links[idx]) {
                return false;
            }
            node = node->links[idx];
        }
       
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Tree* node = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(!node->links[idx]) {
                return false;
            }
            node = node->links[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */