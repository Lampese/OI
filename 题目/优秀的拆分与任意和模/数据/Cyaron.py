#73369
from cyaron import *
_n=ati([0,10,100,100,3300000,3300000,4000000,4000000,4000000,4000000,4000000])
_k=ati([0,64,100,100,1e7,1e7,1e7,1e7,1e7,1e7,1e7])
for i in range(1, 11):
    test_data=IO(file_prefix="mod",data_id=i)
    test_data.input_writeln(_n[i],73369,randint(2,1000))
    for j in range(1,_n[i]+1):
        test_data.input_writeln(_k[i])
    test_data.output_gen("../std/std")
