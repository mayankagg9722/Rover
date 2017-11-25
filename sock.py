import socket

s = socket.socket()
host ="192.168.43.237"
port =8081
s.connect((host,port))
s.close ()