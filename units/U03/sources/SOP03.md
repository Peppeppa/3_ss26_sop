---
source_id: SOP03
original_file: 03-working_script_2026-09-25.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 38
source_sha256: f7e775e08696af2addee48746f4263203b078062e69e0f415a93cb79e94cdcfb
verification: partial
verification_note: "All physical pages captured from indexed PDF text; embedded slide images and their code/figures have not been fully transcribed or visually verified."
---

# Working with the Linux Shell

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** The following is the extracted original-language PDF text **page by page**, without KI summaries. The slide pictures accompanying each page, including diagrams, screenshots, slide-only code, and embedded visual formulas, are **not** reproduced by this text extraction. The source PDF is still needed for full visual fidelity. Verification is therefore **partial**, not verified. Printed page numbers may differ from PDF pages.

## Page 001 — Script

````text
           System-oriented Programming
                 Working with the Linux Shell
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

Welcome to this unit, where we will look at the Linux command line and some Linux commands.
We will first look at some of the basics. The main goal is to show you that you do not need a
mouse to control the computer via the command line. We will then introduce you to the most
important Linux commands. You will learn how to navigate in the directories and work with
files. Finally, we will explain the first possibility of linking several Linux commands to perform
more complex tasks with just one command. In between, there are some exercises that you
should do on your computer. You must, therefore, have a computer with a Linux-like operating
system available for this unit. We use the Ubuntu operating system. However, you can also
work on most topics on a computer with the macOS operating system.




                                                2
````

## Page 003 — Philosophy of Unix

````text
Slide 3: Philosophy of Unix




Script

The Linux operating system goes back to the Unix operating system, which originated in the
early 1970s. We will not go into the history of Unix or Linux here. At the end of the unit, you
will find some references to interesting books. These include the highly recommended book by
Brian Kernighan about the early days of Unix. The developers of Unix at that time had a vision
that is now understood as the basic philosophy of Unix. You can think of it as a construction
kit or building with Lego. Under Unix, you write programs that can do one thing and do it
really well. It’s a Lego building block, so to speak. These programs should also be compatible
with each other, i.e., be able to work together. Now, the Lego bricks are put together. So you
should always be able to plug the simple program together so they can do something more
complex together. The programs should always be able to use text streams because they are a
universal interface. We will see what this means in the course of this and the next units.




                                              3
````

## Page 004 — Linux Shell

````text
Slide 4: Linux Shell




Script

Within this course, we will use the “Bourne Again Shell” or “Bash” for short because it is the
most widely used and is also pre-installed by default on all Linux systems. Bash is also available
by default on macOS. There is also a simpler shell called SH, but it is so rudimentary that it
is no longer used. And, of course, there are also newer and more advanced shells, such as the
Korn shell or KSH and the Z shell or ZSH for short. Incidentally, Zed is the default shell on
newer macOS versions. But as I said, we will be looking at Bash because it is available on every
Linux-like operating system. Let’s take a closer look at Bash now, and to do this you should
start Linux on your computer.




                                                4
````

## Page 005 — Screencast 1: Shell

````text
Slide 5: Screencast 1: Shell




Script

So after you have switched on your computer you have probably a graphical user interface at
your hand and to get the command line you have to start the app terminal first. I showed you
this in the last video already how to start this terminal app and when you start this this looks
like this not identical to what you see here in the video from my computer but it should be
similar. I’m here on a remote server so I use the console or the shell now via SSH so everything
is a little bit different here. So you can type in commands here and you can use the backspace
key to delete everything and in the front here every line has the so-called prompt. This comes
in every line here and the prompt contains of my name here or the login name and the name of
the computer. So I will explain how to configure the prompt later at the end of this video and
next I type in here the first command echo hello world just prints the text hello world in the
console. The next command is called LS. LS stands for list and this command shows all files or
directories in the current directory. So this is a new computer there are no files and therefore I
switch to another directory and this is called etc so we now show all files in this etc directory
you can see this is a lot and you can see here some graphical coloring here for some files this
is just for illustration that you can distinguish different file types this is not so important here
at the moment and next I’m going to show the command cat this stands for catalog and this
command is used to show the contents of text files as argument I give here the file name etc pass
wd which is the file that contains all users and in former times also the password was stored
in this file nowadays this is solved in a different way of course for security reasons no longer
plain password information here in this file cat always shows the whole file and more is another
command that is used that only parts of the file is shown you can see here 71% of the file is now
shown on the first screen and when you press the space key then you can get the second page
and third page or the rest of the document so next I would like to show you how to read input
from the user and the command for this is named read and when we type in this here then this



                                                 5
