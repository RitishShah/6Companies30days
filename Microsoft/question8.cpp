class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       root->nextRight = NULL;
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           Node*temp = q.front();
           q.pop();
           
           if(temp->left){
               q.push(temp->left);
               
           }
           
           if(temp->right){
               q.push(temp->right);
           }
           
           if(temp->left && temp->right){
               temp->left->nextRight = temp->right;
               
               if(temp->nextRight){
                   if(temp->nextRight->left){
                       temp->right->nextRight = temp->nextRight->left;
                   }
                   
                   else if(temp->nextRight->right){
                       temp->right->nextRight = temp->nextRight->right;
                   }
                   
                   else{
                       temp->right->nextRight = NULL;
                   }
               }
               
               else{
                   temp->right->nextRight = NULL;
               }
           }
           
           else if(temp->left || temp->right){
               if(temp->right){
                   if(temp->nextRight){
                       if(temp->nextRight->left){
                           temp->right->nextRight = temp->nextRight->left;
                       }
                       
                       else if(temp->nextRight->right){
                           temp->right->nextRight = temp->nextRight->right;
                       }
                       
                       else{
                           temp->right->nextRight = NULL;
                       }
                   }
               }
               
               else{
                   if(temp->nextRight){
                       if(temp->nextRight->left){
                           temp->left->nextRight = temp->nextRight->left;
                       }
                       
                       else if(temp->nextRight->right){
                           temp->left->nextRight = temp->nextRight->right;
                       }
                       
                       else{
                           temp->left->nextRight = NULL;
                       }
                   }
               }
           }
       }
    }    
      
};

TC = O(n)
SC = O(n)