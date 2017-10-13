//
//  Created by Anurag Singh on 5/1/17.
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


int main(int argc, const char * argv[])
{

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

 
  
    
    for(int i=0;i<no_item;i++)
    {
        cout<<"Item "<<i+1<<" Weight: "<<weight[i]<<" Profit: "<<profit[i]<<endl;
    }
    
    
    return 0;
}



