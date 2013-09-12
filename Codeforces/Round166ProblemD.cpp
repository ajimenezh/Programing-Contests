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
int k;
string bad;
int l[1600];
set<int> se;
int code[1510][1510];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    cin>>bad;
    cin>>k;

    l[0] = 0;
    for (int i=0; i<s.length(); i++) {
        l[i+1] = l[i] + (bad[s[i]-'a']=='0');
    }

    int m = 1346253;
    long long a = 12165647;

    for (int i=0; i<s.length(); i++) {
        long long b = s[i]-'a'+3;
        for (int j=i; j<s.length(); j++) {
            b = (a + a*b)%m;
            code[i][j] = b;
            //cout<<code[i][j]<<endl;
        }
    }

    int res = 0;
    for (int i=0; i<s.length(); i++) {
        for (int j=i; j<s.length(); j++) {
            if (l[j+1]-l[i]<=k && se.find(code[i][j])==se.end()) {
                res++;
                se.insert(code[i][j]);
                //cout<<s.substr(i,j-i+1)<<" "<<code[i][j]<<endl;
            }
            cout<<s.substr(i,j-i+1)<<" "<<code[i][j]<<endl;
        }
    }

    cout<<res;

    return 0;

}
