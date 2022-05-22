class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxv;
        int maxval = 0;
        int chunks = 0;
        for(int i=0; i<n; i++){
            maxv = max(i, arr[i]);
            maxval = max(maxval, maxv);
            if(maxval == i)
                chunks+=1;
        }
        return chunks;
    }
};