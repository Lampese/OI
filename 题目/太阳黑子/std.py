from cyaron import *
import random
_n=ati([0,10,10,10,10,10,10,10,10,10,10])       
for i in range(1,11):
    test_data=IO(file_prefix="Sun",data_id=i)
    N=_n[i]
    test_data.input_writeln(N)
    for j in range(1,N+1):
        opt=randint(1,4)
        if opt==3:
            vent=randint(1,2)
            if vent==1:
                opt=1
        l=randint(1,N)
        r=randint(1,N)
        v=randint(1,2**10)
        if l>r:
            l,r=r,l
        if opt==1:
            test_data.input_writeln(1,l,r,v)
        if opt==2:
            test_data.input_writeln(2,l,r)
        if opt==3:
            test_data.input_writeln(3,l,r)
        if opt==4:
            test_data.input_writeln(4,l,r,v)