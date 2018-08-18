#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

#define invalid -1

//removes invalid characters
string remover(string s, char last){
	cout << s << endl;	//DeBuG
	int i=0;
	while(i<s.length()){
		if(s[i]<'A'||last<s[i])	s.erase(i, 1);
		else i++;
	}
	cout << s << endl;	//DeBuG
	return s;
}

//judges if the vote is valid
bool valchecker(string s){
	if(s.empty())	return false;
	stable_sort(s.begin(), s.end());
	cout << s << endl;	//DeBuG
	for(int i=0; i<s.length()-1; i++)
		if(s[i]==s[i+1])	return false;
	return true;
}

int main(){
	cout << "This program is for single voting screen." << endl;
	cout << "How many responses? : ";
	int n;	//how many responses?
	cin >> n;
	if(n<2||n>27){
		//Error
		cout << "That seems too few/many.\n";
	}else{
		int v;	//how many votes to input?
		
		cout << "How many votes? :";
		cin >> v;
		if(v<1){
			cout << "What?! Then this program is inappropriate for that case.\n";
		}else{
			cout << "From now, you must input all the votes. You must separate each vote by space.\n";
			//double r[v][n]={0};	//mini-ranks
			double ms[v][n]={0};	//mini-scores
			unsigned valids = 0;	//how many valid votes?
			
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
					const double unranked = (s.length()+1+n)/2.0;
					cout << unranked << endl;	//DeBuG
					for(int j=0; j<n; j++){
						int tmp = s.find('A'+j);
						//r[i][j]=(tmp==string::npos)?unranked:tmp+1;
						ms[i][j]=(tmp==string::npos)?unranked:(n-tmp-1.0)*100.0/(n-1.0);
					}
					valids++;
				}else{
					cout << "An invalid vote got input.\n";
					//INVALID!
					for(int j=0; j<n; j++)
						//r[i][j]=invalid;
						ms[i][j]=invalid;
				}
			}
			
			//DeBuG
			for(int i=0; i<v; i++){
				for(int j=0; j<n; j++)
					//cout << r[i][j] << ' ';
					cout << ms[i][j] << ' ';
				cout << endl;
			}
			
			//Below Here:calculation! hooray!
			if(valids>0){
				//double ravr[n], rsd[n];
				double avr[n], sd[n];
				for(int i=0; i<n; i++){
					double sum=0;
					for(int j=0; j<v; j++){
						//sum+=(r[j][i]==invalid)?0:r[j][i];
						sum+=(ms[j][i]==invalid)?0:ms[j][i];
					}
					//ravr[i]=sum/valids;
					avr[i]=sum/valids;
					
					double sum0=0;
					for(int j=0; j<v; j++){
						//sum0+=(r[j][i]==invalid)?0:r[j][i]*r[j][i]-ravr[i]*ravr[i];
						sum0+=(ms[j][i]==invalid)?0:ms[j][i]*ms[j][i]-avr[i]*avr[i];
					}
					//rsd[i]=sqrt(sum0/valids);
					sd[i]=sqrt(sum0/valids);
				}
							
				//Below Here:result by character
				cout << "Copy and paste the following text to your spreadsheet:\n";
				if(valids>1){
					cout << "Alphabet\tAverage\tStandard Deviation\n";
					for(int i=0; i<n; i++){
						//cout << (char)('A'+i) << '\t' << ravr[i] << '\t' << rsd[i] << '\n';
						cout << (char)('A'+i) << '\t' << avr[i] << '\t' << sd[i] << '\n';
					}
				}else{
					cout << "Alphabet\tAverage\tStandard Deviation\n";
					for(int i=0; i<n; i++){
						//cout << (char)('A'+i) << '\t' << ravr[i] << "\tN/A\n";
						cout << (char)('A'+i) << '\t' << avr[i] << "\tN/A\n";
					}
				}
			}else{
				cout << "There were only invalid votes.... \n";
			}
		}
	}
	return 0;
}
