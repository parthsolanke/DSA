def top_fiv(lst):
    n = len(lst)
    arr = []
    for i in range(5):
        num = n-i
        arr.append(lst[num-1])
    return arr

def bub_sort(list):
    leng = len(list)
    for i in range(leng):
        for j in range(0, leng-i-1):
            if list[j] > list[j+1]:
                temp = list[j]
                list[j] = list[j+1]
                list[j+1] = temp
        return list
    
    
lst = []
n = int(input("Enter the no of student: "))

for i in range(n):
    stud = float(input(f"Enter marks of {i+1} student: "))
    lst.append(stud)
    
new_lst = bub_sort(lst)
lst_fiv = top_fiv(new_lst)

print("Top five marks are: ",lst_fiv)