class Solution {
public:
 vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    vector<int> ans;
    bool res = true;
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        if (j == n)
        {
            break;
        }
        if (nums2[i] == nums1[j])
        {
            res = false;
        }
        if (res)
        {
            if (nums2[i] != nums1[j])
            {
                continue;
            }
        }
        if (nums2[i] > nums1[j])
        {
            ans.push_back(nums2[i]);
            j++;
            res = true;
            i = -1;
        }
        else if (i == m - 1)
        {
            ans.push_back(-1);
            j++;
            res = true;
            i = -1;
        }
    }

    return ans;
}
    
};