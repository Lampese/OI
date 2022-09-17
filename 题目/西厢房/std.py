from cyaron import *
import random
_n=ati([0,1000,1000,1000,1000000,1000000,1000000,1000000,1000000,1000000,1000000])       
for i in range(1,11):
    test_data=IO(file_prefix="Four",data_id=i)
    N=_n[i]
    test_data.input_writeln(randint(5000000,100000000),randint(500,N))
    test_data.output_gen("./std")