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

string s;
int c[26];
bool vis[1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    for (int i=0; i<s.length(); i++) vis[i] = 0;
    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<26; j++) c[j] = 0;
        for (int j=0; j<s.length(); j++) if (!vis[j]) {
            c[s[j]-'a']++;
        }
        int c1=0,c2=0;
        for (int j=0; j<26; j++) {
            if (c[j]>0 && c[j]%2==0) c1++;
            else if (c[j]>0 && c[j]%2!=0) c2++;
        }
        //cout<<c1<<" "<<c2<<endl;
        if (c2<=1) {
            if (i%2==0) {
                cout<<"First";
                return 0;
            }
            else {
                cout<<"Second";
                return 0;
            }
        }
        if (c1!=0) {
            int p = 0;
            for (int j=0; j<26; j++) if (c[j]>0 && c[j]%2==0) {
                p = j;
                break;
            }
            for (int j=0; j<s.length(); j++) if (!vis[j] && s[j]==char('a'+p)) {
                p = j;
                break;
            }
            vis[p] = 1;
        }
        else {
            for (int j=0; j<s.length(); j++) if (!vis[j]) {
                vis[j] = 1;
                break;
            }
        }
    }

    if (s.length()%2==0) cout<<"First";
    else cout<<"Second";

    return 0;

}
