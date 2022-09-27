class Solution{
    public:
    string repeatLimitedString(string s, int limit)
    {
        map<char,int> mpp;
        for(auto i:s)
        {
            mpp[i]++;
        }
        
        priority_queue<pair<char,int>> pq;
        for(auto i:mpp)
        {
            pq.push({i.first, i.second});
        }
        
        string ans;
        while(!pq.empty())
        {
            pair<char,int> temp = pq.top(); pq.pop();
            
            point : // ( * )
            
            int fill = min(limit, temp.second);
            temp.second -= fill;
            
            while(fill--)ans.push_back(temp.first);
            if(temp.second > 0)
            {
                if(pq.empty())return ans;
                
                pair<char, int> now = pq.top(); pq.pop();
                ans.push_back(now.first);
                now.second -= 1;
                if(now.second) pq.push(now);
                goto point;// ( * )
            }
        }
        return ans;
    }
};