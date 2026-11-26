---
source_id: SOP17
original_file: 17-using_script_2026-11-10.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 27
source_sha256: f4b8dbc48736f4b34d2bd46c95c768d09251fbc31a22794d7552aa7750898d4e
verification: partial
verification_note: "All pages captured from PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or visually verified."
---

# Using the File API

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** Original-language text extracted page by page without summaries. Original slide pictures, source-code images and diagrams **not** in this text representation. The original PDF is required for complete visual content. Verification: **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                        Using the File API
                          Prof. Dr. Peter Braun



Slide 1:




Script

[Musik]




             1
````

## Page 002 — Learning Goals

````text
Slide 2: Learning Goals




Script

Welcome to this unit, where we will look at handling files under Linux in the C programming
language. Linux offers us, as software developers, a comprehensive interface to access the opera-
ting system’s resources. This includes, for example, memory management or creating processes
or threads. Instead of interface, we sometimes call this collection of functions API, which stands
for Application Programming Interface. Some Linux API functions are intended to handle files
and directories. Today, we will give you an overview of the most important functions for file
handling. However, we cannot go into the details too deeply due to time constraints. Today,
you will learn how to open and close files. In particular, you need to understand why it is
important to close files again. We will also discuss different ways of reading from and writing
to files. Finally, we will briefly show you how to deal with directories and their entries.




                                                2
````

## Page 003 — Open Files

````text
Slide 3: Open Files




Script

Let’s start with the function for opening files. The header file “Standard IO” defines a data
structure, i.e., a STRUCT in C with the name FILE. We use this data structure to manage file
access in a C program. Within our program, we need a pointer to such a data structure. You can
see this in the example above. The F open function is used to open a file. This function requires
two parameters. The first parameter contains the name of the file. The second parameter also
includes a character string describing the mode in which the file is to be opened. The function
returns a pointer to a data structure of type FILE. You will need this pointer for all other
functions to access the file. There are six modes, the first three of which are shown below. The
letter R indicates that the file already exists and should only be opened for reading. If you
open a file this way, you will receive an error message when you try to write to the file. You
can think of this as a safeguard to ensure that you do not accidentally write to a file or change
data in it. Opening a non-existent file for reading is not supported. That would be pointless.
The mode with the letter W opens a file for writing but not reading. If the file does not yet
exist, it is created. However, if the file already exists, it is first deleted in this mode and can
then be written again. Therefore, changing an existing file in this mode is impossible. Mode
A is used to add data to a file. If the file does not yet exist, it is created. However, if the file
already exists, data can be added to the existing file. However, this mode cannot be used to
write to any position in the file; it can only be used to add data at the end. This is also to be
understood as a safeguard to prevent existing data from being deleted or overwritten.




                                                 3
````

## Page 004 — More Modes to Open Files

````text
Slide 4: More Modes to Open Files




Script

As you have just seen, these three modes are insufficient to open a file for reading and writing
at any position. Therefore, there are now three more modes. They differ from the first three by
the “+” appended. The first mode in the list next to me is intended to open a file for reading
and writing. The file must already exist, so no new file is created. The second mode, “W+,”
also opens the file for reading and writing. In this mode, however, the file is emptied first if it
already exists. A new one is created if no file exists under the specified name. Finally, mode
A plus is used for reading and appending data. A new file is created if no file exists under the
name used. Existing files are, of course, not deleted beforehand. This would also be pointless if
a file were to be appended. “R+” is the most frequently used mode for reading and writing to
an existing file. This also allows you to change data at any point. Please note, however, that
the file must already exist in this case.




                                                4
````

## Page 005 — More Modes to Open Files

````text
Slide 5: More Modes to Open Files




Script

