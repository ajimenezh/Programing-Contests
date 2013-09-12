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

string s,t,f;
int cnt[27];
vector<char> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>t;
    for (int i=0; i<27; i++) cnt[i] = 0;
    for (int i=0; i<s.length(); i++) cnt[s[i]-'a']++;
    for (int i=0; i<t.length(); i++) {
        if (cnt[t[i]-'a']>0) {
            cnt[t[i]-'a']--;
            f = f + t[i];
        }
        else {
            while (true) {
                char c = char('z'+1);
                for (int j=0; j<s.length(); j++) if (s[j]>t[i] && cnt[s[j]-'a']>0) {
                    c = min(c,s[j]);
                }
                if (c==char('z'+1)) {
                    if (f.length()==0) break;
                    i--;
                    v.push_back(f[f.length()-1]);
                    f = f.substr(0,f.length()-1);
                    continue;
                }
                cnt[c-'a']--;
                f = f + c;
                for (int j=0; j<s.length(); j++) if (cnt[s[j]-'a']>0) {
                    v.push_back(s[j]);
                    cnt[s[j]-'a']--;
                }
                sort(v.begin(),v.end());
                for (int j=0; j<v.size(); j++) {
                    f = f + v[j];
                }
                cout<<f;
                return 0;
            }
            break;
        }
    }

    cout<<-1;

    return 0;

}
