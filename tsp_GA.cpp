#include<bits/stdc++.h>
using namespace std;

vector<int>v;
vector<string>chromosome;

map<int,int>m1,m2;
map<int,string>mv;
int mnnx=10000000;

/*int dis[6][6]={{0,2,5,1,4,9},
               {2,0,7,8,3,5},
               {5,7,0,5,6,3},
               {1,8,5,0,7,2},
               {4,3,6,7,0,8},
               {9,5,3,2,8,0}};

*/
int dis[6][6]={{0,863,1987,1407,998,1369},
               {863,0,1124,1012,1049,1083},
               {1987,1124,0,1461,1881,1676},
               {1407,1012,1461,0,2061,2095},
               {998,1049,1881,2061,0,331},
               {1369,1083,1676,2095,331,0}};


int sdis(string s)
{
       int p=0,i;
       for( i=0; i<s.length()-1; i++)
       {
                 int v1=s[i]-'0';
                 int v2=s[i+1]-'0';
                 //cout<<v1<<"to"<<v2<<" "<<dis[v1-1][v2-1]<<endl;
                 p+=dis[v1-1][v2-1];
       }
                int v1=s[i]-'0';
                 int v2=s[0]-'0';
                 //cout<<v1<<"to"<<v2<<" "<<dis[v1-1][v2-1]<<endl;
                 p+=dis[v1-1][v2-1];

          return p;
}
int main()
{
          int a[7],p=0,steps=0;

          srand (time(NULL));
          for(int i=0; i<6; i++)
{
          string s="";
          memset(a,0,sizeof(a));
          for(int j=0; j<6; j++)
          {
            p=(rand()%6)+1;
           while(a[p])
          { p=(rand()%6)+1;
          }
          a[p]++;
          s+=(char)(p+'0');}
          mv[sdis(s)]=s;
          chromosome.push_back(s);

          cout<<s<<" "<<sdis(s)<<endl;

}
int uuu=0;
while(1)
{//mating pool
int mn=10000,p11,p22,mnx=10000;
for(int i=0; i<8; i++)
{
int p1=(rand()%6);
int p2=(rand()%6);
while(p1==p2)
{
p2=(rand()%6);
}

//cout<<p1<<" "<<p2<<endl;
          string s1=chromosome[p1],s2=chromosome[p2];
           mn=min(sdis(s1),sdis(s2));
           mnx=min(mn,mnx);
           if(mnx==sdis(s1))
                    p11=p1;

            else if(mnx=sdis(s2))
                    p11=p2;
}

mn=10000,mnx=10000;
for(int i=0; i<8; i++)
{
int p1=(rand()%6);
while(p1==p11)
p1=(rand()%6);
int p2=(rand()%6);
while(p1==p2 || p2==p11)
{
p2=(rand()%6);
}

//cout<<p1<<" "<<p2<<endl;
          string s1=chromosome[p1],s2=chromosome[p2];
           mn=min(sdis(s1),sdis(s2));
           mnx=min(mn,mnx);
           if(mnx==sdis(s1))
                    p22=p1;

            else if(mnx=sdis(s2))
                    p22=p2;
}

cout<<"parents : "<<chromosome[p11]<<" "<<chromosome[p22]<<endl;

//crossover
for(int i=0; i<6; i++)
{
   m1[chromosome[p11][i]-'0']=i;
   m2[chromosome[p22][i]-'0']=i;
}

vector<int>e[1000];
for(int i=1; i<=6; i++)
{
          //int p=chromosome[p11][i]-'0';
          int ind2=m2[i],ind1=m1[i];
          //cout<<ind1<<" "<<ind2<<endl;
          int in11=ind1-1,in12=ind1+1,in21=ind2-1,in22=ind2+1;
         if(ind1==0)
          in11=5;
         else if(ind1==5)
          in12=0;
         if(ind2==0)
          in21=5;
         else if(ind2==5)
          in22=0;

          int v1=chromosome[p11][in11]-'0',v2=chromosome[p11][in12]-'0';
          int u1=chromosome[p22][in21]-'0',u2=chromosome[p22][in22]-'0';
          //cout<<v1<<" "<<v2<<" "<<u1<<" "<<u2<<endl;

           if(v1!=i &&(v1==u1||v1==u2 ))
                    e[i].push_back(-v1);
           else if(v1!=i)
                    e[i].push_back(v1);

          if(v2!=i &&(v2==u1||v2==u2))
                    e[i].push_back(-v2);
           else if(v2!=i)
                    e[i].push_back(v2);
           if(u1!=v1 && u1!=v2 && u1!=i)
                    e[i].push_back(u1);

                      if(u2!=v1 && u2!=v2 && u2!=i)
                    e[i].push_back(u2);

}


/*for(int i=1; i<=6; i++)
{         cout<<i<<" ";
          for(int j=0; j<e[i].size(); j+=1)
                    cout<<e[i][j]<<" ";
          cout<<endl;
}*/

string nch="";
int j,o;
memset(a,0,sizeof(a));
for( j=0; j<e[1].size(); j++)
     { o=e[1][j];
     //cout<<o<<endl;
      if(o<0)
      {
                nch+=char ((-1)*o+'0');
                o=-o;
                a[o]++;
                break;
      }
     }
int b=0;
//cout<<j<<e[1].size()<<endl;
if(j==e[1].size())
{
          o=e[1][b];
          while(a[o])
           {b++;
           o=e[1][b];
           }
          a[o]++;
 nch+=char (o+'0');


}

//cout<<nch<<" "<<o<<endl;

int k=0;
while(k<5)
{
 for( j=0; j<e[o].size(); j++)
     {int oo=e[o][j];
     //cout<<oo<<" "<<a[-oo]<<endl;
     if(a[-oo])
          continue;
      if(oo<0)
      {
                nch+=char ((-1)*oo+'0');
                o=-oo;
                a[o]++;
                break;
      }
     }
     //cout<<"j= "<<j<<"s= "<<e[o].size()<<endl;
      if(j==e[o].size())
      {
                b=0;
                int oo=e[o][b];
                while(a[oo])
                    {b++;
                    oo=e[o][b];
                    }
                    o=oo;
                    nch+=char (o+'0');
                    a[o]++;

      }


          k++;
}
cout<<nch<<endl;
int indx=rand()%6;
chromosome[indx]=nch;
mv[sdis(nch)]=nch;

//mutation

int pro=rand()%100;

if(pro==20)
{     cout<<"\n\nmutation\n\n";
          int innd=rand()%6;
          cout<<"chrom= "<<chromosome[innd]<<endl;
          int f1=rand()%6;
          cout<<"f1 "<<f1<<endl;
          int f2=rand()%6;
          while(f1==f2)
            f2=rand()%6;
            cout<<"f2 "<<f2<<endl;
            int c=chromosome[innd][f1]-'0';
            chromosome[innd][f1]=chromosome[innd][f2];
            chromosome[innd][f2]=c+'0';
            cout<<"chrom= "<<chromosome[innd]<<endl;
}

cout<<"\n\n";
//for(int i=0; i<chromosome.size(); i++)
//          cout<<chromosome[i]<<endl;

int mnn=1000000;

for(int i=0; i<chromosome.size();i++)
{
          mnn=min(mnn,sdis(chromosome[i]));
}
cout<<"mnn= "<<mnn<<" ch= "<<mv[mnn]<<endl;
if(mnnx==mnn)
uuu++;
else
          uuu=0;
mnnx=min(mnnx,mnn);
cout<<"steps= "<<steps<<" mnnx= "<<mnnx<<" ch= "<<mv[mnnx]<<endl;


if(uuu>2000)
          break;
steps++;
}
cout<<"mnnx= "<<mnnx<<" ch= "<<mv[mnnx]<<endl;

//minimum=6341
}


