National University of Computer and Emerging Sciences

![](media/image1.png)

**Laboratory Manuals**

*for*

**Computer Networks**

(CL -307)

<table>
<thead>
<tr class="header">
<th>Course Instructor</th>
<th>Dr. Taimur Bakshi</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td>Lab Instructor(s)</td>
<td><p>M. Ali Umair</p>
<p>M. Salman Shoaib</p></td>
</tr>
<tr class="even">
<td>Section</td>
<td>CS-5A</td>
</tr>
<tr class="odd">
<td>Semester</td>
<td>Fall 2020</td>
</tr>
</tbody>
</table>

Department of Computer Science

FAST-NU, Lahore, Pakistan

> Lab Manual 04

# Objective: 

  - UDP Socket Programming

**UDP Socket Programming**

**<span class="underline">UDP (User Datagram Protocol):</span>**

UDP uses a simple connectionless transmission model with a minimum of
protocol mechanism. With UDP, computer applications can send messages,
referred to as datagrams, to other hosts on an Internet Protocol (IP)
network without prior communications to set up special transmission
channels or data paths. Following are its characteristics:

1\. There is no guarantee of delivery, ordering, or duplicate
protection.

2\. Ideal for network applications where we can tolerate data loss but
want to achieve low latency

# In lab Statement: \[20\]

Create a UDP based **Check in/Check out System.** In this system, the
user should be able to Check in and Check out from the system by sending
a data packet from its host machine. For instance

User **must** send a message with the following format

**YY-AAAA-CI (For check in) (e.g., 12-4159-CI)**

**Or**

**YY-AAAA-CO (For check out) (e.g., 12-4159-CO)**

**(YY-AAAA is your roll number)**

The system must get the packet sent by the client and must process the
packet accordingly. Your system must cater the following cases.

**Check in: **

  - Marks the in attendance of the client in a database of the students
    and returns a welcome message **“Welcome Student YY-AAAA”**

  - If the user is already checked in it must send the message **“You
    are already here.”**

**Check out:**

  - Marks the out attendance for the client from the student database
    and then fill the empty place in the database (e.g., if a student
    initially placed at place 5 has left then all the students above
    position 5 must come one position down to fill that position). The
    server must send the message **“Good Bye Student YY-AAAA\! Have a
    nice day.”**

  - If the user didn’t check in and sent the checkout packet, the server
    must return the message **“You didn’t check in today. Contact System
    Administrator.”**

> **<span class="underline">Note: </span>**

  - **You must print all the members present in the database each time
    client makes a request to check in or check out.**

  - **Server must not be restarted once started.**
