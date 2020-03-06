import urllib.request
import cv2
import numpy as np

#access webserver
stream = urllib.request.urlopen("http://192.168.4.1")

buf = b''
#read stream
while(1):
	buf += stream.read(1024)
	a = buf.find(b'\xff\xd8')
	b = buf.find(b'\xff\xd9')
	if a != -1 and b != -1:
		jpg = buf[a:b+2]
		buf = buf[b+2:]
		frame = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
		cv2.imshow('ESP32 Stream', frame)
		if cv2.waitKey(1) == 27:
			exit(0)   