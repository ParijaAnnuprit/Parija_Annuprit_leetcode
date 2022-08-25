struct Node{
    Node* arr[26];
    bool flag= false;
    bool containskey(char ch){
        return (arr[ch-'a']!=NULL);
    }
    void put(char ch, Node* node){
        arr[ch-'a'] = node;
    }
    Node* next(char ch){
        return arr[ch-'a'];
    }
    void setend(){
        flag= true;
    }
    bool retend(){
        return flag;
    }
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* dummy = root;
        for(int i=0;i<word.length();i++){
            if(!dummy->containskey(word[i])){
                dummy->put(word[i],new Node());
            }
            dummy = dummy->next(word[i]);
        }
        dummy->setend();
    }
    
    bool search(string word) {
        Node* dummy = root;
        for(int i=0;i<word.length();i++){
            if(!dummy->containskey(word[i])) return false;
            dummy = dummy->next(word[i]);
        }
        return dummy->retend();
    }
    
    bool startsWith(string prefix) {
        Node* dummy = root;
        for(int i=0;i<prefix.length();i++){
            if(!dummy->containskey(prefix[i])) return false;
            dummy = dummy->next(prefix[i]);
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


// struct Node {
// 	Node *links[26];
// 	bool flag = false;
// 	//checks if the reference trie is present or not
// 	bool containKey(char ch) {
// 		return (links[ch - 'a'] != NULL);
// 	}
// 	//creating reference trie
// 	void put(char ch, Node *node) {
// 		links[ch - 'a'] = node;
// 	}
// 	//to get the next node for traversal
// 	Node *get(char ch) {
// 		return links[ch - 'a'];
// 	}
// 	//setting flag to true at the end of the word
// 	void setEnd() {
// 		flag = true;
// 	}
// 	//checking if the word is completed or not
// 	bool isEnd() {
// 		return flag;
// 	}
// };
// class Trie {
// private:
// 	Node* root;
// public:
// 	Trie() {
// 		//creating new obejct
// 		root = new Node();
// 	}

// 	void insert(string word) {
// 		//initializing dummy node pointing to root initially
// 		Node *node = root;
// 		for (int i = 0; i < word.size(); i++) {
// 			if (!node->containKey(word[i])) {
// 				node->put(word[i], new Node());
// 			}
// 			//moves to reference trie
// 			node = node->get(word[i]);
// 		}
// 		node->setEnd();
// 	}

// 	bool search(string word) {
// 		Node *node = root;
// 		for (int i = 0; i < word.size(); i++) {
// 			if (!node->containKey(word[i])) {
// 				return false;
// 			}
// 			node = node->get(word[i]);
// 		}
// 		return node->isEnd();
// 	}

// 	bool startsWith(string prefix) {
// 		Node* node = root;
// 		for (int i = 0; i < prefix.size(); i++) {
// 			if (!node->containKey(prefix[i])) {
// 				return false;
// 			}
// 			node = node->get(prefix[i]);
// 		}
// 		return true;
// 	}
// };
