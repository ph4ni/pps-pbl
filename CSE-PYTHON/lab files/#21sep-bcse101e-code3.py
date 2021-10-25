#21sep-bcse101e-code3
#average marks w/ pass and fail

n=int(input("enter number of subjects: "))

sum = 0

for i in range (0,n):
    a = int(input("enter marks for a single subject: "))
    sum+=a

avgmarks = sum/n

if avgmarks<65:
    print("student has failed")
else:
    print("student has passed")
