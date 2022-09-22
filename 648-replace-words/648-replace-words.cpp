struct Node{
    Node* arr[26];
    int flag = false;
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
        flag = true;
    }
    bool retend(){
        return flag;
    }
};



class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* root = new Node();
        for(int i=0;i<dictionary.size();i++){
            insert(dictionary[i], root);
        }
        queue<string>q,nq;
        map<string,string>mpp;
        stringstream x(sentence);
        string t;
        string res;
        while(getline(x,t,' ')){
            q.push(t);
        }
        while(!q.empty()){
            string k = q.front();
            q.pop();
            nq.push(k);
            string j = search(k, root);
            if(j.length()==0) mpp[k] = k;
            else mpp[k] = j; 
        }
        while(!nq.empty()){
            res+= mpp[nq.front()];
            nq.pop();
            res+=' ';
        }
        res.pop_back();
        return res;
    }
//     inserting strings inside the trie
    void insert(string s, Node* root){
        Node* dummy = root;
        for(int i=0;i<s.length();i++){
            if(!dummy->containskey(s[i])){
                dummy->put(s[i], new Node());
            }
            dummy = dummy->next(s[i]);
        }
        dummy->setend();
    }
//     searching strings inside the trie
    string search(string s, Node* root){
        Node* dummy = root;
        string k = "";
        for(int i=0;i<s.length();i++){
            if(dummy->retend()== true)
                return k;
            else if(dummy->containskey(s[i])){
                k+=s[i];
                dummy = dummy->next(s[i]);
            }
            else break;
        }
        return "";
    }
};

// !dummy->containskey(s[i]) && 