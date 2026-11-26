---
source_id: SOP14
original_file: 14-build_script_2026-10-17.pdf
source_type: script
source_subtype: lecture_transcript
language: en
page_count: 15
source_sha256: 31fa0cbb98e9d47e191785b25b23c2ebdb6e884638bb799a5ffecf0477c6f78f
verification: partial
verification_note: "All pages captured from PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or visually verified."
---

# Build Systems

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** Original-language text extracted page by page without summaries. Original slide pictures, source-code images and diagrams **not** in this text representation. The original PDF is required for complete visual content. Verification: **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                           Build Systems
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

Welcome to this unit about the build process in C programming. In this unit, we will dive
into the concept of Makefiles, a tool to automate the build process in C projects. You’ll learn
how to write your Makefiles, effectively manage dependencies, and understand the difference
between file-based and task-based targets. Additionally, we’ll explore how to execute Makefiles
in subdirectories, helping you structure large projects more efficiently. By the end of this unit,
you’ll be equipped with essential skills to organize your compilation process and enhance your
productivity as a C programmer. Let’s get started.




                                                2
````

## Page 003 — The Compilation Process in C

````text
Slide 3: The Compilation Process in C




Script

When discussing the compilation process in C, it’s crucial to know its four fundamental stages:
preprocessing, compiling, assembly, and linking. During preprocessing, the preprocessor handles
the “include” directives. These directives instruct the preprocessor where to find the header files
containing the function declarations your program needs to execute properly. Preprocessing
involves replacing the “include” directives with the corresponding content from the appropriate
header files. The preprocessor also handles the “define” directives to define macros or constants.
After pre-processing, we step into the compilation phase, translating your high-level C code
into assembly code, a low-level human-readable language that you might know from a course
on computer architecture. This assembly code is specific to the target processor architecture,
allowing the computer to comprehend what actions it needs to perform. Next, we have assembly.
In this phase, the assembly code is translated into binary machine code. This machine code is
collected into an object file. Each C source file you compiled will correspondingly produce a
separate object file. Finally, we bring everything together in the linking phase. This is where
all the disparate object files are stitched together to form one cohesive executable program.
The linker also resolves any external references, such as functions or variables declared in one
file but used in another. You can also perform the entire compilation process in one step
using a command in your shell. The most commonly used command for this purpose is ’gcc -o
myprogram myprogram.c’. This line tells the gcc compiler to take ’myprogram.c’ as input and
produce an output file named ’myprogram’. All the intermediate steps are invisible now. So,
remember, the compilation process is not a monolithic stage but is layered and sophisticated,
which gives us developers more control and debugging power. Understanding this process helps
us write better, more efficient code.




                                                3
````

## Page 004 — Introduction to Build Tools

````text
Slide 4: Introduction to Build Tools




Script

Understanding build tools, like Make or CMake, is fundamental for any serious programmer.
These systems are designed to efficiently manage and automate the software building process
from its source code. When discussing building software, we primarily refer to compiling the
source files to create an executable. While you could compile each source file manually, ima-
gine doing so for a large project with hundreds or thousands of files. This process would be
terribly slow and highly prone to errors. That’s where build tools come in. These tools allow
you to automate the build process completely, essentially jumping from source code to an ope-
rational program with a single command. They parse through the codebase to understand the
dependencies between files and then ‘adeptly organize the compilation order to respect these
dependencies. But there’s more - build tools are also incredibly efficient. If you’re making a
minor tweak to a single piece of code within a vast project, you don’t need to rebuild the entire
software from scratch. Build tools are designed only to rebuild files that have been changed and
any other files that depend on those transformations. This can save a considerable amount of
time, especially for large projects.




                                               4
````

## Page 005 — Introduction to \{}texttt{make}

````text
Slide 5: Introduction to \{}texttt{make}




Script

