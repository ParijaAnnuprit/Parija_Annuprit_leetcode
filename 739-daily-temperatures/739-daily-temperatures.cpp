// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         stack<int>st;
//         vector<int>res;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 st.push(temperatures[j]);
//                 if(st.top()>temperatures[i]){
//                     res.push_back(st.size());
//                     while(!st.empty())
//                         st.pop();
//                     break;
//                 }
//                 else if(j==n-1 && st.top()<temperatures[i]){
//                     res.push_back(0);
//                     while(!st.empty())
//                         st.pop();
//                 }
//             }
//         }
//         res.push_back(0);
//         return res;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>>st;
        int n=t.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--)
        {
            while((st.size()>0)&&t[i]>=st.top().first)
                st.pop();
            if(st.size()==0)
                ans[i]=0;
            else
            {
                ans[i]=st.top().second-i;
            }
            st.push({t[i],i});
        }
        return ans;
    }
};