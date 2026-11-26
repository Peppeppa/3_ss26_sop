---
source_id: SOP02
original_file: 02-installing_script_2026-09-25.pdf
source_type: script
source_subtype: lecture_transcript
language: en
page_count: 23
source_sha256: 7ae9616e9c54552efc6d69689cb0ff84c346357823d0ac8a4907ded809fa3a78
verification: partial
verification_note: "All physical pages captured from indexed PDF text; embedded slide images and their code/figures have not been fully transcribed or visually verified."
---

# Installing Linux in a Virtual Machine

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** The following is the extracted original-language PDF text **page by page**, without KI summaries. The slide pictures accompanying each page, including diagrams, screenshots, slide-only code, and embedded visual formulas, are **not** reproduced by this text extraction. The source PDF is still needed for full visual fidelity. Verification is therefore **partial**, not verified. Printed page numbers may differ from PDF pages.

## Page 001 — Script

````text
           System-oriented Programming
           Installing Linux in a Virtual Machine
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

Welcome to this unit on installing Linux within a virtual machine. This unit is primarily aimed
at all students who work with the Windows or macOS operating system on their computer
and need a Linux computer for some of the units in this course. If you already have Linux
installed on your computer, you can still follow the steps for installing a virtual machine. For
example, using a different Linux distribution in a virtual machine might be useful. We will be
installing Ubuntu in this unit simply because it is a very common Linux distribution. However,
the steps can also be carried out with other Linux distributions. In this unit, we will first explain
some basics about virtual machines and introduce the important term hypervisor. We will then
guide you through installing a hypervisor and setting up a Linux operating system in a virtual
machine. We will do this step by step and always explain what will happen in a step. You
should start by watching the video, including a live demo for every step, and then follow this
step on your computer. At the end of the unit, we will briefly show you the basics of operating
a Linux computer via a graphical user interface and how to install missing software packages.
We will then also briefly discuss the configuration options for a virtual machine.




                                                 2
````

## Page 003 — Virtual Machines

````text
Slide 3: Virtual Machines




Script

Let’s start with a few terms. By a real machine, we mean the device in front of you right now
and with which you are watching these videos. The computer has processors, main memory,
hard drives, a graphics card, and perhaps a few other devices such as a keyboard and mouse.
This real machine called the host, runs an operating system that manages the computer’s
resources and controls access to the hardware. The examples in this video will be from MacOS,
as we are working on Apple devices. For you, it will probably be Windows. This operating
system runs all the applications you need on a daily basis, such as a web browser, a software
development environment, and a database. We will start a virtual machine on this real machine,
and for this, we need new software, which we will install together later. This software is called
Virtual Machine Monitor, but the better-known name for it is Hypervisor. When you start
this hypervisor on your computer, you have a virtual machine that behaves exactly like a real
computer, but the only difference is that it is not real. The virtual machine has processors,
main memory, and also hard disks but no real resources; instead, the real resources of the real
machine are used. Every access to the resources of the virtual machine is controlled accordingly
by the hypervisor and then passed on to the host. We can install a so-called guest operating
system in such a virtual machine. And once you have done this, you can work with the virtual
computer exactly the same way as with a real computer, provided that the host is powerful
enough. But we will come back to this later. With this approach, you can set up a Linux or
even a macOS computer on a Windows computer, provided you have the necessary licenses.
Any combination is theoretically possible.




                                               3
````

## Page 004 — Virtual Machines

````text
Slide 4: Virtual Machines




Script

Here, you can see a picture to illustrate what we have just said. On the lowest level, we have the
real hardware of your computer. The host operating system is running on it. Parallel to other
applications, a hypervisor runs on this host operating system as another process subject to the
usual rules for using the processor and main memory, just like any other process. Incidentally,
the hypervisor can not only run one virtual machine, but many in parallel. This is indicated in
the figure by the two boxes labeled VM 1 and VM 2. And these virtual machines are strictly
separated from each other. On a normal PC or laptop, there is usually just enough performance
for one virtual machine. But on large, powerful servers with, for example, 64 processors and
several hundred gigabytes of main memory, dozens of virtual machines can be run in parallel.
Each virtual machine can also be configured differently. For example, the virtual machines are
assigned different numbers of processors or amounts of main memory. A guest operating system
is installed in the virtual machines; in the graphic, you can see Linux on the left and Windows
on the right. The applications then run on the guest operating system.




                                                4
````

## Page 005 — Use-Cases of Virtual Machines

````text
Slide 5: Use-Cases of Virtual Machines




Script

