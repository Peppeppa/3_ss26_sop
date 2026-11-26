---
source_id: SOP18
original_file: 18-using_script_2026-11-06.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 35
source_sha256: 2fab13541598a5833c20942b17655198c18ac7efdc9655c07c582de33eac1a00
verification: partial
verification_note: "All pages captured from PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or visually verified."
---

# Using the Linux API

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** Original-language text extracted page by page without summaries. Original slide pictures, source-code images and diagrams **not** in this text representation. The original PDF is required for complete visual content. Verification: **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                       Using the Linux API
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

Welcome to this unit, where we will look at the Linux API from the perspective of the C
programming language. You already know how to write C programs and have used pointers
and dynamic memory management in earlier units. Today, we take the next step and look
at how a C program actually talks to the operating system underneath it. Every time your
program creates a new process, waits for another program to finish, or reacts to something like
pressing Control-C, it uses functions that Linux provides for exactly this purpose. We will start
by clarifying what distinguishes a system call from an ordinary library function, and how to
find out what a given function does and which header file it needs. Then we move into process
control. You will learn how a running program can create a new process, replace itself with a
different program, and wait for a child process to finish, including how to read its exit status
correctly. After that, we connect two processes with a pipe, the same mechanism the shell itself
uses whenever you type a vertical bar between two commands. Finally, we turn to signals, the
way Linux notifies a process that something has happened, and you will learn how to install
your own handler so your program can react to such events instead of simply being terminated
by them. Let’s get started.




                                               2
````

## Page 003 — System Calls versus Library Functions

````text
Slide 3: System Calls versus Library Functions




Script

Let’s begin with a distinction that will run through the entire unit. When you call a function
like “printf” or “strlen” in your C program, that function runs entirely in what is called user
space. It uses only the memory and processor time that your process already owns. A system
call is different. It is a request your program sends to the kernel to act on your behalf, such as
opening a file, creating a new process, or sending a signal. Only the kernel is allowed to access
certain resources directly, so whenever your program needs one of those resources, it must ask
the kernel through a system call. Here is something that often surprises people at first. Many
of the library functions you already know aren’t doing the work themselves. They are thin
wrappers around one or more system calls, adding convenience on top. If you want to know
whether a function you’re using is a real system call or a library function built on top of one,
the man pages tell you immediately. Functions documented in section two of the man pages are
system calls, and functions documented in section three are library functions. This distinction
is not just academic. Because a system call has to switch from your program into the kernel
and back again, it carries noticeably higher overhead than a plain library function call. Keep
that in mind, and we’ll see exactly how to detect and handle failures from these calls next.




                                                3
````

## Page 004 — Error Handling with Errno

````text
Slide 4: Error Handling with Errno




Script

Now that you know system calls come with real overhead, let’s look at how they report when
something goes wrong. Almost every system call in Linux uses the same simple convention for
signaling failure: it returns minus one. But minus one on its own does not tell you why the call
failed. For that, Linux keeps a global variable called “errno”, which is updated with a specific
error code every time a system call fails. You get access to “errno” and its associated constants
by including the header file “errno.h”. Reading a raw numeric error code is not very convenient,
so there are two functions to help you. The function “perror” prints a human-readable message
describing the current value of “errno”, prefixed with whatever text you pass as a parameter. The
function “strerror” does something similar, but instead of printing directly, it converts “errno”
into a string you can use however you like, for example, to build your own error message. Look
at the example next to me. In line 5, the “chdir” call tries to change into a directory that does
not exist, and it returns minus one. In line 6, “perror” immediately reports what went wrong,
and line 7 also prints the raw numeric value of “errno” for good measure. Getting comfortable
with this pattern now will save you a lot of confusion later, because from here on, almost every
system call we look at follows exactly this same convention.




                                               4
````

## Page 005 — Process Control

````text
Slide 5: Process Control




Script

[Musik]




                           5
````

## Page 006 — Processes and Process IDs

````text
Slide 6: Processes and Process IDs




Script

With the basic vocabulary of system calls and error handling in place, we can now turn to
the first major topic of today’s unit: controlling processes. Every process running on a Linux
system, whether it’s your shell, your editor, or the smallest C program you compile, is identified
by a unique number called the process ID, or PID for short. Your program can find its own PID
by calling “getpid”, and it can find the PID of the process that started it, its parent, by calling
“getppid”. These two functions require no parameters; they simply return the information the
kernel already keeps about your process. It’s worth knowing that PIDs are not permanent
labels tied to a program. Once a process terminates, its PID becomes free again, and Linux will
eventually reuse it for a completely different process. So a PID only identifies a process while
that process is actually alive. If you are curious and want to look under the hood, every running
process on a Linux system has a corresponding entry under “/proc/pid”, where “pid” is replaced
by the actual number. That directory contains a wealth of information the kernel maintains
about the process, and it’s genuinely worth exploring on your own machine sometime. Look at
the example next to me. Line 5 asks for the process’s own PID, line 6 asks for its parent’s PID,
and both are simply printed to the screen. Knowing who you are and who started you is the
first step. The next step is far more interesting: how do you actually create a new process?




                                                6
