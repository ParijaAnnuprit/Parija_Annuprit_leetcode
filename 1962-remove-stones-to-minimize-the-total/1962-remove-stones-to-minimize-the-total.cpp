class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        long long sum = 0;
        priority_queue<long long>q;
        for(int i=0;i<piles.size();i++){
            long long k = piles[i];
            sum+=k;
            q.push(k);
        }
        while(k){
            long long m;
            if(q.top()%2==0) m = q.top()/2;
            else m = (q.top()/2)+1;
            sum-=q.top();
            sum+=m;
            q.pop();
            q.push(m);
            k--;
        }
        return sum;
    }
};



// class Solution {
// public:
//     int minStoneSum(vector<int>& piles, int k) {
//         priority_queue<int> pq;
        
//         for(int i=0;i<piles.size();i++)
//             pq.push(piles[i]);
//         while(k--)
//         {
//             int x=pq.top();
//             pq.pop();
//             if(x%2==0)
//                 x/=2;
//             else
//             x=x/2+1;
//             pq.push(x);
//         }
//         int sum=0;
//         while(!pq.empty())
//         {
//             sum+=pq.top();
//             pq.pop();
//         }
//         return sum;
//     }
// };