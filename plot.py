import matplotlib.pyplot as plt

x = []
y = []

with open('fulldata1000avgtime.txt') as fp:
    for line in fp:
        nums = line.split()
        d = nums[0]
        t = nums[1]

        x[d] = d
        y[d] = t

plt.plot(x, y)