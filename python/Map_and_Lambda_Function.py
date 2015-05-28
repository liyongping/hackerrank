def fibonacci(n):
    if n==1:
        return 0
    elif n==2:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
    
def fibonacci_list(n):
    if n==0:
        return []
    elif n==1:
        return [0]
    elif n==2:
        return [0,1]
    else:
        p_fb_value = fibonacci_list(n-1)
        p_fb_value.append(p_fb_value[-1]+p_fb_value[-2])
        return p_fb_value
   
n = int(raw_input())
print map(lambda a:pow(a,3),fibonacci_list(n))