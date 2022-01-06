Here, we are using min Heap to solve this question.

vector<int> solve(vector<int>v, int k = 10){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0;i<1e6;i++){
        minHeap.push(v[i]);

        if(minHeap.size() > k) minHeap.pop();
    }

    vector<int> ans;

    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }

    return ans;
}

we can reaplace int data-type with long, inorder to not get int overflow.

TC = O(nLogk)
SC = O(k)