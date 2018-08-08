#include<iostream>
#include<cstring>
#include<string>
#include<locale>
#include<algorithm>
using namespace std;

#define invalid -1

string toU(string s){
	locale l;
	for(int i=0; i<s.length(); i++)
		toupper(s[i], l);
	cout << s << endl;
	return s;
}

string remover(string s, char last){
	int i=0;
	while(i<s.length()){
		if(s[i]<'A'||last<s[i])	s.erase(i, 1);
		else i++;
	}
	cout << s << endl;
	return s;
}

bool valchecker(string s){
	stable_sort(s.begin(), s.end());
	cout << s << endl;
	for(int i=0; i<s.length(); i++)
		if(s.find(s[i])==string::npos)	return false;
	return true;
}

int main(){
	cout << "This program is for single voting screen." << endl;
	cout << "How many responses? : ";
	int n;
	cin >> n;
	if(n<2||n>27){
		cout << "That seems too few/many.\n";
	}else{
		cout << "How many votes? :";
		int v;
		cin >> v;
		if(v<1){
			cout << "What?! Then this program is inappropriate for that case.\n";
		}else{
			cout << "From now, you must input all the votes. You must separate each vote by space.\n";
			double r[v][n]={0};
			for(int i=0; i<v; i++){
				string s;
				cin >> s;
				s = toU(s);
				const char lc = 'A' + n - 1;
				s = remover(s, lc);
				if(valchecker(s)){
				}else{
					for(int j=0; j<n; j++)
						r[i][j]=-1;
				}
			}
		}
	}
	return 0;
}
