from cyaron import *
import random
_n=ati([0,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000])       
for i in range(1,11):
    test_data=IO(file_prefix="Hash",data_id=i)
    test_data.input_writeln(_n[i])
    for j in range(1,_n[i]+1):
        test_data.input_writeln(randint(1,10**9))
    test_data.output_gen("./std")