````

## Page 006 — Fortsetzung / ohne Folientitel

````text
doesn’t make any sense because we cannot store the data so when you press enter now you type
in some text like hello word and you press enter again so the read command is now finished
but we don’t have any container or whatever where we can store this hello words therefore we
have to pass the parameter name greetings in this case and when we now type in hello we can
ask for the contents of this greetings variable so this is a very good way to read data from the
user and you can do this so this read command will not terminate here so either you type in
some text and press return or you have to stop this program by pressing ctrl C and this is what
I wanted to show you here ctrl C is the keyboard command to cancel the current application
so whenever a command runs forever because of an error for example you can interrupt this
program here so as I said in the beginning I would like to show you how we can configure this
prompt in the beginning of each line and we will do this by changing a variable and the variable
is named ps1 and the way to define the contents of a variable is is a command named export
export and we now we set this variable ps1 to a new value and you can see here we use this
equal sign as assignment operator and we now use backslash you would have stand for the user
backslash age stands for the hostname backslash W stands for the current path so backslash
you and then the greater than sign a space character and then the double quote and now the
prompt only shows the username and let’s do another example we show the full path and here
as full path you can see just one character which is the symbol for the home directory so let’s
change to another directory etc and then you can see now it shows the current directory etc so
that’s it




                                               6
````

## Page 007 — Working with the Shell: Moving the Cursor

````text
Slide 6: Working with the Shell: Moving the Cursor




Script

If we work with the shell, then the mouse is unnecessary and this is simply because the shell
existed before the mouse even existed as an input device. But even today, there is still a desire
to get by without a mouse as far as possible and this is simply for reasons of speed. It is
much quicker to use the computer if you can keep your hands on the keyboard. Provided, of
course, that you can find the keys reasonably quickly. So here are a few shortcuts you should
know. Everything here revolves around controlling the cursor in the input line. Of course, you
could also do everything using the arrow keys, but with the shortcuts, it is much quicker. For
example, you can use CTRL-A to quickly jump to the beginning of the line. So if you have
already entered a longer command and you realize that you have forgotten something at the
beginning, you can jump to the beginning with CTRL-A and back to the end with CTRL-E
so that you can then enter RETURN. By the way, the English words are shown on the slides
next to me. So CTRL for the German word “Steuerung” or STRG. With F and B, you jump
one character forward or backward. It’s quite easy to remember. F stands for forward, and B
for backward. With ALT-F and ALT-B, you can move one word forward or backward. With
macOS, the shortcuts are slightly different. And you have to be careful if you have already
assigned other functions to these shortcuts. Then, these shortcuts will no longer work.




                                               7
````

## Page 008 — Working with the Shell: Deleting Characters

````text
Slide 7: Working with the Shell: Deleting Characters




Script

The last character entered is deleted as usual with Backspace. You can use CTRL-K to quickly
delete everything from the cursor position to the end of the line. The K stands for Kill. And
then there is ESC-D. Unfortunately, this is not so easy to use on the keyboard. But you can
use it to delete the rest of the word from the cursor position. If you have deleted something
that you need again, you can use CTRL-Y to restore the last deleted characters. With a little
practice, you can memorize these few shortcuts relatively quickly. You should force yourself
not to use the mouse when working with the Linux shell and not to use the arrow keys for all
cursor movements. If you ever find yourself in an interview for a job as a software developer,
they might want to see how you handle a computer. It always makes a very good impression if
you are confident in the shell and use these shortcuts.




                                              8
````

## Page 009 — Screencast 2

````text
Slide 8: Screencast 2




Script

