> National University of Computer and Emerging Sciences
> 
> ![](media/image1.jpg)

# Laboratory Manuals

*for*

## Computer Networks

(CL -307)

<table>
<tbody>
<tr class="odd">
<td><blockquote>
<p>Semester</p>
</blockquote></td>
<td><blockquote>
<p>Fall 2020</p>
</blockquote></td>
</tr>
</tbody>
</table>

Department of Computer Science

FAST-NU, Lahore, Pakistan

**Lab Manual 02**

**Objectives: **

  - To learn basic commands of Linux related to Directory and File
    Manipulation, Process management and Network Management

  - GNU Debugger using a C Language Program

### In-lab Statement

#### 1\. Find out the purpose of the following commands and execute them on your system with different parameters. \[1\]

<table>
<thead>
<tr class="header">
<th></th>
<th><blockquote>
<p><strong>man chmod</strong></p>
</blockquote>
<table>
<tbody>
<tr class="odd">
<td>chmod</td>
<td>400 lab1.txt</td>
</tr>
</tbody>
</table>
<blockquote>
<p>Check what happened to your file.</p>
<p>Now write</p>
</blockquote>
<table>
<tbody>
<tr class="odd">
<td>chmod</td>
<td>700 lab1.txt</td>
</tr>
</tbody>
</table>
<blockquote>
<p>What happened to your file?</p>
</blockquote></th>
<th></th>
<th></th>
<th></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td><blockquote>
<p><strong>ifconfig</strong></p>
</blockquote></td>
<td><blockquote>
<p>ifconfig is used to configure the kernel-resident network interfaces.</p>
<p>If no arguments are given, ifconfig displays the status of the currently active interfaces. If a single interface argument is given, it displays the status of the given interface only; if a single -a argument is given, it displays the status of all interfaces, even those that are down. Otherwise, it configures an interface.</p>
</blockquote></td>
<td></td>
<td>ifconfig</td>
<td><table>
<thead>
<tr class="header">
<th>-a</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>eth0</td>
</tr>
</tbody>
</table></td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td></td>
<td><table>
<thead>
<tr class="header">
<th>ifconfig</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>ifconfig</td>
</tr>
</tbody>
</table></td>
<td></td>
</tr>
<tr class="odd">
<td><blockquote>
<p><strong>route</strong></p>
</blockquote></td>
<td><blockquote>
<p>Route manipulates the kernel's IP routing tables. Its primary use is to set up static routes to specific hosts or networks via an interface.</p>
</blockquote></td>
<td></td>
<td>route</td>
<td></td>
</tr>
<tr class="even">
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><blockquote>
<p><strong>ss</strong></p>
</blockquote></td>
<td><blockquote>
<p>The command is used to investigate socket statistics.</p>
<p>Use ss-u for udp and ss-t for tcp sockets to analyze which sockets are being used for which protocol.</p>
</blockquote></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><blockquote>
<p><strong>wget</strong></p>
</blockquote></td>
<td><blockquote>
<p>wget stands for "web get". It is a command-line utility which downloads files over a network. It supports HTTP, HTTPS, and FTP protocols, as well as retrieval through HTTP proxies. wget has been designed for robustness over slow or unstable network connections; if a download fails due to a network problem, it will keep retrying until the whole file has been retrieved. If the server supports rejects permission, it will instruct the server to continue the download from where it left off.</p>
<p>The simplest way to use wget is to simply provide it with the</p>
</blockquote></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td><p>location of a file to download over HTTP. For example, to download the file http://website.com/files/file.zip, this command:</p>
<table>
<tbody>
<tr class="odd">
<td>wget</td>
<td><blockquote>
<p><a href="http://website.com/files/file.zip">http://website.com/files/file.zip</a></p>
</blockquote></td>
</tr>
</tbody>
</table>
<p>Where will this file be downloaded?</p></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>traceroute</strong></td>
<td>traceroute prints the route that packets take to a network host. traceroute gives an insight to the entire path that a packet travels through, names and identity of routers and devices in your path, network latency (the time taken to send and receive data to each devices on the path). It’s a tool that can be used to verify the path that your data will take to reach its destination, without actually sending your data. Write on your terminal traceroute nu.edu.pk</td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><strong>nslookup</strong></td>
<td><p>nslookup is a network administration tool for querying the Domain Name System (DNS) to obtain domain name or IP address mapping or any other specific DNS record. It is also used to troubleshoot DNS related problems.</p>
<p>Write on your terminal window</p>
<table>
<tbody>
<tr class="odd">
<td>nslookup</td>
<td><blockquote>
<p><a href="http://www.google.com/">www.google.com</a></p>
</blockquote></td>
</tr>
</tbody>
</table></td>
<td></td>
<td></td>
<td></td>
</tr>
<tr class="even">
<td><strong>host</strong></td>
<td><table>
<tbody>
<tr class="odd">
<td>host</td>
<td><a href="http://www.google.com/"><span class="underline">www.google.com</span></a></td>
</tr>
</tbody>
</table>
<p>It is an alternative of nslookup but with more details. Write up on your terminal window:</p></td>
<td></td>
<td></td>
<td></td>
</tr>
</tbody>
</table>

####  3. Ping command: \[2\]

> Ping is a command that is used to check the connection and latency
> rate between two computers in a network. One network pings another in
> order to exchange data packets (Response) to calculate the latency and
> exchange rate.
> 
> Syntax for Pinging is:

#### ping \[other network’s ID (Domain/IP Address)\]

> **Question - You are required to ping at least 5 other networks
> (including your own address i.e. 127.0.0.1) and compare the
> <span class="underline">latency rate</span> of all networks. **
> 
> 4\. Write a C program to find out the host byte ordering (little
> endian/big endian) of your machine. Your program must output the byte
> ordering of your machine along with the data stored in the individual
> bytes e.g, you can store a number in hex as 0x3412 and visualize how
> data is stored in the memory (either in little endian or big endian).
> You must be able to debug your program using **GNU Debugger**
> **i.e.,** to view variable values during running program, to insert
> breakpoints, to check some condition etc. **\[3\]**
> 
> • **Hint: C has a datatype short. It takes 2 bytes. Now, you can store
> some data in your short datatype and read memory byte wise. Well you
> can use other datatypes too.**

### Post Lab \[5\]

> Write a C Program to find out the Average CPU Utilization Percentage
> in Linux System over the entire time your program is executing. You
> can read the first line of the file named stat having the path
> “/proc/stat” to get the string depicting the CPU usage. It will look
> like this:
> 
> **cpu %user %nice %system %idle %iowait %irq %softirq**
> 
> You will then parse the string to extract the relevant information and
> print it out on the terminal. As this file keeps on getting updated,
> so you have to keep on reading the file in an infinite loop, process
> the information and then print the Average CPU utilization percentage
> on the terminal. You have to read the two samples with a gap of 1 sec
> and find out the average CPU utilization percentage over these two
> intervals with this sequence repeating indefinitely.
> 
> **Hint: The time CPU has remained idle is represented by %idle and
> %iowait fields.**
