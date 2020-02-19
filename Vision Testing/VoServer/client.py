import socket

TCP_IP = '192.168.43.135'
TCP_PORT = 23
BUFFER_SIZE = 8000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(TCP_IP, TCP_PORT)

while(1):
	data = client.recv(BUFFER_SIZE)
	print(data)

client.close()