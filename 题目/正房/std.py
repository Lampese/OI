from cyaron import *  
_n=ati([1,1000,1000,1000,10000,10000,1500000,1500000,1500000,2500000,2500000])
for i in range(1,11):
    test_data=IO(file_prefix="dwt",data_id=i)
    N=_n[i]
    test_data.input_writeln(randint(N-10,N))
    test_data.output_gen("./std")