There are two more characters that you can enter when defining the mode for accessing a file.
Use the letter B to define access to a binary file. This means that the data is written exactly as
you specify it when reading and writing. This is also the default setting under Linux, meaning
you do not have to specify this letter to achieve this mode. If you are working with text files,
indicating this with the letter T in the mode may be useful. Some conversions are then carried
out when reading or writing data. The most important conversion here is the translation of the
special character “\{}N,” which stands for a line feed in C, into the respective representation
on the operating system on which the software will be executed. This conversion takes place
both when reading and writing. If you want to write your software portably from the start and
know that you are working with text files, you should start setting this mode T explicitly. Our
examples in this unit will deal exclusively with text files. For the sake of simplicity, however,
we will omit the T.




                                                5
````

## Page 006 — Example: Open File For Reading

````text
Slide 6: Example: Open File For Reading




Script

Here is the first complete example of working with a file. In line five, we declare a variable as
a pointer to the data structure named File. In line seven, we open the file named “Test.txt” for
reading. If the file does not exist, the F-open function returns NULL. We check this case in line
nine and then output a suitable error message in line ten. We end the program with an EXIT
command that indicates an error. In all other cases, we end the program successfully.




                                               6
````

## Page 007 — Writing Into File By Characters

````text
Slide 7: Writing Into File By Characters




Script

Now that we have opened a file, we first want to write data to this file. We start with the
simplest case. Use the F PUT C function to write a single character to a file. The character
that you want to write is passed as an integer value. You also pass the pointer to the file you
received as a result of the F open function. If the write was successful, the function returns a
numerical value greater than or equal to zero. An error case is characterized by the numerical
value -1. There is a constant for this with the name EOF, which stands for the end of the file.




                                               7
````

## Page 008 — Example: Writing Into File By Characters

````text
Slide 8: Example: Writing Into File By Characters




Script

Writing individual characters is not yet particularly convenient, but we can look at the first
somewhat longer example of writing text to a file. In line six, we define a character string with
the content Hello World. In line nine, we open a file for writing. In lines 10-12, we run through
all the characters of the variable output with the text Hello World in a while loop and write
character by character into the file. The notation in line ten with the asterisk followed by the
name of the variable output followed by two + means that we first access the memory cell
content to which the pointer output is currently pointing and then increment the pointer by
one position. This value at the memory location is then in variable C and is written in line
eleven of the file. For space reasons, we do not show the actual necessary handling of errors in
this example.




                                               8
````

## Page 009 — Reading From File By Characters

````text
Slide 9: Reading From File By Characters




Script

Next, we will examine reading individual characters from a file. The f-get-c function is used for
this and only requires a pointer to the file when called. The read character is returned to the
caller as a return value. If there are no more characters in the file to read, this is indicated by
-1 or the constant EOF.




                                                9
````

## Page 010 — Example: Reading From File By Characters

````text
Slide 10: Example: Reading From File By Characters




Script

Here is a quick example before we proceed to our first exercise. The file is opened in line eight.
In lines ten and eleven, we read individual characters with a while loop using the F GET C
function until the end character is reached. The “Put character” function in line 11 outputs the
read character to the console. Once again, for reasons of clarity, we do not use error handling.




                                               10
````

## Page 011 — Exercise 1: Reading From Files

### Exercise SOP17-E01 (source slide)

````text
Slide 11: Exercise 1: Reading From Files




Script

Now, we come to the first exercise for today. Please write a program in C to read letters from a
file. This file should already exist. At the beginning of this exercise, you should create a text file
on your system. In your program, please reserve memory for 20 characters in an array. Within
a loop, as you have just seen on the last slide, read in all characters up to the end of the file and
save them in the array. Now consider two different cases. Your program should work smoothly
if the file contains less than 20 characters. But what happens if the file is longer? Please try
it out. When you have finished your tests and want to see the solution, please click on the
button




                                                 11
````

## Page 012 — Screencast 1

````text
Slide 12: Screencast 1




Script

