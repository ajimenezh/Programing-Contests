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

int n,t;
int l[] = {31,28,31,30,31,30,31,31,30,31,30,31};
vector<pair<int,int> > v;
set<int> all;

int calc_day(string s) {
    int year = atoi(s.substr(0,4).c_str());
    int month = atoi(s.substr(5,2).c_str());
    int day = atoi(s.substr(8,2).c_str());
    int k = 0;
    if (year>2013) {
        k += 365*(year-2013);
    }

    for (int i=0; i<month-1; i++) {
        if (i==1){
            if (year==2016) k += 29;
            else k += 28;
        }
        else k += l[i];
    }
    k += day;
    return k + 1;
}

int calc_hour(string s) {
    int hour = atoi(s.substr(0,2).c_str());
    int minute = atoi(s.substr(3,2).c_str());
    int k = hour*60 + minute;
    return k;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n>>t;
        v.clear();
        all.clear();
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            string day;
            cin>>day;
            int start = calc_day(day);
            string hour;
            cin>>hour;
            start = start*46*60 + calc_hour(hour);
            cin>>day;
            int fin = calc_day(day);
            cin>>hour;
            fin = fin*46*60 + calc_hour(hour) + t;

            v.push_back(make_pair(start, i+1));
            v.push_back(make_pair(fin,-i-1));
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for (int i=0; i<v.size();) {
            int k = i;
            while (k<v.size() && v[i].first==v[k].first) {
                if (v[k].second>=0) {
                    all.insert(v[k].second);
                }
                else {
                    all.erase(-v[k].second);
                }
                k++;
            }
            i = k;
            ans = max(ans, (int)all.size());
        }
        cout<<ans<<endl;
    }

    return 0;

}
