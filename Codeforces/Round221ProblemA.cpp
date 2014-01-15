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
int cnt[12];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    for (int i=0; i<s.length(); i++) cnt[s[i]-'0']++;

    int sum = 0;
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    for (int i=1; i<10; i++) {
        for (int j=0; j<cnt[i]; j++) {
            cout<<i;
            sum = (sum*10 + i)%7;
        }
    }

    s = "1689";
    do {
        int k = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
        if (((sum*10000)%7+k%7)%7==0) {
            cout<<s;
            break;
        }
    } while (next_permutation(s.begin(),s.end()));

    for (int i=0; i<cnt[0]; i++) cout<<"0";

    return 0;

}
