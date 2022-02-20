import random

with open("pattern.txt", "w") as file1:
    # Writing data to a file
    data = ("0", "1")
    d = {"101011011000101010111":0 , "1" : 0 , "0":0}
    for i in range(0,100000):
        r = random.choice(data);
        d[r] += 1;
        file1.write(f"{r}")

    print(d)
