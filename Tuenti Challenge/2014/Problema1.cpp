#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h> 
#include <set>
#include <fstream>
#include <vector>
using namespace std;

set<pair<pair<int,int>,pair<pair<string,int>,string> > > all;
vector<string> input;

int main() {
	
	//freopen("students.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int t;
    string s;
	cin>>t;
	getline(cin,s);
	for (int i=0; i<t; i++) {
		getline(cin,s);
		input.push_back(s);
	}
	
    
    ifstream infile;
    
    infile.open("students.txt"); // open file 
    
	while (getline(infile, s)) {
		
		//cout<<s<<endl;
		
		string name, studies;
		int age, gender, academic;
		
		for (int i=0; i<s.length(); i++) {
			if (s[i]==',') {
				name = s.substr(0,i);
				s = s.substr(i+1, s.length()-(i+1));
				break;
			}
		}
		gender = s[0] - 'A';
		s = s.substr(2, s.length()-2);
		//cout<<s<<endl;
		string tmp;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==',') {
				tmp = s.substr(0,i);
				s = s.substr(i+1, s.length()-(i+1));
				break;
			}
		}
		age = atoi(tmp.c_str());
		//cout<<tmp<<" "<<s<<endl;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==',') {
				studies = s.substr(0,i);
				s = s.substr(i+1, s.length()-(i+1));
				break;
			}
		}
		academic = atoi(s.c_str());
		
		//cout<<age<<" "<<academic<<endl;
		
		all.insert(make_pair(make_pair(age, academic), make_pair(make_pair(studies, gender), name)));
	}
	infile.close();
	infile.clear();
	//cin.ignore();
	cin.clear();
	
	set<pair<pair<int,int>,pair<pair<string,int>,string> > >::iterator it;
	

	for (int i=0; i<t; i++) {
		s = input[i];
		
		string studies;
		int age, gender, academic;
		
		gender = s[0] - 'A';
		//cout<<s[0]<<endl;
		s = s.substr(2, s.length()-2);
		//cout<<s<<endl;
		string tmp;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==',') {
				tmp = s.substr(0,i);
				s = s.substr(i+1, s.length()-(i+1));
				break;
			}
		}
		age = atoi(tmp.c_str());
		//cout<<tmp<<" "<<s<<endl;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==',') {
				studies = s.substr(0,i);
				s = s.substr(i+1, s.length()-(i+1));
				break;
			}
		}
		academic = atoi(s.c_str());
		
		tmp = '#';
		
		it = all.lower_bound(make_pair(make_pair(age, academic), make_pair(make_pair(studies, gender), tmp)));
		
		vector<string> v;
		while (it!=all.end()) {
			
			//cout<<(*it).second.second<<endl;
			//cout<<(*it).second.first.second<<" "<<gender<<endl;
			
			if ((*it).first==make_pair(age, academic) && (*it).second.first.second==gender && (*it).second.first.first==studies) {
				s = (*it).second.second;
				v.push_back(s);
			}
			else break;
			it++;
		}
		cout<<"Case #"<<i+1<<": ";
		for (int j=0; j<v.size(); j++) {
			cout<<v[j];
			if (j==(int)v.size()-1) cout<<"\n";
			else cout<<",";
		}
		if (v.size()==0) cout<<"NONE\n";
	}
	
	
	return 0;
}
