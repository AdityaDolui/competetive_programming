class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i=0;
       long long sum=0;
        int n=chalk.size();
        
       sum=accumulate(chalk.begin(),chalk.end(),0LL);
       cout<<sum;
        k=k%sum;
        while(true){
            i=i%chalk.size();
            if(chalk[i]>k)return i;
            k-=chalk[i++];
        }
    }
};