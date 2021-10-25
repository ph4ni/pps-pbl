#Little Bob loves chocolate, and he goes to a store with Rs. N in his pocket. 
#The price of each chocolate is Rs. C. 
#The store offers a discount: for every M wrappers he gives to the store, 
#he gets one chocolate for free. This offer is available only once. 
#How many chocolates does Bob get to eat?


n = int(input("Enter total money available: "))
c = int(input("Enter cost of each: "))
m = int(input("number of wrappers req for free chocolate: "))


chocolates_eaten = n // c
wrappers = chocolates_eaten

free = wrappers // m
chocolates_eaten += free
    
print (chocolates_eaten, "is total number of chocolates eaten by bob.")


