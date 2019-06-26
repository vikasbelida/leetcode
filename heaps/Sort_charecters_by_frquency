struct comp{
  bool operator()(pair<char,int>&p1,pair<char,int>&p2){
      return p1.second<p2.second;
  }  
};
class Solution {
public:
    string frequencySort(string s) {
     string res="";
        unordered_map<char,int>umap;
        for(int i=0;s[i];i++){
            umap[s[i]]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int> >,comp>pq;
        for(int i=0;s[i];i++){
            pair<char,int>p1;
            if(umap[s[i]]>0){
                p1.first=s[i];
                p1.second=umap[s[i]];
                pq.push(p1);
            }
            umap[s[i]]=0;
        }
        while(!pq.empty()){
            pair<char,int>p1;
            p1=pq.top();
            pq.pop();
            for(int i=0;i<p1.second;i++){
                res+=p1.first;
            }
        }
     return res;
    }
};
