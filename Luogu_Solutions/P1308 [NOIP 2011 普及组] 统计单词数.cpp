#include<bits/stdc++.h>
using namespace std;
bool judgement(string a,string b){
	if(a.length()!=b.length()){
		return 0;
	}else{
		for(int j=0;j<a.length();j++){
			if(tolower(a[j])!=tolower(b[j])){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	string str,article,word_now;
	int count=0,firstpos=-1,leng=0;
	
	getline(cin,str);
	getline(cin,article);
	for(int i=0;i<=article.length();i++){
		if(article[i]==' '||i==article.length()){
			if(judgement(word_now,str)){
				count++;
				if(firstpos==-1){
					firstpos=leng;
				}
			}
			leng+=(word_now.length()+1);
			word_now.clear();
		}
		else{
			word_now+=article[i];
		}
	}
	if(count==0){
		cout<<-1<<endl;
	}else{
		cout<<count<<' '<<firstpos<<endl;
	}	
	return 0;
}
/*
To
to be or not to be is a question
*/