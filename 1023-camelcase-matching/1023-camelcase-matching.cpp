struct Node{
    unordered_map<char,Node*>children;
    bool flag = false;
    bool containskey(char ch){
        return (children[ch]!=NULL);
    }
    void put(char ch, Node* node){
        children[ch] = node;
    }
    Node* next(char ch){
        return children[ch];
    }
    void setend(){
        flag = true;
    }
    bool retend(){
        return flag;
    }
};





class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Node* root = new Node();
        vector<bool>v;
        int upper = insert(pattern, root);
        for(int i=0;i<queries.size();i++){
            if(search(queries[i], root, upper)==false){
                v.push_back(false);
            }
            else v.push_back(true);
        }
        return v;
    }
    int insert(string s, Node* root){
        Node* dummy = root;
        int uc = 0;
        for(int i=0;i<s.length();i++){
            if(!dummy->containskey(s[i])){
                dummy->put(s[i], new Node());
                dummy = dummy->next(s[i]);
            }
            if(s[i]>=65 && s[i]<=90) uc++;
        }
        dummy->setend();
        return uc;
    }
    bool search(string k, Node* root, int upper){
        Node* dummy = root;
        int uc = 0;
        for(int i=0;i<k.size();i++){
            if(dummy->containskey(k[i])){
                dummy = dummy->next(k[i]);
            }
            if(k[i]>=65 && k[i]<=90) uc++;
        }
        if(uc!=upper) return false;
        return dummy->retend();
    }
};