#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

int t;
string s;
int l[1001];
int r[1001];
int next[1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;

    while (t--) {
        cin>>s;

        int n = s.length();

        int c = 1000000;

        for (int i=0; i<n; i++) l[i] = 0;
        for (int i=0; i<n; i++) r[i] = 0;
        for (int i=0; i<s.length(); i++) {
            if (i!=0) l[i] = l[i-1] + min(s[i]-'A', 26-(s[i]-'A'))+1;
            else l[i] = min(s[i]-'A', 26-(s[i]-'A'));
        }
        r[n] = 0;
        for (int i=0; i<s.length(); i++) {
            r[n-i-1] = r[n-i] + min(s[s.length()-1-i]-'A', 26-(s[s.length()-1-i]-'A'))+1;
        }
        int last = -1;
        for (int i=0; i<n; i++) {
            if (s[i]=='A' && last != -1) next[i] = last;
            else {
                last = i;
                for (int j=i+1; j<n; j++) {
                    if (s[j]=='A') last++;
                    else break;
                }
                next[i] = last+1;
            }
        }

        for (int i=0; i<n; i++) {
            c = min(l[i]+r[next[i]] + min(i,(n-next[i])),c);
            //cout<<i<<" "<<l[i]<<" "<<next[i]<<" "<<r[next[i]]<<endl;
        }


        cout<<c<<endl;
    }

    return 0;

}
