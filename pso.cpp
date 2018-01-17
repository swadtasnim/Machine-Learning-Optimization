#include <bits/stdc++.h>

using namespace std;


vector<double>particle,pbest,V;
double gbest;

double fit(double x)
{
    return -(x*x)+5;

}

int main()
{
    srand(time(NULL));
    double c1=rand()%4;

    int c=4-c1;
    cout<<c<<endl;
    double c2=rand()%c;
    cout<<(double)c1<<" "<<(double)c2<<endl;
    cout<<"Enter particle number: ";
    int n;
    cin>>n;
    gbest=INT_MAX;
    for(int i=0; i<n; i++)
    {
     int r=rand()%100;
     particle.push_back(r);
     pbest.push_back(r);
     if(fit(gbest)<fit(pbest[i]))
          gbest=pbest[i];
     V.push_back(rand()%40);

    }

    //sort(pbest.begin(),pbest.end());
    //gbest=pbest[pbest.size()-1];
    cout<<"current gbest = "<<gbest<<endl;
    int h;
    cout<<"Press 1\n";
    cin>>h;
 int u=0;
 double g=gbest;
    for(int j=0; 1; j++)
    {
              if(u>200)
                    break;
        for(int i=0; i<n; i++)
        {

            if(fit(particle[i])>fit(pbest[i]))
            {  //cout<<pbest[i]<<" "<<particle[i]<<endl;
                pbest[i]=particle[i];
            }
            if(fit(gbest)<fit(pbest[i]))
                    gbest=pbest[i];


    //sort(pbest.begin(),pbest.end());
    //gbest=pbest[pbest.size()-1];

    int i1=rand()%100,i2=rand()%100;
    double r1=(double)i1/100;
    double r2=(double)i2/100;
    //cout<<(double)i1/100<<" "<<(double)i2/100<<endl;

            V[i]=(int)(V[i]+c1*r1*(pbest[i]-particle[i])+c2*r2*(gbest-particle[i]));
            particle[i]=particle[i]+V[i];}
             if(g!=gbest)
                    {g=gbest;
                     u=0;
                    }
              else
                    u++;
           // cout<<"current gbest = "<<gbest<<endl;

            for(int i=0; i<n; i++)
            {
                      cout<<particle[i]<<" "<<pbest[i]<<endl;
            }

        cout << "step:  "<<j<<endl;
        cout << "gbest= "<<gbest<<" fitness= "<<fit(gbest)<<endl;
        //cout << gbest<<endl;
        cout<<endl;

    }
    cout <<"final gbest "<< gbest<<endl;
    cout <<"final fitness  "<< fit(gbest);
    return 0;

}
