National University of Computer and Emerging Sciences

![](media/image1.png)

**Laboratory Manuals**

*for*

**Computer Networks**

(CL -307)

Department of Computer Science

FAST-NU, Lahore, Pakistan

> Lab Manual 12

# <span class="underline">Objective:</span>

  - Establishing Serial Connection Between Two Routers using RIP

  - # Development of FAST NU Network Topology using Packet tracer

  - Configuring Router using CLI of the Router

# <span class="underline">Serial Connection between Routers:</span>

We will establish serial connection between different Routers using
Routing Information Protocol (RIP)

![](media/image2.png)

**Networks Available:**

  - 192.168.2.0

  - 192.168.3.0

  - 10.0.0.0

# In lab Statement 1: \[20\]

You have to design a network solution for the Fast-NU three **Labs,
Staff and Faculty members**.

  - All the three Labs, Staff and faculty members should be on
    **different Sub networks.**

<!-- end list -->

  - There are total **15 computers** divided in this way
    
      - 3 for Staff
    
      - 3 for Faculty
    
      - 3 for Lab-1 ,
    
      - 3 for Lab-2 and
    
      - 3 for Lab-3.

  - Assume that FAST-NU is given a **Network Class B** address having
    first two octets of IP address fixed as 172.19.X.X. You can change
    the next two octets in order to make desired number of subnets and
    desired number of hosts in each subnet for the above given topology.

Make sure that you optimally design the network considering the number
of devices (switches, routers etc.) used and how you are assigning the
IP addresses to different subnets in your design. (You can consult the
slides for sub netting provided to you in case you have no idea about
sub netting or you have forgotten it)

1.  Use wires (**straight through and cross over** where necessary and
    applicable) – no wireless LAN is required for this submission.

2.  Use **2911 Router**

3.  Use **2950-24 switches.**

4.  **You can connect a maximum of two networks with a single router
    (except router-to-router connection)**

5.  You have to assign IPs to the machines using **static IP
    allocation**.

6.  Use ping from the command prompt of computers to check your network
    design is working.

7.  Make your design as neat as possible and properly add the IPs of all
    the PCs and router **interfaces using comments** in your design to
    get the full credit. (You can insert comments in the design area
    using a sticky note sign in the right sidebar of Cisco Packet
    Tracer)

**<span class="underline">For RIP Classless Configuration:</span>**

Router\>enable

Router\#configure terminal // Global configuration mode

Enter configuration commands, one per line. End with CNTL/Z.

Router(config)\#router rip

Router(config-router)\#version 2

Router(config-router)\#no auto-summary

Router(config-router)\#network 172.19.0.0

Router(config-router)\#network 172.19.32.0

Router(config-router)\#network 172.19.160.0

Router(config-router)\#exit

Router(config)\#exit

**<span class="underline">LINKS</span>**

<https://www.youtube.com/watch?v=_ISu9f8ofZk>

<https://www.youtube.com/watch?v=DqU3KVCyFNg>

<https://www.youtube.com/watch?v=krM9GprN6qA>

<https://www.youtube.com/watch?v=oet-s1xDLOA>
