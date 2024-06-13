class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans=0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int n=seats.size();
        for(int i=0;i<n;i++){
            ans+=abs(seats[i]-students[i]);
        }
        return ans;
    }
};