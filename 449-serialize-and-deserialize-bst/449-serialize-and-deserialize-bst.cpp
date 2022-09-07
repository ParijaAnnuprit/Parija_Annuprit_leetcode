/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Codec {
// public:

//     // Encodes a tree to a single string.
//     vector<int>v;
//     string serialize(TreeNode* root) {
//         convertstr(root);
//         string s ="";
//         for(int i=0;i<v.size();i++){
//             s+=to_string(v[i]);
//             s+="#";
//         }
//         return s;
//     }
    
//     void convertstr(TreeNode* root){
//         if(root==NULL) return;
//         v.push_back(root->val);
//         convertstr(root->left);
//         convertstr(root->right);
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         vector<int>v;
//         string s = "";
//         for(int i=0;i<data.length();i++){
//             if(data[i]=='#'){
//                 v.push_back(stoi(s));
//                 s = "";
//             }
//             else{
//                 s+=data[i];
//             }
//         }
//         if(v.size()==0) return NULL;
//         return construct(v,0,v.size()-1); 
//     }
//     TreeNode* construct(vector<int>& v, int b, int e){
//         TreeNode* root = new TreeNode(v[b]);
//         int k;
//         if(b!=e && v[b+1]<v[b]){
//             for(int i=b+1; i<=e;i++){
//                 if(v[i]>v[b]){
//                     k=i;
//                     break;
//                 }
//             }
//             root->left = construct(v,b+1,k-1); 
//         }
//         if(b!=e && k-1 != v.size()-1){
//             root->right = construct(v,k,e);
//         }
//         return root;
//     }
// };

class Codec {
public:

	void serialize_helper(TreeNode* root , string &s){
		if(root == NULL){
			s.push_back('/');
			s.push_back(',');
			return;
		}

		string t = to_string(root -> val);
		int i = 0;
		while(i < t.size()){
			s.push_back(t[i++]);
		}
		s.push_back(',');

		serialize_helper(root -> left , s);
		serialize_helper(root -> right , s);
	}

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		 string s = "";
		 serialize_helper(root , s);
		 return s;
	}

	int idx =  0;
	TreeNode* deserialize_helper(string data){

		string t;
		while(idx < data.size() && data[idx] != ','){
			t.push_back(data[idx++]);
		}

		if(idx >= data.size() || t == "/"){
			idx++;
			return NULL;
		}

		TreeNode* root = new TreeNode(stoi(t));
		idx++;
		root -> left  = deserialize_helper(data);
		root -> right = deserialize_helper(data);
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data){
		return deserialize_helper(data);
	}

};


// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;