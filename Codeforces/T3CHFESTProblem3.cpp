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

int stricmp ( const string &S1,const string &S2 ) {
    for (int i=0; i<min(S1.length(),S2.length()); i++) {
        char c1 = S1[i];
        if (c1<'a') c1 = (c1-'A') + 'a';
        char c2 = S2[i];
        if (c2<'a') c2 = (c2-'A') + 'a';
        cout<<c1<<" "<<c2<<endl;

        if (c1<c2) return -1;
        if (c1>c2) return 1;
    }

    if (S1.length()==S2.length()) return 0;
    if (S1.length()>S2.length()) return 1;
    return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s1 = "abcD";
    string s2 = "abcD";

    cout<<stricmp(s1,s2)<<endl;;

    for (int i=0; i<10000000; i++) cout<<"a";

    return 0;

}
