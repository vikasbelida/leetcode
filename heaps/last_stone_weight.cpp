class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
     priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            int res=f-s;
            pq.push(res);
        }
        if(pq.top()==0){
            return 0;
        }
        else{
            return pq.top();
        }
    }
};
