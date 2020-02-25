import socket
from pynput.keyboard import Key, Listener

HOST = '192.168.43.195'
PORT = 23

F = 0 #forward
B = 1 #backward
L = 2 #left
R = 3 #right
S = 4 #stop

client, addr = '', ''

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)

def on_press(key):
	if (key == 'w'):
		server.send(S)
		server.send(F)

	if (key == 'a'):
		server.send(S)
		server.send(L)

	if (key == 's'):
		server.send(S)
		server.send(B)

	if (key == 'd'):
		server.send(S)
		server.send(R)

def on_release(key):
	if ((key == 'w') or (key == 'a') or (key == 's') or (key == 'd')):
		server.send(S)

while True:
	print("Waiting for a connection...")
	client, addr = server.accept()

	try:
		print("Connection from {}".format(addr))

		with Listener(on_press=on_press, on_release=on_release) as Listener:
			listener.join()

	finally:
		server.close()
