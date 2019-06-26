struct comp{
  bool operator()(pair<string,int>&p1,pair<string,int>&p2){
      if(p1.second==p2.second){
          return p1.first>p2.first;
      }
      return p1.second<p2.second;
  }  
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>umap;
        int size=words.size();
        for(int i=0;i<size;i++){
            umap[words[i]]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int> >,comp >pq;
        for(int i=0;i<size;i++){
            pair<string,int>p1;
            if(umap[words[i]]>0){
                p1.first=words[i];
                p1.second=umap[words[i]];
                pq.push(p1);
            }
            umap[words[i]]=0;
        }
        vector<string>v1;
        while(k--){
            pair<string,int>p2;
            p2=pq.top();
            pq.pop();
            v1.push_back(p2.first);
        }
        return v1;
    }
};
