class Solution
{
    private:
    void preorderSerialize(Node* root, vector<int> &ans){
        if(root == NULL){
            ans.push_back(-1);
            return;
        }
        
        ans.push_back(root->data);
        preorderSerialize(root->left, ans);
        preorderSerialize(root->right, ans);
    }
    
    Node*preorderDeserialize(vector<int> &A, int &N){
        if(A.size() == N || A[N] == -1){
            N++;
            return NULL;
        }
        
        Node*node = new Node(A[N]);
        N++;
        node->left = preorderDeserialize(A,N);
        node->right = preorderDeserialize(A,N);
        return node;
    }
    
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        preorderSerialize(root,ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       int v = 0;
       return preorderDeserialize(A, v);
    }

};

TC = O(n)
SC = O(n)