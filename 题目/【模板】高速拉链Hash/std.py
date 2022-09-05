from cyaron import *
import random
_n=ati([0,200000,200000,200000,200000,200000,200000,200000,200000,200000,200000])       
for i in range(1,11):
    test_data=IO(file_prefix="Hash",data_id=i)
    N=_n[i]
    s=set({114514})
    ans=0
    test_data.input_writeln(N)
    test_data.input_writeln(1,114514)
    for i in range(1,N):
        ask=randint(1,2)
        if ask==1:
            k=randint(1,2**31)
            while 1:
                if k in s:
                    k=randint(1,2**31)
                else:
                    s.add(k)
                    break
            test_data.input_writeln(1,k)
        if ask==2:
            yes=randint(1,2)
            if yes==1:
                num=random.sample(s,1)[0]
                test_data.input_writeln(2,num)
                ++ans
            else:
                k=randint(1,2**31)
                while 1:
                    if k in s:
                        k=randint(1,2**31)
                    else:
                        break
                test_data.input_writeln(2,k)
    test_data.output_writeln(ans)