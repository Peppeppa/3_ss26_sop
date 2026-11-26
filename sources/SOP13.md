---
source_id: SOP13
original_file: 13-pointers_script_2026-10-27.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 28
source_sha256: 1ba92afd0e2a7ecff5b4c0b38fa12902f378d4823c009ce5d4c023afab754a2f
verification: partial
verification_note: "All pages captured from PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or visually verified."
---

# Pointers and Memory Management in C

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** Original-language text extracted page by page without summaries. Original slide pictures, source-code images and diagrams **not** in this text representation. The original PDF is required for complete visual content. Verification: **partial**.

## Page 001 — Script

````text
              System-oriented Programming
           Pointers and Memory Management in C
                                Prof. Dr. Peter Braun



Slide 1:




Script

[Musik]




                1
````

## Page 002 — Goals of this Unit

````text
Slide 2: Goals of this Unit




Script

Welcome to this unit as part of our introduction to the C programming language. Today, we
will be looking at a very important topic. In addition to the primitive data types for characters
and numbers, there are also data types for so-called pointers in the C language. Simply put,
a pointer contains the address of a memory cell. This allows us to read data directly from the
memory and write changes directly to the memory. Using pointers or addresses is common if
you work closely with the processor. For example, the Assembler language has instructions on
how to copy data from the memory to a register using an address. This concept was adopted in
the C language as it should also be possible to program close to the hardware with C. Nowadays
and in modern programming languages, however, this pointer type no longer exists, or only to
a very limited extent. First, we will show you how to work with addresses in a C program.
Then, we will show you some examples that will teach you why it makes sense to use addresses.
Finally, we need to draw your attention to some dangers. The incorrect use of pointers is often
the cause of program crashes and severe security problems.




                                               2
````

## Page 003 — Motivation for Pointers

````text
Slide 3: Motivation for Pointers




Script

Let’s start with a simple example of why pointers are useful and necessary. You can see the
Swap function in the source code next to me. It expects two integer parameters. The task that
should be solved with this function is to swap the contents between these two parameters. To do
this, we first save the value of parameter X in a temporary variable in line 4. We then overwrite
parameter X with the value of Y in line 5. And finally, in line 6, we copy the value from the
temporary variable to Y. However, if you now call this function within your main program, as
you can see in line 11, you will notice that the intended exchange of values has not worked. This
is because how values are passed as parameters to functions in the C programming language
works exclusively according to the so-called call-by-value principle. The value of the variable
A is copied to the parameter X. However, changes to parameter X are not visible in the main
program. The screen output in line twelve still shows the values A equal to ten and B equal to
20.




                                               3
````

## Page 004 — Pointers Basics

````text
Slide 4: Pointers Basics




Script

[Musik]




                           4
````

## Page 005 — Pointer Variables in C (1)

````text
Slide 5: Pointer Variables in C (1)




Script

Now, let’s look at how to handle pointer variables in C. In line four, we declare two variables,
A and B. In the next line, we declare a pointer variable named PA. At this point, we can even
specify that this pointer should point to an integer number. To declare a pointer variable, write
an asterisk before the variable name. In the source code examples in this unit, we always mark
pointer variables with the letter “P” at the beginning of the name. The P stands for pointer.
In practice, marking pointer variables in this way is not common. In line seven, we assign the
number 1 to the variable A. In the next line, we determine the address of this variable in the
memory using the operator ampersand, which precedes the variable A. We then assign this
address to the variable PA. Instead of address, we will also use the term reference. You can
imagine the memory as a very long list of memory cells; each memory location can store exactly
one byte. Each memory location has a number; it is very easy to imagine that the first memory
location has the number zero, the next the number one, and so on. We call this number the
address of the memory cell. The variable A is now somewhere in the memory and occupies four
bytes. We use the ampersand operator to determine the address of the first byte. We also call
this operator the address operator because it is used to determine addresses. The address is now
in the variable PA. In line ten, we assign the value two to this pointer variable. But beware, this
instruction is only for demonstration purposes. Although it is syntactically correct, the content
is completely wrong. We do not know what data is in memory location two. It is possible that
this address no longer belongs to our process. Such incorrect use of an address often leads to a
program crash.




                                                5
