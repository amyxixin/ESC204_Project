import urllib
import numpy as np
import cv2

url = "http://192.168.43.135/saved-photo"
raw_img = urllib.request.urlopen(url)
img_array = np.array(bytearray(raw_img.read()), dtype=np.uint8)
img = cv2.imdecode(img_array, -1)
cv2.imshow("yo", img)
cv2.waitKey()

