// 2. 逻辑小岛
// 题目描述 在逻辑岛上住着N (N≤10) 个人, 编号为 (1∼N). 每个人是如下两种类型之一:
// 诚实者: 永远说真话;说谎者: 永远说假话.
// 某一天, 他们排成一排, 每个人各说了一句话. 每句话都只讨论部分人, 形式如下: “在我提到的这些人
//  (允许包括自己) 中, 说真话的人 至少/至多/恰好 有 (k) 个.”
// 你的任务是判断: 根据所有人的发言, 是否能够确定每个人究竟是在说真话还是在说假话. 你需要输出:
// 若不存在任何一种真假话情况能让所有人的发言成立, 输出 Impossible;
// 若存在多种可能情况都能符合条件, 输出 Ambiguous;
// 若恰好只有一种符合条件的情况, 则输出一个长度为 N 的字符串表示结果:
// 如果第 i 个字符为 T 表示第 (i) 个人说真话;
// 如果第 i 个字符为 L 表示第 (i) 个人说假话. 示例: LTTT 表示 1 号说假话、2/3/4 号说真话.
// 输入描述 输入从标准输入读取. 每组测试数据包含多个测试用例.
// 第一行包含一个正整数 T (T≤10), 表示测试用例个数.
// 第二行包含一个正整数 N (N≤10), 表示岛上的人数 (后续每个测试用例中岛上均有 N 人)
// 随后给出 T 个测试用例. 每个测试用例包含 N 行描述, 第 i 行表示第 i 个人的发言, 格式为:
// op k m x1 x2 ... xm,各字段含义:
// op为一个字符, 表示比较类型, 只可能为g, l, e三类之一:g 表示“至少” (大于等于)l 表示“至多” (小于等于);
// e 表示“恰好” (等于).
// k为一个整数, 表示比较值; m为一个整数, 表示提到的人的数量. 保证 0≤k≤m≤Nx1..xm为 m个整数, 表示被提到
// 人的编号 (互不重复), 且 1≤xj≤N.例如: g 2 3 1 3 5 表示: 在 1、3、5 号中, 至少有 2个人在说真话.
// 输出描述 共输出 T行, 每行一个字符串, 对应该测试用例的答案: Impossible / Ambiguous / 或唯一确定的 T/L 串.
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct word{
    char m;
    int compare;
    int people;
    int man[10]; 
};

bool examine(word t,int j){
    bool k=false;
    if(t.m=='g'){
        int num=0;
        for(int i=0;i<t.people;i++){
            if((j>>(t.man[i]-1))&1) num++;
        }
        if(num>=t.compare) k=true;
    }
    if(t.m=='l'){
        int num=0;
        for(int i=0;i<t.people;i++){
            if((j>>(t.man[i]-1))&1) num++;
        }
        if(num<=t.compare) k=true;
    }
    if(t.m=='e'){
        int num=0;
        for(int i=0;i<t.people;i++){
            if((j>>(t.man[i]-1))&1) num++;
        }
        if(num==t.compare) k=true;
    }
    return k;
}

//输入一个数字，输出相应的字符串
void change(int i,int n){
    for(int p=0;p<n;p++){
        if((i>>p)&1) cout<<"T";
        else cout<<"L";
    }
}

int main()
{
    int answer[10];
    int special[10];
    word person[10];
    int t,n;
    cin>>t>>n;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            cin>>person[j].m>>person[j].compare>>person[j].people;
            for(int d=0;d<person[j].people;d++)
                cin>>person[j].man[d]; }
        int count=0;
        
        for(int l=0;l<(1<<n);l++){
        bool o=true;
        for(int j=0;j<n;j++){
            if(examine(person[j],l)==((l>>j)&1)){
                continue;
            }  
            else {o=false; break;}
        }
        if(o) count++;
    }
    //难点：当count=1时返回去确认对应数字，重新枚举一遍
    if(count==1){
        for(int l=0;l<(1<<n);l++){
        bool o=true;
        for(int j=0;j<n;j++){
           if(examine(person[j],l)==((l>>j)&1)){
                continue;
            }  
            else {o=false; break;}
        }
         if(o){
            answer[i]=1;
            special[i]=l;//问题，l可不可能是零或大于二的，届时无法分辨
            break;
        }
    }
}
    else 
        answer[i]=count;
     
}
    for(int i=0;i<t;i++){
        if(answer[i]==0) cout<<"Impossible"<<endl;
        if(answer[i]>=2) cout<<"Ambiguous"<<endl;
        if(answer[i]==1) {change(special[i],n);cout<<endl;}
    }
    system("pause");
    return 0;
}