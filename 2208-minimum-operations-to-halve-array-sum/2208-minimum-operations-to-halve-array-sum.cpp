class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        int count =0;
        priority_queue<double>q;
        for(int i=0;i<nums.size();i++){
            float a = nums[i];
            q.push(a);
            sum+=a;
        }
        double half = sum/2;
        while(!q.empty()){
            double b = q.top()/2.0;
            sum-=q.top();
            sum+=b;
            q.pop();
            q.push(b);
            count++;
            if(sum<=half) break;
        }
        return count;
    }
};



// class Solution {
// public:
//     int halveArray(vector<int>& nums) {
//         double sum=0,s=0,count=0;
//         priority_queue<double> pq;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             s+=nums[i];
//             pq.push(nums[i]);
//         }
//         while(!pq.empty() && s>sum/2)
//         {
//             double x=pq.top();
//             pq.pop();
//             x/=2.0;
//             s-=x;
//             pq.push(x);
//             count++;
//         }
//         return count;
        
//     }
// };