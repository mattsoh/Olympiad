import random


# Set the number of distinct numbers
num_count = 299992

# Generate a list of distinct numbers
numbers = range(300000,2, -1)

# Write the numbers to a file
with open("distinct_numbers.txt", "w") as f:
    f.write("1\n")
    f.write("200000 999\n")
    for i in range(200000):
        random_numbers = str(random.randint(20000000, 80000000))
        f.write(random_numbers+' ')
    f.write('\n')
    for i in range(200000):
        random_numbers = str(random.randint(30000000, 80000000))
        f.write(random_numbers+' ')
    f.write('\n')

print(f"{num_count} distinct numbers have been written to 'distinct_numbers.txt'")
