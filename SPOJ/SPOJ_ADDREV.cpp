#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        string s1,s2;
        cin>>s1>>s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int s = atoi(s1.c_str()) + atoi(s2.c_str());
        if (s==0) {
            cout<<0<<endl;
        }
        else {
            string str;
            while (s>0) {
                str += char(s%10+'0');
                s /= 10;
            }
            while (str[0]=='0' && str.length()>1) str = str.substr(1,str.length()-1);
            cout<<str<<endl;
        }
    }

    return 0;

}
