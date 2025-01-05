class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> arr(s.size()+1);

        // for(int i=0;i<shifts.size();i++){
        //     for(int j=shifts[i][0];j<=shifts[i][1];j++){
        //         if(shifts[i][2]){
        //             arr[j]++;}
        //         else {
        //             arr[j]--;}
        //     }
        // }
          for (auto i : shifts) {
            int direction = i[2];
            
            arr[i[0]] += (direction == 1)? 1: -1;
            arr[i[1]+1] -= (direction == 1)? 1: -1;
        }
        // for(auto it:arr)cout<<it<<" ";
        // cout<<endl;
int it=0;
                for(int i=0;i<arr.size();i++){
             it+=(arr[i])%26;
             it=(it+26)%26;
           // cout<<it<<" ";

                int val=s[i]-96;
                if((val+it)>26)val=(it+val)%26;
                else val=it+val;
                s[i]=96+val;

        }
        return s;
    }
};