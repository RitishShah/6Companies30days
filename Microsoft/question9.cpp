int solve(Node*root, int X, int &ans){
    if(root == NULL) return 0;
    
    int ls = solve(root->left, X, ans);
    int rs = solve(root->right, X, ans);
    
    int sum = ls + rs + root->data;
    
    if(sum == X) ans++;
    
    return sum;
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	if(root == NULL) return 0;
	int ans = 0;
	solve(root, X, ans);
	return ans;
}

TC = O(n)
SC = O(h) h -> height of tree.