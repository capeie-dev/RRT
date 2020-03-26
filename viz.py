import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
with open('path.txt') as f:
    lines = f.readlines()
    x = [line.split()[0] for line in lines]
    for i in range(0, len(x)):
        x[i] = int(x[i])
    y = [line.split()[1] for line in lines]
    for i in range(0, len(y)):
        y[i] = int(y[i])
with open('all_nodes.txt') as f:
     lines = f.readlines()
     x_pos = [line.split()[0] for line in lines]
     for i in range(0, len(x_pos)):
         x_pos[i] = int(x_pos[i])
     y_pos = [line.split()[1] for line in lines]
     for i in range(0, len(y_pos)):
         y_pos[i] = int(y_pos[i])
with open('obstacles.txt') as f:
    lines = f.readlines()
    x_end = [line.split()[0] for line in lines]
    for i in range(0, len(x_end)):
         x_end[i] = int(x_end[i])
    y_end = [line.split()[1] for line in lines]
    for i in range(0, len(y_end)):
         y_end[i] = int(y_end[i])

fig = plt.figure()
ax1 = fig.add_subplot(111)


colors = (0,0,0)
area = np.pi*3
print(x)
print(y)
x_pos = np.asarray(x_pos)
y_pos = np.asarray(y_pos)


x = np.asarray(x)
y = np.asarray(y)
x_end = np.asarray(x_end)
y_end = np.asarray(y_end)
plt.scatter(x_pos,y_pos)
plt.scatter(x_end,y_end, s =np.pi*5*5)
plt.plot(x ,y)
#print(x_pos)
plt.show()



