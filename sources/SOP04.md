---
source_id: SOP04
original_file: 04-using_script_2026-09-25.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 23
source_sha256: d372595cf9f358e6745bd6f8630b1bac2fcd6dbe94a99d5f57978e5b4fcd4b52
verification: partial
verification_note: "All pages captured from indexed PDF text, but slide-image contents (code, figures, and tables) not fully represented or visually verified."
---

# Using the Editor VIM

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** This is extracted original-language PDF text, page by page; not a summary. Each original page also contains a slide image that is **not** reproduced here. Original PDFs are needed for the image-based diagrams, formulas, and source-code snippets. Verification is **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                      Using the Editor VIM
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

Welcome to this unit with a short introduction to editors under Linux. In the later units, we
want to write programs, for example, in the Bash scripting language or the C programming
language. Of course, we will need an editor for text documents for this. There are many editors
available under Linux. Some are very simple and can be used without a graphical user interface.
Other editors, which you may know from your work on a Windows or macOS system, are usually
also available on Linux but not on every Linux system. Today, we would like to introduce you
to a simple editor called VI. At first glance, this editor seems very strange because it is very
different from the modern editors you are familiar with today. The great advantage of this editor
is that you don’t have to take your hands off the keyboard to edit a document. To achieve this,
there are various modes and many kinds of cryptic keyboard commands. We will now introduce
you to the basic commands for operating this editor. We hope you like it and you will see that
is the way how a text editor should work.




                                               2
````

## Page 003 — Linux Editors

````text
Slide 3: Linux Editors




Script

As mentioned in the introduction, there are, of course, many editors available under Linux.
Next to me, you can see three examples of editors that are frequently used on the command
line. We are not looking at editors that can only be used in a graphical user interface. The
first editor, called Nano, is a simple editor that is mainly used by people who do not have
much experience with Linux. You can use this editor without any prior knowledge because
there is something similar to a menu, and the operation is similar to what you would expect.
The second editor in the list is called “emacs”. This program was created from a collection of
macros for another editor. Hence the name: “emacs” stands for Editor Macros. Emacs is also
an editor that is initially very easy to use. However, its real strength is the programming of
its own functions or macros using the LISP programming language. LISP is comparable to
Scheme what you have learned in the first semester. This editor can, therefore, be extended
very easily. Emacs can also be used to edit e-mails, as a text-based web browser, and as a
calendar. There are even games integrated into Emcas. In earlier times, this led to the remark
that Emacs is a pretty good operating system but, unfortunately, not a good editor. The last
editor in our list is called VI. The name comes from the first two letters of the English word
VISUAL. To understand this, you need to know that at the beginning of the UNIX era in the
1970s, editors were still line-orientated. This means that if a user wanted to change a file, they
first had to enter a line number and could then change the selected line. Editor VI displays
the document as a whole on the screen, which makes editing much easier. The Editor VI can
be operated completely without a mouse and only with keyboard commands. This is why it
is still very popular with software developers today, as it allows them to work extremely fast.
Current software development environments such as Eclipse or IntelliJ also offer the option of
activating VI-like keyboard commands via plug-ins. However, the biggest argument in favor
of this editor is the following: this editor is installed on every Linux-based system. So if you



                                                3
````

## Page 004 — Continuation / untitled

````text
want to change something as a system administrator on any system, for example, if you need
to adapt a text file with configuration data, then you can rely on this editor being available.
And only this editor. Basic knowledge of how to use VI is, therefore, extremely important.




                                              4
````

## Page 005 — VI is a Modal Editor

````text
Slide 4: VI is a Modal Editor




Script

The first thing you need to know about the operation of this tool is the two modes in which the
editor works. There is the command mode and the edit mode. In command mode, keyboard
inputs are interpreted as commands. In this mode, you can, for example, place the cursor on the
screen, i.e., change lines or jump to the beginning or end of a line. In edit mode, the keyboard
entries are then regarded as input for the text document. To switch to this mode, you must also
switch from command to edit mode using a command. A special keyboard command returns
from edit mode to command mode. You are initially in command mode after starting the editor
from the command line. This is the point at which beginners fail. Because without knowing
how to switch to edit mode, you can’t do anything with this editor. Let’s take a look at this on
my computer.




                                               5