````

## Page 006 — Pointer Variables in C (2)

````text
Slide 6: Pointer Variables in C (2)




Script

What we want to do here is to write the number 2 to the location in the memory to which the
variable PA points. To achieve this, we write an asterisk before the variable name PA in line
twelve. We call this asterisk the dereferencing operator. Dereferencing means the resolution of
an address. This indicates we do not want to overwrite the variable PA but the memory cell to
which PA points. This also works with read access. You can see this in line 13, where we access
the memory cell content pointed to by PA on the right-hand side of the assignment operator.
We use the asterisk again here. As a result, variable B now contains the content of the memory
cell to which PA points.




                                              6
````

## Page 007 — Operators for Address and Dereference

````text
Slide 7: Operators for Address and Dereference




Script

Using another example, we would like to explain the relationship between normal and pointer
variables. You can see a short source code example next to me above, which we will now go
through line by line. We will then use the image next to me to explain the changes in the
memory. In the first line, we create a variable X of the data type integer and assign it the value
four. In the memory, this variable X is stored at position 16, for example. This means that
the address of the variable X is 16, where we also see the content of the variable, namely the
number 4. In the second line, we create the variable Y and assign the value ten. This variable is
located in memory at position 24, for example. The variable PA is to be a pointer variable. Of
course, this variable also occupies memory. This variable PA should now be located at memory
location 36. The value 112, which we assigned in line three, is located there. Please note the
special syntax here. We must type-cast the number 112 to be an address. Also, please note
that this assignment of a specific memory address is only for demonstration purposes. This is
different from how it is done in practice. In line four, we reference the variable PA, i.e., we look
at which memory location this variable points to. To do this, we use the content of the variable
PA, namely 112, and interpret this number as an address. After assigning the number 6, the
memory location 112 now contains the number 6.




                                                 7
````

## Page 008 — C and Memory: Working with Addresses

````text
Slide 8: C and Memory: Working with Addresses




Script

Even as a beginner in the C programming language, you quickly come into contact with the
address operator. We also had to use this address operator in our first unit. In C, for example,
the Scan F function is used to read data from the user. This function requires an address as
the second parameter to store the read-in data in the memory via the keyboard. Lines six and
seven show two possible ways of writing this. In line six, we pass the address of the variable
A and use the address operator here. If we already have a pointer variable in another way, we
can pass this pointer as the second parameter. You can see this in line seven next to me. Why
is this made so complicated? Why does the address of a memory area have to be passed as a
parameter here? Why couldn’t the Scan F function offer the user’s input as a return value?
Please pause the video for a moment and think about these questions.




                                               8
````

## Page 009 — Solution

````text
Slide 9: Solution




Script

In practice, user entries can be as long as required. However, the Scan F function would have
to request memory space from the operating system to save the input. The Scan F function has
no way of estimating this length. Therefore, the possibility of returning the input to the caller
as the result of the Scan F function is ruled out. Only the caller has any chance of estimating
the input length. Therefore, the caller is responsible for reserving sufficient memory from the
operating system. Only the address of this memory area is passed to the Scan F function. If
this memory’s size is insufficient, the Scan F function will continue to write data to the memory
anyway. There is then a very high probability that the program will crash.




                                               9
````

## Page 010 — Function Swap: Fixed

````text
Slide 10: Function Swap: Fixed




Script

With this knowledge, we can correctly implement the Swap function from our first example.
Instead of two integer numbers, the swap function expects two pointer variables as parameters.
Within the swap function, we first save the value of the memory location to which PX points
in the temporary variable. Then, we overwrite the memory to which PX points with the value
of the memory to which PY points. Finally, we write the value of the temporary variable to
the memory at the address stored in the variable py. When calling the Swap function in line
eleven, we use the address operator and now pass the addresses of variables A and B. With
the help of pointer variables, we have now realized a way of parameter passing named “call by
reference.” Instead of a value, we pass a pointer or the address of this variable. Changes to the
memory locations to which the pointer variable points are also visible to the caller.




                                               10
````

## Page 011 — Pointer Examples (1)

