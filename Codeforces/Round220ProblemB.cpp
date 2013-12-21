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

    string s;
    cin>>s;
    long long res = 1;
    for (int i=0; i<s.length()-1; i++) {
        if (s[i]-'0'+s[i+1]-'0'==9) {
            int j = i;
            int k=0;
            while (j<s.length()-1 && s[j]-'0'+s[j+1]-'0'==9) {
                j++; k++;
            }
            i = j;
            if (k%2==0) res = res*(k/2+1);
        }
    }

    cout<<res<<endl;

    return 0;

}
