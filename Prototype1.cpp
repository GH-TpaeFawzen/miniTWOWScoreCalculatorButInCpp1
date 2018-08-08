#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

#define invalid -1

//removes invalid characters
string remover(string s, char last){
	cout << s << endl;
	int i=0;
	while(i<s.length()){
		if(s[i]<'A'||last<s[i])	s.erase(i, 1);
		else i++;
	}
	cout << s << endl;
	return s;
}

//judges if the vote is valid
bool valchecker(string s){
	if(s.empty())	return false;
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
		//Error
		cout << "That seems too few/many.\n";
	}else{
		int v;
		
		cout << "How many votes? :";
		cin >> v;
		if(v<1){
			cout << "What?! Then this program is inappropriate for that case.\n";
		}else{
			cout << "From now, you must input all the votes. You must separate each vote by space.\n";
			double r[v][n]={0};
			
			//Below Here:gets votes and record placement.
			for(int i=0; i<v; i++){
				string s;
				cin >> s;
				
				//CAPITALIZATION!
				transform(s.begin(), s.end(), s.begin(), ::toupper);
				const char lc = 'A' + n - 1;
				s = remover(s, lc);
				if(valchecker(s)){
					//VALID VOTE
				}else{
					//INVALID!
					for(int j=0; j<n; j++)
						r[i][j]=invalid;
				}
			}
			
			//Below Here:calculation! hooray!
			
		}
		cout << "Copy and paste the following text to your spreadsheet:\n";
		
		//Below Here:result by character
	}
	return 0;
}
