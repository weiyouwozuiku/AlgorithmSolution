//
// Created by king on 2021/4/1.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    //这里的d2表示因数中2的个数，d5表示5的个数
    int res=1,d2=0,d5=0;
    for(int i=1;i<=n;i++){
        int x=i;
        while(x%2==0) x/=2,d2+=1;
        while(x%5==0) x/=5,d5+=1;
        //这里取余可以有效的减小数字的大小，对于结果没有影响
        res=res*x%10;
    }
    //将多扣除的2或者5乘回去
    int k=d2<d5?d2:d5;
    //这里取余可以有效的减小数字的大小，对于结果没有影响
    for(int i=0;i<d2-k;i++) res=res*2%10;
    for(int i=0;i<d5-k;i++) res=res*5%10;
    printf("%d",res%10);
    return 0;
}