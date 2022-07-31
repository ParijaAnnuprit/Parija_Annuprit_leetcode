class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mpp;
        vector<string>res;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    mpp[list1[i]]=i+j;
                    break;
                }
            }
        }
        int mini = INT_MAX;
        for(auto i:mpp){
            mini = min(mini, i.second);
        }
        for(auto i:mpp){
            if(i.second == mini)
                res.push_back(i.first);
        }
        return res;
    }
};