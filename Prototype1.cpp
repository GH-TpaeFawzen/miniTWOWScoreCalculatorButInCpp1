#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define invalid -1

//This chooses what do you do with votes with same characters twice or three times.
enum Option{
	Invalid = 0,
	Highest = 1,
	Lowest = 2,
};

string invRemover(string s, char last);
string remover(string s, char l, Option o, int n);
bool dChecker(string s);
//bool valchecker(string s, Option o);

//removes invalid characters
string invRemover(string s, char last){
	cout << s << endl;	//DeBuG
	int i=0;
	while(i<s.length()){
		if(s[i]<'A'||last<s[i])	s.erase(i, 1);
		else i++;
	}
	cout << s << endl;	//DeBuG
	return s;
}

//removes double characters depends on option
string remover(string s, char l, Option o, int n){
	s=invRemover(s, l);
	if(s.empty())	return s;
	
	if(o==Invalid)	return (dChecker(s))?"":s;
	
	bool alS[n] = {false};	//stands for "already seen"
	if(o==Highest){
		//Only the highest one will alive!
		int i=0;
		do{
			//DeBuG Below
			cout << s << endl;
			for(int j=0; j<i; j++)
				cout << ' ';
			cout << '^' << endl;
			
			if(alS[s[i]-'A']){
				s.erase(i,1);
			}else{
				alS[s[i]-'A']=true;
				i++;
			}
			cout << s << endl;	//DeBuG
		}while(i<s.length());
	}else{
		//Only the lowest one will alive!
		int i=s.length()-1;
		do{
			//DeBuG Below
			cout << s << endl;
			for(int j=0; j<i; j++)
				cout << ' ';
			cout << '^' << endl;
			
			if(alS[s[i]-'A']){
				s.erase(i,1);
				i--;
			}else{
				alS[s[i]-'A']=true;
				i--;
			}
			cout << s << endl;	//DeBuG
		}while(i>=0);
	}
	
	return s;
}

//judges if it contains some same characters
bool dChecker(string s){
	stable_sort(s.begin(), s.end());
	cout << s << endl;	//DeBuG
	for(int i=0; i<s.length()-1; i++)
		if(s[i]==s[i+1])	return true;
	return false;
}

/*
//judges if the vote is valid
bool valchecker(string s, Option o){
	if(s.empty())	return false;
	else if(o==Invalid)	return !(dChecker(s));
	else	return true;
}
*/

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
			int optnum;
			do{
			cout << "What do you do with votes having same characters twice?\nInput 0 to make them invalid.\nInput 1 to count the highest one.\nInput 2 to count the lowest one.\n :";
			cin >> optnum;
			if(0>optnum&&optnum>2)
				cout << "That's a valid input!\n\n";
			}while(0>optnum&&optnum>2);
			Option option=(Option)optnum;
			
			
			cout << "From now, you must input all the votes. You must separate each vote by space.\n";
			//double r[v][n]={0};	//mini-ranks
			double ms[v][n]={0};	//mini-scores
			unsigned valids = 0;	//how many valid votes?
			
			const char lc = 'A' + n - 1;	//Last character on voting screen.
			//Below Here:gets votes and record placement.
			for(int i=0; i<v; i++){
				string s;
				cin >> s;
				
				//CAPITALIZATION!
				transform(s.begin(), s.end(), s.begin(), ::toupper);
				
				//Removes invalid chars.
				//s = remover(s, lc);
				s = remover(s, lc, option, n);
				
				//Here is the new version!
				if(s.empty()){
					//INVALID VOTE!
					cout << "An invalid vote got input.\n";
					for(int j=0; j<n; j++)
						ms[i][j]=invalid;
				}else{
					//VALID VOTE
					valids++;
					const double unranked = (s.length()+1+n)/2.0;
					cout << unranked << endl;	//DeBuG
					for(int j=0; j<n; j++){
						int tmp = s.find('A'+j);
						ms[i][j]=(tmp==string::npos)?unranked:(n-tmp-1.0)*100.0/(n-1.0);
					}				
				}
				
				//It's getting messed up!
				/*
				if(valchecker(s, option)){
					//VALID VOTE
					const double unranked = (s.length()+1+n)/2.0;
					cout << unranked << endl;	//DeBuG
					
					if(!(dChecker(s))){
						for(int j=0; j<n; j++){
							int tmp = s.find('A'+j);
							//r[i][j]=(tmp==string::npos)?unranked:tmp+1;
							ms[i][j]=(tmp==string::npos)?unranked:(n-tmp-1.0)*100.0/(n-1.0);
						}
					}else{
						bool alreadySeen[n]={false};
						//If:Highest, from top to bottom
						//If:Lowest, from bottom to top
						if(option==Highest){
							int j=0;
							do{
								//前からカウントただし一度出たものがあれば次の文字を見る
								s[j];
								j--;
							}while();
							
						}else{
							int j=n-1;
							do{
								//後ろからカウントただし一度出たものがあれば前の文字を見る
								//でもこの場合は未投票の文字はどうしよう
								//とりあえずどれが未投票なのかを全部探してから投票されたものを順位付けるのはどうだろうか
								j--;
							}while();
						}
					}
					valids++;
				}else{
						cout << "An invalid vote got input.\n";
						//INVALID!
						for(int j=0; j<n; j++)
							//r[i][j]=invalid;
							ms[i][j]=invalid;
				}
				*/
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
					avr[i]=sum/valids;
				}
					cout << "Copy and paste the following text to your spreadsheet:\n";
					if(valids>1){
						//ravr[i]=sum/valids;
						
						
						double sum0=0;
						for(int i=0; i<n; i++){
							for(int j=0; j<v; j++){
								//sum0+=(r[j][i]==invalid)?0:r[j][i]*r[j][i]-ravr[i]*ravr[i];
								sum0+=(ms[j][i]==invalid)?0:ms[j][i]*ms[j][i]-avr[i]*avr[i];
							}
							sd[i]=sqrt(sum0/valids);
						}
						
						//Below Here:result by character
						cout << "Alphabet\tAverage\tStandard Deviation\n";
						for(int i=0; i<n; i++){
							//cout << (char)('A'+i) << '\t' << ravr[i] << '\t' << rsd[i] << '\n';
							cout << (char)('A'+i) << '\t' << avr[i] << '\t' << sd[i] << '\n';
						}
					}else{
						//Below Here:result by character
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
