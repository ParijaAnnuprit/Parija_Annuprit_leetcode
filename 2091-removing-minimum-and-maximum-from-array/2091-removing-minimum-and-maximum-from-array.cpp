// class Solution {
// public:
//     int minimumDeletions(vector<int>& nums) {
//         int n = nums.size();
//         map<int,pair<int,int>>mpp;
//         for(int i=0;i<nums.size();i++){
//             int f = i+1;
//             int b = n-i;
//             mpp[nums[i]] = {f,b};
//         }
//         int maxa = (mpp.begin())->first;
//         int mini = (--mpp.end())->first;
//         if(mpp[maxa].first <= mpp[maxa].second && mpp[mini].first <= mpp[mini].second)
//             return max(mpp[maxa].first, mpp[mini].first);
//         else if(mpp[maxa].first > mpp[maxa].second && mpp[mini].first > mpp[mini].second)
//             return max(mpp[maxa].second, mpp[mini].second);
//         return min(mpp[maxa].first,mpp[maxa].second) + min(mpp[mini].first,mpp[mini].second);
//     }
// };

class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int a = max_element(begin(A), end(A)) - begin(A), b = min_element(begin(A), end(A)) - begin(A), N = A.size();
        if (a > b) swap(a, b);
        return min({ a + 1 + N - b, b + 1, N - a });
    }
};