So let’s have a look at these shortcuts here in the command line. Let’s say we want to see the
contents of this file etc passwd and now cat is not the correct command here we want to change
this to more and now you could use the arrow keys of course left and right and then jump
character by character to the left and so on but it would be easier and faster and this is what
is using the command line all about. You press Ctrl A and then you jump immediately to the
beginning of the line then you press escape D to delete the first word and then you can enter
the new command more and you press return and then you see the contents here. So when we
enter this command again we jump back and forth with Ctrl A and E between the beginning
and the end of the line. So instead of using the arrow keys you can also use Ctrl F and Ctrl
B to jump character by character forward and backward and this might be useful if the arrow
keys are really far away on your keyboard or you have a very old keyboard that does not even
have the arrow keys. So we can also jump word by word by using Alt F and Alt B you can see
this here And the last thing I would like to show you is autocompletion and for this we delete
the last word and then when you have a path for example and you press the tab key then the
shell will suggest what could be the next possible word here that makes any sense.




                                              9
````

## Page 010 — Linux Commands

````text
Slide 9: Linux Commands




Script

In general, the commands for the BASH are always structured in such a way that you first enter
the command’s name. Followed by any options and arguments. The curly brackets on the slide
are intended to indicate that these entries can be made but are not mandatory. Options are
usually written by a hyphen or dash and usually a letter. Such options influence the behavior
of the command. In the command for sorting a text file, for example, options are used to
control the sort sequence. Many commands also expect an argument. These can be thought of
as parameters for a method or a function. For example, the command for sorting a text file
requires the name of the file. This is followed by a redirect. This means what should happen to
the output of the program. By default, the output is always displayed on the screen. But you
can also use a redirect to write the output to a file or pass it to another command. We will
look at this at the end of this unit using a few examples. Let’s start with the first commands.
The whoami command displays the current user’s name. The second command, groups, shows
which groups the user is in. In Linux, a group is a set of users who have similar rights on the
system. LS can be used to display all files in the current directory. With “ls dash l,” you get a
long list in which further information is given, such as read and write permissions, the name of
the user who owns the file, and the date on which the file was last modified. Now, an example
of an argument. In the next line, the word “Documents” is given as an argument. This means
that the ls command should only output files from this directory. The help option provides
information about the ls command from the user manual. Incidentally, every Linux command
should understand this help option and provide corresponding information.




                                               10
````

## Page 011 — Working with the Shell: History of Commands

````text
Slide 10: Working with the Shell: History of Commands




Script

Every command you enter in the shell is saved in the bash history. This is a file that is hidden
in the user’s root directory. Now comes another very important shortcut. CTRL-P, or the up
arrow key, takes you to the last command or all commands you have entered. Especially if, for
whatever reason, you want to execute the same command again and again, you should retrieve
the last input from the history. This history file is also searchable. To do this, press CTRL-R
and start typing the command. Bash then completes with the first hit from the history file. This
is particularly interesting if you rarely need a long command with many options and arguments.
The history is, therefore, like a notepad for commands.




                                              11
````

## Page 012 — Exercise 1: Using Linux Commands

### Exercise SOP03-E01 (source slide)

````text
Slide 11: Exercise 1: Using Linux Commands




Script

Let’s move on to the first exercise. Now that you have learned the basics, please look at the
manual pages for the “whoami”, “echo”, and “ls” commands. You can either call the command
with the help option. Or you can use the man command for manual pages and enter the
command for which you want information as an argument. Please try out some of the available
options for the respective commands. For example, find out how you can display hidden files.
Can you recognize what hidden files have in common? And please find out how to display only
the subdirectories in the current directory. When you are finished, please press the button.
Then we’ll take another look together.




                                             12
````

## Page 013 — Screencast 3: Solution for the Exercise

````text
Slide 12: Screencast 3: Solution for the Exercise




Script

