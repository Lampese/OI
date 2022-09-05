from cyaron import *
import random
_n=ati([0,10,20,500000,500000,500000,500000,500000,500000,500000,500000])       
for i in range(1,11):
    top=0
    test_data=IO(file_prefix="Moon",data_id=i)
    N=_n[i]
    test_data.input_writeln(N)
    for j in range(1,N+1):
        opt=randint(1,3)
        if top<5:
            opt=1
        if opt==1:
            top+=1
            l=randint(1,N)
            r=randint(l,N)
            v=randint(1,2**30)
            test_data.input_writeln(opt,l,r,v)
        if opt==2:
            pos=randint(1,N)
            test_data.input_writeln(opt,pos)
        if opt==3:
            do=randint(1,top-1)
            top-=do
            test_data.input_writeln(opt,do)
    test_data.output_gen("./std")