So let’s look at the solution. We only have to include standard IO here because we do some
file operations of course. And we implement everything in the main function. We need an array
where we store the data that we read from the file. And this array is 20 characters long. Then
we need a pointer to the file that we are going to open and read. We need some variable I as
a counter or as an index where to store the next character from the file into the array. And
we need some variable to keep the character that we just read from the file. So we open the
file and we check if there was any problem. And if opening was not successful we print some
error message. Otherwise now we start a loop. And for file operations it makes sense to use a
while loop because you read characters or maybe later lines as long as there is some condition
fulfilled. And the condition here is we read until we reach the end of the file. We store the
character in variable C and then we save this into the array. And at the end we have to add
the terminal symbol null so that the print statement will work later. We output this string to
the screen. And we exit with zero. And before that we have to close the file of course. So we
start the compiler. And before we start the program let’s have a look at the file here that we
are going to use for testing. And I think we have to shorten this for the first test so that we are
under 20 characters. And in this case everything works. And now we increase the length of the
file because the problem that we wanted to show is when the file is longer than 20 bytes what
happens then. So we edit the file. OK now that’s enough. We have more than 20 characters.
And you can see now the program crashes because we are writing into memory into a memory
area that is beyond the arrays of 20 bytes. And therefore we have some segmentation fault
here. And to solve this problem we only have to implement another condition here a kind of a
safeguard. So that we check that the value of I never becomes larger than the size of the array.
And we do this here in front of the first condition and we say I plus one is smaller than 20.
And this plus one comes from the terminal symbol for which we have to reserve one byte. So



                                                12
````

## Page 013 — Continuation / untitled

````text
actually we only can handle 19 characters from the file. We compile again. We start the file
again. And now you can see there is no problem with the output program does not crash. And
you can count the number of characters here and you will see this is exactly 19 and plus the
terminal zero we have 20 bytes. So keep in mind when you read data from a file always count
the number of characters.




                                            13
````

## Page 014 — Change Position in File

````text
Slide 13: Change Position in File




Script

You may have wondered how your program knows where a character is to be written in the
file or from which position a character is to be read. This pointer has nothing to do with
pointers in the C programming language, i.e., direct access to the memory. This pointer points
to the current position in the file for reading and writing. After opening a file with the F open
function, this pointer is always guaranteed to be at the very first character if it exists. If the
file is empty, this pointer is at the beginning of the file. Reading or writing characters always
advances this pointer by one position. It is, therefore, perfectly sufficient, as you have seen in
the previous examples, to execute the function F GET C or F PUT C in a loop one after the
other. The pointer is automatically carried along. In many cases, this is completely sufficient.
Sometimes, however, you may only want to start reading from a file from a certain position,
for example. Or, if you’re going to overwrite data in a file, you must first find the position at
which you want to write. There is the F SEEK function for this. This function first receives
the pointer to the file, then a value called the offset corresponds to the number of characters
by which the pointer is to be moved. This value is relative. There are three different options
for specifying the starting point, from which you can choose and which you must select as the
third parameter with the name Origin. You can see these three options next to me in the list
below. With the first value SEEK_SET you define that the offset value should be interpreted
relative to the start of the file. The last value, SEEK_END, corresponds to the end of the file.
With the SEEK_CUR command, the offset value will be interpreted relative to the current
position.




                                               14
````

## Page 015 — Close a File

````text
Slide 14: Close a File




Script

When you have finished editing a file, you must close this file again. The F Close function for
this purpose only expects the pointer to the file as a parameter. The return value shows possible
error cases. Closing files is necessary, and there are two reasons for this. Firstly, the number
of simultaneously open files in a Linux operating system is limited. In Linux, for example, this
value is 1024 files per process. If you open many files in your program but do not close them,
you may reach this limit at some point and no longer be able to open any new files. However,
a serious reason for this lies in how files are written. Only some functions called to write a
character to a file are written directly on the hard drive. Memory accesses may be held back
for performance reasons and are initially collected in the main memory. Only when you close
the file will the data on the hard disc be updated. So, if you forget to close the file, the file may
not be up to date at the end of the program.




                                                 15
````

## Page 016 — Writing Into File By Lines

````text
Slide 15: Writing Into File By Lines




Script

Writing to a file as a sequence of individual characters is tedious. With the F-put-s function, you
can write a sequence of characters to a file. You pass a pointer to the memory area containing
the characters to be written as the first parameter. As usual in the C programming language, we
assume that the value zero is the delimiting character. As usual, the second parameter points
to the file to be written. The function returns the number of characters written or indicates an
error by -1, i.e., the constant EOF.




                                                16
