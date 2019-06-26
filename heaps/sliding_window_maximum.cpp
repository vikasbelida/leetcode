class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v1;
        int size=nums.size();
        deque<int>dq;
        for(int i=0;i<size;i++){
            //remove the element if it is not in the window.
            if(!dq.empty()&&dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                v1.push_back(nums[dq.front()]);
            }
        }
        return v1;
    }
};
