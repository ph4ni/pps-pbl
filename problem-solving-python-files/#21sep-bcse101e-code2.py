#21sep-bcse101e-code2
#average marks

n=int(input("enter number of subjects: "))

sum = 0

for i in range (0,n):
    a = int(input("enter marks for a single subject: "))
    sum+=a

avgmarks = sum/n

print("average marks are:", avgmarks)