````text
Slide 11: Pointer Examples (1)




Script

We want to show you some examples of how to work with pointer variables or addresses and
simple arithmetic operations. The brackets are particularly important here, and you should
learn the priority with which the operators are processed from these examples. Please don’t
panic; we will go through each line step by step. In lines two and three, we create two variables,
X and Y. The variable X has a value of ten at the beginning. In line five, we create a pointer
variable PX and assign the address of X to it. In line six, we use the asterisk for de-referencing.
So we get the number that is stored at the address PX and add one to it. The result 11 is stored
in Y. In line seven, we take the address PX and add one. We de-reference this new address and
assign the result to the variable Y. This expression is permitted, but we cannot say what value
Y now has. With the +1, we access the memory 4 bytes further up and, from there, access
an integer with a length of 4. The four comes from the fact that an integer value occupies 4
bytes.




                                                11
````

## Page 012 — Pointer Examples (2)

````text
Slide 12: Pointer Examples (2)




Script

As we cannot say what is stored there, we cannot specify the value of y. This instruction might
even cause the program to crash because we are accessing memory that may not belong to us.
Line nine is a compact notation to increase the value at the memory location to which PX
points by one. The next two lines have the same effect. However, please note the necessary
brackets. The plus-plus operator has a higher priority than the de-referencing operator. If we
omit the brackets in line ten, the pointer PX would first be moved one position to the right,
and then the referencing would take place. The plus-plus operator considers the data type of
the pointer and does not move the address one byte to the right but four. No brackets are
necessary in line eleven because the de-referencing operator is now closer to the variable than
the plus-plus operator. In line 13, we dispense with the brackets, and the following happens.
The plus-plus operator binds with a higher priority than the de-referencing operator. However,
the incrementing is only carried out after the assignment. In this instruction, Y receives the
memory value to which PX points and then increments the pointer by one position depending
on the data type integer, i.e., by four bytes. In line 14, the plus-plus is written before the
variable PX, which means that the incrementing takes place before the value is accessed. The
pointer is now first moved four bytes to the right, and Y then receives the value of the memory
to which PX now points. All these rules seem very confusing, which is one reason why source
code in C is so difficult to read, especially when working with pointer variables.




                                              12
````

## Page 013 — Pointers Extended

````text
Slide 13: Pointers Extended




Script

[Musik]




                              13
````

## Page 014 — Pointer Example: Arrays

````text
Slide 14: Pointer Example: Arrays




Script

Pointer variables and data fields are closely related, and we would like to illustrate this relati-
onship in this source code. In line four, a data field with 255 bytes is created. In line five, we
create a pointer to a single character. The variable input is practically an address so that we
can assign the value of this variable to the pointer PE1 in line five. The instruction in line six
has the same meaning. We use the square brackets to access the first element of the data field
named “Input” and use the address operator to obtain the address of this first element. In the
next block with lines 8-10, we show three Print F statements that all deliver the same result.
We can access the sixth element of the data field using the typical notation in square brackets.
We first add five to the address in the variable input and then use de-referencing. Or we can
use the pointer PE1. However, there is a difference between pointer variables and data fields.
In line twelve, we increase the value of the variable PE1 and thus move the pointer one byte
to the right. Although the variable input also contains an address, the plus-plus operator for
incrementing is not permitted. The value of the variable input must remain the same. Similarly,
we cannot assign a different address to the variable “input.”




                                                14
````

## Page 015 — Pointer Arithmetic

````text
Slide 15: Pointer Arithmetic




Script