So before we start with the commands from the last exercise I would like to show you with
the history again. So when we type in here a command then we can use the arrow keys up
and down to get the last command. So if we go up further, go up in the history we get more
commands and you can also search for commands in the history and this is done by Ctrl R
and then you start typing in the command and then there is kind of an autocompletion here
what the shell has found in the history of commands. Okay, so let’s start with the commands
from the exercise. The first one is whoami and whoami just prints the name of the logged in
user and to get more information about the whoami command we call the manual man with
parameter or option whoami and then you can read here this is not too much so the whoami
command is kind of simple let’s say. You can ask for help this double dash help option is always
valid for all commands. The next is echo, echo is the manual page is a little bit longer here you
can see this so for example we have in general we have here the possibility to when the main
page is longer to skip forward and backward and as with the more command so space brings
us to the next page and B to the previous page. So when we start reading here what kind of
options does echo allow so for example dash N do not output the trailing new line so dash E
enable interpretation of backslash escapes. So let’s try one of these options here we write echo
and then dash N and then hello world so here you can see now the difference so what does
this dash N option here. Let’s do the normal echo word again so that okay this does not work
let’s type this in again so after hello world there is the backslash N which we did not type in
but this comes automatically and with dash N we skip this line feed character and you can see
this the output and the prompt from the next command they follow on each other. So let’s
have a look at the main page of LS and this is very long now and for example we have this
dash A option and this was actually the option that you should look for in the first exercise so
the question was how to also display hidden files and unfortunately the word hidden does not



                                               13
````

## Page 014 — Fortsetzung / ohne Folientitel

````text
appear in this main page here but when you read the first description of this dash A option
do not ignore entries starting with dot you might have an idea that these two things match
together so actually and this is right so dash A is for printing all entries of a directory and also
including the hidden ones. So let’s try this out. We go to the home directory and LS dash A
and now you can see more files than compared to just LS and all these files start with a dot
and this is really important to remember hidden files start with a dot and Linux has many
hidden files. So the next option was or the next question from the exercise was how to print
also directories and I mean here in this list you can see test is a directory but its content is not
shown but when you use the option minus or dash capital R then you can see another type of
output here. When you start reading this from the first line on so we have the current directory
which is the dot then we have a colon as like now comes the list of entries in this directory and
this is only test and then we go one level down into the directory test and there we have this
file demo dot txt. So with this command LS dash R we can show files in sub directories.




                                                14
````

## Page 015 — More Linux Commands

````text
Slide 13: More Linux Commands




Script

We will now introduce you to a few more important commands under Linux. The first command
displays the current date on the screen—the second command, who, shows which people are
currently logged on to the computer. More precisely, this command shows every open shell.
If you are logged on to the computer alone but have several shells open, your name will be
displayed several times. The W command provides information about the processes of all logged-
in users. The command DF for disk free provides information about the file system, in particular,
how much space is already occupied and how much space is still free. The WC command for
word count can be used to count the number of words or lines in files. And finally, the EXIT
command is used to quickly close the current shell.




                                               15
````

## Page 016 — Exercise 2: Using Linux Commands

### Exercise SOP03-E02 (source slide)

````text
Slide 14: Exercise 2: Using Linux Commands




Script

In the second exercise, you should familiarize yourself with these new commands. Firstly, please
find out how to use the DF command to display the free memory space in megabytes. Then, use
the Date command to display only today’s weekday, for example, Tuesday, and not the whole
date. Then, find out how to use the “who” command to display the number of logged-in users.
You should not count the output of who manually, but find an option for this. If you want to
see the solution, please click the button.




                                              16
````

## Page 017 — Screencast 4

````text
Slide 15: Screencast 4




Script

