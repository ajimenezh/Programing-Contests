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

string s, t;
int cnt[26];
int sum[26];
int tmp[26];
int all[26];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>s>>t;
    for (int i=0; i<s.length(); i++) cnt[t[i]-'A']++;
    for (int i=0; i<s.length(); i++) all[t[i]-'A']++;
    for (int i=0; i<s.length(); i++) cnt[s[i]-'A']--;
    int k = 0;
    for (int j=0; j<t.length(); j++) if (cnt[s[j]-'A']<0) {
        for (int i=0; i<26; i++) {
            if (cnt[i]>0) {
                if ((s[j]-'A')>i || all[s[j]-'A']==0) {
                    cnt[i]--;
                    all[i]--;
                    cnt[s[j]-'A']++;
                    s[j] = char('A'+i);
                    k++;
                }
                else {
                    cnt[s[j]-'A']++;
                    cnt[s[j]-'A']--;
                    all[s[j]-'A']--;
                }
                break;
            }
        }
    }

    cout<<k<<endl;
    cout<<s<<endl;

    return 0;

}
