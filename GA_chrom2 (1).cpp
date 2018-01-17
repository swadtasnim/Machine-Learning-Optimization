#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<string>chromosome;
map<int,string>m;
map<int,int>cont,cont2;

int fun(int v)
{
          return -(v*v)+9;
}

int sTi(string s)
{
          int i=s.length()-1,p=0,k=0;
          for(int j=i; j>=0; j--)
                    {  if(s[k]=='1')
                              p+=pow(2,j);
                     //cout<<pow(2,j)<<" ";
                     k++;
                    }

          return p;
}
int main()
{

for(int i=0; i<4; i++)
{
          string s="";

          for(int j=0; j<7; j++)
          {int p=rand()%2;
          s+=(char)(p+'0');}
          chromosome.push_back(s);
          cout<<s<<endl;
          m[sTi(s)]=s;
}
cout<<"\n\n\n";
for(int i=0; i<chromosome.size(); i++)
          cout<<chromosome[i]<<endl;



  for(int i=0; i<chromosome.size(); i++)
          v.push_back(sTi(chromosome[i]));
  for(int i=0; i<v.size(); i++)
          cout<<v[i]<<endl;


cout<<"\n\n\n";
for(int i=0; i<chromosome.size(); i++)
          cout<<m[v[i]]<<endl;
cout<<"\n\n\n";

int mx=INT_MIN,gmx=INT_MIN;
int hhh=0,jjj=0,u=mx;
while(1)
//select

{vector<int>vv;
map<int,int>vvv;
for(int i=0; i<4; i++)
{
          vv.push_back(fun(v[i]));
          vvv[fun(v[i])]=v[i];

}

sort(vv.begin(),vv.end());
mx=max(mx,vv[vv.size()-1]);

gmx=vvv[vv[vv.size()-1]];
cout<<"gmx= "<<gmx<<" mx= "<<mx<<endl;

int sv1=vvv[vv[vv.size()-1]],sv2=vvv[vv[vv.size()-2]];
cout<<sv1<<" "<<sv2<<endl;
string ss1=m[sv1],ss2=m[sv2];
cout<<ss1<<" "<<ss2<<endl;

//crossover
int point=rand()%(ss1.size()-2);
while(!point)
point=rand()%(ss1.size()-2);
          string sub1=ss1.substr(0,point);
          string sub2=ss2.substr(0,point);
          string sub3=ss1.substr(point);
          string sub4=ss2.substr(point);

          cout<<ss1<<" "<<ss2<<" "<<sub1<<" "<<sub2<<" "<<sub3<<" "<<sub4<<endl;
          ss1=sub2+sub3;
          ss2=sub1+sub4;
          cout<<ss1<<" "<<ss2<<" "<<sub1<<" "<<sub2<<" "<<sub3<<" "<<sub4<<endl;
          m[sTi(ss1)]=ss1;
          cout<<sTi(ss1)<<endl;
          m[sTi(ss2)]=ss2;
          cout<<sTi(ss2)<<endl;
          for(int i=0; i<4; i++)
          {
                    if(v[i]==vvv[vv[0]])
                    {v[i]=sTi(ss1);
                    break;
                    }
          }

                    for(int i=0; i<4; i++)
          {
                    if(v[i]==vvv[vv[1]])
                    {v[i]=sTi(ss2);
                    break;
                    }
          }
cout<<"\n\n\n";
          for(int i=0; i<4; i++)
                    cout<<v[i]<<endl;


//mutation
int rr=rand()%50;
cout<<"rr= "<<rr<<endl;
if(rr==24)
{
    int ppp1=rand()%4;
    int ind=rand()%7;


    string ssss1=m[v[ppp1]];
    cout<<ssss1<<endl;
    if(ssss1[ind]=='0')
        ssss1[ind]='1';
    else
        ssss1[ind]='0';
    cout<<ssss1<<" "<<sTi(ssss1)<<endl;
    v[ppp1]=sTi(ssss1);
    m[v[ppp1]]=ssss1;
}


cout<<"\n\n\n";
          for(int i=0; i<4; i++)
                    cout<<v[i]<<endl;

cout<<"step: "<<hhh<<endl;
cout<<"gmx= "<<gmx<<" mx= "<<mx<<endl;

if(mx!=u)
{
u=mx;
jjj=0;

}
else
    jjj++;

if(jjj>500)
    break;
                    hhh++;
                    }



}
