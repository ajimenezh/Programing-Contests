#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXSIZE 3201340
#define MAXWORD 120

string vs[MAXSIZE];
pair<string,string> v[MAXSIZE];
char buf[MAXWORD];
string str;
string s;
string name;
int n;
vector<pair<string,string> > w;

int main() {

    getline(cin,str);
    getline(cin,str);
    stringstream ss(str);
    ss>>name;
    string dir = "C:\\Users\\Alex\\Downloads\\dictionaries\\" + name;

    FILE *input;
    input = fopen(dir.c_str(),"r+");

    //cout<<"Abierto archivo"<<endl;

    int k = 0;
    int n = 0;
    string p;
    while (!feof(input) && fscanf(input,"%s",buf)) {
        int c = 0;
        s = string(buf);
        c = s.length();

        sort(buf,buf+c);
        str = string(buf);
        v[n++] = make_pair(str,s);
    }
    n--;

    fclose(input);

    sort(v,v+n);
    w = vector<pair<string,string> > (v,v+n);

    getline(cin,str);
    getline(cin,str);
    ss.str(str);
    ss>>str;
    n = atoi(str.c_str());
    getline(cin,str);

    for (int i=0; i<n; i++) {
        scanf("%s",buf);
        str = string(buf);
        string s = str;
        cout<<str<<" ->";
        int c = str.size();
        sort(buf,buf+c);
        str = string(buf);
        vector<pair<string,string> >::iterator it = lower_bound(w.begin(),w.end(),make_pair(str,str));

        while (it!=w.end() && (*it).first==str) {
            if ((*it).second!=s) cout<<" "<<(*it).second;
            it++;
        }
        cout<<"\n";
    }

    return 0;

}
