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
<td></td>
<td></td>
</tr>
<tr class="even">
<td></td>
<td></td>
</tr>
<tr class="odd">
<td><blockquote>
<p>Semester</p>
</blockquote></td>
<td>Fall 2020</td>
</tr>
</tbody>
</table>

Department of Computer Science

FAST-NU, Lahore, Pakistan

**Lab Manual 01**

**Objectives:**

  - Introduction to GCC Compiler

  - Revision of Programming Concepts with C Programming Language

**GCC Compiler:**

In this lab, we will use the GCC Compiler on Ubuntu to Compile the
programs in C Language and we will use POSIX Thread Libraries for
multithreading in the later part of the lab. One important thing to note
is that you will not be provided any IDE to code in C Language. You will
use a simple text editor to code in Linux which is called GEDIT. The
text editor will not provide you any help in coding. You will have to
write out the correct code yourself without any errors (we expect this
from you in 5<sup>th</sup> semester).

After you have written your code, you will save your file with *\*.c*
extension e.g *MyCode.c* and then you will move to the directory where
you have saved your file from your home folder using command line in
Ubuntu. To list the files and folders in the current directory you can
simply write “ls” command. To move into any directory you have to write
“cd \<directory\_name\>”. To go directly into home directory we simply
write “cd”. To go one step down in the hierarchy of directories we write
“cd ..”.

  - To **COMPILE YOUR FILE** using gcc compiler you first have to go to
    the directory where the file is placed and then you will write the
    following:

> ***gcc \<file\_name\>.c –o \<executable\_fileName\>***

If there is any error in your code then compiler will tell you those
errors and you will correct them. If there will be no error you will see
an executable formed in the same directory having a diamond like shape.

  - Then you will **RUN YOUR EXECUTABLE** by issuing the following
    command in the directory where your executable is placed:

> ***./\<executable\_fileName\>***

Make sure you write the correct file name in any case otherwise you will
get error. You can use **TAB** after writing two to three letters of
file and it will auto complete your file name for you.

  - To open the terminal you will either open it using GUI or press
    “**Ctrl+Alt+T**”. To open two windows in the same terminal you
    will use “**Ctrl+Shift+T**”. To paste something in the Terminal you
    will press “**Ctrl+Shift+V**”**.** To copy something from your
    terminal you will use “**Ctrl+Shift+C**”. To terminate any running
    program you will use “**Ctrl+C**” or “**Ctrl+Z**”.

**In Lab Statements:**

**1. Write a code in c which performs the following functions:**

1.  Reads the text file Input\_File.txt and displays its data on
    terminal. **\[3\]**

2.  Write only the integers from the Input\_File.txt file to another
    file which will be created at runtime. **\[3\]**

3.  Write non-alphabet words (non-alphabet word is the one in which all
    letters are nonalphabet e.g., “a\#$2\#” is not a non-alphabet word
    but “$%^&\#32” is a non-alphabet word) from the Input\_File.txt file
    into another text file which will be created at run-time.

> **\[6\]**

4.  Invert all the words in Input\_File.txt file which contain one or
    more vowels and write the complete content (with inverted and
    non-inverted words) into another file which will be created at run
    time. For example ‘computer’ will be inverted to ‘retupmoc’.
    **\[8\]**