Data fields are accessed using the Index Position notation in square brackets. You will remember
this from the last unit when we dealt intensively with data fields. If we pass a data field to a
function, the call-by-value principle is also used here, but /not/ regarding the full array, but,
and this is now very important, regarding the address. Even if you used the square-bracket
syntax in the parameter. In contrast, when we work with arrays in C, we use the pointer syntax
using the asterisk. In line 2, besides me, we pass an address to a char array as a parameter,
and this is the address of the first element at index position zero. If you have a pointer to an
array inside the function and want to access different index positions, you also don’t use the
square-bracket syntax anymore, but you use pointer arithmetic, which means you do address
calculations. This looks a bit strange in the beginning, but it is the most natural thing in C.
Look at the example next to me, where we implement a function for calculating the length of a
character string. In line three, this new function expects a pointer to a character string. First,
we copy the address into a new variable named “X” because we need this value later. Now, we
run through a WHILE loop as long as the value to which the variable X points in memory is
not zero. Zero is the end indicator for a character string. In each loop iteration, we move the
pointer X one position further, i.e., one character to the right. The data type’s size is always
considered when dealing with such arithmetic operations and pointer variables. As this is a
pointer to a character, the pointer is moved one byte further in line six. Once we have reached
the end of the character string, we return the difference between the current value of X and
the start address A as the length of the character string. The Main function beginning in line
ten only demonstrates that the function has been implemented correctly. Working with pointer
variables in this way is typical for programming in C. Arithmetic operations on pointer variables
are summarised in the C programming language under the keyword pointer arithmetic.




                                               15
````

## Page 016 — Exercise 1: Pointers

### Exercise SOP13-E01 (source slide)

````text
Slide 16: Exercise 1: Pointers




Script

Let’s now move on to the first exercise of today’s unit. Like the function for calculating the
length of a character string we have just presented, you should now implement your function
for copying character strings. You can see the desired signature of the function next to me in
line three. The function expects two parameters. The first parameter is a pointer to the target
area, and the second parameter points to the source. Within the function, characters should
be copied from the source to the target character by character until they reach the terminal
symbol. You can and must also assume that the memory area to be copied to is sufficiently
large. Please test your function with a main function that should look similar to the example
next to me. Please click the button when you are finished or want to see the solution.




                                              16
````

## Page 017 — Screencast

````text
Slide 17: Screencast




Script

So let’s start editing a new file for this exercise. We first have to include standard IO because
we later want to print something to the screen. And then we define our function myStringCopy.
And the first parameter is the destination and the second parameter is the source. This is quite
usual in C that the destination is always the first and the source is the second parameter. Now
we can implement this copying of strings in a very very compact form. Actually at the end it’s
only one line of code. And in the condition of this while loop we do the assignment from the
source position to the destination position. And after the value has been copied we increment
the pointer for the destination but also for the source. So we move the pointer one position
to the right in the source pointer but also in the destination pointer. And then the last part
of this condition is now we do this copying while the value that we copy here is not equal to
zero. So and that’s all. This while loop actually does not have anybody because we do this the
work the assignment already in the condition. So and that’s all. Now we have to write a main
function here. We test this function. We first create a string hello world then we provide some
space for the target. This is usually done in a different way here but for our examples here in
this unit it’s enough to know this can be done with arrays. Then we copy the string using our
new function here and finally we print the value of the target to the screen. So let’s compile
this and we execute this and you can see it works. So this implementation of this while loop is
a good example how to do this copying in a very very compact form using pointers.




                                               17
````

## Page 018 — Pointers Example: Arrays Extended

````text
Slide 18: Pointers Example: Arrays Extended




Script

It is also possible, and in practice, it is not uncommon to combine data fields and pointers.
We want to show you two examples of this. In the first line, we declare an ARR variable as a
data field in which the elements represent pointers to integer variables. In the second line, the
brackets create a different meaning. Here, we declare an ARR variable as a pointer to a data
field of ten integer variables. You can use the rule below next to me when reading and writing
such declarations. Go to the right if you can and to the left if you must. When applying this
rule, we always start with the variable’s name. In the first line, starting from the variable’s
name, we can now go to the right and find the notation with square brackets for creating a
data field. We can, therefore, say that the variable ARR is a data field. Now that the line has
ended, we have to go to the left and find the asterisk and the data type integer in front of it.
So, we can now say that the variable ARR is a data field of pointer variables to integers. In
the second line, we are forced by the brackets to go to the left, starting from the name of the
variable. We now have the asterisk; therefore, we can say ARR is a pointer. Now comes the
question of what this variable points to. We can go to the right and find the square brackets for
the data field. This describes the variable ARR as a pointer to a data field with ten elements
of type integer.




                                               18
````

## Page 019 — Exercise 2: Array Pointers

