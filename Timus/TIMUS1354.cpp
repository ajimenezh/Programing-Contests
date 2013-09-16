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

#define MAXN 10000

vector<int> a;

void fastLongestPalindrome(string s)
{
    int i = 0;
    int n = s.length();
    int palLen = 0;

    while (i < n)
    {
        if (i > palLen && s[i-palLen-1] == s[i])
        {
            palLen += 2;
            i += 1;
            continue;
        }
        a.pb(palLen);

        int c = a.size() - 2;
        int e = c - palLen;
        bool exit = false;

        for (int j=c; j>e; j--)
        {
            int d = j - e - 1;

            if (a[j] == d)
            {
                palLen = d;
                exit = true;
                break;
            }
            a.pb(min(d,a[j]));
        }

        if (!exit)
        {
            palLen = 1;
            i += 1;
        }
    }

    a.pb(palLen);

    int l = a.size();
    int c = l - 2;
    int e = c - (2*n + 1 - l);
    for (i=c; i>e; i--)
    {
        int d = i - e - 1;
        a.pb(min(d,a[i]));
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    fastLongestPalindrome(s);

    int best = 0;
    int p = -1;
    for (int i=0; i<a.size(); i++) {
        if (a[i]+i==2*s.length() && i-a[i]>0 && a[i]>best) {
            best = a[i];
            p = i;
        }
    }
    if (best==1) {
        string str = s.substr(0,s.length()-1);
        reverse(str.begin(),str.end());
        cout<<s<<str<<endl;
    }
    else {
        string str = s.substr(0,s.length()-best);
        reverse(str.begin(),str.end());
        cout<<s<<str<<endl;
    }
    //for (int i=0; i<a.size(); i++) cout<<a[i]<<" ";

    return 0;

}
