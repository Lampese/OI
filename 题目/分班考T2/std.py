from cyaron import *  
_n=ati([1,10,1000,1000,10000,10000,10000,10000,10000,200000,200000])
for i in range(1,11):
    test_data=IO(file_prefix="",data_id=i)
    T=_n[i]
    test_data.input_writeln(T)
    while True:
        flag=False
        a=T*(T+1)//2-randint(1,T*(T+1)//2)
        b=T*(T+1)//2-a
        for j in range(1,T+1):
            if (T+1-j)*j==b:
                flag=True
        if flag==True:
            break
    test_data.input_writeln(a,b)
    test_data.output_gen("./std")
image.png