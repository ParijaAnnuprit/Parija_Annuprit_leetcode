class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>q;
        q.push(a);
        q.push(b);
        q.push(c);
        int count =0;
        while(q.size()>1){
            int x = q.top()-1;
            q.pop();
            int y = q.top()-1;
            q.pop();
            if(x!=0) q.push(x);
            if(y!=0) q.push(y);
            count++;
        }
        return count;
    }
};