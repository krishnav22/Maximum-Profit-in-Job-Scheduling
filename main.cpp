// Maximum Profit in Job Scheduling
class Solution {
public:
int n;
int t[50001];
     int findNextIdx(vector<vector<int>>&arr, int l,int target){
         int r=n-1;
         int ans=n+1;
         while(l<=r){
             int mid=l+(r-l)/2;
             if(arr[mid][0]>=target){
                 ans=mid;
                 r=mid-1;
             }
             else{
               l=mid+1;
             }
         }
return ans;
     }
    int solve(vector<vector<int>>&arr,int idx){
        if(idx>=n)return 0;
        if(t[idx]!=-1)return t[idx];
        int next=findNextIdx(arr,idx+1,arr[idx][1]);
        int taken=arr[idx][2]+solve(arr,next);
        int not_taken=solve(arr,idx+1);
        return t[idx]= max(taken,not_taken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       n=startTime.size();
       vector<vector<int>>arr(n,vector<int>(3,0));
       for(int i=0;i<n;i++){
           arr[i][0]=startTime[i];
           arr[i][1]=endTime[i];
           arr[i][2]=profit[i];
       }
       sort(arr.begin(),arr.end());
       memset(t,-1,sizeof(t));
       return solve(arr,0);
    }
};