````

## Page 006 — Screencast 1

````text
Slide 5: Screencast 1




Script

Okay, now we are here in the terminal of a Linux operating system. And the first thing I would
like to show you is how to start vi and how to quit the editor at the end. Let’s enter vi and
as argument we give doc dot txt and that’s the editor and as you can see it’s very like empty
here so you don’t have any menus, you don’t have command palettes or so, so the only thing
that you see is in the status line at the bottom the name of the file dot doc dot txt and you see
the information that it is a new file. So whenever you start typing now you can press whatever
key you like you will not see anything because when the editor starts you are in the command
mode that means every keystroke is interpreted as a command. And how to get into the input
mode that’s by typing letter i and we do this now and now we can start typing. So you cannot
see that we are now in the input mode now but all characters that we now enter hello world
are interpreted as input to the file. So the next question is how can we leave this input mode
and come back to command mode and this is done by using the key escape and maybe you
have seen the cursor jumped to the last character the d but again you cannot see it here. And
the next thing you must learn is in command mode now you can use the colon and wq to write
and quit the editor. Now we can have a look at the file so we type in ls and we see okay this
file here now has 12 byte and we can have a look at with a command cat and now we start
editing again. So next thing you must learn is when you are in command mode you can use the
arrow keys to jump around but this is a very simple version of vi the very basic version and in
this when we jump to input mode again and you press now the arrow keys we have a problem
you can see there are some random letters that appear here like b a d c and so on. So in this
very easy in this very basic version of vi the arrow keys do not work in input mode but they
do work in command mode and now the last command for this first video is colon q and now
we add an exclamation mark and this means quit and don’t save the file.




                                               6
````

## Page 007 — Command Mode: Append, Insert, Replace, Delete

````text
Slide 6: Command Mode: Append, Insert, Replace, Delete




Script

You have already seen how to switch to edit mode with the i command. There are a total of
four commands to switch to edit mode. With the small “a” you can enter characters after the
current cursor position. With the capital “A,” you set the cursor to the end of the line and can
enter something there. Use the small “I” to start typing before the current cursor position. And
with the capital “I” you set the cursor to the beginning of the line and can enter something
there. Use the Escape key to return to command mode, as seen in the first demo. In the current
versions of VI, you can also use the arrow keys to position the cursor between the lines or
within a line. This works in both command and input mode. Now, we introduce the first two
commands to change the text document. If you are in command mode, press the lowercase “r”
key, and you can overwrite the character in the current cursor position. You are then not in
input mode. With capital “R” you overwrite characters until you press ESC. The same applies
to the “X” command, which deletes the character on which the cursor is currently positioned.
We will delete lines and words later.




                                               7
````

## Page 008 — Command Mode: Moving the Cursor

````text
Slide 7: Command Mode: Moving the Cursor




Script

We have already mentioned the arrow keys for moving the cursor in the document. However,
the disadvantage of the arrow keys is that you have to take your right hand off the keyboard.
This is why VI also offers the option of using the four keys “H”, “J”, “K”, and “L” in command
mode. If you are an experienced keyboard user, both hands are normally positioned on the
keyboard so that the index finger of the left hand is on the F and the index finger of the right
hand is on the J key. To position the cursor, all you have to do is move your right hand one key
to the left so that four fingers are on the four keys “H, K, and L”. Now, you have to remember
that the two outer keys are for horizontal navigation, and the two inner keys are for vertical
positioning. And then you can quickly position the cursor in the document without taking your
hand off the keyboard. If you think that positioning the cursor one character to the left or right
or up and down is far too slow to work quickly in a larger document, then you are right. That’s
why we’re going to show you in the next demo that many more commands allow you to quickly
jump to the beginning or end of a document or a specific line, or to quickly jump forwards or
backwards word by word in a line.




                                                8
````

## Page 009 — Screencast 2

````text
Slide 8: Screencast 2




Script