### Exercise SOP13-E02 (source slide)

````text
Slide 19: Exercise 2: Array Pointers




Script

The second exercise gives an outlook on what we want to discuss afterward. But first, please
think about what the definition next to me means. The difference is that two asterisks are now
in front of the variable foo. Please apply the rule you have just learned. Please click the button
if you have a result or want to see the solution.




                                               19
````

## Page 020 — Screencast

````text
Slide 20: Screencast




Script

We want to understand what this statement or expression that was on this slide really means.
So we open a new C file and so here we don’t need any standard IO because we don’t want
to print anything but we directly copy what was written on the slide. So we have a long with
two stars here and a variable name foo with ten elements and we want to find out what can
be assigned to this foo variable so therefore we start with a long variable a which is initialized
with one and now we could apply this rule that you have learned before. Go to the right if you
can go to the left if you must. So we can assume foo is an array of pointers but the question
remains open what does the second star mean. So first we could try to assign a long value to
foo at index position zero. So it is fair to assume that this will not work but let’s see what GCC
says to this. And the error message here is actually it’s only a warning says that we cannot
do this assignment here because we have different data types and without a cast, cast always
means we change the data type and this would be not safe way to do this assignment here.
So we go back to the source code and the next idea would be that we don’t assign value A
but the address of A. So therefore now we would assume that foo at index position zero is a
pointer. Let’s check this. So the warning message has changed but still we have an incompatible
pointer assignment here. So what is expected is written on the left side long int two stars. So
we could assume now that we it might be possible to write two ampersand signs here. So this is
completely wrong but this has a completely different meaning in C so this also does not work
and but we are very close to the solution. The only problem is that it is not allowed to do
these two ampersand signs because we cannot determine the address of the address. We must
always go via a temporary variable. So we initialize here a pointer P A with the address of A
there then we have some memory position where we store P A and then we can ask for the
address of P A and that’s actually now the solution and we can check what GCC does and for
GCC this is okay now. So what you should learn from this exercise is that if you want to have



                                               20
````

## Page 021 — Continuation / untitled

````text
this pointer of pointer thing you must go via a temporary variable because otherwise it’s not
allowed to determine addresses.




                                             21
````

## Page 022 — Pointer of Pointers

````text
Slide 21: Pointer of Pointers




Script

When declaring a variable, an asterisk means that the variable should be a pointer. As you have
seen in the exercise, two asterisks mean it is a pointer to a pointer. Now, unfortunately, things
are getting a little abstract. Let’s take a look at a short section of the source code. Variable
PA is a pointer to an integer variable variable. PPA is the pointer to a pointer to an integer
variable. The instructions in lines six and seven are now familiar. The variable PA now contains
the address of the variable a. In line nine, we use the address operator on the variable PA and
save the address of the memory area in which the variable PA is located in the variable PPA. In
other words, the variable PPA contains a pointer to a pointer to an integer variable. In line ten,
we then use the double de-referencing operator to change this variable A. The only question
remains: When do you need something like this? If you manage an array with pointers, and
since an array is equal to a pointer, we already have a pointer to pointers here. You often find
this, for example, when you have to manage a data field of character strings. Since a pointer
describes a character string, a data field of character strings is a pointer to a pointer of type
Character. It’s just a matter of dimensions.




                                               22
````

## Page 023 — Pointers and Functions

````text
Slide 22: Pointers and Functions




Script

Pointers cannot only point to data but also to functions. Please look at the example next to
me. In line six, we define a function with the name random, which accepts no parameters and
returns an integer. In the main function, we then call the function foo in line eleven and pass
the address of this function as a parameter. We use the same notation here when determining
the address of a variable. We define this function foo in the first line. Please pay attention
to the spelling when declaring the parameters. The parameter F is preceded by an asterisk,
which indicates a pointer. The brackets before the asterisk and after the F suggest that it is
a function pointer. The round brackets at the end could be used to indicate the signature of
the function that is expected here. The foo function expects a function without parameters
but which returns an integer value. Within the function, we call the function F in line 2. We
save the return value in R and then use it in line three. In other words, the Foo function only
defines a framework for running an algorithm. It delegates a calculation step to a function F,
which is expected as a parameter for this function. This allows us to parameterize the sequence
of algorithms elegantly. In some use cases, this technique of passing a pointer to a function is
named a callback.




                                              23