````

## Page 007 — Process Creation with Fork

````text
Slide 7: Process Creation with Fork




Script

This is where things get interesting, and maybe even a little strange the first time you see it.
The function “fork” creates a near-identical copy of the calling process. Right after the call to
“fork” returns, you effectively have two processes running your program: the original one, called
the parent, and the newly created one, called the child. Both continue execution from exactly
the same point in the code, immediately after the “fork” call. Now, here comes the question
you should already be asking yourself: if both processes are running the same code, how does
each one know which one it is? The answer lies in the return value of “fork” itself, and this is
the clever part. In the parent process, “fork” returns the PID of the newly created child. In the
child process itself, “fork” returns the value zero. So the very same function call gives back two
different answers depending on who is asking. Look at the example next to me. In line 4, we
call “fork” once. In line 6, we check whether the return value is zero, and if it is, we know we
are in the child, so we print its own PID using “getpid” in line 7. Otherwise, in line 9, we are in
the parent, and the variable “pid” already holds the child’s PID directly; no extra function call
needed. This pattern of checking the return value of “fork” is something you will use constantly
from here on. But a copy that runs the exact same code as its parent is only useful up to a
point, so let’s look at what parent and child actually share, and what they don’t.




                                                7
````

## Page 008 — Parent and Child Processes

````text
Slide 8: Parent and Child Processes




Script

So what exactly does the child inherit when “fork” creates it? In principle, the child receives a
full copy of the parent’s memory, its variables, its stack, everything, at the exact state it was in
at the moment of the call. If Linux actually duplicated all of that memory eagerly every single
time, forking would be an extremely expensive operation. So the kernel is smarter about it.
Linux organizes memory in so-called pages; each page has a size of 4 Kilobytes, for example.
Such a paging mechanism makes it possible to move only some pages to an external hard drive
if they are not needed at the moment. Back to our forking example. After the new process has
been forked, memory is not completely copied but all memory pages are marked copy-on-write,
which means parent and child initially share the very same physical memory pages, and a page
is only actually duplicated the moment either process tries to modify it. From your program’s
perspective, everything behaves exactly as if a full copy had happened; you simply don’t pay
the cost for pages that never change. Something else the child inherits is the parent’s open file
descriptors. If the parent had a file open before calling “fork”, the child has that same file open
right after, pointing at the very same position in the file. Beyond that, though, parent and child
are really independent. The child owns its own address space and runs on its own, completely
separately from the parent, from the moment “fork” returns. One important consequence of this
independence: Linux makes absolutely no promise about which of the two processes actually
runs first. The parent might continue immediately, the child might run first, or the operating
system’s scheduler might interleave them in ways you can’t predict. So far, both processes are
still running the exact same program. What if the child is supposed to run something completely
different instead? That’s exactly the problem “exec” solves.




                                                 8
````

## Page 009 — Process Replacement with Exec

````text
Slide 9: Process Replacement with Exec




Script

“Fork” gives you a copy of the current program, but very often that’s not actually what you
want. Very often, what you actually want in the child is to run an entirely different program
altogether; think of a shell that forks a child just to run the “ls” command inside it. This
is exactly the job of the “exec” family of functions. Calling “exec” replaces the process image
currently running- its code, its data, its stack- with a completely new program loaded from disk.
What’s remarkable is that the process ID itself stays exactly the same across this replacement;
from the operating system’s point of view, it is still the same process, just running entirely
different code from this point onward. There are several variants of “exec”, and they differ
mainly in how you hand over the arguments and how the target program gets located. “execl”
expects you to list the arguments individually, one after another, directly in the function call.
“execv”, instead, expects you to build an array of argument strings yourself and pass that array
in. And “execvp” adds one more convenience: it searches through the directories listed in your
“PATH” environment variable to actually locate the executable, exactly like your shell does
when you simply type a command name. Look at the example next to me. In line 4, we build
an array holding the command name “ls”, the flag “-l”, and finally a “NULL” marking the end of
the array. Line 5 then calls “execvp”, and if that call succeeds, the lines after it, including the
“perror” in line 6, never execute at all, because our program has literally become “ls” at that
point. This combination, forking to get a new process and then calling “exec” to load a different
program into it, is exactly how your shell implements every single command you type. Now
that a child can run its own program, the parent needs a way to actually receive information
from it, and that starts with its command-line arguments and its environment.




                                                9
````

## Page 010 — Arguments and Process Environment