For the demonstration of the first commands to jump around in an existing document, I dow-
nloaded a kind of longer text document here and the name is sample3.txt and we open this file
now using vi and so what you can see here is the text is longer than one page so we can jump
with M to the middle of the page always follow the cursor now with command H, capital H
back to the first line of the screen not the first line of the document but the first line of the
screen and L capital L to the last line of the screen when you want to go to the last line of
the document you type in capital G and don’t wonder you are now in the not in the very last
line but in the last line but this is long enough to wrap around three lines here now capital H
brings you back to the first line of the screen and when you want to go from here now to the
first line of the document you type in double G small lowercase g so two times G so capital G
to the bottom two times lower key lower G to the top and now within one line you can move
word by word with W one word forward and B one word backward when you want to go to the
beginning of a line you type in zero and dollar brings you to the last character in the line so
you can go back again and you can also type a number before a command for example now I
type five B and this jumps five words back and five W five words forward




                                               9
````

## Page 010 — Command Mode: Copy, Paste, and Delete

````text
Slide 9: Command Mode: Copy, Paste, and Delete




Script

An important technique in all editors is copying and pasting text parts. Of course, this also
includes deleting parts of text. Today’s word processing systems and editors use the standar-
dized keyboard commands Control C for copying, Control X for cutting, and Control V for
pasting. On a Mac, by the way, you do not use Control C but Command C. The same applies
to the other two commands. Copying and cutting always refers to a selected area of the docu-
ment. And marking is now usually done with the mouse. Unfortunately, these three keyboard
commands do not work in Editor VI. But there is something much better. Because you have
many more functions available for copying or cutting parts of text than just these very simple
commands. Copying parts of text works via the Y command. This letter stands for the word
Yank, which means to tear or rip out. You often want to copy a complete line, for example. To
do this, use the YY command. Use the YIW command to copy the word in which the cursor
is currently positioned. Use the YW command to copy the part of a word from the current
cursor position to the beginning of the word. Use the command Y0 to copy the part of the
line from the current cursor position to the beginning and Y Dollar to copy the part from the
current cursor position to the end of the line. There are a few more commands for copying,
which you can read about on the websites listed in the recommended reading at the end of this
unit. Perhaps one more thing. If you write a number before the command YY, you can copy
as many lines as you specified with the number. You can then paste what you have just copied
with the command “p” at the current cursor position and with the command capital “P” after
the current cursor position. Deleting works with the “D” command and, as with copying, you
can then append further letters to the command, for example, deleting an entire line with DD,
deleting a word with DW, deleting everything from the current cursor position to the beginning
of the line with the zero and everything to the end of the line with the dollar. Everything you
have deleted can be inserted again using the “P” command.



                                              10
````

## Page 011 — Command Mode: Repeat and Undo

````text
Slide 10: Command Mode: Repeat and Undo




Script

Every command that you enter in command mode can then be executed again with the com-
mand dot. For example, if you have just deleted a line with the command the idea, you can
delete the next line with this short command. You can also undo any command. To do this,
use the command U for UNDO.




                                           11
````

## Page 012 — Command Mode: Indentation

````text
Slide 11: Command Mode: Indentation




Script

Formatting the source code plays a major role in programming. In some programming langua-
ges, such as Python, the source code must be indented to be syntactically correct. In other
programming languages such as C and script programming, which we will look at later, the
source code is indented within loops, branches, or functions, for example, to make it easier to
read. If you are already in input mode, you can use the tab key as expected. But what do you
do if you have already entered a few lines and later realize that you have forgotten to indent
the lines? In command mode, you can indent a line with a command consisting of two “greater-
than” characters and, in the same way, undo this indentation with two “less-than” characters.
These two commands can be combined wonderfully with the specification of a number before
the respective “greater” or “less-than” characters. In many programming languages, blocks are
enclosed by curly braces. If the cursor is positioned on one of the two curly braces, you can
use the command “greater-than” and the percentage sign to indent a complete block and, si-
milarly, use the command “less-than” and the percentage sign to indent the block again. Other
commands for indenting and outdenting blocks also work with other types of brackets.




                                              12
````

## Page 013 — Screencast 3

````text
Slide 12: Screencast 3




Script

