unv_set = []
ele = 0  

def inpt (n,lst,s_lst) :
    for i in range(0, n) :
        #print(f"Name of {i+1} student - ")
        ele = input(f"Name of {i+1} student - ")
        s_lst.append(ele)
        if ele not in unv_set :
            unv_set.append(ele)
    print(s_lst)

def union(lst1,lst2):
    lst3=lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3

def diff(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def either_or(lst1,lst2):
    lst3=[]
    D1=diff(lst1,lst2)
    D2=diff(lst2,lst1)
    lst3=union(D1,D2)
    return lst3

def intersection(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3

n = int(input("\nEnter number of students plays cricket : "))
cricket_lst = []
inpt(n,unv_set,cricket_lst)

m = int(input("\nEnter number of students plays badminton : "))
badminton_lst = []
inpt(m,unv_set,badminton_lst)

l = int(input("\nEnter number of students plays football : "))
football_lst = []
inpt(l,unv_set,football_lst)

print("\nstudents playing cricket & badminton : ",intersection(cricket_lst,badminton_lst))

print("\nstudents playing either cricket or badminton : ",either_or(cricket_lst,badminton_lst))

lit = union(cricket_lst,badminton_lst)

print("\nNumber of students who play neither cricket nor badminton: ",len(diff(lit,football_lst)))

print("\nNumber of students who play cricket and football but not badminton: ",len(intersection(cricket_lst,football_lst)))

print("\nTotal no. of students playing sports : ", unv_set)