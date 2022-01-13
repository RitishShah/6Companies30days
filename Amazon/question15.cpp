class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        while(head != NULL){
            int tempM = M-1;
            while(head && tempM){
                head = head->next;
                tempM--;
            }
            
            Node*prev = head;
            
            int tempN = N+1;
            while(head && tempN){
                head = head->next;
                tempN--;
            }
            
            if(prev) prev->next = head;
        }
    }
};

TC = O(n)
SC = O(1)