import socket
import cv2

TCP_IP = '192.168.43.135'
TCP_PORT = 23
BUFFER_SIZE = 8000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(TCP_IP, TCP_PORT)

data = client.recv(BUFFER_SIZE)
#print(data)
client.close()

img = cv2.imdecode(data, CV_LOAD_IMAGE_COLOR)
cv2.imshow('img', img)
cv2.waitKey(0)