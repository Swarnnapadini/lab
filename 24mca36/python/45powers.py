twox=lambda x:2**x
terms=int(input("Enter the number of terms: "))
power_of_2=list(map(twox,range(terms)))
print("Power of 2 upto ",terms," terms:")
for i in range(terms):
        print(f"2^{i}={power_of_2[i]}")


