import socket
import cv2
import numpy as np

HOST = "192.168.43.195" #find laptop ip on network sometime
PORT = 44444
BUFFER_SIZE = 1024

#Create UDP socket
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#Bind the socket to the host and port
server.bind((HOST, PORT))

#Image buffer will contain bytes from stream
buf = b''
#Main loop
while(True):
	data, addr = server.recvfrom(BUFFER_SIZE)
	buf += data
	a = buf.find(b'\xff\xd8')
	b = buf.find(b'\xff\xd9')
	if (a != -1):
		print('a')
		print(buf)
		break
	#if (a != -1) and (b != -1):
		#jpg = buf[a:b+2]
		#buf = buf[b+2:]		
		# frame = cv2.imdecode(np.frombuffer(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
		# cv2.imshow('ESP32 Stream', frame)
		# if cv2.waitKey(1) == 27:
		# 	exit(0)   