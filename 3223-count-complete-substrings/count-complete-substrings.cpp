class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int ans=0;
        int len,cnt;
        int n=word.size();
        
        for(int i=1;i<=26;i++){
             len=i*k;
            cnt=0;
            if(n<len)break;
           // int l=0,h=0;
            //fill(freq.begin(),freq.end(),0);
            vector<int> freq(26,0);
            for(int l=0,h=0;h<n;h++){
                
                if((h>0) && abs(word[h]-word[h-1])>2){
                    cnt=0;
                    fill(freq.begin(),freq.end(),0);
                    l=h;
                }

                if(freq[word[h]-'a']==k)cnt--;
                freq[word[h]-'a']++;
                if(freq[word[h]-'a']==k)cnt++;
            if((h-l+1)>len){
                if(freq[word[l]-'a']==k)cnt--;
                freq[word[l]-'a']--;
                if(freq[word[l]-'a']==k)cnt++;


            l++;
            //h++;
            }
            if(((h-l+1)==len) && (cnt==i))ans++;
        }
        }
        return ans;
    }
};