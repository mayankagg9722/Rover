
import socket                                         


serversocket = socket.socket(
	        ) 


host = socket.gethostname()                           

port = 9999                                           


serversocket.bind((host, port))                                  


serversocket.listen(5)                                           

while True:
    
    clientsocket,addr = serversocket.accept()      

    print("Got a connection from %s" % str(addr))
    
    clientsocket.close()