Virtual machines are very popular in the server environment. This means that a very powerful
computer with many resources in terms of processors, main memory, and hard drives is used to
run many virtual machines. Of course, they are typically used in a data center with many servers
connected via a network and a distributed hypervisor infrastructure. This means that virtual
machines can even be migrated from one server to another during operation to better distribute
the load. What we are doing here today is called desktop virtualization. A virtual machine is
installed on your workstation, for example, to test software under a different operating system
during development. There is also the so-called application virtualization. A better-known term
for this is containerization, which we will discuss briefly. Virtualization has advantages, above
all, in the utilization of resources. For example, instead of using a separate physical machine for
each web server, which is then underutilized most of the time, you can share a slightly larger
and more powerful server and run many virtual web servers on it, which together make much
better use of the resources. From the point of view of computer administration, working with
virtual machines is also much easier because you can simply configure the virtual machine in
the hypervisor, for example, allocate more processors or more hard disk space, and do not have
to physically access the real hardware. Finally, in a distributed infrastructure, it is very easy to
move virtual machines between servers, i.e., migrate them, and thus distribute the load better
or, in the event of a failure of one computer, absorb the load with the other servers. In most
cases, the user of the virtual machine is not even aware of such migrations. It is, therefore,
completely unrecognizable to the user on which real servers the virtual machine is currently
running.




                                                 5
````

## Page 006 — Virtual Machines vs.\{} Containers

````text
Slide 6: Virtual Machines vs.\{} Containers




Script

Virtual machines are to be seen separately from the so-called containers. Containers are a
technology for so-called application virtualization. A container can be considered a package
consisting of the actual application and all other programs or services relevant to the operation
of the application. Additional libraries or other applications must be installed on the computer
beforehand to run the software. With a container, you can combine all these dependencies
and then deliver the application with the dependencies as a package. A major advantage is
that containers can resolve the different dependencies between software versions. Imagine that
one application still requires Java 8 and another already requires Java 21. Then, you must
install both Java versions in parallel on your operating system. With containers, you can place
the different Java versions in the respective container, and each application simply brings the
required Java version with it. However, containers run directly on the host operating system
and use certain techniques to separate the processes. A container, therefore, does not contain
a fully-fledged operating system. Containers are not a replacement for server virtualization but
a very useful addition. Containers are very often found today, for example, in the environment
of so-called microservice architectures. Each microservice is delivered in a container, and the
microservices can work together via virtual networks. At the end of this semester, we will talk
about containers and Docker as one example.




                                               6
````

## Page 007 — Type-1 Hypervisor (bare-metal)

````text
Slide 7: Type-1 Hypervisor (bare-metal)




Script

Two types of hypervisors are distinguished in the approaches to realizing virtual machines.
The so-called type 1 hypervisors work practically directly on the hardware of the real machine.
Although the hypervisor has a minimal operating system, access to the hardware from the
virtual machine is practically direct. For this to work, the processors must be prepared for
virtual machines, which has been the case with x86 processors since around 2005. Only virtual
machines run on these type 1 hypervisor and no other applications because no fully-fledged
operating system is supplied. Examples of such products are vSphere ESX or Xen Server. They
are mainly used in server virtualization.




                                              7
````

## Page 008 — Type-2 Hypervisor (hosted)

````text
Slide 8: Type-2 Hypervisor (hosted)




Script

Type 2 hypervisors, on the other hand, work on the host operating system, which is also
responsible for resource allocation and access to the hardware. This type is used, for example,
in desktop virtualization, which we will also look at in this unit. The hypervisor is one process
among many others and allows you to use a Linux computer in parallel on your computer
alongside your web browser and your development environment. Examples of such hypervisors
are VMware Workstation, Parallels for macOS, and Virtualbox, which we will use in this unit.




                                               8
````

## Page 009 — Ubuntu Desktop / Hardware Requirements

````text
Slide 9: Ubuntu Desktop / Hardware Requirements




Script

We are about to install the Linux distribution Ubuntu Desktop on your computer. The word
desktop indicates that the Linux computer is equipped with a graphical user interface and can
also be operated with a mouse. The hardware requirements would be very straightforward if
you wanted to install this operating system on a computer without virtualization. A 2 gigahertz
processor with two cores, 4 GB RAM and approx. 10 to 20 GB of hard disk space, depending on
what software you want to install later. Even less than 10 GB would be adequate for an initial
installation. However, if you want to install this in a virtual machine on your computer, your
real computer should have a processor with four cores, ideally 8 to 16 GB of main memory and
at least 20 GB of free space on the hard drive. You will also need a few gigabytes to load the
ISO image. So, 25 GB of disc space would be better. If your computer at home is not powerful
enough, you could also ask our university whether they could set up a virtual machine for you
in the computer center.




                                              9
````

## Page 010 — Step 1: Download and Install Virtualbox

````text
Slide 10: Step 1: Download and Install Virtualbox




Script