Okay, your task was to learn more about some commands. The first one is df. So, the command
df shows us for all mounted file systems the number of blocks currently used and compared to
the number of blocks that is free and available. And you can see at the headline here we are at
the moment reading about 1k blocks and we now want to have another unit so that it’s more
easy for us to understand the file size or the file system size here. So we have to look at the
main page of df and we are looking for a more, let’s say, human readable form of block sizes, for
example, and when we scroll down we find this description here that we can influence the size
by giving some units. And k stands for kilobyte, m for megabyte and g for gigabyte and so on.
So we try this and we go for dash capital B, that’s the option, and m for megabyte blocks. And
you can see the headline has changed here and the number is now a little bit more readable.
We can even make this more easy for us by changing this to gigabyte. So now it’s clear how
much space is free. The next command is date. When we enter this command, playing on the
console, then we get the current date. We open the command line here, we open the main page,
sorry, and we are looking now for options to output only the current day of the week. So always
start in the top with an overview of the options that are available and when you look at the
first line there, date option and then plus format, this plus format could be a hint that this
is the way to configure the output. And when we scroll down in the main page we have here
the overview how to control the format and all these commands start with a percentage sign
and we try this by using date and the plus sign to start the format, then the percentage sign
and capital A gives us the day of the week. So this is the way how we want to use this. And
the next and last command was who. Without any options it gives us information about the
currently logged in users, but in the exercise your task was to find a way to print the number
of users. So we open the main page, it’s always the same procedure. If you don’t know how to
use a command, open the main page and then either you start reading the whole main page



                                               17
````

## Page 018 — Fortsetzung / ohne Folientitel

````text
or you make some guesses about where to find this parameter and you can see here dash q is
the parameter we are looking for. So we try this who dash q and this gives us the number of
users.




                                            18
````

## Page 019 — Filesystem Navigation

````text
Slide 16: Filesystem Navigation




Script

We assume that you already have a basic understanding of directories and files. You have
certainly all worked with the file manager in the Windows operating system or with the Finder
on macOS. A file is a sequence of bytes that are saved under a name. Files are always located
in a directory. And directories can, in turn, contain sub-directories. The topmost directory is
called the root. Of course, there are also graphical programs under Linux that work similarly to
the file manager or the Finder. But here, we want to deal with the operation of the command
line. Therefore, we will show you the most important commands for navigating a directory tree.
Firstly, you need the PWD command. This stands for Print working directory and shows you
the name of the directory in which you are currently located. Use the CD command for Change
Directory to change to a different directory. If you want to change to one of the subdirectories
relative to the current directory, enter the command CD and the subdirectory’s name as an
argument. Enter the CD command without arguments to quickly return to the personal main
directory from anywhere in the directory tree. If you want to move up one level from the current
directory, i.e., to the parent directory, enter CD and then two dots. Incidentally, you can change
to the respective subdirectory or the directory above it and quickly change to any directory
if you know the full path to this directory. To do this, use the last instruction next to me.
The first slash stands for the root directory, and the first directory name for a subdirectory in
the root directory. Another slash may follow this, and the second directory name is another
subdirectory.




                                               19
````

## Page 020 — Working with Directories

````text
Slide 17: Working with Directories




Script

Next, you need the two commands for creating and deleting a directory. The MKDIR command
stands for Make Directory and creates a new directory under the name given as an argument.
The second command, RMDIR, stands for Remove Directory and deletes an empty directory. If
the directory is not yet empty, you will receive a corresponding error message on the command
line. You must then use another command, which we will learn about briefly, to delete all files
in this directory. The last command on the list next to me is used relatively frequently in
practice to create an empty file. The command is called Touch, and the file’s name is given as
an argument.




                                              20
````

## Page 021 — Copy, Move, and Delete

````text
Slide 18: Copy, Move, and Delete




Script

Before we move on to the next exercise, you will need three more commands. But then we are
already through with the basic commands for handling directories and files. The first command
is used to copy files. The command is called Cp and stands for copy. Two arguments are
specified, the first being the name of the file to be copied and the second the name of the target
file. The second command is called MV and stands for Move. This command can either move
a file from one directory to another or rename a file. Or to rename a directory. Again, the first
argument is the source file, and the second is the destination file. And finally, we use the RM
command for Remove to delete a file. The command accepts arguments that are understood as
file names. One last thing: In the so-called social media, you will see a joke about the “remove”
command. It’s shown in the last line. It is said that this command is used to remove all fresh
language packages. Actually, it removes all files and directories, beginning in the root directory
and working recursively. The option r stands for recursively and the option f stands for force,
which means: don’t ask, delete immediately. You can only hope that you don’t have enough
permissions on your system to execute this command.




                                               21
````

## Page 022 — Exercise 3: Working with Files

### Exercise SOP03-E03 (source slide)

````text
Slide 19: Exercise 3: Working with Files




