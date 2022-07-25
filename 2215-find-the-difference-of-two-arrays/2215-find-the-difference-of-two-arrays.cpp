class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m1,m2;
        vector<int>l1,l2;
        vector<vector<int>>v;
        for(int i:nums1){
            m1[i]++;
        }
        for(int i:nums2){
            m2[i]++;
        }
        for(auto i:m1){
            if(!m2[i.first])
                l1.push_back(i.first);
        }
        for(auto i:m2){
            if(!m1[i.first])
                l2.push_back(i.first);
        }
        v.push_back(l1);
        v.push_back(l2);
        return v;
    }
};

// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
//         map<int,int>m1;
//         map<int,int>m2;
//         vector<int> lst1;
//         vector<int> lst2;
//         vector<vector<int>> ans;
        
//         for(int i:nums1)
//             m1[i]++;
        
//         for(int i:nums2)
//             m2[i]++;
        
//         for(auto i:m1)
//         {
//             if(i.second >=1 && !m2[i.first]  )
//                 lst1.push_back(i.first);
//         }
        
//         for(auto i:m2)
//         {
//             if(i.second >=1 && !m1[i.first] )
//                 lst2.push_back(i.first);
//         }
//         ans.push_back(lst1);
//         ans.push_back(lst2);
//         return ans;
//     }
// };