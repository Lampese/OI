from cyaron import *  
_n=ati([1,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000])
for i in range(1,11):
    test_data=IO(file_prefix="wrxwjd",data_id=i)
    N=_n[i]
    test_data.input_writeln(N,N)
    for i in range(1,N+1):
        test_data.input_write(randint(1,10**40))
    test_data.input_write('\n')
    for i in range(1,N+1):
        opt=randint(1,2)
        l=randint(1,N)
        r=randint(l,N)
        if opt==1:
            v=randint(1,10**40)
            test_data.input_writeln(opt,l,r,v)
        else:
            test_data.input_writeln(opt,l,r)
    test_data.output_gen("./std")