````text
Slide 10: Arguments and Process Environment




Script

Every C program you write already has access to two pieces of information the operating
system hands it at startup, and by now you’ve almost certainly used at least one of them
without necessarily thinking too hard about where it comes from. The parameters “argc” and
“argv” of your “main” function carry the command-line arguments the program was started with.
“argv” at index zero always holds the name the program was invoked as, and the entire array
is terminated by a “NULL” pointer, exactly like the argument array we just built for “execvp”
on the previous slide. That’s not a coincidence; it’s the very same convention. Alongside the
arguments, every process also carries an entire environment with it, a set of key-value pairs
like “PATH” or “HOME” that configure how programs behave. Your program can access the
full list directly through the global variable “environ”, which points at that environment array.
More often, though, you just want a single specific value, and for that, “getenv” lets you read
one environment variable by name without walking the whole array yourself. If you need to go
the other way and actually change the environment your own process sees, both “setenv” and
“putenv” let you do that, which matters, for instance, if you’re about to “exec” a child program
and want it to inherit a modified environment from you. Command-line arguments and the
environment are how a child process receives input. Now let’s close the loop and see how the
parent finds out what happened once that child is done.




                                               10
````

## Page 011 — Waiting for Child Processes

````text
Slide 11: Waiting for Child Processes




Script

Once a parent has forked a child, it has a responsibility that’s easy to forget about: it really
should wait for that child to terminate. The function “wait” does exactly that; it blocks the
calling process until any one of its children exits, whichever one happens to finish first. Often,
though, a parent has several children running and cares about one specific one. For that case,
“waitpid” lets you target one exact child by its PID instead of just taking whichever one finishes
first. Both functions hand back a status value through an output parameter, and that value is
not simply the child’s exit code sitting there ready to read. It’s an integer value that encodes
several different pieces of information at once, including both the exit code and, if the child
was killed by a signal, which signal that was. Because of that packing, you should never try
to interpret this status value directly yourself. Instead, Linux gives you a set of macros to
decode it safely. “WIFEXITED” tells you whether the child terminated normally, and if it did,
“WEXITSTATUS” extracts the actual exit code from inside that packed value. Look at the
example next to me. In line 5, we fork a child that immediately exits with the code forty-two
in line 6. The parent then calls “waitpid” in line 8, waiting specifically for that child, and once
it returns, line 9 checks “WIFEXITED” before line 10 safely extracts and prints the exit code
using “WEXITSTATUS”. We’ve now seen how a parent reads a child’s status, but what exactly
goes into that status? That depends on how the child actually chose to terminate.




                                                11
````

## Page 012 — Exit Status and Termination

````text
Slide 12: Exit Status and Termination




Script

A process can end its own execution in a couple of different ways, and the difference between
them matters more than it might first appear. Calling “exit” performs a clean shutdown: it runs
any cleanup that’s been registered, and importantly, it flushes any “stdio” buffers, meaning that
any output you’ve queued up with “printf” actually gets written out before the process disap-
pears. “_exit”, by contrast, terminates the process immediately, skipping all of that cleanup
entirely. If you’ve buffered output waiting to be flushed and you call “_exit”, that output is
simply lost. You saw exactly this function used in the child on the previous slide, precisely
because a child that’s only demonstrating an exit code doesn’t need any of that cleanup machi-
nery. You should also know that simply returning a value from “main” behaves exactly as if you
had called “exit” with that same value; there’s no meaningful difference between the two. One
constraint that catches people off at the first time they run into it: an exit status is limited to
only eight bits, meaning it can only represent numbers from zero up to two hundred fifty-five.
If your program tries to exit with some larger number, only the lowest eight bits actually sur-
vive. By convention, an exit status of zero signals success, and any nonzero value signals that
something went wrong, though the specific nonzero number is otherwise entirely up to you to
define. Finally, if you need to guarantee that certain cleanup code runs no matter how or where
your program decides to exit, “atexit” lets you register additional handlers that Linux will call
automatically during a normal exit. Now, what happens if a child finishes but the parent never
calls “wait” for it, or if a parent disappears before its child does? That’s the next important
topic.




                                                12
````

## Page 013 — Zombie and Orphan Processes

````text
Slide 13: Zombie and Orphan Processes




Script

