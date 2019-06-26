struct comp{
    bool operator()(pair<double,pair<int,int> >&p1,pair<double,pair<int,int> >&p2){
        return p1.first>p2.first;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int size=points.size();
        priority_queue<pair<double,pair<int,int> >,vector<pair<double,pair<int,int> > >,comp >pq;
        for(int i=0;i<size;i++){
            int x1=(points[i][0]-0);
            int x2=points[i][1]-0;
            double res=sqrt(pow(x1,2)+pow(x2,2));
            pair<double,pair<int,int> >p1;
            p1.first=res;
            p1.second.first=points[i][0];
            p1.second.second=points[i][1];
            pq.push(p1);
        }
        vector<vector<int> >v1; 
        while(K--){
            pair<double,pair<int,int> >p1;
            p1=pq.top();
            pq.pop();
            vector<int>small;
            small.push_back(p1.second.first);
            small.push_back(p1.second.second);
            v1.push_back(small);
        }
        return v1;
    }
};
