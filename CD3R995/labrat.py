import sys

def II() -> int : return int(input())
def MI() -> int : return map(int, input().split())
def TI() -> tuple[int] : return tuple(MI())
def LI() -> list[int] : return list(MI())
#str-input
def SI() -> str : return input()
def MSI() -> str : return input().split()
def SI_L() -> list[str] : return list(SI())
def SI_LI() -> list[int] : return list(map(int, SI()))
#multiple-input
def LLI(n) -> list[list[int]]: return [LI() for _ in range(n)]
def LSI(n) -> list[str]: return [SI() for _ in range(n)]
#1-indexを0-indexでinput
def MI_1() -> int : return map(lambda x:int(x)-1, input().split())
def TI_1() -> tuple[int] : return tuple(MI_1())
def LI_1() -> list[int] : return list(MI_1())

from bisect import bisect_left

t = II()
for _ in range(t):
    n,k = MI()
    a = LI()
    b = LI()
    
    a.sort()
    b.sort()
    
    c = list(sorted(set(a+b)))
    
    ans = 0
    res = 0
    for cost in c:
        good = n - bisect_left(a,cost) #購入
        bad = (n - bisect_left(b,cost)) - good
        
        if bad <= k and ans < cost*(good+bad):
            ans = cost*(good+bad)
    
    print(ans) 
        
        
        
        
        
        