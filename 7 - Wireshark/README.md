National University of Computer and Emerging Sciences

![](media/image1.png)

**Laboratory Manuals**

*for*

**Computer Networks**

(CL -307)

Department of Computer Science

FAST-NU, Lahore, Pakistan

**Lab Manual 07**

# Objective:

  - Analyzing the **FTP** packets using Wireshark

  - Analyzing the **ICMP** packets using Wireshark

**PREVIOUS Lab Statement 2: Trick Question (5)**

**Use the http-ethereal-trace-3 (Wireshark Capture File)**

What is the length of the text for The Bill of Rights in bytes? How do
you justify this length of text when your Response Packet Size is only
490 bytes? Give complete explanation how the length of text in various
packets add up to a total of 4500 Bytes.

**Lab Statement 1: Capturing FTP packets using Wireshark (10)**

**<span class="underline">Step 1</span>**: **Start a Wireshark
capture.**

> **a.** Close all unnecessary network traffic, such as the web browser,
> to limit the amount traffic during the Wireshark capture.
> 
> **b.** Start the Wireshark capture.

**<span class="underline">Step 2</span>: Download the .txt file.**

> **a.** From the command prompt, enter ftp
> [<span class="underline">ftp.mcafee.com</span>](ftp://ftp.mcafee.com)
> 
> **b.** Log into the FTP site for mcafee.com with user **anonymous**
> and no password.
> 
> **c.** Locate and download any .txt file.
> 
> ![](media/image2.jpeg)

**<span class="underline">Step 3:</span> Stop the Wireshark capture.**

**<span class="underline">Step 4:</span> View the Wireshark Main
Window**

Wireshark captured many packets during the FTP session to
[<span class="underline">ftp.mcafee.com</span>](ftp://ftp.mcafee.com).
To limit the amount of data for analysis, type **tcp and ip.addr ==
195.89.6.167** in the Filter. The IP address, **195.89.6.167**, is the
address for
[<span class="underline">ftp.mcafee.com</span>](ftp://ftp.mcafee.com).

**<span class="underline">Step 5:</span> Analyze the packets**

Carefully analyze the packets in Wireshark windows and answer the
following question:

> **Use the FTP\_Session.pcapng (Wireshark Capture File) to answer the
> questions below**

1.  FTP uses two port numbers: 20 and 21. Apply **tcp.port==20** and
    **tcp.port==21**. Analyze the result and write down the purposes of
    these two ports for FTP.

2.  Filter out each packet using either FTP or FTP-DATA Protocol (using
    **ftp || ftp-data** filter). Mention each packet number and its
    purpose with reference to request made and response received in the
    above mentioned FTP Session in command line to get file legal.txt
    (screenshot show above). Also look for **Response Code** and
    **Response Arg** in the FTP Header for each packet

> **(**There are **19 such packets** and you have to write one/two lines
> explanation for each packet, what the packet is doing w.r.t FTP
> Session (Screenshot shown above) **e.g., Packet 104: Client asks
> server to send the data on IP:192.168.1.2 and Port:16341**
> \[63(0x3F),213(0xD5) and **(0x3FD5=16341**)**\] )**

**<span class="underline">Lab Statement 2:</span> Analyzing ICMP Packets
using Wireshark (10)**

  - **Step 1:** Run Wireshark

  - **Step 2:** Load the Session file **ICMP\_Session**

  - **Step 3:** Now filter out all non-ICMP packets by typing “icmp”
    (without quotes) in the filter field towards the top of the
    Wireshark window

  - **Step 4:** Analyze the ICMP Packets and answer the following
    questions strengthened with screenshots

<table>
<thead>
<tr class="header">
<th><ol start="10" type="1">
<li><p>Are ICMP messages sent over UDP or TCP?</p></li>
</ol></th>
<th></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td><ol type="1">
<li><p>What is the link-layer (e.g., Ethernet) address of the host?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="even">
<td><ol start="2" type="1">
<li><p>Which kind of request is sent through these ICMP packets?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="odd">
<td><ol start="3" type="1">
<li><p>How many requests are sent through the host?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="even">
<td><ol start="4" type="1">
<li><p>What is the IP address of your host? What is the IP address of the destination host?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="odd">
<td><ol start="5" type="1">
<li><p>Why is it that an ICMP packet does not have source and destination port numbers?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="even">
<td><ol start="6" type="1">
<li><p>What values in the ICMP request message differentiate this message from the ICMP reply message?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="odd">
<td><ol start="7" type="1">
<li><p>Examine one of the ping request packets sent by your host. What are the ICMP type and code numbers? What other fields does this ICMP packet have? How many bytes are the checksum, sequence number and identifier fields?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="even">
<td><ol start="8" type="1">
<li><p>Examine the corresponding ping reply packet. What are the ICMP type and code numbers? What other fields does this ICMP packet have? How many bytes are the checksum, sequence number and identifier fields?</p></li>
</ol></td>
<td></td>
</tr>
<tr class="odd">
<td><ol start="9" type="1">
<li><p>Examine the packet no 56. What are the ICMP type and code numbers? Why is the IP and TCP Header included in the ICMP Header? What does these headers depict?</p></li>
</ol></td>
<td></td>
</tr>
</tbody>
</table>