Here’s a case that looks strange the first time you see it, but it follows directly from everything
we’ve just discussed. When a child process finishes running, it doesn’t just vanish immediately.
If its parent hasn’t called “wait” or “waitpid” yet, the child becomes what’s called a zombie. A
zombie process has already exited, its code is no longer running, but it still occupies an entry
in the kernel’s process table, essentially waiting around so its exit status can eventually be
collected. The moment the parent finally does call “wait”, that entry is removed and the zombie
disappears for good. This is exactly why we said earlier that a parent really should wait for
its children; skip that step consistently, and zombie entries can pile up. There’s a mirror-image
situation, too. What happens if the parent terminates before its child does? Such a child is called
an orphan. Rather than being left with no parent at all, which would leave nobody responsible
for eventually reaping it, Linux automatically adopts orphaned processes and reassigns them to
process number one, traditionally called “init”. “Init” is specifically designed to automatically
acquire any orphaned children that get assigned to it, so an orphan doesn’t linger around as a
zombie forever, even though its original parent is long gone. Between zombies and orphans, you
can see why properly waiting for your children matters, not just for reading their exit status,
but for keeping the process table clean. That covers the full lifecycle of a single process. Now
it’s your turn to put fork, exec, and wait together yourself.




                                                13
````

## Page 014 — Exercise 01: Create and Execute a Child Process

### Exercise SOP18-E01 (source slide)

````text
Slide 14: Exercise 01: Create and Execute a Child Process




Script

For this first exercise, you’ll bring together everything we’ve covered about process control
into one small but complete program. Write a program that forks a child process, and in that
child, execute the program “/bin/ls” using “execvp”, exactly the pattern you saw a few slides
ago. Meanwhile, the parent should wait for that child to terminate and then print out the exit
status it receives back. As you write this, pay close attention to error handling: both “fork”
and “exec” can fail, and when they do, you should report that failure using “perror”, just as we
discussed at the very beginning of today’s unit. Take your time with this one; think carefully
about which code belongs in the child and which belongs in the parent, and remember the
check on the return value of “fork” that tells you which one you currently are. When you are
finished, please click the button, and I will show you one possible solution.




                                              14
````

## Page 015 — Solution 01: Create and Execute a Child Process

````text
Slide 15: Solution 01: Create and Execute a Child Process




Script

I am here in the repository for this unit number 18 and we first check what kind of branches
we have. Locally we only have a few, so we have the branches on the origin server already, only.
We want to have a look at the solution for the first exercise, so we switch to the exercise one
after branch and we have a look at this file here, exercise one, and the structure follows almost
identical what we have seen on the slides before, so we fork a process here, we check for errors.
If this is the child, we start the ls command and in the parent process we wait for the child to
exit. If an error occurs here, with a wait we just exit the program with the error code, then we
check using this macro the status value and if there was a correct exit then we print this here
and in the other case we print just the information that there was a problem and we return
with an exit status code nevertheless. So what should happen? The child calls ls, ls prints the
names of the files and directories to the output, so we can open a terminal here, make and then
we call exercise one and this is the output of the files of the current directory that comes from
this ls that was called by the child.




                                               15
````

## Page 016 — Pipes and Redirection

````text
Slide 16: Pipes and Redirection




Script

[Musik]




                           16
````

## Page 017 — Inter-Process Communication with Pipes

````text
Slide 17: Inter-Process Communication with Pipes




Script

You’ve just seen how to create child processes and run entirely different programs inside them.
But processes that can’t talk to each other are not so useful. What if the output produced by
one process needs to become the input of another? This is exactly the problem a pipe solves.
A pipe connects two processes so that whatever one writes becomes available for the other to
read, output on one side flowing in as input on the other. You know the concept already from
the video about Bash programming. The function “pipe” sets up exactly this kind of channel,
and it’s important to note that it’s unidirectional; data only flows in one direction through
it. Calling “pipe” hands you back two file descriptors at once: one for reading and one for
writing. Whatever bytes get written into the write end travel through the kernel itself, entirely
in memory, and become available to read from the read end on the other side. Pipes are almost
always used together with “fork”, since you typically want two separate processes on either
end of the channel, one writing and one reading. In fact, as I said earlier, you have learned
exactly this mechanism already without realizing the machinery behind it: every time you type
a vertical bar between two commands in your shell, the shell is setting up precisely this kind
of pipe underneath. Let’s look at exactly how you create and use one in your own code.




                                               17
````

## Page 018 — Creating and Using a Pipe

````text
Slide 18: Creating and Using a Pipe




Script

Things get a bit tricky now. Let’s look at the mechanics in detail. Calling “pipe” with an array
of two integers, written as you can see in lines 4 and 5, fills that array with the two descriptors
we just talked about. By convention, “fd[0]” is always the read end, and “fd[1]” is always the
write end; that ordering never changes, so it’s worth simply memorizing it. Once you have those
two descriptors, using them is familiar: “write” sends bytes into the pipe through the write end,
and “read” retrieves bytes back out through the read end, exactly the same functions you’d use
on an ordinary file. There’s one habit you should build right from the start: close whichever end
of the pipe you’re not actually using anymore. Leaving unused ends open doesn’t just waste a
file descriptor; it can actually change the pipe’s behavior, as we’ll see in a moment. Look at
the example next to me. Line 5 creates the pipe, line 6 writes the two characters “hi” into the
write end “fd[1]”, and line 8 reads those same two characters back out from the read end “fd[0]”
into a local buffer, which line 9 then prints. Notice that this number of bytes that you need to
pass as parameter when you call “read” defines the maximum number of bytes to read. If there
are less bytes in the pipe, function “read” only reads this amount of bytes. The return value
informs you about this. Our example runs entirely within a single process just to demonstrate
the mechanism, but a pipe becomes really useful once it connects two separate processes, one
on each end, which is the situation we look at next.




                                                18