Script

In the third exercise, you should now translate the description that you see next to me into
the corresponding Linux commands and execute them in sequence. First, change to your user
directory. Then, create a new subdirectory named “test” and change to this directory. Then
copy the file passwd, which stands for the password, from the directory ETC, a subdirectory of
the root directory, into this directory Test. Now, use a Linux command to count the number of
lines in this passwd file. Then, change back to the directory above and delete the Test directory.
Please try to find out how to delete a not yet empty directory with just one Linux command.
If you want to see the solution, please click the button.




                                               22
````

## Page 023 — Screencast 5

````text
Slide 20: Screencast 5




Script

Okay, let’s have a look at the commands to work with directories and files. So the first command
is cd and this is used to jump to the home directory and we can print this current directory
with pwd. Then we can create a new directory using mkdir, makedir, we can change into this
directory and then we can copy a file from etc passwd to the current directory and this is
written as the dot. Remember that you always have to give source and target. So now we can
see, we can view more information about files. So here dash l gives us a long list and we see
that this file has 2944 bytes. We can also count the number of lines using the wc command
with dash l for lines and then the name of the file as argument and we have 50 lines here in this
file. So now we go back to the parent directory, so we are back in the home directory now and
we want to delete a directory using rm for remove, dir for directory and we cannot delete this
because the directory is not empty. So with this command we can only delete empty directories
and instead of this we use rm for remove, r for recursive and f for force which means don’t ask
me anything and now we can see there is no more directory in the home directory.




                                               23
````

## Page 024 — Linux Filesystem Access Rights

````text
Slide 21: Linux Filesystem Access Rights




Script

Now that you have learned many important commands and know how to navigate a directory
tree, we must deal with access rights to files next. If you use the LS command and the dash L
option to display the contents of a directory, you will receive information on the access rights at
the beginning of each line. You will see an initially incomprehensible sequence of letters similar
to the third point on the slide next to me. You will see three blocks of three characters each. The
first block describes the access rights for the file owner, the second block for a group and the
last block describes the access rights for all other users. Therefore, each file or directory has an
owner and belongs to a group. You will see the letter R in each block if the file is readable. You
will see a W if the file is writable and an X if the file is executable. If the respective permission
is not available, this is indicated by a hyphen. Incidentally, the right to execute a file is to start
the program or a script for a normal file. For directories, the right to execute means changing to
the directory. Let’s take another look at the example in the third bullet point. Therefore, this
file’s owner has read, write, and execute rights. All group members to which this file belongs
have the right to read and change but not to execute. And all other users only have the right
to read the file.




                                                 24
````

## Page 025 — Linux Filesystem Access Rights

````text
Slide 22: Linux Filesystem Access Rights




Script

Of course, there is also a command to change access rights. The command is called CHMOD
and stands for Change Mode. This command expects two arguments. The first argument sets
or changes the access rights. The second argument contains the name of the file or the name
of a directory. There are now four options for setting or changing access rights. You can see an
example of these four options next to me. Let’s start at the top. You can define the rights as a
sequence of three digits. The first digit defines the owner’s rights, the second for the group, and
the third for all other users. You can see the meaning of the digits in the table below. Imagine
the octal number as a binary number with three digits. The left-hand digit defines the right to
read, the middle digit is the right to write, and the right-hand digit is the right to execute. For
example, the binary representation of the number 5 is 101, which means that the right to read
is set, the right to write is not set, but the right to execute is set. Let’s take a look at the second
possibility. Here, you can see the argument U equals R. The U stands for the user, and the R
stands for read. With this command, we set the rights for this file so that only the owner can
read the file. And nothing else. In the next line, we do not use an = but the dash, which is to
be understood here as a minus. We are, therefore, removing the write and fill permissions from
the group, G stands for the group. All other rights remain unchanged. We use the + instead of
the minus sign in the next line. This, of course, means that we are adding the specified rights.
The A in front of the + stands for all other users.




                                                  25
````

## Page 026 — Becoming a Privileged Root User

````text
Slide 23: Becoming a Privileged Root User




Script

