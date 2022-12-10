#include<bits/stdc++.h>

using namespace std;



bool check(string x,string y) {
	string newx,newy=""; // convert the cuurent strings into new strings
	for(int i=0; i<y.size(); ) {        // if the string y has "oo" or "ee" or "y", change it to "u", "i", and "i" respectively
		if(i<y.size()-1 && y[i]=='o' && y[i+1]=='o') {
			newy+='u';
			i+=2;
		}
		else if(i<y.size()-1 && y[i]=='e' && y[i+1]=='e') {
			newy+='i';
			i+=2;
		}
		else if(y[i]=='y') {
			newy+='i';
			i++;
		}
		else {
			newy+=y[i];
			i++;
		}
	}
	for(int i=0; i<x.size(); ) {   // similarly for the string x
		if(i<x.size()-1 && x[i]=='o' && x[i+1]=='o') {
			newx+='u';
			i+=2;
		}
		else if(i<x.size()-1 && x[i]=='e' && x[i+1]=='e') {
			newx+='i';
			i+=2;
		}
		else if(x[i]=='y') {
			newx+='i';
			i++;
		}
		else {
			newx+=x[i];
			i++;
		}
	}
	if(newx.size()!=newy.size()) {
		return false;
	}
	for(int i=0; i<newx.size(); i++) {
		if(newx[i]!=newy[i]) {
			return false;
		}
	}
	return  true;
}







int main() {
	string word; // given word of which the phonetic combinations are to be found
	int N; // number of words in the file
	vector<string> words;
	cin>>N;
	for(int i=0; i<N; i++) {
		string temp;
		cin>>temp;
		words.push_back(temp);
	}
	cin>>word;
	for(int i=0; i<N; i++) {
		if(check(word,words[i])) {
			cout<<words[i]<<endl;
		}
	}
	return 0;
}
