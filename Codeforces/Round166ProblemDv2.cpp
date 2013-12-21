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

string s;
string w;
int n;
int k;
vector<map<char,int> > next;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    cin>>w;
    n = s.length();
    cin>>k;
    int tot = 0;
    next.push_back(map<char,int>());
    for (int i=0; i<n; i++) {
        int sum = 0;
        int cur = 0;
        for (int j=i; j<n; j++) {
            sum += 1 - (w[s[j]-'a']-'0');
            if (sum>k) break;
            if (next[cur].find(s[j])==next[cur].end()) {
                tot++;
                next[cur][s[j]] = next.size();
                cur = next.size();
                next.push_back(map<char,int>());
            }
            else {
                cur = next[cur][s[j]];
            }
        }
    }
    cout<<tot<<endl;

    return 0;

}
