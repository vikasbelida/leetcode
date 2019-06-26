struct comp{
  bool operator()(pair<int,int>&p1,pair<int,int>&p2){
      if(p1.second==p2.second){
          return p1.first<p2.first;
      }
      return p1.second<p2.second;
  }  
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int size=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int> >,comp >pq;
        for(int i=0;i<size;i++){
            umap[nums[i]]++;
        }
        for(int i=0;i<size;i++){
            pair<int,int>p1;
            if(umap[nums[i]]>0){
            p1.first=nums[i];
            p1.second=umap[nums[i]];
            pq.push(p1);
            }
            umap[nums[i]]=0;
        }
        vector<int>v1;
        while(k--){
            pair<int,int>p1;
            p1=pq.top();
            pq.pop();
            v1.push_back(p1.first);
        }
        return v1;
    }
};