Delving into building systems, let’s start with a fundamental tool, ’make.’ Think about it with
the Java tools you’re familiar with, such as Maven or Gradle. The functionalities are quite alike.
Just as Maven and Gradle simplify the software building process of Java and Kotlin projects
by automating the tasks, ’make’ does the same for C. To get its job done, ’make’ relies on a
Makefile. This Makefile, a simple text file, delineates the rules for building the software. It’s
essentially a blueprint that ’make’ follows for the build process. A key aspect of ’make’ is its
understanding of dependencies. Inside your Makefile, you define dependencies between files. If
one file changes, ’make’ knows how and which parts of your program need to be recompiled based
on these rules. This leads to efficient and faster builds as only modified files are recompiled. The
utility of ’make’ isn’t just limited to C files. It extends to automating tasks involving similar
file types. For instance, if you have a LaTeX document, you can use ’make’ to compile it into
a PDF file. It would be fantastic if you could put any documentation as Latex or Markdown
file into the same repository as your source code and use ‘make’ to create the documentation
in PDF, for example.




                                                 5
````

## Page 006 — Basic Structure of a Makefile

````text
Slide 6: Basic Structure of a Makefile




Script

We now look into the basic structure of a Makefile. A Makefile rule has three key components:
target, dependencies, and commands. Firstly, we have our ’target.’ This is typically the file
that needs to be generated. A target ’file’ often depends on one or more ’source’ files. Source
files are those files that, when modified, require the target to be updated or ’remade.’ Certain ’
commands ’ come into play depending on the state of our source files. These commands are the
series of steps that the make tool takes to create or update our target file. Let’s illustrate this
with an example rule to compile a C file. You can see the rule at the bottom beside me. Our
target file could be an executable named ’myprogram’, which depends on the ’myprogram.c’
source file and a header file called ’myprogram.h’. The command to create this target could
be executing the ’gcc -o myprogram myprogram.c’. Whenever the two source files change, the
’make’ tool will execute the gcc command to update or ’remake’ our program. If the source files
aren’t updated, the make tool does nothing.




                                                6
````

## Page 007 — Variables in Makefiles

````text
Slide 7: Variables in Makefiles




Script

An important aspect of optimizing your work in building systems is variables that can signifi-
cantly simplify defining rules. They act as containers where you can store file names, options,
or any other common data you can conveniently call upon throughout your Makefile. Let’s take
a look at how this works. It’s pretty straightforward to define a variable in a Makefile. Let’s
say you want to define a variable named CCffor the C-compiler because this is something you
may be reusing across multiple rules. You would do so by stating CC = gcc. Later, as part of
a rule, you need to use this variable. All you have to do is invoke it with dollar signs and write
the variable name in parentheses. So, variables in Makefiles reduce the repetition of common
data, reducing chances of error and improving overall readability. It is very common to define
variables for commands and parameters or options of this command.




                                                7
````

## Page 008 — Phony Targets in Makefiles

````text
Slide 8: Phony Targets in Makefiles




Script

Next, we explore ’Phony Targets.’ One notable feature about Phony Targets is that, unlike
regular targets, they don’t produce files but instead perform actions. This distinction from
regular targets may seem insignificant in the context of a small project. Nonetheless, phony
targets can be the difference between a successful and failed build in complex software systems.
To understand this better, let’s take a commonly known use case: cleaning up. Cleanup is often
done using a phony target named ’clean.’ This ’clean’ task typically involves removing all the
files produced during the build process to return the environment to its original, pre-build state.
Defining ’PHONY’ in line 1 beside me might not seem necessary, but it is a good style in the
realm of programming. Labeling a target with ’PHONY’ tells ‘make’ that the target doesn’t
correspond to a literal file; it has no file to check for freshness. For instance, this becomes
extremely useful when, by chance, a file named ’clean’ exists. If ‘make’ sees a ’clean’ file in your
directory and you don’t specify ’PHONY’, it will assume that the ’clean’ target is up-to-date
and, therefore, do nothing.




                                                 8
````

## Page 009 — More Complex Makefiles

````text
Slide 9: More Complex Makefiles




Script

As we dive deeper into more complex Makefiles, let’s examine an example using multiple source
files. In a larger project, splitting code into several source files for organization and improved
maintainability is customary. Like single file projects, each of these independent source files
must be compiled into object files. Object files, denoted by a “.o” extension, prevent needless
recompilation. Only modified source files will be recompiled into new object files, saving time
and computational resources. The linker will then stitch these object files to create the final
executable.




                                                9
````

