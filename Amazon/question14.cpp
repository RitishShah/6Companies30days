class Solution {
  private:
    int timeToBurn(Node*targetNode, map<Node*,Node*> parentsOfNodes){
        queue<Node*>q;
        q.push(targetNode);
        map<Node*,int> visited;
        visited[targetNode] = 1;
        int time = 0;
        
        while(!q.empty()){
            int sz = q.size();
            int fl = 0;
            
            for(int i=0;i<sz;i++){
                Node* node = q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    fl=1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                
                if(node->right && !visited[node->right]){
                    fl = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                
                if(parentsOfNodes[node] && !visited[parentsOfNodes[node]]){
                    fl=1;
                    visited[parentsOfNodes[node]] = 1;
                    q.push(parentsOfNodes[node]);
                }
            }
            if(fl) time++;
        }
        return time;
    }
  
    Node* bfsToFindTarget(Node* root, map<Node*,Node*> &parentsOfNodes, int target){
        queue<Node*> q;
        q.push(root);
        Node* ans;
        
        while(!q.empty()){
            Node*node = q.front();
            q.pop();
            
            if(node->data == target) ans = node;
            
            if(node->left){
                parentsOfNodes[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                parentsOfNodes[node->right] = node;
                q.push(node->right);
            }
        }
        
        return ans;
    }
    
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> parentsOfNodes;
        
        Node* targetNode = bfsToFindTarget(root,parentsOfNodes,target);
        
        int time = timeToBurn(targetNode, parentsOfNodes);
        
        return time;
    }
};

TC = O(n)
SC = O(n)