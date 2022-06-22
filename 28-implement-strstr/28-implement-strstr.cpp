class Solution {
public:
    int strStr(string haystack, string needle) {
        int found = haystack.find(needle);
        if(found!=-1)
            return found;
        else if(needle.length()== 0)
            return 0;
        return -1;
    }
};