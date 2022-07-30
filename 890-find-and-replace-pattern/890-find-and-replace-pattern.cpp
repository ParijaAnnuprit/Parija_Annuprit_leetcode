bool match(string word,vector<int>&vp){
    unordered_map<char,int>m;
    vector<int>v;
    int ind =0;
    for(int i=0;i<word.length();i++){
        if(m.find(word[i])==m.end()){
            m.insert({word[i],ind++});
            v.push_back(m[word[i]]);
        }
        v.push_back(m[word[i]]);
    }
    for(int i=0;i<v.size();i++){
        if(v[i]!=vp[i])
            return false;
    }
    return true;
}

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    unordered_map<char,int>m;
    vector<int>vp;
    int ind =0;
    for(int i=0;i<pattern.length();i++){
        if(m.find(pattern[i])==m.end()){
            m.insert({pattern[i],ind++});
            vp.push_back(m[pattern[i]]);
        }
        vp.push_back(m[pattern[i]]);
    }
        vector<string>res;
        for(auto word: words ){
            if(match(word, vp))
                res.push_back(word);
        }
        return res;
    }
};