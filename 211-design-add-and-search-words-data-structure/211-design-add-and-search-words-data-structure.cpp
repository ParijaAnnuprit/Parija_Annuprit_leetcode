// struct Node{
//     Node* arr[26];
//     bool isend = false;
//     bool containskey(char ch){
//         return (arr[ch-'a']!=NULL);
//     }
//     void put(char ch, Node* node){
//         arr[ch-'a'] = node;
//     }
//     Node* next(char ch){
//         return arr[ch-'a'];
//     }
//     void setend(){
//         isend = true;
//     }
//     bool checkend(){
//         return isend;
//     }
// };



// class WordDictionary {
// public:
//     Node* root;
//     WordDictionary() {
//         root = new Node();
//     }
    
//     void addWord(string word) {
//         Node* dummy = root;
//         for(int i=0;i<word.length();i++){
//             if(!dummy->containskey(word[i])){
//                 dummy->put(word[i],new Node());
//             } 
//             dummy = dummy->next(word[i]);
//         }
//         dummy->setend();
//     }
    
//     bool search(string word) {
//         Node* dummy = root;
//         return traverse(word,dummy,0);
//     }
//     bool traverse(string s, Node* dummy, int ind){
//         if(ind == s.length()) return dummy->checkend();
//         if(s[ind]=='.'){
//             for(int i=0;i<26;i++){
//                 if(dummy->arr[i]!=NULL && traverse(s,dummy->arr[i],ind+1)) return true;
//             }
//         }
//         else{
//             if(dummy->containskey(s[ind]) && traverse(s,dummy->next(s[ind]),ind+1)) return true;
//         }
//         return false;
//     }
// };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class Node {
 public:
    std::array<Node*, 26> links;
    bool end;
    void insert(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void setEnd() {
        end = true;
    }
    bool isEnd() {
        return end;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if(!node->contains(ch)) {
                node->insert(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool dfs(string& word, Node* node, int index, int count) {
        if (count > 3)
            return false;
        if (index == word.length())
            return node->isEnd();
        int ret {};
        if (!isalpha(word[index])) {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr &&
                    dfs(word, node->links[i], index + 1, count + 1)) {
                    return true;
                }
            }
        } else {
            return node->contains(word[index]) && dfs(word, node->get(word[index]), index+1, count);
        }
        return ret;
    }
    bool search(string word) {
        return dfs(word, root, 0, 0);
    }
};