class Solution {
public:
    vector<int> sumZero(int n) 
{
	vector<int> ans;
	if(n%2!=0)
	{
		ans.push_back(0);
	}
	for(int i=1;ans.size()<n;i++)
	{
		ans.push_back(i*pow(-1,i));
		ans.push_back((-1)*i*pow(-1,i));
	}
	return ans;
}
};