class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int x = 0;
        int y = numbers.size()-1;
        vector<int>v;
        while(x<y){
            if(numbers[x]+numbers[y] < target){
                x++; 
            }
            else if(numbers[x]+numbers[y] > target){
                y--;
            }
            else{
                v.push_back(x+1);
                v.push_back(y+1);
                break;
            }
        }
        return v;
    }
};