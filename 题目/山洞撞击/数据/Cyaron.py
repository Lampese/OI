from cyaron import *
_n=ati([0,10,100,100,1000,1000,1000,1000,1000,1000,1000])
_m=ati([0,10,100,100,1000,1000,1000,1000,1000,1000,1000])
for i in range(1, 11):
    test_data=IO(file_prefix="cave",data_id=i)
    N=_n[i]
    M=_m[i]
    test_data.input_writeln(N,M,N*5,randint(N*0.5,N),randint(100,2000),randint(10,100))
    _x=1
    for j in range(0,N+1):
        _t=randint(_x,_x+3)
        _x+=4
        test_data.input_write(_t)
        test_data.input_write(" ")
    test_data.input_write("\n")
    _x=1
    for j in range(0,N+1):
        _t=randint(_x,_x+3)
        _x+=4
        test_data.input_write(_t)
        test_data.input_write(" ")
    test_data.output_gen("../std/std")