````

## Page 019 — Connecting Parent and Child with Pipes

````text
Slide 19: Connecting Parent and Child with Pipes




Script

Now let’s put pipes and “fork” together, because that combination is where pipes really earn
their keep. The order here matters: you create the pipe first, before calling “fork”. That way,
since the child inherits all of the parent’s open file descriptors, exactly as we discussed a few
slides ago, both the parent and the child end up holding both ends of the very same pipe. Having
both ends open in both processes isn’t actually what you want, though. Each process should
close whichever end it doesn’t need: if the child is meant to write into the pipe, it closes its read
end, and the parent, meant to read, closes its write end. This is why we told you a moment
ago to always close unused ends. Once that’s sorted out, communication is straightforward: the
writer sends its data, and the reader consumes it on the other side. There’s one more subtlety
worth knowing, because it’s how a reader detects that there’s nothing more coming: closing the
write end signals that no more data will ever arrive, and “read” on the other side returns zero
exactly once every single process holding that write end has closed it. This is why closing unused
ends properly isn’t just tidiness; it’s actually load-bearing for correctness. With data flowing
between two processes through a pipe, there’s one more piece needed before this becomes truly
useful: connecting that pipe to a process’s standard input and output.




                                                 19
````

## Page 020 — Redirecting File Descriptors with Dup2

````text
Slide 20: Redirecting File Descriptors with Dup2




Script

Here’s an elegant piece of Linux internals. So far, our processes have talked to the pipe using the
file descriptors that “pipe” itself handed back. But what if you want a program like “ls”, one that
simply writes to its normal standard output without knowing anything at all about pipes, to
have its output arrive inside our pipe instead? That’s exactly what the function “dup2” makes
possible: it duplicates one file descriptor onto a fixed, specific number, effectively making that
fixed number point at wherever the original descriptor pointed. In practice, this lets you redirect
“stdin”, “stdout”, or “stderr” to point somewhere else entirely, all without the program on the
other end ever being aware anything changed. Under the hood, “dup2” first closes whatever was
previously open at the target descriptor number before making the duplicate, which is exactly
why the descriptor you’re redirecting to gets silently replaced rather than colliding with what
was there before. Look at the example next to me. In line 6, inside the child process, we call
“dup2” with parameters “fd[1]” and “1”, which makes file descriptor one, standard output, point
at the write end of our pipe. From that moment on, anything the child writes to standard
output actually flows into the pipe instead of appearing on the screen. Lines 7 and 8 then close
both original pipe descriptors, since “dup2” has already given us what we need at descriptor
one. Finally, line 9 calls “execlp” to run “ls”, and “ls” writes to what it believes is its ordinary
standard output, with absolutely no idea that its output is actually flowing into our pipe. The
example besides me does not show how data is actually read from the pipe. You could imagine
that the main process uses “fd” to read data from “ls”. Another use case is how shell pipelines
work. Speaking of which, let’s put every piece together and build a full pipeline ourselves.




                                                20
````

## Page 021 — Building a Process Pipeline

````text
Slide 21: Building a Process Pipeline




Script

We now have every ingredient needed to build something that looks exactly like a shell pipeline,
the kind you type on the console with a vertical bar between two commands. Each stage of
the pipeline runs in its own child process, and a pipe connects one stage’s standard output
directly to the next stage’s standard input. “dup2” is what actually wires those pipe ends onto
the standard streams, exactly as you just saw on the previous slide. For a pipeline with several
stages, the parent forks off one child for every single stage in the chain. There’s one detail that’s
easy to overlook and that causes real bugs when it’s missed: every pipe descriptor needs to be
closed after forking, in every single process, both the ones actively using a given pipe and the
ones that aren’t. Leftover open descriptors can quietly prevent “read” from ever seeing that
end-of-data signal we talked about a moment ago, because the pipe won’t be considered fully
closed as long as any process anywhere still holds a copy of the write end open. Once all the
children are launched and wired up correctly, the parent simply waits for every single one of
them to finish before considering the pipeline complete. Let’s put this into practice with an
exercise built around a pipeline you already know well from the command line.




                                                 21
````

## Page 022 — Exercise 02: Implement a Simple Pipeline

