from cyaron import *
_n=ati([10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000])
for i in range(1, 11):
    test_data=IO(file_prefix="coin",data_id=i)
    N=_n[i]
    test_data.input_writeln(randint(1000000,N))
    test_data.output_gen("./std")