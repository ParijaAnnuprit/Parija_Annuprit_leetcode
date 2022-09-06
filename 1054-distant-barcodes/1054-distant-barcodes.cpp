class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>>q;
        unordered_map<int,int>mpp;
        vector<int>v;
        for(int i=0;i<barcodes.size();i++){
            mpp[barcodes[i]]++;
        }
        for(auto i:mpp){
            q.push({i.second,i.first});
        }
        while(q.size()>1){
            pair<int,int>p = q.top();
            q.pop();
            pair<int,int>r = q.top();
            q.pop();
            v.push_back(p.second);
            p.first--;
            v.push_back(r.second);
            r.first--;
            if(p.first!=0) q.push(p);
            if(r.first!=0) q.push(r);
        }
        if(q.size()==1){
            while(q.top().first){
                pair<int,int>z = q.top();
                q.pop();
                v.push_back(z.second);
                z.first--;
                q.push(z);    
            }
        }
        return v;
    }
};