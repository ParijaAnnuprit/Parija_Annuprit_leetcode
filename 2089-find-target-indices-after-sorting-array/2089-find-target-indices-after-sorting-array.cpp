class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>vect;
        sort(nums.begin(), nums.end());
        int first = -1;
        int last = -1;
        int l = 0;
        int h = n-1;
        
        
        // for(int i=0; i<n; i++){
        //     if(nums[i] == target)
        //         vect.push_back(i);
        // }
        
//         finding first index of target;
        while(l<=h){
            int m = l + ((h-l)/2);
            if(nums[m] == target){
                first = m;
                h = m-1;
            }
            else if(nums[m]>target)
                h = m-1;
            else if(nums[m]< target)
                l = m+1;
        }
        l = 0;
        h = n-1;
        
//         finding lalst index of target;
         while(l<=h){
            int m = l + ((h-l)/2);
            if(nums[m] == target){
                last = m;
                l = m+1;
            }
            else if(nums[m]>target)
                h = m-1;
            else if(nums[m]< target)
                l = m+1;
        }
        if(first == -1 || last == -1)
            return vect;
        
//         storing in vector
        for(int i=first; i<=last; i++){
            vect.push_back(i);
        }
        return vect;
    }
};