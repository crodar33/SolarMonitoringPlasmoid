import socket
import time
import struct
import random

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)

# Enable port reusage so we will be able to run multiple clients and servers on single (host, port). 
# Do not use socket.SO_REUSEADDR except you using linux(kernel<3.9): goto https://stackoverflow.com/questions/14388706/how-do-so-reuseaddr-and-so-reuseport-differ for more information.
# For linux hosts all sockets that want to share the same address and port combination must belong to processes that share the same effective user ID!
# So, on linux(kernel>=3.9) you have to run multiple servers and clients under one user to share the same (host, port).
# Thanks to @stevenreddie
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)

# Enable broadcasting mode
server.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

# Set a timeout so the socket does not block
# indefinitely when trying to receive data.
server.settimeout(0.2)

while True:
    v1 = random.randint(0, 65000)/100
    v2 = random.randint(0, 65000)/100
    v3 = random.randint(0, 65000)/100
    v4 = random.randint(0, 65000)/100
    v5 = random.randint(0, 65000)/100
    print("message: %f %f %f %f %f" % (v1, v2, v3, v4, v5))
    message = struct.pack("5f", v1, v2, v3, v4, v5)
    message = b"cm:" + message
    server.sendto(message, ('<broadcast>', 7798))
    print("message sent!")
    time.sleep(4)