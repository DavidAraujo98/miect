
#   Weather update client
#   Connects SUB socket to tcp://localhost:5556
#   Collects weather updates and finds avg temp in zipcode
#

import sys
import zmq


#  Socket to talk to server
context = zmq.Context()
socket = context.socket(zmq.SUB)

print("Collecting updates from weather server...")
socket.connect("tcp://localhost:5556")

# Subscribe to zipcode, default is NYC, 10001
zip_filter = sys.argv[1] if len(sys.argv) > 1 else "10001"
socket.setsockopt_string(zmq.SUBSCRIBE, zip_filter)
socket.setsockopt_string(zmq.SUBSCRIBE, "10003")

# Process 5 updates
total_temp = 0
while True:
    string = socket.recv_string()
    zipcode, temperature = string.split()

    print((f"Average temperature for zipcode " 
       f"'{zipcode}' was {temperature} F"))