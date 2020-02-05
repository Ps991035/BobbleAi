#include<iostream>
#include<fstream>
#include<queue>
#include<sstream>
//#include<bits/stdc++.h>
using namespace std;
fstream print;
fstream scan;
vector<string>v1;
vector<string>v2;
queue<string>queue1;
int main()
{
    scan.open("input.csv",ios::in);//object creation to read a file
    print.open("output.csv",ios::out);// object creation to write a file
    while(!scan.eof())
    {
        string a,b;
        getline(scan,a);
        stringstream ss(a);// reading a line from the file
        string t;

        while(getline(ss,b,','))
        {
            t.push_back(b[0]);
        }
        v2.push_back(t);
    }
   
    for(int i=0;i<v2.size();i++)
    {
        if(i==0)
        {
            for(int j=0;j<v2[i].size();j++)
            {
                string ca;
                ca.push_back(v2[i][j]);//the fist element of queue is added which will be used further to create permutation.
                queue1.push(ca);
            }
        }
        else
        {
            queue<string> queue2;
          while(!queue1.empty())
          {
              string z=queue1.front();
              for(int j=0;j<v2[i].size();j++)
              {
                  z.push_back(v2[i][j]);
                  queue2.push(z);//pushing int the queue the newly made permutations.
                  z.pop_back();
              }
              queue1.pop();
          }
            queue1=queue2;//swapping the queue 
            
        }
    }
    cout<<queue1.size();
    while(!queue1.empty())
    {
        print<<queue1.front();
        if(queue1.size()>1)
        {
            print<<", ";
        }
        queue1.pop();
    }
    
}