## Page 010 — Automatic Variables in Makefiles

````text
Slide 10: Automatic Variables in Makefiles




Script

We can leverage automatic variables to make our Makefiles more efficient and less error-prone.
Imagine automatic variables as smart shortcodes, which Makefile provides to simplify writing
rules. Moving onto some of these automatic variables, let’s start with dolloar @ - This represents
the target name. It’s especially handy when the target’s name is lengthy or complicated. Instead
of writing it out for every rule, “dollar @” lets you refer to it concisely. Next is “dollar circumflex";
this automatic variable refers to all the dependencies of a rule. It ensures all your source
files are accounted for when creating an object file or executable. Lastly, we have “dollar <”,
corresponding to the first dependency. This is helpful in scenarios where only the first source
file needs to be called out or specifically manipulated in any way.




                                                   10
````

## Page 011 — Make all

````text
Slide 11: Make all




Script

Let’s focus on the ’Make all’ concept in build systems. ‘All’ is essentially a target or rule built
within the makefile. It serves an important role, and having an ’all’ target is generally considered
a good style. The ’all’ target is usually the first target or rule in the makefile. Being the first
rule, it becomes the default target when ’make’ is executed without arguments. This is crucial
because it makes the user’s job easier. They’re not required to remember the names of different
targets or their sequence. They can type ’make,’ and it will, by default, call the ’all’ target. The
’all’ target is also helpful when creating multiple targets, often expected to be built together.
For instance, if you are developing software with multiple parts, you can include all those parts
under the ’all’ target. In the example beside me, you can see this in line 1. In this example, we
assume that the parts of the software are defined behind rules one, two, and three. This way,
all those parts will be built together when the ’make’ command is invoked.




                                                11
````

## Page 012 — Makefile for Larger Projects

````text
Slide 12: Makefile for Larger Projects




Script

When working with mass projects, one practice we often employ is to use separate directories for
the various modules of the project. This modular approach offers a more organized structure,
making the project more manageable and navigable. Separate directories also ease tracking
changes and updates, thus enhancing overall workflow efficiency. In the example beside me, you
can see in lines 6 to 8 how to iterate over a list of directory names and recursively call make
with the dash C option to go into the given directory first. By the way, the variable MAKE is
defined by default. Makefile can get huge. The Makefile for the Linux kernel spans up to 2,000
lines! So, it’s a good idea to bring some structure to Makefiles.




                                              12
````

## Page 013 — Outlook to Bazel

````text
Slide 13: Outlook to Bazel




Script

Let’s conclude this unit by giving you an overview of a modern building system called Bazel.
Bazel is developed by Google and has been gaining attention in recent years. The beauty of
Bazel lies in its speed and scalability, making it particularly advantageous when dealing with
larger projects. Where other build systems may stumble or slow down when faced with large
codebases, Bazel can handle them more efficiently. In the example beside me, the rule “cc binary”
defines to call the C compiler and take care of all dependencies. While Make and Cmake have
their place for smaller projects, Bazel should only be used for large projects. Historically, many
developers have turned to Make for its simplicity. It’s straightforward, efficient, and works well
for smaller projects. On the other hand, Bazel might come with a steeper learning curve, but
its benefits in dealing with large-scale projects are often worth the initial investment.




                                               13
````

## Page 014 — Summary

````text
Slide 14: Summary




Script

That’s it for today. In this learning unit, we’ve underscored the importance of build systems
for automation in programming tasks. One key takeaway is the recognition that build tools like
’make’ elevate the efficiency of our workflows, resulting in highly optimized codes and faster
output times. The tool ’make,’ with its tested reliability and straightforward functionality, may
be a great starting point for those new to build systems. It would be best if you remembered
to consider Bazel as an alternative when the project becomes bigger. We did not talk about
‘cmake,’ which, in essence, is a makefile generator. It is a cross-platform free and open-source
software for managing the build process of software using a compiler-independent method.
CMake uses scripts to generate makefiles, guiding the compilation process. While ’make’ relies
heavily on compilers, ’CMake’ allows work seamlessly across various operating systems.




                                               14
````

## Page 015 — Literatur

````text
Slide 15: Literatur




Script

[Musik]




                      15
````
