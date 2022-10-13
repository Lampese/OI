from cyaron import *  
_n=ati([1,10000,10000,10000,500000,500000,5000000,5000000,5000000,5000000,5000000])
for i in range(1,11):
    test_data=IO(file_prefix="",data_id=i)
    N=_n[i]
    test_data.input_writeln(randint(N-100,N))
    test_data.output_gen("./std")