I would like to demonstrate the commands that we saw on the last slide. So we open here and
edit a C program, C source code with a main function and some simple print statement to
output hello world. And you can now use the percentage sign to jump between the two braces
here. So this is the first let’s say shortcut here to jump around within a function. When you
want to indent you can use greater than percentage sign, but this as you can see indents the
whole block that is marked with the curly braces. This is not what we want so we undo this by
smaller than percentage sign. When you are in one line you can use the greater than sign twice
to indent just one line and twice the smaller than sign to undo this. So we make the block a
little bit larger so we copy one line by double y p so double y for yank the current line and p
for paste the line. And then we can write 2 so number 2 and the greater than sign twice so that
both lines are indented now and we can undo this by number 2 and twice the smaller than sign.
You can also just indent one line here and then go down one line and press the dot to repeat
this command.




                                              13
````

## Page 014 — Command Mode: Save and Exit

````text
Slide 13: Command Mode: Save and Exit




Script

Before we move on to the first exercise, you will need the commands to save the file and exit
the editor. With the command “colon” W, you save the document to the hard disc, but the
editor is not exited, and you can continue working. If you add a Q, the editor is also closed. The
command “colon” Q closes the editor, and you will receive a message if there are any unsaved
changes in the document. You can only exit the editor with this command if you have saved
the document. If you no longer want to save changes to the document and still want to exit the
program, use the command “colon” Q with an exclamation mark at the end.




                                               14
````

## Page 015 — Exercise 1: Working in Insert Mode

### Exercise SOP04-E01 (source slide)

````text
Slide 14: Exercise 1: Working in Insert Mode




Script

You have already seen that using the editor is somewhat unusual because you constantly switch
between these two modes for commands and input. You also have to memorize many different
commands, but these commands are extremely helpful for quickly making the necessary changes
to a text document. In the beginning, it is necessary, and also, later, when you already have
some experience, it is certainly helpful to have a short overview of all commands at hand.
There are some so-called cheat sheets on the web for this purpose, and we have listed one of
them here, which you can and should look up if required. If you open this page, you will see
many more commands than the ones we presented here in the short time available. Initially, it
was strange to constantly switch back and forth between these two modes for commands and
inputs. For this reason, there are also special key combinations to move the cursor and delete
characters even though you are already in input mode. In the first exercise, please look at this
cheat sheet, find out for yourself what these key combinations are, and try them out on your
computer. When you are finished, please press the button. Then, we will look at the solution
together.




                                              15
````

## Page 016 — Screencast 4

````text
Slide 15: Screencast 4




Script

So, let’s have a look at the cheat sheet here. This is the recommended one that is also linked in
the video and also in the Moodle course. We talked about cursor movement, we talked about
cutting and pasting, we talked about editing already and indenting and de-indenting text. We
mentioned this also. So your task in this exercise was to find a way how to move the cursor
and delete characters in the input mode. So you remember that when we type the arrow keys,
then these strange letters like B, A, C, D and so on appear on the screen. So cursor movement
does not work in the input mode, but you can use these commands here. But now we have a
problem. The first version of VI that I showed to you is very old, but this was the standard
version that was installed on the Linux system. And these new commands with Ctrl H, Ctrl W
and so on, even this does not work in this old version of VI. So when you are on a system where
you are not the root user or super user and you cannot install new versions, then you must get
around this problem. And the only solution is that you move the cursor only in the command
mode. So this always works, but not in the insert mode. What I did here now, I would like to
demonstrate this to you and therefore I installed an update. I installed a new version of VI on
my computer here and the version that I installed is now 8.2. And we start VI now and you
can see with the same text and now we go to the input mode and you can see the difference
here in the status line there is now the German word Einfügen for input mode. And we type in
and now we can use the cursor to move around while still being in the insert mode. So let’s go
to the cheat sheet and see what other commands we have here, for example Ctrl H deletes the
character left of the cursor. This is like the backspace key or Ctrl W for deleting the word.




                                               16
````

## Page 017 — Exercise 2: Search and Replace

### Exercise SOP04-E02 (source slide)

````text
Slide 16: Exercise 2: Search and Replace




Script

