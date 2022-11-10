from cyaron import *  
_n=ati([1,1000,1000,1000,100000,100000,100000,100000,100000,100000,100000])
for i in range(1,11):
    test_data=IO(file_prefix="",data_id=i)
    N=_n[i]
    test_data.input_writeln(N,randint(1,1000000),randint(1,1000000))
    for j in range(1,N+1):
        test_data.input_writeln(randint(1,10000000),randint(1,10000000),randint(1,2))
    test_data.output_gen("./std")