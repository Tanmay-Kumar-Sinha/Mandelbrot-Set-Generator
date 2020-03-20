import numpy as np
import os

X = np.linspace(-1,1,100)
# X,Y = np.meshgrid(X,Y)
# M = X + Y*1.j

count = 0
os.system('g++ Julia_set.cpp -o generator')
for z in X:
  command = "./generator " + str(-0.7269) + " " + str(z) + " images/image" + str(count) + ".pgm"
  count += 1
  os.system(command)
  print("Done with " + str(count) + " images")

os.system('rm generator')
os.system("ffmpeg -r 16 -i images/image%01d.pgm -vcodec mpeg4 -y movie.mp4")