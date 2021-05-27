#include <bits/stdc++.h>
using namespace std;
#define pb push_back
map<int,vector<pair<int,int > > >mp;
int a[1000][1000];
int visted[10000];
int sum;
void tsp(int city)
{
    cout<<"city"<<city<<"->"<<" ";
  visted[city]=1;
  int minm=1e9;
  int index=-1;
  vector<pair<int,int> >z=mp[city];
  for(int i=0;i<z.size();i++)
  {
  	  pair<int,int>x= z[i];
      if(visted[x.first]==0&&x.second<minm)
      {
          minm=x.second;
          index=x.first;
      }
  }
  
  if(index==-1)
  {
      //cout<<"k"<<" ";
      sum+=a[city][0];
      return;
  }
  else 
  {
      //cout<<"pp"<<" ";
      sum+=a[city][index];
  }
  tsp(index);
}
int main()

  {
	 int t=1;
    
   
    while(t--)
    {
   cout<<"ENTER NUMBER OF CITIES"<<"\n";
   int n;
   cin>>n;
  
   
   string s;
   vector<int>v;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
       	   cout<<"ENTER DISTANCE B/W CITIES "<<i+1<<" "<<j+1<<"\n";
           cin>>a[i][j];
          mp[i].push_back({j,a[i][j]});
          mp[j].push_back({i,a[i][j]});
       }
   }
   cout<<"THE TOUR IS"<<"\n";
   tsp(0);
   cout<<"\n";
   cout<<"COST OF TOUR IS"<<"\n";
   cout<<sum<<"\n";
   
   }
}