### Exercise SOP18-E02 (source slide)

````text
Slide 22: Exercise 02: Implement a Simple Pipeline




Script

For this exercise, you’re going to reconstruct a pipeline that you’ve almost certainly typed on
the command line already: something equivalent to “ls | wc -l”, counting how many entries are in
a directory. Start by creating a single pipe before forking two separate children. The first child
should redirect its standard output to the write end of that pipe and then run “ls”. The second
child should redirect its standard input from the read end of the same pipe and then run “wc
-l”. The part that might trip you is the detail we just emphasized: make sure you close every
unused descriptor in both children, not just the one each child is actively using. If you forget to
close an unused end somewhere, you’ll likely see your program hang instead of finishing cleanly,
because the pipe never gets that final end-of-data signal it’s waiting for. When you’re finished,
or if your pipeline seems to be hanging and you’d like to compare against a working solution,
please click the button.




                                                22
````

## Page 023 — Solution 02: Implement a Simple Pipeline

````text
Slide 23: Solution 02: Implement a Simple Pipeline




Script

Okay, we switch to the branch of the second exercise. Okay, we have been there already. And
then we have a look at the solution. So as described on the slides, we create these file descriptors,
we create a pipe here, then we start the first child. And in the child process, we do this, let’s call
it redirecting of standard output to the file. So you need to get used to this tab two functions
with the parameters and make yourself clear what the parameters are and what is the correct
order of these parameters. So what is done here is we let standard output point to the right
end of the pipe so that every data that is written to the standard output is then written in
reality to the pipe. And because we don’t write into the pipe by ourselves and we don’t read
from this, we close both ends of the pipeline. And also this, make yourself clear why this is
necessary. Because if we don’t close the pipe, the kernel thinks there might be some data be
sent in the future. And then we might run into a problem when the process that reads from the
pipe waits for this end of file signal, which actually cannot come if there is an open pipe end.
So we start with the ls command here and then the output of ls is then written via standard
output, so to speak, into the pipe. Back in the main and the parent process, we start another
child and here we do the other thing with the standard input to the read end of the pipe. So
everything that is to be meant to be read from standard input is now in reality read from the
read end of the pipe. We close the two unused ends of the pipe. We start wc to count and this
command now waits for data normally from the standard output and this is now waiting for
data that comes from the pipe. Therefore it is also no problem to start these two programs here
in the sequence because wc, the second child, waits for data from standard input. That means
from the pipe. And only if ls has written some data to it, it terminates or it starts running and
executing whatever wc does. In the parent process, we also do not need the ends of the pipe,
so we close them. And we wait for the two processes to finish. And we can start this program.




                                                 23
````

## Page 024 — Continuation / untitled

````text
And this is the result because we have here, we can call this on the console. So this is one file
more. So we have to call ls not ls-l and then we can see it’s the same number of lines here.




                                               24
````

## Page 025 — Signals

````text
Slide 24: Signals




Script

[Musik]




                    25
````

## Page 026 — Signals as Asynchronous Events

````text
Slide 25: Signals as Asynchronous Events




Script

We’ve now covered how processes are created, connected, and how they communicate through
pipes. There’s one more essential piece of the Linux API left, and it works quite differently
from everything we’ve seen so far. A signal is how Linux notifies a process that some event
has occurred, and unlike a return value from a function you call yourself, a signal’s delivery
is asynchronous: it can interrupt your program’s normal flow at essentially any point, without
any warning about exactly when. Signals can originate from several different places. The kernel
itself can send one, for instance, when your program tries to access memory it shouldn’t. Other
processes can send one directly, and a process can even send a signal to itself. Every signal comes
with a default action defined by the operating system; terminating the process is a common
one, but a process is not simply stuck with that default. It can install its own custom handler
instead, a function that runs when that particular signal arrives, letting your program decide
for itself how to react rather than simply being terminated on the spot. Before we look at
installing a handler ourselves, let’s get familiar with a few of the signals you’ll encounter most
often in practice.




                                                26
````

## Page 027 — Common Linux Signals

````text
Slide 26: Common Linux Signals




Script

Let’s look at a handful of signals you’ll run into constantly once you start working with Linux
programs. Look at the two groups next to me. In the first group, we have signals whose whole
purpose is termination. “SIGINT” is the one sent whenever you press Control-C in a terminal;
it’s a request asking the running program to stop, not a demand. “SIGTERM” similarly asks
a process to shut down gracefully, giving it the chance to clean up first. “SIGKILL”, on the
other hand, is far more forceful: it terminates a process immediately, and critically, it cannot
be caught or ignored by any handler at all; the kernel simply ends the process on the spot. In
the second group, you can see a few other signals worth knowing. “SIGSEGV” is delivered when
a program touches memory it has no business accessing, an invalid memory access, something
you may well have already triggered accidentally while experimenting with pointers in an earlier
unit. “SIGCHLD” is sent to a parent process whenever one of its children changes state, for
instance, when a child terminates, which turns out to be quite useful, as we’ll see shortly. And,
like “SIGKILL”, “SIGSTOP” also cannot be blocked, ignored, or caught by a handler; it simply
pauses the process outright. Knowing what a signal means is one thing. Now let’s look at how
a process actually sends one to another.




                                               27
