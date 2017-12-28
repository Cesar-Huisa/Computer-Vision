import subprocess

img2 = 145
img1 = 71

for i in range (3,150):
	subprocess.call(["mv",str(i)+".jpg",str(i-1)+".jpg"])
	img1-=1
	img2-=2
