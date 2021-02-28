National University of Computer and Emerging Sciences

![](media/image1.png)

**Laboratory Manuals**

*for*

**Computer Networks**

(CL -307)

Department of Computer Science

FAST-NU, Lahore, Pakistan

> Lab Manual 10

# Objective:

  - Analyze Distance vector routing protocol on NS2

  - Implementation of Circular and Star Topology using ns2

**<span class="underline">Distance vector routing protocol</span>**

**Distance vector protocols** (a **vector** contains both **distance**
and direction) determines the path to remote networks using hop count as
the metric. A hop count is defined as the number of times a packet needs
to pass through a **router** to reach a remote (far away) destination.

In NS2, we add following command to set the routing protocol to Distance
Vector

***$ns rtproto DV***

To bring the link between two nodes down/up at specific simulation time
we write the following commands  
**$ns rtmodel-at 0.30 down $node1 $*node2***

***$ns rtmodel-at 0.40 up $node1 $node2***

**<span class="underline">For Arrays in tcl:</span>**

**set arrayName(Index) arrayValue**

**<span class="underline">NOTE:</span>**

  - You will have to implement both the following topologies using For
    loop in TCL Language and use as much less statements as possible.

  - You must define the nodes and links between the nodes using for
    loop. Simple definitions of nodes/links will not be accepted.

**In-lab statement 1: \[10\]**

1.  Write a Tcl script that forms a network consisting of **7 nodes**,
    numbered from 0 to 6, forming a **ring topology.**

2.  The links have a 512Kbps bandwidth with 5ms delay and droptail
    queue.

3.  Set the routing protocol to DV (Distance vector).

4.  Send UDP packets from node 0 to node 3 with the rate of 100
    packets/sec with each packet having a size of 1 Kilo Bytes.

5.  Start transmission at 0.02.

6.  Bring **down the link** between node 2 and node 3 at 0.4.

7.  Bring the dropped link back **up** at 1.0.

8.  Finish the transmission at 1.5
    
    End the simulation at 2.0.

9.  Also monitor two queues (b/w Node 0 &1) and (b/w Node 0 &6) and
    answer the following.

**Answer the following in a text document:**

1.  What path do the packets follow initially? And why?

2.  What path do the packets take after the link fails? And why?

3.  If we remove the Distance Vector Algorithm, what path the packets
    follow after the link fails? And why?

**In-lab statement 2: \[10\]**

You will have to create **a star topolgy** as given in the diagram below
using ns2 to implement the Distance vector routing protocol. Assume all
the devices in the following star topology as nodes and all the wires as
duplex links having a **capacity of 512Kb** and a **propagation delay of
10ms** with a **stochastic fair queue** scheduling algorithm.

You will have to send TCP data from H1 to H4 having red color. Also you
will have to send UDP data with a rate of 256Kbps from H2 to H5 having
blue color.

**Scheduling Events:**

  - TCP Data starts at 0.1 and stops at 1.5

  - UDP Data starts at 0.2 and stops at 1.3

  - Bring the link between SW1 and H5 down at 0.5 and bring it back up
    at 0.9

  - Bring the link between SW1 and H4 down at 0.7 and bring it back up
    at 1.2

  - Stop the simulation at 2.0

![](media/image2.png)**Note: You must orient the nodes as shown in the
topology using the orient feature for NAM. Consider SW1 as a node.**
