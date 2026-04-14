# l = [1,2,3,4,5,6,7,8,9]
# p = len(l)
# k = int(input("Enter the element to get searched : "))

# for i in range(0,p):
#     if(l[i] == k):
#         print("The element found at the index : ",i)
#         break

# else:
#     print("The element no found")

l = [1,2,3,4,5,6,7,8,9,10]

low = 0
high = len(l) - 1
flag = False

k = int(input("Enter the element to get searched : "))

while(low <= high):
    mid = (low + high) // 2   # FIX: inside loop

    if(l[mid] == k):
        print("The element found at the index", mid)
        flag = True           # FIX: update flag
        break
    elif l[mid] < k:
        low = mid + 1
    else:
        high = mid - 1

if not flag:
    print("Element not found")


l = [1,2,3,8,9,12,16,4,5,6,7]
p = len(l)

for i in range(p-1):
    for j in range(p-1-i):
        if(l[j] > l[j+1]):
            l[j], l[j+1] = l[j+1], l[j]

print("Sorted list is : ",l)
