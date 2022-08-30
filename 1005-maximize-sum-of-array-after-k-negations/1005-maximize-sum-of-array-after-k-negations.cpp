class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
//         min heap priority queue
        priority_queue<int , vector<int>, greater<int>>p;
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
        }
        while(k){
            int x = p.top();
            x*=-1;
            p.pop();
            p.push(x);
            k--;
        }
        int sum =0;
        while(!p.empty()){
            sum += p.top();
            p.pop();
        }
        return sum;
    }
};