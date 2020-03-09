import urllib.request
import cv2
import numpy as np

#access webserver
#stream = urllib.request.urlopen("http://192.168.4.1")

stream = cv2.VideoCapture("http://192.168.4.1")
#buf = b''
#read stream
# while(1):
# 	buf += stream.read(1024)
# 	a = buf.find(b'\xff\xd8')
# 	b = buf.find(b'\xff\xd9')
# 	if a != -1 and b != -1:
# 		jpg = buf[a:b+2]
# 		buf = buf[b+2:]
# 		frame = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
# 		show = frame.copy()
# 		gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
# 		circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1.2, 100)
# 		if circles is not None:
# 			circles = np.round(circles[0,:]).astype("int")

# 			for (x, y, r) in circles:
# 				cv2.circle(show, (x,y), r, (0, 255, 0), 4)

# 		cv2.imshow('ESP32 Stream', show)
# 		if cv2.waitKey(1) == 27:
# 			exit(0)  

while (True):
	#frame = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
	ret, frame = stream.read()
	show = frame.copy()
	gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
	circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 1.2, 100)
	if circles is not None:
		circles = np.round(circles[0,:]).astype("int")

		for (x, y, r) in circles:
			cv2.circle(show, (x,y), r, (0, 255, 0), 4)

	cv2.imshow('ESP32 Stream', show)
	if cv2.waitKey(1) == 27:
		exit(0)   