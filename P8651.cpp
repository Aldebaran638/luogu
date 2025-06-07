#include<bits/stdc++.h> 
#define ll long long
//1.devc++编译器不接受stoi,to_string等函数.所以如果要写字符串和数字混合的题,建议全部转化为字符串(如本题),非必要不转整数
//2.思路一定要正确再写.思路混乱(本来就应该想到这道题不可能那么难)就别下笔,最好过一会来再写
//3. 注意重复情况!交代码前考虑重复情况是否会影响样例 
using namespace std;

string date[3];
string md[13]={"00","31","29","31","30","31","30","31","31","30","31","30","31"};

int stoint(string s){
	int result=0;
	for(int i=0;i<s.size();i++){
		result+=(int)(s[i]-'0')*pow(10,s.size()-1-i);
	}
	return result;
}

bool isrun(string _num){
	int num=stoint(_num);
	if((num%4==0&&num%100!=0)||num%400==0){
		return true;
	}
	else{
		return false;
	}
}
void changemd(string y){
	if(isrun(y))
		md[2]="29";
	else
		md[2]="28";
}

string changetoy(string s){
	if(s>="60"){
		return "19"+s;
	}
	else{
		return "20"+s;
	}
}

set<string> result;

int main(){
#ifndef ONLINE_JUDGE 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif	
	for(int i=0;i<2;i++){
		date[0]+=getchar();
	}
	getchar();
	for(int i=0;i<2;i++){
		date[1]+=getchar();
	}
	getchar();
	for(int i=0;i<2;i++){
		date[2]+=getchar();
	}
	changemd(changetoy(date[0]));
	if((date[1]<="12"&&date[1]>="01")&&(date[2]>="01"&&date[2]<=md[stoint(date[1])])){
		result.insert((changetoy(date[0])+'-'+date[1]+'-'+date[2]+'\n'));
	}
	changemd(changetoy(date[2]));
	if((date[0]<="12"&&date[0]>="01")&&(date[1]>="01"&&date[1]<=md[stoint(date[0])])){
		result.insert((changetoy(date[2])+'-'+date[0]+'-'+date[1]+'\n'));
	}	
	changemd(changetoy(date[2]));
	if((date[1]<="12"&&date[1]>="01")&&(date[0]>="01"&&date[0]<=md[stoint(date[1])])){
		result.insert((changetoy(date[2])+'-'+date[1]+'-'+date[0]+'\n'));
	}
	
	for(set<string>::iterator i=result.begin();i!=result.end();i++){
		cout<<*i;
	}
}
