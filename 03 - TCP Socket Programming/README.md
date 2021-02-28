> National University of Computer and Emerging Sciences
> 
> ![](media/image1.jpg)

# Laboratory Manuals

> *for*

## Computer Networks

> (CL -307)

Department of Computer Science

FAST-NU, Lahore, Pakistan

### Lab Manual 03

> **Objective: **

Students should know:

•What a computer network is and what its advantages are.

•What is OSI Model?

•What is a socket?

•Client-Server Model

•TCP Socket Programming.

#### In-lab Statement 1: \[5\]

  - Write **TCP** client and server that can communicate to each other
    saying

> “Hello I am client and My id is 1” and “Hello I am server. Your
> received id is 1”

  - The ID of the client should be only a **single digit** i.e from 0 to
    9

  - Run one client and server on same machine

  - Your server should be in running state **infinitely** and should not
    terminate after serving one client only. The clients will keep on
    coming one by one and server will keep on serving them unless
    terminated intentionally.

  - **<span class="underline">Sample Test Bench</span>**
    
      - Client1 sends : “Hello I am client and My id is 1”
    
      - Client2 sends: “Hello I am client and My id is 2”
    
      - Server response on client1: “Hello I am server. Your received id
        is 1”
    
      - Server response on client2: “Hello I am server. Your received id
        is 2”

#### In-lab Statement 2: \[15\]

  - Write TCP client and server program such that client will send one
    string to a server and server will display the string with all the
    words containing one or more vowels in an inverted fashion e.g.,
    computer must be inverted as ‘retupmoc’.

  - The server will then send the resulting string to client and client
    as a result will invert all the words containing no vowels and
    display it on the terminal e.g., dry must be inverted as ‘ryd’.

  - Your server should be in running state **infinitely** and should not
    terminate after serving one client only. The clients will keep on
    coming one by one and server will keep on serving them unless
    terminated intentionally.  Sample Test Bench
    
      - Client sends to server: “the birds fly in dry sky at night”
    
      - Server displays the string and returns to client: “eht sdirb fly
        ni dry sky ta thgin”
    
      - Client displays the string: “eht sdirb ylf ni yrd yks ta thgin”
