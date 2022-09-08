class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i=0;i<stones.size();i++){
            q.push(stones[i]);
        }
        while(q.size()>1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            int z = y-x;
            if(z!=0) q.push(z);
        }
        if(q.size()==0) return 0;
        return q.top();
    }
};