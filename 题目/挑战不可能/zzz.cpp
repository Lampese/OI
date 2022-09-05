#include "zzz.h"
//hi，我是zzz，这段cpp你不可以动哦
//(你动了也没用，去看zzz.h吧)
int main(){
    vector<int>a;
    for(register int i=1;i<=10000000;++i)a.push_back(i);
    vector<int>b;
    for(register int i=1;i<=100;++i)Function(a,b);
    //我复制了一百次b，因为我不放心诶
    //最后的b数组一定要和a一模一样！听说毒瘤出题人会专门检查！
}