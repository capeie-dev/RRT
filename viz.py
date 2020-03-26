import matplotlib.pyplot as plt
import numpy as np
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
with open('endpoints.txt') as f:
    lines = f.readlines()
    x_end = [line.split()[0] for line in lines]
    y_end = [line.split()[1] for line in lines]




colors = (0,0,0)
area = np.pi*3
print(x)
print(y)
x_pos = np.asarray(x_pos)
y_pos = np.asarray(y_pos)
x = np.asarray(x)
y = np.asarray(y)
plt.scatter(x_pos,y_pos)
plt.plot(x ,y)
#print(x_pos)
plt.show()



