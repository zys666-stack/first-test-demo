//读取输入的数据，根据小数点分块，比较大小，由小到大排序

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string &a,string &b){
    int i=0,j=1;
    int total_a[101]={0};
    int total_b[101]={0};
    while(i<a.size()){
        while(i < a.size() && a[i]!='.'){
            total_a[j]=10*(total_a[j-1]) + (a[i]-'0');
            i++;
        }
        j++;
        if(i < a.size()){
            i++;
        }
    }
    i=0,j=1;
    while(i<b.size()){
        while(i < b.size() && b[i]!='.'){
            total_b[j]=10*(total_b[j-1]) + (b[i]-'0');
            i++;
        }
        j++;
        if(i < b.size()){
            i++;
        }
    }
    for(int k=1;k<101;k++){
        if(total_a[k]>total_b[k]){
            return false;
        }
        if(total_a[k]<total_b[k]){
            return true;
        }
    }
    return false;
}

int main()
{
    string q;
    vector<string> a;
    string b;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    for(int s=a.size()-1;s>0;s--){
        for(int d=0;d<s;d++){
            if(!(compare(a[d],a[d+1]))){
                q=a[d];
                a[d]=a[d+1];
                a[d+1]=q;
            }
        }
    }
    for(int k=0;k<a.size();k++)
        cout<<a[k]<<endl;
    system("pause");
    return 0;
}