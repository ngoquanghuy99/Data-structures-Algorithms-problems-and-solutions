#include<bits/stdc++.h>

using namespace std;

void trunghieu()
{
	string s;
	cin>>s;
	while(!s.empty())
	{
		int flag = 0;
		for(int i = 0;i<s.size() - 1;i++)
			if(s[i] == s[i+1])
			{
				flag = 1;
				s.erase(i,2);
				break;
			}
		if(!flag)
			break;
	}
	if(!s.empty())
		cout<<s;
	else cout<<"Empty String";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	trunghieu();
	return 0;
}