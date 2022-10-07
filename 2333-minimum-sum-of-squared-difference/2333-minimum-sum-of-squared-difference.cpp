// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         priority_queue<pair<int,int>q;
//         for(int i=0;i<nums1.size();i++){
//             int diff = abs(nums1[i]-nums2[i]);
//             q.push({diff,i});
//         }
//         while(k1>0 || k2>0){
//             if(q.top().first == 0) break;
//             int x = q.top().first;
//             int y = q.top().second;
//             q.pop();
//             if(nums1[y]>nums2[y]){
//                 if(k1>0){
//                     nums1[y]--;
//                     int z = abs(nums1[y]-nums2[y]);
//                     k1--;
//                     q.push(z);
//                 }
//                 else if(k2>0){
//                     nums2[y]++;
//                     int z = abs(nums1[y]-nums2[y]);
//                     k2--;
//                     q.push(z);
//                 }
//             }
//             else if(nums1[y]<nums2[y]){
//                 if(k1>0){
//                     nums1[y]++;
//                     int z = abs(nums1[y]-nums2[y]);
//                     k1--;
//                     q.push(z);
//                 }
//                 else if(k2>0){
//                     nums1[y]--
//                 }
//             }
//         }
//     }
// };


class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        unordered_map<ll, ll> mp;
        for(int i = 0; i < n; ++i) {
            mp[abs(nums1[i] - nums2[i])]++;
        }
        long long tot = k1 + k2;
        
        priority_queue<array<ll, 2>> pq;
        for(auto [x, y]: mp) {
            if(x == 0) continue;
            pq.push({x, y});
        }
        
        while(!pq.empty() and tot > 0) {
            array<ll, 2> v = pq.top();
            pq.pop();
            
            if(pq.size() == 0) {
                ll mn = min(tot, v[1]);    
                tot -= mn;
                v[1] -= mn;
                if(v[0] - 1 > 0) pq.push({v[0] - 1, mn});
                if(v[1] > 0) pq.push(v);
            } else {
                ll mn = min(tot, v[1]);
                tot -= mn;
                v[1] -= mn;
                if(v[1] > 0) pq.push(v);
                
                if(pq.top()[0] == v[0] - 1) {
                    array<ll, 2> v1 = pq.top();
                    pq.pop();
                    v1[1] += mn;
                    pq.push(v1);
                } else if(v[0] - 1 > 0) {
                    pq.push({v[0] - 1, mn});
                }
            }
        }
        
        ll ans = 0;
        while(!pq.empty()) {
            array<ll, 2> v = pq.top();
            ans += v[0] * v[0] * v[1];
            pq.pop();
        }
        return ans;
    }
};