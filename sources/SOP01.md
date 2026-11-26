---
source_id: SOP01
original_file: 01-introduction_script_2026-09-25.pdf
source_type: script
source_subtype: lecture_transcript
language: en
page_count: 10
source_sha256: a05371c08e6a1244468b06cd30893b218332d629904d118ac0873c3aafa408ae
verification: partial
verification_note: "All physical pages captured from indexed PDF text; embedded slide images and their code/figures have not been fully transcribed or visually verified."
---

# Introduction to System-oriented Programming

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** The following is the extracted original-language PDF text **page by page**, without KI summaries. The slide pictures accompanying each page, including diagrams, screenshots, slide-only code, and embedded visual formulas, are **not** reproduced by this text extraction. The source PDF is still needed for full visual fidelity. Verification is therefore **partial**, not verified. Printed page numbers may differ from PDF pages.

## Page 001 — Script

````text
           System-oriented Programming
                 Introduction to System-oriented
                                   Programming
                                Prof. Dr. Peter Braun


Slide 1:




Script

[Musik]




             1
````

## Page 002 — Welcome to this course

````text
Slide 2: Welcome to this course




Script

Welcome to this first unit of the System-oriented Programming course. You are a second-year
computer science student who should have already learned a lot about programming. You are
quite fluent in Java and object-oriented programming, right? Programming in Java is more on
the application level. In this course, I will introduce you to new concepts and programming
languages closer to the computer’s hardware. This course is not about the hardware but the
first layer of software on top of the hardware. We are not talking about how a computer’s
processor works, but we talk about how it is possible that a computer can do many things
in parallel, although it only has a single CPU. We do not talk about how bits and bytes are
stored in memory, but we talk about how the computer protects access to memory so that one
application cannot manipulate other applications. But before we talk about these operating
system concepts, I want you to become familiar with the Linux operating system and how to
use and configure it. You will learn how to survive on the command line. I will also introduce
you to the C programming language. Although this language is quite old, it is still in use and
still in the top 5 of the most popular programming languages. In this video, I will give you an
overview of the topics covered in this course.




                                              2
````

## Page 003 — Linux Command Line

````text
Slide 3: Linux Command Line




Script

We will start the Linux operating system. I will show you how to install it on your computer in
parallel to the other operating systems you might already have. Then, we will continue with the
command line, the human-computer interface for computer scientists and software developers
to control your computer. When you currently use a graphical user interface and operate with
the mouse a lot, this will be quite new and unfamiliar to you. Though it might seem a little
old school to use text commands in a world dominated by the mouse and touchscreen gadgets,
the command line is an extremely efficient and fast way of getting your computer to do exactly
what you want. On the command line, several text editors are available, such as Vim, Emacs,
Nano, and many others. They lack the fanciness of applications like VS Code or IntelliJ, but
they’re all much more powerful. They might not have pretty buttons or menus, but they can
edit text, and that’s what we want. Data processing also happens seamlessly on the command
line. You can sort data, search through it, and even modify it using many Linux commands.




                                              3
````

## Page 004 — Programming Shell Scripts using Bash

````text
Slide 4: Programming Shell Scripts using Bash




Script

Next, we will talk about the first new programming language. It’s called Bash, and it’s a
scripting language built on top of Linux commands. It’s a Turing-complete language. That
means you can implement everything like in Java, for example. But Bash is more focused on
automating tasks that you would normally do manually on the command line. Coding repetitive
commands into a Bash script allows these operations to run automatically, with little need for
direct involvement from the user. Bash scripts are also important in system administration
and configuration. System administrators often employ Bash scripts to perform routine tasks,
such as creating users, restarting services, and maintaining systems. These tasks may seem
trivial, but when magnified over large-scale server landscapes, the importance of Bash in system
administration becomes quite evident. Bash scripts can also be used for ETL tasks. ETL stands
for Extract-Transform-Load. It involves extracting data from a source, transforming it into
another format or structure, and finally loading it into a target, such as a database.




                                               4
````

## Page 005 — Programming in C

````text
Slide 5: Programming in C




Script

The second programming language will be C. As I said in the beginning, it’s quite an old
language; it was developed in 1972 as an alternative to Assembler programming. But it’s still
in use not only because there are some legacy systems around, but it’s still a popular language
for new systems. One reason is performance. It will be difficult to find another programming
language that allows performance optimization to such a level as C. When I introduce C, it
will be not about the introduction to programming. I assume you know at least Java and you
are familiar with if-statements and for or while loops. I will only point out the differences. One
huge difference is memory management, and this is also one big challenge when learning C.
You have to take care of memory consumption and release. We will talk about the Linux API,
that means, the system calls like how to handle files and network sockets. We will talk about
how to debug and profile C programs.




                                                5
````

## Page 006 — Security Aspects

````text
Slide 6: Security Aspects




Script

Next, we will talk about security. When programming close to the operating system level you
might run into new security risks. Especially when programming in C it becomes dangerous if
you don’t care about some basic protection mechanisms. Diving into the examples of dangerous
code, take buffer overflow as an example. This is when a program writes data beyond the
boundaries of pre-allocated fixed-length buffers, leading to erratic program behavior or even
its crash. It’s one of the oldest and most common errors, a fundamental slip-up that young
developers often make, effectively leaving the backdoor wide open. Or consider the problem of
unchecked user input, a common but dangerous oversight made by programmers. An application
that directly uses input from an end-user without the correct validations can cause a program to
behave differently than intended, potentially giving an attacker various advantages. I will show
you examples of possible dangerous codes, and we will talk about protection mechanisms.




                                               6
````

## Page 007 — Architecture of Linux

````text
Slide 7: Architecture of Linux




Script

When it comes to the theory of operating systems, we will talk about Linux as an example.
From time to time, I will show examples from Linux, but we will unfortunately not have much
time to really read Linux source code. An operating system is responsible for managing the
resources of your computer. And these resources are processes, memory, network connections,
and file systems. We will also briefly talk about inter-process communication. After this section,
you will understand how it is possible to run many programs in parallel on your computer and
how the computer can have several times more virtual memory than it has physically. You will
also have a basic understanding of how data is stored on a hard disk.




                                                7
````

## Page 008 — System Administration

````text
Slide 8: System Administration




Script

The last topic of this semester will be about system administration. Let’s assume you become
the admin of some Linux boxes. You will have to install Linux updates, sometimes even critical
security patches. You have to configure the system, maybe including new hard disks or other
devices. You have to organize data backups and restore mechanisms, especially for databases.
Nowadays, many applications run in Docker containers. We will talk about these containers
and how to start and stop containers.




                                              8
````

## Page 009 — Summary

````text
Slide 9: Summary




Script

So, that’s it for today. I am looking forward to this course on system-oriented programming. At
the end of this semester, you will be familiar with Linux and the Linux command line. It would
be great if, after this semester, you continue to use the command line and prefer it over the
graphical user interface. Maybe you can completely switch from the Windows operating system
to Linux or macOS. When it comes to the command line, macOS is very similar to Linux. In
total, you have gained in this semester more knowledge about the computer and the operating
system of your computer works. Let’s get started.




                                              9
````

## Page 010 — Literatur

````text
Slide 10: Literatur




Script

[Musik]




                      10
````