````

## Page 028 — Sending Signals to Processes

````text
Slide 27: Sending Signals to Processes




Script

So how does a signal actually get sent from one process to another in the first place? The
function “kill” sends a specified signal to a process identified by its PID; despite the somewhat
alarming name, it can send any signal at all, not only ones that terminate the target. If a
process wants to send a signal to itself specifically, “raise” does exactly that, without needing to
know its own PID at all. There’s also a special case worth knowing: passing a negative PID to
“kill” targets an entire process group at once rather than a single process, which is handy when
you want to signal several related processes together. One thing that’s easy to overlook: sending
a signal isn’t something any process can simply do to any other process at will. The sender
needs the appropriate permission to signal the target, typically meaning it must be running as
the same user, or as an administrator. Look at the example next to me. In line 4, the parent
forks a child. In line 5, the child immediately calls “pause”, which simply suspends it until a
signal arrives. Meanwhile, in line 8, the parent calls “kill” to send “SIGTERM” to that very
child, using the PID that “fork” handed back to it in the parent. Since we haven’t installed any
custom handler here, that child simply terminates using the default action for “SIGTERM”.
But what if we don’t want the default action? That’s exactly what we look at next.




                                                28
````

## Page 029 — Handling Signals with Sigaction

````text
Slide 28: Handling Signals with Sigaction




Script

If a signal’s default behavior isn’t what you want, you need a way to install your own handler,
and “sigaction” is the tool for that job. Compared with the older function simply called “signal”,
“sigaction” is both more portable across different Unix systems and more precise about exactly
how your handler behaves, which is why it’s the function you should reach for in serious code.
“sigaction” expects a data structure with a few fields you should know. The field “sa_handler”
holds a pointer to the actual function that should run when the signal arrives, your custom
handler itself. The field “sa_mask” lets you specify additional signals that should be blocked
for the duration your handler is running, preventing certain kinds of interruption while you’re
already inside the handler. And “sa_flags” lets you configure various finer details of exactly
how the handler behaves. Look at the example next to me. Line 4 defines the handler function
itself, which simply prints which signal number it caught. Line 6 builds a “sigaction” structure
with that handler installed in “sa_handler”, and line 7 registers it for “SIGINT” specifically. The
first two parameters when calling “sigaction” are clear, but what is the third one? It’s called
“old-action” and it points to another “sigaction” structure to store the old information in. If
you don’t need this, leave it “NULL” as shown in the example. From that point on, line 8 calls
“pause” to wait, and when you press Control-C, instead of the program terminating the way
it did in the previous example, our custom handler runs instead. Now, remember that signal
we mentioned a couple of slides ago, the one sent specifically when a child changes state? Let’s
look at what that one is actually useful for.




                                                29
````

## Page 030 — Signals and Child Processes

````text
Slide 29: Signals and Child Processes




Script

Here’s a very practical use for signals that connects directly back to something we covered
earlier today. Do you remember zombie processes, children that have finished but haven’t yet
been caught by their parent calling “wait”? “SIGCHLD” gives you an elegant way to deal with
exactly that situation. This signal is sent to a parent automatically whenever one of its children
terminates, and a handler for it can simply call “waitpid” right then and there to catch that
child immediately, rather than the parent needing to sit around blocking on “wait” the whole
time. There’s a particular flag worth knowing here: passing “WNOHANG” to “waitpid” makes it
return immediately if there’s genuinely nothing to catch yet, instead of blocking, which matters
quite a bit inside a signal handler, since a handler blocking indefinitely would be a serious
problem. Interestingly, on Linux, there’s an even simpler option: explicitly ignoring “SIGCHLD”
altogether causes the kernel to automatically reap the process’s children for you, no handler
required at all. One thing you must always keep in mind, though: signal handlers need to stay
short, and they need to be what’s called async-signal-safe. Since a signal can interrupt your
program at literally any point, only a specific, limited set of functions are actually guaranteed
safe to call from inside a handler. That restriction turns out to run much deeper than it might
first appear, so let’s look at exactly why.




                                               30
````

## Page 031 — Pitfalls of Signal Handling

````text
Slide 30: Pitfalls of Signal Handling




Script

