import random

with open("stations.txt", "w") as f:
    f.write("50\n")
    for i in range(50):
        f.write(f"{i},Station_{i}\n")
    # Generate random connections
    for i in range(49):
        #1-20mins
        weight = random.randint(1, 20) 
        f.write(f"{i},{i+1},{weight}\n")
    #shortcuts
    for _ in range(20):
        u, v = random.sample(range(50), 2)
        weight = random.randint(1, 5) 
        f.write(f"{u},{v},{weight}\n")