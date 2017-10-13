
//
//  Created by Anurag Singh on 4/30/17.
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
 // Max Profit Starts//
void max_profit(int capacity, int weight[], int profit[], int no_item)
{
   
    int temp_weight1[no_item];
    int temp_profit1[no_item];
    
    for (int i=0;i<no_item;i++)
    {
        temp_weight1[i]=weight[i];
        temp_profit1[i]=profit[i];
        
    }
    for(int i=0; i<no_item; i++)
    {
        for(int j=i+1; j<no_item; j++)
        {
            if(temp_profit1[i]<temp_profit1[j])
            {
                int temp=temp_profit1[j];
                temp_profit1[j]=temp_profit1[i];
                temp_profit1[i]=temp;
                
                int temp1=temp_weight1[j];
                temp_weight1[j]=temp_weight1[i];
                temp_weight1[i]=temp1;
                
            }
        }
        
    }
    
    int temp_capacity1=0;
    int counter1=0;
    vector<int> dis1;
    while(true)
    {
        
        if(capacity < temp_capacity1)
        {
            
            break;
        }else
        {
            temp_capacity1+=temp_weight1[counter1];
            for(int i=0;i<no_item;i++)
            {
                if(temp_weight1[counter1]==weight[i])
                {
                    dis1.push_back(i);
                }
            }
            counter1++;
        }
        
    }
    temp_capacity1-=temp_weight1[--counter1];
    
    int final_profit1=0;
    for(int i=0;i<dis1.size()-1;i++)
    {
        final_profit1+=profit[dis1[i]];
    }
    cout<<"/****** Max Benefit First ******/ \n\n";
    cout<<"Total profit: "<<final_profit1<<"\nTotal weight: "<<temp_capacity1<<"\n";
    cout<<"\nItems selected:\n";
    for(int i=0;i<dis1.size()-1;i++)
    {
        cout<<"Item"<<dis1[i]+1<<" weight: "<<weight[dis1[i]]<<" profit: "<<profit[dis1[i]]<<"\n";
    }
    cout<<"\n\n";
    
  

}
  // Max Profits End//

  //  MIN WEIGHT FIRST  starts //
void min_weight(int capacity, int weight[], int profit[], int no_item)
{
  
    
    int temp_weight2[no_item];
    int temp_profit2[no_item];
    
    for (int i=0;i<no_item;i++)
    {
        temp_weight2[i]=weight[i];
        
        temp_profit2[i]=profit[i];
        
    }
    
    for(int i=0; i<no_item; i++)
    {
        for(int j=i+1; j<=no_item-1; j++)
        {
            if(temp_weight2[i]>temp_weight2[j])
            {
                int temp=temp_weight2[j];
                temp_weight2[j]=temp_weight2[i];
                temp_weight2[i]=temp;
            }
        }
        
    }
    
    int temp_capacity2=0;
    int counter2=0;
    vector<int> dis2;
    
    while(true)
    {
        
        if(capacity < temp_capacity2)
        {
            
            break;
        }else
        {
            temp_capacity2+=temp_weight2[counter2];
            for(int i=0;i<no_item;i++)
            {
                
                if(temp_weight2[counter2]==weight[i])
                {
                    dis2.push_back(i);
                    
                }
            }
            counter2++;
        }
        
    }
    temp_capacity2-=temp_weight2[--counter2];
    
    int final_profit2=0;
    for(int i=0;i<dis2.size()-1;i++)
    {
        final_profit2+=profit[dis2[i]];
    }
    cout<<"/****** Min Weight First ******/ \n\n";
    cout<<"Total profit: "<<final_profit2<<"\nTotal weight: "<<temp_capacity2<<"\n";
    cout<<"\nItems selected:\n";
    for(int i=0;i<dis2.size()-1;i++)
    {
        cout<<"Item"<<dis2[i]+1<<" weight: "<<weight[dis2[i]]<<" profit: "<<profit[dis2[i]]<<"\n";
    }
    
    cout<<"\n\n";
    
    
    
    
}
// Min weight first end's//

