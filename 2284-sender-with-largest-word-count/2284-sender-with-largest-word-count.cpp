class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>mpp;
        vector<int>v;
        for(int i=0;i<messages.size();i++){
            int l=1;
            for(int j=0;j<messages[i].size();j++){
                if(messages[i][j]==' ') l++;
            }
            v.push_back(l);
        }
        for(int i=0;i<senders.size();i++){
            mpp[senders[i]]+=v[i];
        }
        priority_queue<pair<int,string>>q;
        for(auto i:mpp){
            q.push({i.second,i.first});
        }
        int x = q.top().first;
        string s = q.top().second;
        q.pop();
        while(!q.empty()){
            if(q.top().first< x) break;
            else{
                if(q.top().first == x){
                    s = max(s, q.top().second);
                }
                q.pop();
            }
        }
        return s;
    }
};



