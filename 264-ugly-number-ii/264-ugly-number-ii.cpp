// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<int,vector<int>,greater<int>>q;
//         q.push(1);
//         n--;
//         while(n){
//             long long int k = q.top();
//             q.push(k*2);
//             q.push(k*3);
//             q.push(k*5);
//             q.pop();
//             while(q.top()==k) q.pop();
//             n--;
//         }
//         return q.top();
//     }
// };


class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long int ,vector<long long int>,greater<long long int>> pq;
        pq.push(1);
        n--;
        while(n>0)
        {
            long long int k=pq.top();
            pq.push(k*2);
            pq.push(k*3);
            pq.push(k*5);
            pq.pop();
            while(pq.top()==k) pq.pop();
            n--;
        }
        return pq.top();
    }
};