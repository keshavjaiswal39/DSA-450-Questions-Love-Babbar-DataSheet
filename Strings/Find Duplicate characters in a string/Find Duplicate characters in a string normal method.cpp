#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	string name;
	
	int i=0,j=0,len,count=1;
	
	cin>>name;
	
	len=name.size();
	
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(name[j]!=0)
			{
				
				if(name[i]==name[j])
				{
					count++;
					name[j]=0;
				}
		    }
        }
        
        if(count>1)
        {
			cout<<name[i]<<"->"<<count<<endl;
			count=1;
		}
	}
}
