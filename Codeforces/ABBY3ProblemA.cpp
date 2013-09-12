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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;

    if (s[0]>='0' && s[0]<='9') {
        int k = 1;

        int a=0, b=0;

        set<char> se;

        for (int i=1; i<s.length(); i++) {
            if (s[i]=='?') a++;
            if (s[i]>='A' && s[i]<='J') se.insert(s[i]);
        }

        for (int i=0; i<se.size(); i++) k *= (10-i);

        printf("%d",k);
        for (int i=0; i<a; i++) printf("0");
    }
    else if (s[0]=='?') {
        int k = 9;

        int a=0, b=0;

        set<char> se;

        for (int i=1; i<s.length(); i++) {
            if (s[i]=='?') a++;
            if (s[i]>='A' && s[i]<='J') se.insert(s[i]);
        }

        for (int i=0; i<se.size(); i++) k *= (10-i);

        printf("%d",k);
        for (int i=0; i<a; i++) printf("0");
    }
    else {
        int k = 1;

        int a=0, b=0;

        set<char> se;

        se.insert(s[0]);

        for (int i=1; i<s.length(); i++) {
            if (s[i]=='?') a++;
            if (s[i]>='A' && s[i]<='J') se.insert(s[i]);
        }

        for (int i=0; i<se.size()-1; i++) k *= (9-i);
        k *= 9;

        printf("%d",k);
        for (int i=0; i<a; i++) printf("0");
    }

    return 0;

}
