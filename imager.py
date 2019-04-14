import matplotlib.pyplot as plt
import sys
import numpy as np

f = open(sys.argv[1])
text = f.read()
text1 = text.split('\n')
x_len = len(text1)
y_len = len(text1[0].split(' '))
print(x_len,y_len)
M = np.zeros((x_len, y_len))
x = 0
y = 0

for line in text.split('\n'):
  y = 0
  a = line.split(' ')
  B = []
  for integer in a:
    #print(integer)
    if integer and not integer == ' ':
      M[x,y] = np.float(integer)
      y += 1
  x += 1 
if(len(sys.argv) >= 3):
  colormap = sys.argv[2]
else:
  colormap = 'inferno'

plt.imshow(M,cmap = colormap)
plt.show()