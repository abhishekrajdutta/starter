#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    // Complete this function
    int num[26]={0};
    int index=0;
    string ans="YES";
    for(int i=0;i<s.length();i++)
    {
        index=(int)s[i]-'a';
        // index=index-97;
        cout<<index<<endl;
        num[index]=num[index]+1;
    }
    
   /* int n[3]={0};
    n[0]=num[0];
    n[2]=-1;*/
    index=0;
    
    int first=0,second=0;
    for(int i=0;i<26;i++)
    {
        // cout<<num[i]<<endl;
        if (num[i]>0) 
        {
            
            if (first==0)
            {
                first=num[i];
                cout<<first<<endl;   
            }
            else if(num[i]!=first && second==0)
            {
                second=num[i];
                if ((second-first)>1 || (second-first)<-1)
                    ans="NO";
            }
            else if (num[i]!=first && second!=0 )
                ans="NO";
        }
            
    }
    
   return ans;
}

int main() {
    string s;
    // cin >> s;
    string result = isValid("aabbccde");
    cout << result << endl;
    return 0;
}