In a Linux system, in addition to the normal users, there is a special user with extensive rights.
This user is usually called the ROOT user or super user. Under Linux, this superuser can do
everything. They can read and write all files and execute all programs. Only the super user can
create new users and assign user groups. And only the super user can shut down or restart the
computer. You can try this out on your computer immediately by trying to execute the first
command in the list next to me. The Shut Down command shuts down the computer, and the -
H option also switches the computer off. A normal user does not have the right to perform this
operation. So, if you execute this command on your computer, an error message will appear.
There was a privileged user named root in the first versions of Linux. When installing a Linux
system, this user’s password had to be entered separately. To execute commands that required
superuser rights, you had to log into a different shell as this root user. This procedure was
abolished a few years ago for security reasons. Nowadays, you can become a super user with
the sudo command. This stands for super user do, i.e., do something as a super user. Nowadays,
this command is usually written in front of the command you want to execute in the superuser
role. You are then asked for their password, and the command is executed accordingly. The nice
thing about this procedure is that you only switch to the superuser role for this command. It
is technically possible, but not necessarily recommended, to give yourself superuser rights for
longer by entering the command in the last line next to me. Even then, you will first be asked
for your password and can then enter a series of commands to be executed as a super user.




                                               26
````

## Page 027 — Chaining Linux Commands 1

````text
Slide 24: Chaining Linux Commands 1




Script

The last topic in this unit is about the concatenation of Linux commands. The idea is that
we link two or more commands together so that the output of one command flows into the
next command as input. To achieve this, we use so-called pipelining. Please take a look at the
example next to me. We use the LS minus L command to display all files or directories in the
current directory. Normally, a screen output appears. However, if we now write the vertical
line after it, we redirect the LS command output as input to the next WC command. You
may remember that the WC command counts words or lines. As we also specify the minus L
option here, lines and not words are counted. The output of this WC command is then simply
a number corresponding to the number of lines. So, if we enter this in the shell, we get the
number of files or directories in the current directory as output. Incidentally, both commands
run in parallel. The LS command generates the output with the file names. At the same time,
the WC command is started and waits for input. The WC command waits as long as the LS
command has not produced any output. The WC command immediately processes each output
of the LS command.




                                             27
````

## Page 028 — Chaining Linux Commands 2

````text
Slide 25: Chaining Linux Commands 2




Script

We still need to look at a few other methods for concatenating Linux commands. In this example,
the commands are separated by a semicolon. This means that the first command is executed in
full, and then the second command is executed. With this type of chaining, the output of the
first command is not redirected to the input of the second command. Both commands are also
executed strictly sequentially, one after the other.




                                              28
````

## Page 029 — Exit Codes

````text
Slide 26: Exit Codes




Script

Now comes a small insert. Every Linux command produces a so-called EXIT code at the end.
With this EXIT code, the command reports whether the processing was successful or an error
occurred. Under Unix or Linux, the exit code zero means everything is OK, and EXIT codes
greater than zero indicate an error. What the specific number then means can be found in the
documentation. This EXIT code is not displayed on the screen after the command has been
executed. In some error cases, the exit code may be displayed in addition to the error message.
However, in the event of success, the exit code is guaranteed not to be displayed. In the shell,
you can show the exit code of the last command using the variable Dollar? variable. Please take
a look at the command in the last line. With ECHO, something is displayed on the screen, and
the access code is displayed in this case.




                                              29
````

## Page 030 — Chaining Linux Commands 3

````text
Slide 27: Chaining Linux Commands 3




Script

With the knowledge of these EXIT codes, we can continue in the list of procedures for chaining
Linux commands. In the next case, we chain two commands so that the second command is
only executed if the first is successful. Success here means that the EXIT code was zero. This
type of chaining is always required if it only makes sense to execute the second command if the
first command was successfully processed.




                                              30
````

## Page 031 — Chaining Linux Commands 4

````text
Slide 28: Chaining Linux Commands 4




Script

We will now look at the opposite case. If we link two commands with two vertical lines, the
second command is only executed if the first command is not completed. This type of concaten-
ation is used, for example, if you want to be prepared for the possibility that the first command
may not be successful and, in this case, want to try out another alternative with the second
command.




                                               31
