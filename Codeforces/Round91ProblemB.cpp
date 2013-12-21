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
int n,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>s;

    int i=0;
    while (k>0) {
        for(;i<n-1;i++) if (s[i]=='4' && s[i+1]=='7') {
            if (i<n-2 && i%2==0 && s[i+2]=='7') {
                if (k%2==1) s[i+1] = '4';
                k = -1;
                break;
            }
            else {
                if (i%2==0) {
                    s[i+1] = '4';
                }
                else {
                    s[i]='7';
                    if (i!=0) i--;
                }
                break;
            }
        }
    }
    cout<<s<<endl;

    return 0;

}
