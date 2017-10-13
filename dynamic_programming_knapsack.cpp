//
//  Created by Anurag Singh on 4/22/17.
//  Copyright © 2017 Anurag Singh. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
vector<string> a;

vector<string> read(string filename)
{
    a.clear();
    string line;
    fstream file_(filename.c_str());
    if(file_.is_open())
    {
        while (getline(file_,line))
        {
            a.push_back(line);
        }
    }
    else{
        cout<< "file is not open "<<endl;
    }
    file_.close();
    return a;
    
}

void dynamic(int c, int wi[], int pf[], int ni)
{

    int ks[ni+1][c+1];
    
    for(int i=0;i<=c;i++)
        ks[0][i]=0;
    
    for(int i=1;i<=ni;i++)
    {
        ks[i][0]=0;
        for(int j =1; j <= c; j++)
        {
            
            if(wi[i-1] <= j && (pf[i-1] + ks[i-1][j-wi[i-1]])>ks[i-1][j])
                ks[i][j]=pf[i-1] + ks[i-1][j-wi[i-1]];
            else
                ks[i][j] = ks[i-1][j];
        }
    }

    vector<int> item_c;
    int column= c;
    for(int i=ni;i>0;i--)
    {
    
        if(ks[i][column]!=ks[i-1][column])
        {
        
            int index=i-1;
            item_c.push_back(index);
            column-=wi[index];
        
        }
    
    }
    
    int temp_capacity=0;
    
    for(int i=0;i<item_c.size();i++)
    {
        int temp=wi[item_c[i]];
        temp_capacity+=temp;
    }
    
    cout<<"\nTotal profit: "<<ks[ni][c]<<"\nTotal weight: "<<temp_capacity<<"\n";
    cout<<"\nItems selected:\n";
    for(int i=0;i<item_c.size();i++)
    {
        cout<<"Item"<<item_c[i]+1<<" weight: "<<wi[item_c[i]]<<" profit: "<<pf[item_c[i]]<<"\n";
    }
    
}


int main(int argc, const char * argv[]) {
   
    string filename=argv[1];
    vector<string>a=read(filename);
    
    int no_item=stoi(a[0]);
    int capacity=stoi(a[a.size()-1]);
    int weight[no_item];
    int profit[no_item];
  
    string str1 = a[1];
    vector<int> vect1;
    stringstream ss1(str1);
    int w;
    while (ss1 >> w)
    {
        vect1.push_back(w);
        
        if (ss1.peek() == ',')
            ss1.ignore();
    }
    for(int i=0;i<no_item;i++)
        weight[i]=vect1.at(i);
    
    string str2 = a[2];
    vector<int> vect2;
    stringstream ss2(str2);
    int p;
    while (ss2 >> p)
    {
        vect2.push_back(p);
        
        if (ss2.peek() == ',')
            ss2.ignore();
    }
    for(int i=0;i<no_item;i++)
        profit[i]=vect2.at(i);
    
    
    dynamic(capacity,weight,profit,no_item);
    
    
 
    
}