In the second exercise, they should work with the cheat sheet again. This time, it’s about
searching and replacing characters in the entire document. This is a function that must be
available in all editors. For example, you want to rename a variable and don’t want to do it
yourself in all places, but you want to be able to search the entire document for this variable
name and then replace it in all places. Please look up the commands for this. Try out these
commands yourself in a text document on your computer. When you are finished and want to
see the solution, please click the button.




                                              17
````

## Page 018 — Screencast 5

````text
Slide 17: Screencast 5




Script

So, search and replace was the topic of this exercise. We go to the cheat sheet and we search
for this topic here, search and replace and you can see slash and pattern is the first command
for searching a pattern. A pattern is meant here as a regular expression now. We start vi with
a C program and we start with typing in the slash command and in the status line you can
now see the letters that we type in which are part of the regular expression and this version of
vi now immediately shows the matching parts in the text. Dot star is the regular expression to
match everything after the age until the end of the line. Dot L searches for parts of the code,
parts of the word here and now we copy the line and next I would like to show you how to
search and replace. The command for this is colon %s slash the old pattern or the old pattern,
the new value and G for global replace all occurrences in the text. So we type in colon %s hello
replaced by hello and this is done here. So let’s go back to the search because I want to show
you one more thing here. When we search for hello now we find the first occurrence and with
N we jump to the next one.




                                              18
````

## Page 019 — Exercise 3: Visual Mode

### Exercise SOP04-E03 (source slide)

````text
Slide 18: Exercise 3: Visual Mode




Script

We have mentioned several times that a big advantage of this editor is that you are guaranteed
not to need a mouse. Nowadays, the mouse is mainly used for positioning the cursor when
editing a text document and, above all, for marking text parts so they can be deleted or copied.
However, there is a solution for marking textiles in VI, which works without a mouse but purely
via keyboard commands. Please take a look at the corresponding commands in the cheat sheet.
The keyword you should look for is “visual model”. Try out the commands on your computer
with any text document. When you are finished, please press the button. Then, we will look at
the solution together.




                                              19
````

## Page 020 — Screencast 6

````text
Slide 19: Screencast 6




Script

So, the visual mode is a very, very powerful mode here. We open the C file and the first command
is the lowercase letter V and now you can move the cursor around and you can see the text
is marked now and then you press Y and this copies the text and then we enter a new line
and press P in the command mode to paste what we just have copied before. So we delete this
again and we can now copy this line here to demonstrate that we can use the capital V for line
mode here and let’s go to the cheat sheet. What else do we have here? So for example here we
have the I capital B command to mark a complete block so when we are inside such a block of
curly braces we press V I capital B to mark everything. Or we have here AW to mark a word
so you go to the beginning of the word press VAW and the whole word is marked.




                                              20
````

## Page 021 — What Else?

````text
Slide 20: What Else?




Script

We have now finished our first introduction to using an editor like VI. There are many more
functions that we could not introduce to you here in this first introduction due to time cons-
traints. Next to me, you can see some of the functions that you can read about later in the
books or the cheat sheet. For example, there is a function for defining positions in the document.
These positions or markers also help you to jump to certain places in the document quickly.
You can also work with Editor VI on several documents at the same time; you can compare
files and find differences. There is also an option for recording macros, i.e., functions that you
frequently need to change.




                                               21
````

## Page 022 — Summary

````text
Slide 21: Summary




Script

So, that’s it for today. You have learned about the VI editor. This editor is installed on all
Linux systems and basic knowledge is important if you ever find yourself on a foreign system
where you need to edit any text documents. Basic knowledge is absolutely essential for every
computer scientist and software developer. You have seen how to start and stop the editor from
the command line. You have learned that this editor has two different modes. In command
mode, you navigate the document and copy and paste text parts. In input mode, all text
entries are shown directly in the document. We have introduced you to the most important
commands, and we have given you a reference to a cheat sheet with all the commands of this
editor. In the beginning, the learning curve for this editor is relatively steep, but after a short
time, and if you use this editor daily, you will realize how easy it can be to use an editor. And
who knows, maybe you will also want to use this type of editor for your other work with text
documents. As mentioned at the beginning, there are corresponding plugins for all common
editors.




                                                22
````

## Page 023 — Literatur

````text
Slide 22: Literatur




Script

[Musik]




                      23
````