// Max weight first start //
void max_weight(int capacity, int weight[], int profit[], int no_item)
{
    
    
    int temp_weight3[no_item];
    int temp_profit3[no_item];
    
    for (int i=0;i<no_item;i++)
    {
        temp_weight3[i]=weight[i];
        temp_profit3[i]=profit[i];
        
    }
    
    for(int i=0; i<no_item; i++)
    {
        for(int j=i+1; j<no_item; j++)
        {
            if(temp_weight3[i]<temp_weight3[j])
            {
                int temp=temp_weight3[j];
                temp_weight3[j]=temp_weight3[i];
                temp_weight3[i]=temp;
            }
        }
        
    }
    
    int temp_capacity3=0;
    int counter3=0;
    vector<int> dis3;
    
    while(true)
    {
        
        if(capacity < temp_capacity3)
        {
            
            break;
        }else
        {
            temp_capacity3+=temp_weight3[counter3];
            for(int i=0;i<no_item;i++)
            {
                if(temp_weight3[counter3]==weight[i])
                {
                    dis3.push_back(i);
                }
            }
            counter3++;
        }
        
    }
    
    
    temp_capacity3-=temp_weight3[--counter3];
    int final_profit3=0;
    
    for(int i=0;i<dis3.size()-1;i++)
    {
        final_profit3+=profit[dis3[i]];
    }
    cout<<"/****** Max Weight First ******/ \n\n";
    cout<<"Total profit: "<<final_profit3<<"\nTotal weight: "<<temp_capacity3<<"\n";
    cout<<"\nItems selected:\n";
    for(int i=0;i<dis3.size()-1;i++)
    {
        cout<<"Item"<<dis3[i]+1<<" weight: "<<weight[dis3[i]]<<" profit: "<<profit[dis3[i]]<<"\n";
    }
    cout<<"\n\n";
    
    
    
}
// Max weight first ends //

//MAX BBENIFIT PER UNIT ITEM START//


void per_unit(int capacity, int weight[], int profit[], int no_item)
{
    
    int temp_weight4[no_item];
    int temp_profit4[no_item];
    int per_item4[no_item];
    
    for (int i=0;i<no_item;i++)
    {
        temp_weight4[i]=weight[i];
        temp_profit4[i]=profit[i];
        per_item4[i]=temp_profit4[i]/temp_weight4[i];
    }
    
    
    
    
    for(int i=0; i<no_item; i++)
    {
        for(int j=i+1; j<no_item; j++)
        {
            if(per_item4[i]<per_item4[j])
            {
                int temp=temp_profit4[j];
                temp_profit4[j]=temp_profit4[i];
                temp_profit4[i]=temp;
                
                int temp1=temp_weight4[j];
                temp_weight4[j]=temp_weight4[i];
                temp_weight4[i]=temp1;
                
                int temp2=per_item4[j];
                per_item4[j]=per_item4[i];
                per_item4[i]=temp2;
                
                
            }
        }
        
    }
    
    
    int temp_capacity4=0;
    int counter4=0;
    
    vector<int> dis4;
    
    while(true)
    {
        
        if(capacity < temp_capacity4)
        {
            
            break;
        }else
        {
            temp_capacity4+=temp_weight4[counter4];
            for(int i=0;i<no_item;i++)
            {
                if(temp_weight4[counter4]==weight[i])
                {
                    dis4.push_back(i);
                }
            }
            counter4++;
        }
        
    }
    
    
    temp_capacity4-=temp_weight4[--counter4];
    
    int final_profit4=0;
    
    for(int i=0;i<dis4.size()-1;i++)
    {
        final_profit4+=profit[dis4[i]];
    }
    cout<<"/****** Max Benefit Per Unit Item ******/\n\n";
    cout<<"Total profit: "<<final_profit4<<"\nTotal weight: "<<temp_capacity4<<"\n";
    cout<<"\nItems selected:\n";
    for(int i=0;i<dis4.size()-1;i++)
    {
        cout<<"Item"<<dis4[i]+1<<" weight: "<<weight[dis4[i]]<<" profit: "<<profit[dis4[i]]<<"\n";
    }
    
    
}
// MAX BBENIFIT PER UNIT ITEM ENDS//

int main(int argc, char * argv[])
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
    
    max_profit(capacity,weight,profit,no_item);
    min_weight(capacity,weight,profit,no_item);
    max_weight(capacity,weight,profit,no_item);
    per_unit(capacity,weight,profit,no_item);
    

    return 0;
}
