from cyaron import *
_n=ati([1,3000,3000,3000,300000,300000,300000,300000,300000,300000,300000,3000,3000,3000,300000,300000,300000,300000,300000,300000,300000])       
for i in range(1,21):
    test_data=IO(file_prefix="sqrt",data_id=i)
    T=_n[i]
    test_data.input_writeln(T);
    for j in range(1,T+1):
        tag=randint(1,2)
        n=1
        if tag==1:
            htag=randint(1,3)
            if htag==1:
                n=(2**31)-1
                test_data.input_writeln(n,randint(2,64));
            if htag==2:
                n=(2**29)-1
                test_data.input_writeln(n,randint(2,64));
            if htag==3:
                n=(2**17)-1
                test_data.input_writeln(n,randint(2,64));
        else:
            m=randint(2,8)
            n=randint(2,11)
            test_data.input_writeln((n**m)*randint(2,114514),m);
    test_data.output_gen("./std")