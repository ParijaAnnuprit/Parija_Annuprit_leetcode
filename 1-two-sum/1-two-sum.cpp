class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           vector<int> vect;
        for(int i=0; i<nums.size(); i++){
            for (int j=0; j<nums.size(); j++){
                if(nums[i]+nums[j] == target && i!=j){
                    vect.push_back(i);
                    vect.push_back(j);
                    return vect;
                }
                else{
                    continue;
                }
            }
        }
        return vect;
    }
};