````

## Page 032 — Chaining Linux Commands 5

````text
Slide 29: Chaining Linux Commands 5




Script

The last type of concatenation is more a type of nesting. Please take a look at the example
next to me. The second command is executed first. The output of this command is then passed
as an argument to the first command. This is, therefore, comparable to a function call. First,
the inner function is called, and then the outer function is called with the result of the inner
function.




                                              32
````

## Page 033 — Exercise 4: Chaining Linux Commands

### Exercise SOP03-E04 (source slide)

````text
Slide 30: Exercise 4: Chaining Linux Commands




Script

Now, we come to the last exercise for today. Please take a look at the command next to me. You
are also welcome to try it out on your computer. It’s nothing dangerous. The exit command
generates the exit code that was passed as an argument. But why is it not called directly but
with this notation for a function call, which we learned about on the last slide? And is the
ls command executed or not? If you have the answers to this question, you can change the
command to execute LS. If you want to see the solution, please click the button.




                                             33
````

## Page 034 — Screencast 6

````text
Slide 31: Screencast 6




Script

Okay, the task was to check the given command and understand or learn what it does, so
we type it in. Exit with the exit code 1 in a sub-command and then logical end with ls. So
what does this dollar parenthesis thing here do? So we open a sub-shell, we execute the exit
command, the exit command does nothing except of producing an exit code and after this we
return to the main shell and with this 2 ampersand we do a logical end with the ls. Only if
the first command was successful, ls is executed, in this case it’s not executed because exit 1 is
wrong or false, not successful. So you have 2 options to solve this by changing this to 0, then
the first command is successful and ls is executed or you change instead of logical end, you
change this to logical or and this means only if the first command is not successful, the second
should be executed. And so if we execute this now, then we have the output.




                                               34
````

## Page 035 — Input and Output Redirect

````text
Slide 32: Input and Output Redirect




Script

You have just learned about the pipe symbol, which you can use to redirect the output of a
command to the input of the following command. However, you can now also fill in the input
for a command from a file. To do this, use the notation as in the first line next to me - write
the angle bracket or “smaller than” character after a command and then enter the file name
to be processed as input. The reverse case redirects the output of a command to a file. You,
therefore, write the greater than symbol after the command and enter the name of a file. The
output of the command is then saved under this file name. If a new file is not always to be
created with this type of redirection, but an existing file is to be extended or supplemented,
then the two greater thane characters are used.




                                              35
````

## Page 036 — Screencast 7

````text
Slide 33: Screencast 7




Script

Okay, now some examples for using redirects. We start with the echo command and we want
to have this text hello world in a file. So we do a redirect using this greater than character into
a file named test.txt. And now we can have a look at the contents of this file using the cat
command. So we type in cat test.txt and we have this hello world in this file. So next we use
the other redirect, redirect of input. We use the read command and we want to fill a variable
and the variable should be named hello here in this example. We use the smaller than sign
to read text from this file test.txt into this variable hello and so this read command does not
wait now for any user input or carriage return line feed or whatever, but the content is in this
variable already and we can see this using echo and here it is. And the last thing I would like
to mention is that we can also append to a file. So we write echo hello world with two greater
than sign characters to test.txt and when we now look at the contents of this file you see it
contains two lines of text.




                                                36
````

## Page 037 — Summary

````text
Slide 34: Summary




Script

So, that’s it for today. You have learned a lot about three topics today. Firstly, we looked at
the Linux command line, and you learned about some shortcuts you can use to navigate the
command line. Then we discussed some of the most important, but of course, by no means
all Linux commands. And finally, we introduced you to various ways of linking several Linux
commands. There are a very large number of Linux commands for very different types of tasks.
We recommend that you look at the literature we will show you. Websites that present the
different types of Linux commands are, of course, also very useful. However, the best way to
get to know new commands is to deal with a specific problem and then search whether there
is already a Linux command for it or whether you can solve the problem by linking smaller
programs according to the philosophy of Unix.




                                              37
````

## Page 038 — Literatur

````text
Slide 35: Literatur




Script

[Musik]




                      38
````