````

## Page 017 — Example: Writing Into File By Lines

````text
Slide 16: Example: Writing Into File By Lines




Script

This makes our program for writing a string a little easier. In line six, we create a memory area
with the text Hello World. The variable Output points to the first character. We open the file
for writing in line eight. In line ten, we call the new function F-put-s and pass the necessary
parameters. Finally, we closed the file in line eleven and ended the program successfully in line
13. Again, we have omitted the error handling for clarity. The F put s function writes all string
characters up to terminal zero to the file. A line feed is not automatically inserted. You must
write this line feed into the character string yourself if you require this.




                                               17
````

## Page 018 — Exercise 2: Write Into File In CSV Format

### Exercise SOP17-E02 (source slide)

````text
Slide 17: Exercise 2: Write Into File In CSV Format




Script

In the next exercise, you will write data to a file line by line. Please define a data structure in
your program to store a person’s first and last names. Create an array and store two or three
people in it. Now, write a function that saves this data about people in CSV format in a file.
A semicolon should separate first name and surname. You are welcome to compile the data
in a line yourself, or you can read about the F Print F function in the literature. Please also
remember the line feed at the end of each line. When you have finished and want to see the
solution, please click the button.




                                                18
````

## Page 019 — Screencast

````text
Slide 18: Screencast




Script

So we open the file here where you can see we have already defined a struct to contain first
name and last name of a person and we create now an array where we store the information
about two persons and for creating the persons we use this syntax using curly brackets here for
structs which makes it very compact to define person objects so we have bond and here with
first and last name and we store both in the array so now we open the file and we want to write
data into this file and the file should be cleaned so we use the mode w and we need to check if
this was successful and exit the program with an error message and a valid exit code here to
indicate this problem so now we store the data from the using a loop and in the loop we use
the printf statement which makes it very easy for us to create such a comma separated line and
the format string contains the first name the placeholder for the first name then the separator
key the semicolon then the last name the placeholder for it and line feed and we have to pass
the data and finally we close the file and we exit let’s go to the console and check if it works
okay we check the exit code this is zero everything was fine and this is the content of the file




                                              19
````

## Page 020 — Reading From File By Lines

````text
Slide 19: Reading From File By Lines




Script

Now that you have written data line by line to a text file, you need the function to read data
line by line. This function is called F GET S. As the first parameter, this function expects a
pointer to a memory area into which the data can be written. You are responsible for making
this memory area sufficiently large. As a security measure, this function expects a number
with maximum characters to be read as the second parameter. You must consider the terminal
character at the end of a character string. Typically, you enter the length of the array or memory
area you reserved here. The third parameter contains the pointer to the file. This function F
GET S now reads characters from the file and saves them in the specified memory area until the
end of a line or the maximum number of characters has been reached. An error during reading
is indicated by the return value NULL. If the read-in was successful, the function responds
better with the value in the memory area.




                                               20
````

## Page 021 — Example: Reading From File By Lines

````text
Slide 20: Example: Reading From File By Lines




Script

Here is another short example. In line six, we reserve space for 80 characters. In line eight,
we open a file for reading. Using the selection loop from line ten, we read the file line by line
and display it on the screen. As you can see, in line ten we specify the length of the array as
the maximum number of characters allowed per line. This means that if the line contains more
than 80 characters, the rest is ignored.




                                               21
````

## Page 022 — Exercise 3: Reading From File In CSV Format

### Exercise SOP17-E03 (source slide)

````text
Slide 21: Exercise 3: Reading From File In CSV Format




Script

In the second exercise, you wrote a function to save data about people in a CSV format file. In
today’s last exercise, you must write the corresponding function to read the data. Please read
the data line by line and reserve enough space to save the data. You must now separate the
lines at the semicolon and output the first and last name details separately on the screen. In
this exercise, it is unnecessary to save the data in the data structure for persons beforehand.
When you have finished or want to view the solution, please click the button.




                                              22