````

## Page 024 — Pointers and Structs

````text
Slide 23: Pointers and Structs




Script

In the last unit, you learned about the concept of data structures. Several elements, possibly
with different data types, are summarised under a new name. In lines 1-4, we define a data
structure with the name Person, which consists of the first and last name. We can also determine
the addresses for structures; you can see an example in line eight. To access the elements of a
data structure, we learned about the so-called dot notation in the last unit. The variable James
contains such a structure. The first name is then accessed as in line eleven next to me. However,
if a variable contains a pointer to a structure, you can no longer work with dot notation to
access the elements but with an arrow instead. You can see an example of this in line twelve.
In conjunction with the address operator and the de-referencing operator, this results in the
notations in lines 13 and 14. If there is already a structure pointer, we can resolve this first with
the de-referencing operator and then work with the dot notation. Conversely, we can determine
the address of a data structure and then access an element using the arrow operator.




                                                 24
````

## Page 025 — Exercise 3: Pointers Extended

### Exercise SOP13-E03 (source slide)

````text
Slide 24: Exercise 3: Pointers Extended




Script

In today’s last exercise, you will practice using data structures and pointers. Firstly, please
create a new data structure named Person. This data structure should contain the first and last
name of a person. Now, define a new function to read the first and last name of the user. The
function should expect a pointer to a data structure of type Person. Use the scan f function to
read the data and save the input directly in the data structure. Please click the button when
you have finished the exercise or want to see the solution.




                                              25
````

## Page 026 — Screencast

````text
Slide 25: Screencast




Script

So let’s start a new file for this last exercise in this unit. As usual we start with standard IO
because we need to print something and in the last units you have heard that in C normally it
is a call by a value principle when calling a function but with pointers it is possible to have this
call by reference and we now want to demonstrate this using structures so we define a new or
we define a struct again that contains first name and last name in this case we don’t need the
age information here then we implement a function foo and here as a parameter now we pass
a pointer to a struct of person and we are asking for some data now so for the first name and
we use scanf to read data from the user and since somebody is now pointer we have to use this
arrow notation to select the first name of the struct then we ask for the last name and we do
the same here somebody and then pass the last name and we test this using a main function
where we create a structure and then we pass the address of this struct to function foo and
finally we print first name and last name and since Oliver is now here let’s say a normal variable
not a pointer we can use the dot notation again we call GCC and we type in first name and
last name and that’s the result




                                                26
````

## Page 027 — Summary

````text
Slide 26: Summary




Script

So, that’s all for today. Today, we have dealt with the very important topic of pointer variables.
Normally, parameters are passed to functions as a value. You can use pointers to realize the
call-by-reference principle. Changes to the variables within the function are thus directly visible
to the caller. Pointers are also used to implement so-called dynamic data structures very often.
For example, linear lists in which a list element also contains a pointer to the next list element
in addition to the date. We will look at an example of this in another unit about dynamic
memory management. You have also seen that functions are just addresses and that you can,
therefore, also pass functions as parameters to functions. This principle is called callbacks in
certain application scenarios. Finally, there are two disadvantages to using pointer variables.
Firstly, pointers make the source code difficult to read. It has become a trademark of C to
make intensive use of pointer variables and, at the same time, to produce very compact and,
unfortunately, unreadable code. We have also briefly hinted that dealing with pointers can be
quite dangerous. Once you have saved an address in a variable, you can move the pointer to any
other location. There, you can read data from the memory or overwrite it. In most cases, you
need to know what data was stored there and what effects a data change has. When processing
character strings, in particular, it can easily happen that the terminal symbol 0 needs to be
found. You must avoid reading memory areas that were not intended to be accessed. This
very often leads to a program crash. Worse still, such programming errors can lead to serious
security vulnerabilities in your program. An attacker could use these errors to access areas of
the memory that should normally be hidden from him.




                                                27
````

## Page 028 — Literatur

````text
Slide 27: Literatur




Script

[Musik]




                      28
````
