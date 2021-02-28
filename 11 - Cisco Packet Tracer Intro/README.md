National University of Computer and Emerging Sciences

![](media/image1.png)

**Laboratory Manuals**

*for*

**Computer Networks**

(CL -307)

Department of Computer Science

FAST-NU, Lahore, Pakistan

**  
**

> **Lab Manual 11**

# Objective:

  - Understanding of Subnetting

  - Using Cisco Packet Tracer

**<span class="underline">INTRODUCTION TO PACKET TRACER</span>**

  - **What is Packet Tracer?**

Packet Tracer is a protocol simulator developed by *Dennis Frezzo* and
his team at Cisco Systems. Packet Tracer (PT) is a powerful and dynamic
tool that displays the various protocols used in networking, in either
Real Time or Simulation mode. This includes layer 2 protocols such as
TCP and UDP. Layer 3 protocols such as IP, ICMP, and ARP, RIP, EIGRP and
layer 4 protocols such as Ethernet and PPP (Point-to-Point Protocol).
Routing protocols can also be traced.

  - **Purpose: **

The purpose of this lab is to become familiar with the Packet Tracer
interface. Learn how to use existing topologies and build your own.

**<span class="underline">Introduction to the Packet Tracer
Interface</span>**

<span class="underline">**STEP 1**:</span> Start Packet Tracer and
Entering Simulation Mode

![](media/image2.png)

**<span class="underline">STEP 2:</span> Choosing Devices and
Connections**

We will begin building our network topology by selecting devices and the
media in which to connect them.  
Several types of devices and network connections can be used. For this
lab we will keep it simple by using **End Devices, Switches, and
Links.**

**<span class="underline">STEP 3:</span> Single click on each group of
devices and connections to display the various choices.**

![](media/image3.png)

**<span class="underline">STEP 4:</span> Building the Topology – Adding
Hosts**

**Single click on the End Devices.**

![](media/image4.png)

**<span class="underline">STEP 5:</span>**

**Drag and Drop the end devices in simulation area. Similarly Drag and
Drop the router for communication. We will use CISCO 2811 router because
it’s the latest one from CISCO.**

**<span class="underline">STEP 6:</span>**

**Now you have to connect those end devices to router in order to make a
network topology.**

**For connection we normally use three types of cable. **

  - **Straight through Cable: When we have to connect UNLIKE devices.**

  - **Crossover: When we have to connect LIKE Devices.**

  - **Serial Cable: When we connect two Routers.**

> **<span class="underline">INFO:</span>**

Data can travel over a cable only if the two dots on it are green.
However, when you connect the cables you will see the switch side
turning orange. This is because the switch is doing some checks before
turning on the interface, so you just have to wait (or fast-forward the
time). The dot indicating the port-status refers to the interface status
of the closest device. It can be of three different colors.

  - **Green** – the port is working at OSI layer 1 and 2

  - **Orange** – the port is powered on, but software is blocking it

  - **Red** – the port is shut down

Once your ports become green, you are ready to see how we configure
devices in Cisco Packet Tracer.

# IN LAB STATEMENT 1: (10)

**Steps to create a network using cisco packet tracer:**

1.  **Take 8 GENERIC PC’S (total 8 PCs, 4 on one network and 4 on
    another network) that will be connected by 2 SWITCHES 2950-24, Use
    drag and drop method. All the devices can be found in the bottom
    bar.**

2.  **Connect all of them with COPPER STRAIGHT through cable.**

3.  **If 2 computers want to communicate in a network they must have
    same type of subnet mask (they must have their network bits same).
    So Assign IP addresses to the PCs. Different network of addresses
    for both the sides.**
    
    1.  **Double click on Pc**
    
    2.  **Go to desktop tab and click “ip configuration”**
    
    3.  **Insert ip of the 1<sup>st</sup> pc, subnet will automatically
        generate and leave the gateway right now.**
    
    4.  **You need to limit yourself to one class of private addresses,
        if you want to computers to talk with each other within a
        network**

4.  **<span class="underline">Connecting Network With One
    Router</span>**
    
    5.  **Connect ONE GENERIC ROUTER **
    
    6.  **Connect It With Switch 0 from fast Ethernet 0/0**
    
    7.  **Connect It With Switch 1 from fast Ethernet 1/0**
    
    8.  **Use Copper straight through cable**

5.  **<span class="underline">Router connected with the network 1 from
    fast Ethernet 0/0</span>**
    
    9.  **Double click on router **
    
    10. **Go to “config” tab **
    
    11. **Click fast Ethernet 0/0. **
    
    12. **Insert ip of the class as the network 1 have, subnet will
        automatically generate  
        make sure port status on**
    
    13. **Add corresponding gateway in all PCs**

6.  **<span class="underline">Router connected with the network 2 from
    fast Ethernet 1/0</span>**
    
    14. **Double click on router **
    
    15. **Go to “config” tab **
    
    16. **Click fast Ethernet 1/0. **
    
    17. **Insert ip of the class as the network 2 have, subnet will
        automatically generate  
        make sure port status on**
    
    18. **Add corresponding gateway in all PCs**

7.  **<span class="underline">Pinging:</span> Go to the command prompt
    of any pc and ping any address in the network. If the address is
    correct you should get the reply packet from that PC.**

8.  **<span class="underline">Simulation Mode:</span> You can also go to
    simulation mode and make the real packet travel from one PC to
    another PC. **

# IN LAB STATEMENT 2: (10)

The Dynamic Host Configuration Protocol (DHCP) is a network protocol
that is used to configure network devices. DHCP allows a computer to
join an IP-based network without having a pre-configured IP address.
DHCP is a protocol that assigns unique IP addresses to devices, then
releases and renews these addresses as devices leave and re-join the
network.

Internet Service Providers (ISPs) usually use DHCP to allow customers to
join the Internet with minimum effort. The DHCP server maintains a
database of available IP addresses and configuration information. When
it receives a request from a client, the DHCP server determines the
network to which the DHCP client is connected, and then allocates an IP
address. DHCP servers typically grant IP addresses to clients only for a
limited interval.

Now you have to apply DHCP on Packet Tracer

  - **Make a topology with one router on which we will apply DHCP and
    several client PCs. More like this one,  **

![](media/image5.png)

You have to manually configure the Router which will assign dynamic ip
addresses to your PCs.

Open Command Line Interface of the Router

Enter “No” if it demands for configuration settings. “Continue with
configuration dialog? \[yes/no\]: no”

Next step is to enable the DHCP service on our router by typing the
following command

**Router\>enable //to enable the router configuration**

Now start configuration

**Router\#configure terminal //to configure the terminals of router**

It will prompt following lines

**Enter configuration commands, one per line. End with CNTL/Z.**

Now enter following commands, one per line

![](media/image6.png)//select interface

//assign address

//port status on

//exit interface

***For DHCP configuration***

**Router(config)\# ip dhcp pool *name ***

***To assign IPs starting from IP=192.168.1.2***

**Router(dhcp-config)\# network 192.168.1.2 255.255.255.0**

**Default Gateway of all**

![](media/image7.png)

//exit DHCP config

If you want to reserve some addresses for further use, enter command “ip
dhcp excluded addresses x-x”, (where x is the starting and ending IP
address respectively)

![](media/image8.png)

Else enter

![](media/image8.png)

It will prompt following lines:

![](media/image9.png)

Now, open the PC. 

Click on IP Configuration

Select from Static to DHCP

And after DHCP request is completed you will see the following screen.

![](media/image10.png)

It shows that you have configured the IP through DHCP.