Let’s start by installing the hypervisor. We use the product Virtualbox from Oracle mainly
because it can be used free of charge. Virtualbox is available for Windows, MacOS, and Linux.
Enter the address next to me in your browser or search for the keywords virtualbox and down-
load. Installation under Windows and Linux should be unproblematic. For macOS, please note
that a security setting is required for the latest operating system versions. We will now show
you how to install Virtualbox on a macOS computer.




                                             10
````

## Page 011 — Screencast 1

````text
Slide 11: Screencast 1




Script

So we start the installation process of Linux in a virtual machine on your computer by dow-
nloading VirtualBox. This is the home page, the URL was on the last slide, and you can
immediately start to download here. You select your platform, your operating system, which is
the host operating system of course, and I go for Mac OS Intel here, and then the download
starts. And then we go to the finder, and we open the software, and this looks now different
on Windows and Mac of course, so start the installation process, and when you are done, we
continue with the next part of the video.




                                             11
````

## Page 012 — Step 2: Download ISO Image of Linux

````text
Slide 12: Step 2: Download ISO Image of Linux




Script

To install Linux, we next need a so-called ISO image. This file contains a memory image of a
CD or DVD. This is the usual installation method and historically goes back to the fact that
operating systems were installed from a CD or DVD. This is inserted into the corresponding
drive when the computer is switched on, and the computer’s firmware finds the CD or DVD as
a boot medium when it boots up. Nowadays, you can also boot from USB sticks, and this is a
good alternative when installing Linux on a real computer if your real computer no longer has
a DVD drive. But we install Linux on a virtual machine, and a virtual DVD drive is available.
Please go to the website whose address you see on the slide or enter the keywords “Ubuntu” and
“download” in the search engine. You will then quickly land on this page. Then please select
the version Ubuntu Desktop. The ISO image is approx. 3 GB in size, and the download takes
a few minutes. We will also show you this briefly on the computer.




                                             12
````

## Page 013 — Screencast 2

````text
Slide 13: Screencast 2




Script

So next we need Ubuntu and we go to the download page here and the current version is 24 and
it’s an LTS so it’s long term support version so you get updates for many years for this version
so download this and this is about 5.8 gigabyte here so this takes a while start the download
and in the next step of the video we install this




                                              13
````

## Page 014 — Step 3: Install Linux in Virtual Machine

````text
Slide 14: Step 3: Install Linux in Virtual Machine




Script

Now comes the most important step. We configure a new virtual machine in Virtualbox, insert
a virtual DVD as the ISO image, and start the machine. When booting, the ISO image is found
as the boot medium, and you are then guided through the installation by a program. You will
need to make entries at some points, so let’s look at this together. The following screencast is
accelerated in some places, as the installation of Linux takes 10 to 15 minutes, depending on
the performance of your host computer.




                                              14
````

## Page 015 — Screencast 3

````text
Slide 15: Screencast 3




Script

So, you have installed VirtualBox Manager on your computer. You have downloaded the ISO
image of Ubuntu 24. I now show you the installation process. What you can see here is my
installation of VirtualBox. I have already an old version of Ubuntu and I have another Linux
distribution here, DBN, installed, but we install now together Ubuntu 24. So, we create a new
virtual machine. You have to select the ISO image. And automatically detected here, Ubuntu
64-bit, that’s correct. And I want to have a user named Peter. Just for testing, I use a very
short password. Guest additions. When installing VirtualBox, these so-called guest additions
were downloaded. And if this is available here, I double check this, but it seems to be that it
is available. If it’s available, you can enter this here already. Guest additions mean these are
dependent on your operating system that you want to stall as a guest operating system. Some
more libraries, drivers and so on that help to improve the communication between VirtualBox
and the guest operating system. So, enter the host name. What’s wrong here? OK, domain
name is not necessary. Next, OK, I give it 8 GB of main memory. Let’s say 8 processors. And
now you have to create a virtual hard disk. 25 GB is quite OK if you have so much on your
system to afford. Follow the default parameters here. And then we can start. So now Ubuntu
is starting for the first time. OK, and now we are here at the beginning of the configuration
process. We go for English as language. OK, we skip this. Keyboard. OK, we have a German
keyboard here. Wired connection is OK because the host system in VirtualBox, they emulate
now a wired connection even if your laptop is only connected via Wi-Fi. Install Ubuntu, that’s
what you want. Interactive installation. Default selection is OK. Install software. No, we don’t
want to install software. OK, now the installation process runs. Yes, we want to erase. OK,
so I will stop talking now. The video will be sped up to save some time. And do this on your
computer. There might be some questions arising here from time to time, but in general, that’s
easy now to install the whole system on your computer. OK, so Ubuntu was restarted and we



                                              15
````

## Page 016 — Fortsetzung / ohne Folientitel