This last point deserves real attention, because it’s where signal handling gets really tricky,
and where bugs tend to hide. Most ordinary library functions are not async-signal-safe. Since a
signal can arrive and interrupt your program at essentially any instruction, if your handler calls
a function that happens to already be running, mid-operation, at the exact moment the signal
arrives, you can end up with serious race conditions between the interrupted code and your
handler. Signals can even interrupt a system call that’s already in progress, partway through.
When that happens, the interrupted call returns early with an error, and the constant “EINTR”
specifically indicates that a system call was interrupted this way rather than genuinely failing,
so your code needs to be prepared to check for this case and typically retry the call. If a
handler needs to share any state with the rest of your program, that shared variable needs
to be declared using the type “sig_atomic_t”, which guarantees that reading and writing it
can’t itself be interrupted halfway through in a way that leaves it in some inconsistent, half-
updated state. And as a hard rule: handlers must avoid calling functions like “malloc” or “printf”,
precisely because they are not async-signal-safe and could already be mid-operation, holding
an internal lock, at the exact moment your handler interrupts them. With all of these pieces
in place, from installing a handler with “sigaction” through to keeping it safe, it’s time to put
signal handling into practice yourself.




                                                31
````

## Page 032 — Exercise 03: Implement Signal Handling

### Exercise SOP18-E03 (source slide)

````text
Slide 31: Exercise 03: Implement Signal Handling




Script

For this final exercise, you’ll build a small program that reacts to Control-C instead of simply
being terminated by it. Install a handler for “SIGINT” using “sigaction”, exactly as we walked
through a few slides ago. Rather than letting the default action terminate your program, your
handler should instead print a message to let you know it was actually triggered. As I just
said previously, normally you should avoid “printf” in a signal handler, but here it is used just
for demonstration. Don’t use this in production code. Structure your main program as a loop
that keeps running until some counter limit you choose is reached, using “pause” between each
iteration to wait, exactly as in the earlier example. Once you’ve written this, actually test it:
press Control-C while your program is running and confirm your handler fires the way you
expect, rather than the program simply terminating on the spot. When you’re finished, or if
you’d like to compare your solution with mine, please click the button.




                                               32
````

## Page 033 — Solution 03: Implement Signal Handling

````text
Slide 32: Solution 03: Implement Signal Handling




Script

We are now on the third solution branch of this repository. Let’s have a look at the source
code. We define a handler function here. In this solution you might stumble upon this void
casting of variables here. This is just a way to tell the compiler we know that this variable is
not used but we don’t care. Please don’t print any warnings. We use this here for the parameter
that we actually don’t use and we here store the result of this write function in a variable and
then we also tell the compiler we are not going to use this. This is just for readability. There
would have been other solutions to solve this. In the handler we do just for demonstration what
normally should not be done. We print something using the write function to the standard out
descriptor. In the main function we create a structure of type sick. We clear the whole memory
of this structure and then we set the SA underscore handler field to the handler function that
we have defined earlier. We clear all masks. A sick empty set is just the empty set of mask
or of signals. Masking was this mechanism that we just want to mask all the signals that we
don’t want to be informed about during our handler is running. Here we mask nothing. Then
we register the handler for the sick end signal and then we have here our let’s say main loop
where we iterate over this value count which is defined here at this line. If now control c is
pressed which is the sick end signal we jump into our handler. We increase the count variable
here and once this value is larger than limit we jump out of this loop. So this pause function
here pauses the process until a signal occurs. So pause does not stop or wait for all signals.
There are signals that immediately terminate the program like sick kill for example and if you
have masked a signal then also pause will not notice this but especially sick end is the one
that interrupts pause and calls the handler if you have registered one. Yeah and then we have
the final print message here. We can execute everything. So I press control c for the first time
second time third time and now the program terminates.




                                              33
````

## Page 034 — Summary

````text
Slide 33: Summary




Script

That’s it for today. We’ve spanned a wide range of topics in this unit, starting from the basic
distinction between a system call and a library function, and the “errno” convention that almost
every one of these calls relies on to report failure. From there, we moved into process control,
where “fork” and “exec” together let a program create an entirely new process and then load
a completely different program into it, and where “wait” and “waitpid” let a parent reap its
children and correctly read back their exit status. We then connected separate processes with
pipes, and saw how “dup2” wires those pipe ends onto standard input and output, which is
exactly the mechanism your shell relies on every time you type a vertical bar between two
commands. Finally, we turned to signals, an entirely different, asynchronous way for the kernel
or other processes to notify your program of an event, and you saw how “sigaction” lets you
install your own handler instead of accepting the default action, as long as you’re careful to keep
that handler short and async-signal-safe. Together, these are the building blocks underneath
essentially every Linux command-line tool you’ve ever used, including your own shell. In the
next unit, we move on to network communication.




                                                34
````

## Page 035 — Literatur

````text
Slide 34: Literatur




Script

[Musik]




                      35
````