````

## Page 023 — Screencast

````text
Slide 22: Screencast




Script

We can start here using the given template. So we first have defined the struct in the top, then
we have the main function. We open the file for reading. If the file does not exist, we exit with
an error message and error code, and we expect the data from the file to be stored in this array
data. And finally, this is print to the screen. And now we have to fill the middle part where we
use a buffer array to read one line from the file. We use some index variable i to handle multiple
lines. And we have a temporary struct of person to store the data. Now we read the file line
by line using function fget s, where we pass the buffer to store the data, a maximum number
of characters that should be read, and of course the pointer to the file. And as long as we read
characters from the file, the condition is true, and the loop will continue. Now the question is,
how do we actually do the split? So the line is now in the buffer, and we use a function string
character to search for a character now in the given buffer, and we search of course for the
semicolon. And this function, be aware of this, this function does not return an index position,
of course a pointer. So now we have to copy first name and last name from this buffer into a
struct. And because in this case we only have one separator character here in the middle, and
before that we have the first name, after that we have the last name, we just copy the first part
of the buffer to the variable first name of the given struct, and we use as source the buffer. And
we can give here now in this copy statement the number of characters that should be copied,
and the number of characters is the difference between this pointer s, where the semicolon is,
and the beginning of the buffer. Now we copy the last name. This is simple now because we
can use the normal string copy function that checks for the terminal symbol. And we store the
struct now in the array, and as you know from the previous unit assigning structs really means
copying data. So now everything is copied into the array. And that’s all for the loop. And we
can go to the console, that would be the input file, we compile the program, and we start it,
and that’s the expected output.



                                               23
````

## Page 024 — Working With Directories

````text
Slide 23: Working With Directories




Script

To conclude today’s unit, we briefly look at working with directories. Next to me, you can see
some functions typically required for working with directories. We have divided the functions
into three groups. In the first group at the top, you can see functions for creating a directory,
below that for changing to a specific directory, and then the function for deleting a directory. All
functions accept the name of the directory as a parameter. When creating a directory, you must
also define the access rights. This is done using octal notation, which you must remember from
working on the Linux command line and the LS and CHMOD commands. The second group
only contains the function to determine the current directory. The operating system writes
the name of the current directory to the memory area to which you have passed the pointer.
Again, you specify the maximum length of this memory area so that it is not accessed after
the reserved memory. The third group of functions now allows you to read the contents of a
directory, i.e., practically the list of files or other directories. You first need to access a directory
using the open Dir function. Here, you pass the name of the directory. The return value is a
pointer to a data structure named DIR. With the second function, you read the elements of a
directory, i.e., files or other directories, one after the other. Here, you enter the pointer to the
data structure DIR as a parameter. When you have finished working with the directory, you
must close it again.




                                                   24
````

## Page 025 — Example: Print File Names In Current Directory

````text
Slide 24: Example: Print File Names In Current Directory




Script

Here is another small example. In this source code, we open the current working directory and
display all directories or files on the screen. In line eleven, we open the current directory. You
probably already know that the current directory is always available under Point. We read
element by element within the loop until the Readdir function returns NULL to indicate the
end. This function returns a pointer to a directory entry. This, in turn, is a data structure
from which we then retrieve the entry’s name using the attribute D-Name and display it on the
screen.




                                               25
````

## Page 026 — Summary

````text
Slide 25: Summary




Script

In today’s unit, we have given you a first impression of the functions from the Linux interface
that are important for handling files and directories. When opening a file, you have learned
about the different modes that can be used to distinguish between read and write access. You
have then learned about the functions of reading and writing individual characters and character
strings. You have seen that working with character strings in connection with files is not entirely
unproblematic in some places. As a software developer, you must always remember that you
have provided enough memory space to store the data from the file in the main memory. At the
end, we briefly demonstrated important functions for dealing with directories. You have seen
how to create and delete directories, and we have shown you an example of how to read all files
in a directory.




                                                26
````

## Page 027 — Literatur

````text
Slide 26: Literatur




Script

[Musik]




                      27
````
