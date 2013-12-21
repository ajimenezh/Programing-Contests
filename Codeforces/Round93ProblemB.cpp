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
int n;
int f[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();

    int p = 2;
    int cnt = 0;
    f[0] = -1;
    f[1] = 0;

    while (p<=n) {
        if (s[p-1]==s[cnt]) {
            cnt = cnt+1;
            f[p] = cnt;
            p = p+1;
        }
        else if (cnt>0) {
            cnt = f[cnt];
        }
        else {
            f[p] = 0;
            p++;
        }
    }

    int k = f[n];
    if (k!=-1 && k) {
        bool good = 0;
        for (int i=0; i<n-1; i++) {
            if (f[i]==k) good = 1;
        }
        if (good) {
            cout<<s.substr(0,k)<<endl;
        }
        else {
            if (f[k]==-1 || !f[k])
                cout<<"Just a legend"<<endl;
            else {
                cout<<s.substr(0,f[k])<<endl;
            }
        }
    }
    else {
        cout<<"Just a legend"<<endl;
    }


    return 0;

}
