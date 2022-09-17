from cyaron import *  
_n=ati([1,100,100,100,100,100,100,100,100,100,100])
for i in range(1,11):
    test_data=IO(file_prefix="door",data_id=i)
    N=_n[i]
    test_data.input_writeln(randint(1,N),randint(1,N),randint(1,N))
    test_data.output_gen("./std")