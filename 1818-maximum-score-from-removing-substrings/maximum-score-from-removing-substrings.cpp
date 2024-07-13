class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> st;
        int ans=0;
        int n=s.length();
        string top="",bot="";
        int top_score=0,bot_score=0;
        if(x>y){
            top="ab";
            bot="ba";
            top_score=x;
            bot_score=y;
        }else{
            bot="ab";
            top="ba";
            top_score=y;
            bot_score=x;
        }

        for(auto ch:s){
            if(st.empty())st.push_back(ch);
            else{
                if(ch==top[1] && st.back()==top[0]){
                    st.pop_back();
                    ans+=top_score;
                }else{
                    st.push_back(ch);
                }
            }
        }
          vector<char> st1;
          for(auto ch:st){
            if(st1.empty())st1.push_back(ch);
            else{
                if(ch==bot[1] && st1.back()==bot[0]){
                    st1.pop_back();
                  
                    ans+=bot_score;
                }else{
                    st1.push_back(ch);
                }
            }
        }
        return ans;

        // for(int i=0;i<n;i++){
        //     if(st.empty())st.push_back(s[i]);
        //     else{
        //         bool flag=false;
        //     if(s[i]=='a' || s[i]=='b'){
        //         if(s[i]=='a'){
        //             if(st.top()=='b' && i<n-1 && s[i+1]=='b'){
        //                 if(x<=y){
        //                     ans+=y;
        //                     st.pop();
        //                     flag=true;
        //                     cout<<"ba1 ";
        //                 }
        //                 else{
        //                     ans+=x;
        //                     i++;
        //                     flag=true;
        //                     cout<<"ab1 ";
        //                 }
        //             }
        //             else if(st.top()=='b'){
        //                 ans+=y;
        //                 st.pop();
        //                 flag=true;
        //                 cout<<"ba2 ";
        //             }// }else if(i<n-1 && s[i+1]=='b'){
        //             //     ans+=x;
        //             //     i++;
        //             //     flag=true;
        //             // }
        //         }
        //         else{
        //              if(st.top()=='a' && i<n-1 && s[i+1]=='a'){
        //                 if(y<=x){
        //                     ans+=x;
        //                     st.pop();
        //                     flag=true;
        //                     cout<<"ab3 ";
        //                 }
        //                 else{
        //                     ans+=y;
        //                     i++;
        //                     flag=true;
        //                     cout<<"ba3 ";
        //                 }
        //             }
        //             else if(st.top()=='a'){
        //                 ans+=x;
        //                 st.pop();
        //                 flag=true;
        //                 cout<<"ab4 ";
        //             }// }else if(i<n-1 && s[i+1]=='a'){
        //             //     ans+=y;
        //             //     i++;
        //             //     flag=true;
        //             // }
        //         }
        //     }
        //     if(!flag)st.push(s[i]);
        //     }
        // }
        // return ans;
    }
};