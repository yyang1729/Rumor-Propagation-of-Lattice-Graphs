import matplotlib.pyplot as plt

x = []
y = []

with open('fulldata1000avgtime.txt') as fp:
    for line in fp:
        nums = line.split()
        d = int(nums[0])
        t = float(nums[1])

        x.append(d)
        y.append(t)

plt.plot(x, y)