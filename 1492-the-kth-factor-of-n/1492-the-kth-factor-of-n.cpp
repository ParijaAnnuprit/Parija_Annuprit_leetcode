class Solution {
public:
    int kthFactor(int n, int k) {
        priority_queue<int>q;
        for(int i=1;i<=n;i++){
            if(n%i==0) q.push(i);
            // if(q.size()>k) q.pop();
        }
        if(k>q.size()) return -1;
        while(q.size()>k){
            q.pop();
        }
        return q.top();
    }
};