````text
can now log in. And one thing I would like to show you is how to increase the screen here. You
go to this icon here. And select Virtual Screen 1 and then you select Scale to 200% Auto Scaled.
And now it’s a little bit larger, you can see more on the screen. So let’s go to the settings here.
So settings. And let’s check the display. And this might now differ on your computer. We try
to increase the resolution to at least 1920 here. We apply this. And now this looks better. You
have Firefox here. You have a file manager here. And the app center, we talk about this later.
The trash bin. And here is the icon to show all apps. And one app that we are going to use a
lot during this course is the terminal. And this is the terminal of the console. And ls-l is the
command to list all files in the current directory. So that should be enough for this part. Let’s
continue.




                                                16
````

## Page 017 — Step 4: Installing Software Packages

````text
Slide 16: Step 4: Installing Software Packages




Script

Now that you have installed Linux in the virtual machines, we want to show you how to install
software under Linux. On the one hand, there is a program with a graphical user interface
where you can easily select the software you need using keywords or categories. However, not
all software packages can be installed using this program. The other way is via the command
line and the “apt” command. You can use this to install all available software packages under
Linux, but then you need to know what you need. We now want to install a well-known editor
and the C compiler using these two methods. We need both in other units.




                                             17
````

## Page 018 — Screencast 4

````text
Slide 17: Screencast 4




Script

To install software, we go to the App Center here. And here you can type in the name of
the software you want to install. Let’s go for Visual Studio Code. And you press the key and
you authenticate yourself. And now the software is installed. And this now looks as on your
computer as well. So VS Code runs on Linux as well as on Windows and Mac OS in the same
way. So the other way I’d like to show you is how to install software on the command line.
We start using the command line in the next video, but installing software is just a good first
example. So on the command line, you have a command that’s called apt-get. And you want
to install a software and the software is named GCC. But installing software is only allowed
as a superuser. The superuser is explained later. And now the software apt-get asks you if you
really want to install all these packages here. And then everything is installed. And GCC is, by
the way, the C compiler that we are going to use in one of the next units for C programming.




                                              18
````

## Page 019 — Step 5: Changing Configuration

````text
Slide 18: Step 5: Changing Configuration




Script

If you have shut down the virtual machine, we can now take another look at its configuration in
Virtualbox. When it is switched off, you can change the hardware parameters, thus controlling
the virtual machine’s performance. We would also like to show you how to easily exchange files
using shared directories between the host and guest systems.




                                              19
````

## Page 020 — Screencast 5

````text
Slide 19: Screencast 5




Script

Okay, finally I would like to show you how to configure the virtual machine. The machine is
switched off here and you can go to settings and here you have all the configuration categories for
example when you go to system you can here change the number of processors that is allocated
to the virtual machine we have here is the memory configuration you can add more file systems
for example you can configure the network you can even use USB ports and one thing I would
like to show you is how to share data between the hosts system and the virtual machine and
I have configured this here I show you how it is configured to mount this is called mount to
mount a directory from the host system into the virtual machine so this is the directory on the
host system and this is the path where this directory from the host system should be available
in the guest system so home Peter is my home directory and you have to give a name here of
the so-called mount point so that the directory that contains then all data that comes from this
directory here should be auto mounted and now we start the machine and I will show you the
result the result is here so this is my home directory and here I have a shared folder with some
assembler files for example so I forgot two things this is important now the first thing is you
need to install the the guest additions so to install the guest additions you need to have this
ISO image here activated and once you have done this in the file manager you will see this here
the guest additions and then you’ll run the software and then everything is done you have the
the guest additions I told you about this this is like some new drivers and some configuration
to improve the communication between host and guest system the second point I have to add
is in the terminal so when you have a look at this shared folder here you see well actually I
will explain what this means in the next unit but what you see here this folder belongs to the
super user root and belongs to a group named V box SF shared folder in order to allow yourself
access to this folder you have to add yourself to this group V box SF and to do this you type
in sudo at user then your login name my login name is Peter and a second parameter V box



                                                20
````

## Page 021 — Fortsetzung / ohne Folientitel

````text
SF so now this program responses here that I am already member of this group because I have
done this before and in your case you should see that some success message here it that you
were added to the group then you have to restart the whole system one more time and then
you have access to this shared folder




                                            21
````

## Page 022 — Summary

````text
Slide 20: Summary




Script

That’s all for today. Thank you for your interest in installing Linux on a virtual machine.
First, we have shown you how to set up a virtual machine. To do this, we first decided on a
Linux distribution. We then carried out the hardware configuration of the virtual machine. By
selecting a suitable image, we could install Ubuntu together. Finally, you have seen how you
can make customizations to your virtual machine. You have now set up a Linux computer. In
the next unit, you will learn how to use the Linux command line and how to write bash scripts
or programs in the C programming language against the Linux API.




                                             22
````

## Page 023 — Literatur

````text
Slide 21: Literatur




Script

[Musik]




                      23
````

