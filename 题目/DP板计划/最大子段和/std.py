from cyaron import *
_n=ati([1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,10000000])
for i in range(1, 11):
    test_data=IO(file_prefix="coin",data_id=i)
    N=_n[i]
    test_data.input_writeln(_n[i])
    for j in range(1,_n[i]+1):
        test_data.input_write(randint(-100,100))
    test_data.output_gen("./std")