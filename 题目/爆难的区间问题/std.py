from cyaron import *  
_n=ati([1,1000,1000,1000,10000,10000,10000,10000,10000,200000,200000])
for i in range(1,11):
    test_data=IO(file_prefix="",data_id=i)
    T=randint(5,10)
    test_data.input_writeln(T)
    for k in range(1,T+1):
        print(k)
        N=_n[i]
        s={}
        test_data.input_writeln(N,N)
        for j in range(1,N+1):
            num=randint(1,100000000)
            while num in s:
                num=randint(1,100000000)
            test_data.input_write(num)
        test_data.input_write('\n')
        for j in range(1,N+1):
            rnd=1
            if N==1000:
                rnd=randint(1,3)
            else:
                rnd=randint(1,4)
            l=randint(1,N-200)
            r=randint(l,N-100)
            h=1
            if rnd==4:
                h=randint(1,N-r)
                test_data.input_writeln(rnd,l,r,h)
            else:
                test_data.input_writeln(rnd,l,r)
    test_data.output_gen("./std")
