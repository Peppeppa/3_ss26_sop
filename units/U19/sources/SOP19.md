---
source_id: SOP19
original_file: 19-debugging_script_2026-10-15.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 20
source_sha256: fb6679f7eefc0bf78808af38a54a705e5c893cc7d5ed11dccacd3d76f4060542
verification: partial
verification_note: "All pages captured from PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or visually verified."
---

# Debugging of C Programs

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** Original-language text extracted page by page without summaries. Original slide pictures, source-code images and diagrams **not** in this text representation. The original PDF is required for complete visual content. Verification: **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                  Debugging of C Programs
                           Prof. Dr. Peter Braun



Slide 1:




Script

[Musik]




             1
````

## Page 002 — Learning Objectives

````text
Slide 2: Learning Objectives




Script

Welcome to this unit, in which we turn to a skill that matters just as much as writing code:
finding out what’s wrong with it. Over the last few units, you’ve written real C programs and
first simple algorithms. All of that gives you plenty of ways to write code that compiles, runs,
and still does the wrong thing, or refuses to run at all. Today we’re going to look at how
to deal with exactly that situation, systematically rather than by guesswork. We’ll start with
the vocabulary you need for talking about bugs: the difference between an error the compiler
catches before your program ever runs, one that shows up only while it’s running, and one
that quietly produces the wrong answer without complaining at all. From there we look at how
to actually read what the compiler is trying to tell you, because a warning is very often an
error you haven’t met yet. Then we go through a handful of mistakes that catch almost every
beginner at some point, so that you can recognize them the moment you see them in your own
code. After that, we turn to technique: how to narrow a bug down using nothing more than
well-placed print statements, and how to simplify a failing test case until only the essential
problem remains. Finally, we bring in a proper tool for the job, the GDB debugger, and you’ll
learn how to set breakpoints, step through your code, and inspect variables while your program
is actually running, instead of just guessing from the outside. Let’s get started.




                                               2
````

## Page 003 — Types of Errors: Syntax, Runtime and Logic

````text
Slide 3: Types of Errors: Syntax, Runtime and Logic




Script

Every bug you will ever track down falls into one of three broad categories, and just knowing
which one you’re facing already tells you much about where to look. A syntax error is the
friendliest kind, in a sense, because the compiler catches it before your program ever runs at
all. You misspelled a keyword, you forgot a semicolon, you left a brace unmatched, and the
compiler simply refuses to produce an executable until you fix it. A runtime error is a different
thing entirely. The program compiles just fine, it starts running, and then something goes wrong
while it’s actually executing, for example, when it tries to access memory it has no right to
touch. And then there’s the third kind, which is honestly the most dangerous: a logic error. The
program compiles, it runs to completion, it doesn’t crash, and it still produces the wrong result,
kind of silently, without any indication that anything is wrong at all. You only see a wrong
result and might wonder why. One particular kind of runtime error deserves special mention
here, because you’ll run into it constantly: the segmentation fault, caused by your program
accessing memory that doesn’t belong to it. What makes this whole area tricky is undefined
behavior. C does not require the compiler to catch or report many kinds of invalid operations, so
your program might appear to work correctly on your machine and fail somewhere else entirely,
or fail only sometimes. That unpredictability is exactly why the compiler’s warnings matter so
much, and why we look at them first.




                                                3
````

## Page 004 — Reading Compiler Warnings Correctly

````text
Slide 4: Reading Compiler Warnings Correctly




Script

A compiler warning is not something to skim past on your way to the next line. Every message
the compiler gives you comes with a file name and a line number, telling you precisely where
it thinks the problem is, and that’s the very first thing worth reading carefully, before the
description of the problem itself. It’s also worth knowing the difference between a warning and
a fatal error. A fatal error stops compilation immediately; you get no executable at all until
it’s fixed. A warning, on the other hand, lets compilation continue, and that’s exactly what
makes warnings dangerous: it’s entirely possible to end up with a working executable that still
contains a serious bug the compiler already spotted and told you about. By default, the compiler
doesn’t tell you everything it could. Turning on the flag “-Wall” enables a much broader set of
checks, and “-Wextra” adds still more on top of that. Get into the habit of compiling with both
from the very beginning of a project, not just when something has already gone wrong. When
you do get a wall of warnings, resist the urge to jump to the last one or the one that looks
most interesting. Fix the first one the compiler reports first, because later warnings are very
often just downstream consequences of that same earlier problem. Ignoring warnings because
the program still runs is one of the quickest ways to ship a bug that only shows up later, in
circumstances you didn’t test. With that discipline in place, let’s look at the specific mistakes
warnings most often catch.




                                               4
````

## Page 005 — Typical Beginner Mistakes in C Programs

````text
Slide 5: Typical Beginner Mistakes in C Programs




Script

Certain mistakes show up again and again in C programs, often enough that experienced
programmers can spot them almost on reflex. An uninitialized variable is a classic starting
point: if you declare a variable and use it before assigning it a value, it doesn’t contain zero,
it contains whatever garbage happened to be sitting in that memory beforehand, and your
program’s behavior depends on that garbage. Closely related is a mismatch between the format
specifier you use with “printf” or “scanf” and the actual type of the variable, for example,
telling “scanf” to expect an integer when you actually handed it the address of a float. Loops
are another rich source of trouble. An off-by-one error in a loop condition, running one iteration
too many or too few, is extremely easy to write and, as you’ll see very shortly, extremely easy
to demonstrate. The same mistake shows up again with array indices, where a valid index range
simply doesn’t include the position your code tries to access. And then there’s a pair of mistakes
around numeric types: dividing two integers when you actually wanted a floating-point result,
silently losing the fractional part in the process, and comparing two floating-point numbers for
exact equality, when rounding during their computation means they’re almost never exactly
identical even when they should represent the same value. Recognizing these patterns is useful,
but recognizing them in your own code once it’s already broken is the real skill, and that’s
where a systematic technique comes in.




                                                5
````

## Page 006 — Narrowing Down Bugs with Print Statements

````text
Slide 6: Narrowing Down Bugs with Print Statements




Script

The simplest debugging technique doesn’t need any special tool at all: print the value of a
variable at a key point in your program and see whether it matches what you expected. That
sounds almost too basic to mention, but used well, it’s remarkably effective, especially for
beginners. If you don’t know which part of your program is misbehaving, insert a print statement
somewhere in the middle and see whether the output up to that point already looks wrong. If it
does, the bug lives before that point; if it doesn’t, the bug lives after it. Repeat that a few times
and you’re effectively bisecting your code, cutting the search space in half with each check, the
same way you’d look up a word in a paper dictionary rather than reading from the first page.
You can make this more rigorous with an “assert” statement, which checks that an assumption
actually holds at a given point and stops the program immediately if it doesn’t, rather than
letting a violated assumption quietly propagate further into the code where it becomes much
harder to trace back. Throughout this process, keep comparing the actual output against what
you expected line by line rather than trusting a vague impression that something looks off. And
once you’ve found and fixed the bug, remember to remove the print statements you added; they
were a diagnostic tool, not part of the finished program, of course. There’s a related, slightly
unusual technique worth knowing here too: rubber-duck debugging, where you explain your
code line by line to someone, or even to an actual rubber duck on your desk, and very often
spot the mistake yourself in the middle of the explanation. Print statements help you see what’s
happening. But sometimes the real obstacle isn’t finding where to look; it’s that the failing case
itself is too complicated to reason about at all.




                                                 6
````

## Page 007 — Simplifying Test Cases Systematically

````text
Slide 7: Simplifying Test Cases Systematically




Script

Before you can fix a bug, you need to be able to trigger it on demand. That might sound
obvious, but a bug that only appears occasionally, or only with a particular, hard-to-remember
set of inputs, is very difficult to work on, because you can’t tell whether a change actually fixed
anything if you can’t reliably reproduce the failure. So the first step is always the same: find
a sequence of steps or an input that reproduces the bug reliably, every single time. Once you
have that, start reducing. Take your failing input and try to make it smaller while the bug still
occurs; a huge input file might reduce down to just a handful of characters that still trigger
the exact same failure. Do the same with your code: remove functions, branches, and entire
sections that aren’t actually involved in producing the bug, one step at a time, checking after
each removal that the failure is still there. What you’re aiming for is the smallest possible failing
case, a program so small that the cause becomes almost obvious just by reading it. As you go,
change only one thing at a time between attempts, because if you change several things at once
and the bug disappears, you won’t know which change actually mattered. And write down the
steps that trigger the bug as you discover them, both so you don’t lose your own progress and
so you can verify your fix actually works afterward. Let’s put this into practice with a concrete
example.




                                                 7
````

## Page 008 — Exercise 01: Analyze Faulty Code

### Exercise SOP19-E01 (source slide)

````text
Slide 8: Exercise 01: Analyze Faulty Code




Script

Look at the function “average” next to me. It takes an array of integers and a count, and
it’s supposed to return the arithmetic mean of the values. Somewhere in this short function,
though, there’s a bug, and your job for this exercise is to find it using exactly the kind of careful
reading we’ve just been talking about. Read through the code line by line rather than skimming
it, and pay particular attention to the loop. Once you’ve spotted something suspicious, don’t
stop there. Decide which of our three categories it belongs to: is this a syntax error, a runtime
error, or a logic error? Then describe explicitly what the function is supposed to do versus
what it actually does when this bug is present, and propose the smallest possible fix, a single,
minimal change rather than a rewrite. When you are finished, please click the button, and I
will show you one possible solution.




                                                 8
````

## Page 009 — Solution 01: Analyze Faulty Code

````text
Slide 9: Solution 01: Analyze Faulty Code




Script

So, let’s switch to the starting branch of this exercise and have a look at the source code.
So, there’s a to-do here. But actually, we don’t have to implement anything here in line 16.
The problem is somewhere else and we can demonstrate this by compiling and executing this
program. So, we compile and we start this and you see the average here is a negative number
which indicates that we have an overflow problem and probably you have already guessed it,
the loop is too long. We iterate here also for i equals count and then we add to some value that
is not part of this array here. And now we change the branch. We go to the solution branch and
we have a look at the source code. And here you can see the result, so we only iterate from zero
till count but not including count and then the output is correct and we compile this program
and execute it and that’s the expected value. So this is one of the, let’s say, easiest failures that
you can make. You make the iteration too long.




                                                 9
````

## Page 010 — Introduction to the GDB Debugger

````text
Slide 10: Introduction to the GDB Debugger




Script

Print statements and careful reading will get you a long way, but at some point you’ll run into
a bug where it should be better to watch your program’s state at the exact moment something
goes wrong, instead of guessing where to put the next print statement. That’s what a debugger
gives you. GDB is an interactive debugger for C programs, and it lets you pause a running
program at any point, look at the value of every variable exactly as it stands at that instant,
and then continue on, one step at a time if you like. Be aware, GDB is the most purist way to
debug, because it works on the command line. If you use a real IDE, like C-Lion from JetBrains,
there is a very nice graphical debugger like in IntelliJ that you most probably have used for
the “Programming 2” module to debug Kotlin code. Before GDB can do any of that, though,
your program needs to be compiled with debug symbols, using the “-g” flag. Without that flag,
GDB can still technically run your program, but it won’t be able to connect what’s happening
in memory back to the actual lines of your source code, which makes the whole exercise far
less useful. Once you’ve compiled correctly, you start your program under GDB’s control rather
than running it directly, which lets GDB take charge from the very first instruction. From
there, you can run the program, pause it, and examine the exact source code around wherever
it currently is, right inside the same terminal window. This is a different way of working than
anything we’ve looked at so far today, and the natural next question is: where, exactly, do you
want the program to stop?




                                              10
````

## Page 011 — Setting Breakpoints

````text
Slide 11: Setting Breakpoints




Script

That question has a direct answer: you tell GDB exactly where to pause, by setting a breakpoint.
You can set one at a specific line number, if you already suspect roughly where the problem lies,
or on the entry to a particular function, if you want to catch every single call to it, wherever in
your program it happens to be invoked. Once your program hits a breakpoint, it doesn’t crash,
and it doesn’t finish; it simply pauses, handing control back to you at exactly that point. From
a paused breakpoint, you have a choice about how to keep moving. Stepping into a function
call takes you inside that function, line by line, letting you watch its own internal behavior.
Stepping over a function call, by contrast, runs that entire function to completion in one step
and pauses again right after it returns, which is exactly what you want when you already trust
that function and don’t need to watch its internals. And once you’ve seen what you need to at
a given breakpoint, you can simply continue execution, which runs the program forward until
it either finishes or hits the next breakpoint. Breakpoints you no longer need can be removed
or just temporarily disabled, so they don’t keep interrupting you as you keep working. Let’s
watch this in action.




                                                11
````

## Page 012 — Video: Show breakpoints

````text
Slide 12: Video: Show breakpoints




Script

In this video I would like to demonstrate how to set breakpoints and how to run the program
actually. We start with the version that is the correct implementation of the last exercise and
to view the line numbers we opened the file in the editor and to have better line numbering
we switch to absolute numbers so that we can here really see the correct number. We open a
terminal and we first compile the program and then we start GDB with the program name.
So and the first command so this is the interface this is very low level like the Linux console
itself you work with commands you don’t need a mouse you have no graphical user interface
here so this is actually what you get from this terminal debugging tool but actually it’s enough
that you you don’t need more so to speak. The first command would be run but if we run the
program without breakpoints the program is just executed and then terminated at the end or
it crashes so we want to set a breakpoint and breakpoint we can be set by giving a name so for
example we can say I want to have a breakpoint at the average function and we also can set a
breakpoint let’s switch to the source code here we want to have a breakpoint in line 17 so we
say breakpoint exercises so the file name colon line 17 so and then we have now in line 8 which
is the first statement in the function average and in line 17 we have breakpoints and now we
can start the program run and now the debugger tells us in what line we are at the moment so
line 17 was exactly this line that was the first breakpoint then we can say next now we would
jump into the function and there’s another breakpoint with the first statement initialization
of the sum and we go in the loop now we execute the first statement in the loop and we can
continue now to step-by-step iterating all the arrow arrow array positions but we can also say
until which iterates the whole loop and waits for the next statement after the loop this is the
return statement and we can go next to the jumping out the function and now we are back
in our main function and this is line 19 now the return statement to execute everything and




                                              12
````

## Page 013 — Continuation / untitled

````text
we say now for example run I don’t know sorry next then we have now reached the end of the
program




                                           13
````

## Page 014 — Inspecting Variables

````text
Slide 13: Inspecting Variables




Script

Now that you’ve seen breakpoints pause your program at exactly the right moment, the real
payoff is what you can do once it’s actually stopped there: look inside it. Printing the value of a
variable on demand inside GDB works the same way it did with our print-statement technique,
except now you don’t have to guess in advance which values you’ll need; you can just ask,
right there, once the program has already paused. If you want to track a particular variable
continuously rather than checking it once, you can watch it, and GDB will pause your program
automatically the moment that variable’s value actually changes, wherever in the code that
happens. This goes well beyond simple variables, too. You can inspect the full contents of an
array or a struct at once, rather than checking each element by hand, and if you need to go
even deeper, you can examine raw memory addresses directly, seeing exactly what bytes are
sitting at a given location. GDB also lets you view the current call stack, which is the chain
of function calls beginning with “main” that led to wherever your program currently is, and
navigate between those stack frames to check the state of a variable as it existed in a calling
function, not just the one you’re currently paused inside. Between breakpoints and this level
of insight into memory, you now have real visibility into what a running program is actually
doing.




                                                14
````

## Page 015 — Video: Inspecting memory

````text
Slide 14: Video: Inspecting memory




Script

I would like to demonstrate how to inspect the contents of variables and memory in general.
So we open the file again and we open a terminal, we start the debugger, and we first set some
breakpoints again. So breakpoint in average, and now we set the breakpoint in line 18. And we
start the program, so run. And now the breakpoint, we are in line 18 at the breakpoint, we can
call print values, so you can ask for the current contents of variables. The debugger notices that
this is an array. We can also call the current value of count, which is 4, which is correct. We
can even print the contents of the array, and this can be done by using the x statement. By this
we just immediately inspect the memory. I have the contents of values, so you know values was
declared as an array, which is internally then a pointer. The pointer contains the address, as
you can see now in this print statement here, the address on the left side and the contents of the
memory to which this address points to on the right side. We can also ask for many values at
once, so we want to have the first four values of this memory area, and here again the debugger
recognizes the data type correctly and gives us the contents of the first four integer values. We
can also ask for the first five values, and here you can see the problem that was shown in the
first exercise. The fifth possession of this array has an invalid or not initialized number here.
We can even change the contents by calling set, and we have to dereference that values equals
3, and then we can call the contents, and you can see the value is changed. We step now into
the function, and we can call print for the variable sum, which is 0. We now jump into the
loop, now we have increased sum, not yet, now we have increased sum by the first element of
the array, which is 3, and we can now, if you do not want to have this print statement all over
again, you can say watch sum, and now you can just step from instruction to instruction, and
whenever the value of sum changes, the debugger tells you the old value and the new value,
and by this you can generate over all the elements, and now we jump out of the function, and
here we have the result.



                                               15
````

## Page 016 — Pitfalls When Debugging Programs

````text
Slide 15: Pitfalls When Debugging Programs




Script

Having a powerful tool like GDB doesn’t automatically protect you from bad debugging habits,
and some of the most persistent bugs survive precisely because of how they were approached,
not because they were technically hard to find. A very common trap is fixing the symptom
instead of the root cause: you notice a crash, you add a check that happens to make the crash
go away, and you move on, without ever understanding why the program was in that state
in the first place. That kind of fix tends to resurface later, often in a more confusing form.
Another trap is changing several things at once while trying to fix a bug, which is really the
same mistake we already ran into while simplifying test cases: if multiple things change together
and the bug disappears, you don’t actually know which change fixed it, or whether you’ve just
made it harder to trigger rather than fixed it. Closely related is trusting an assumption without
actually verifying it inside the debugger, printing what you think a variable’s value is, rather
than checking it directly. And don’t let your guard down either: ignoring compiler warnings
while you’re hunting a bug, skipping the step of reliably reproducing the bug before you start
changing code, or skipping a regression check once you believe you’ve fixed something, can each
quietly undo the careful process we’ve spent this whole unit building. Now it’s your turn to
bring breakpoints and variable inspection together on a real bug.




                                               16
````

## Page 017 — Exercise 02: Find a Bug with GDB

### Exercise SOP19-E02 (source slide)

````text
Slide 16: Exercise 02: Find a Bug with GDB




Script

For this exercise, you’ll use GDB itself to track down a bug, rather than reading the code by
eye the way you did in the first exercise. Start by compiling the given program in the repository
with debug symbols, then start it running inside GDB rather than launching it directly. From
there, set a breakpoint somewhere near where you suspect the fault actually happens, and step
through the surrounding code line by line rather than letting the program run straight through.
As you step, keep inspecting the values of the relevant variables at each point, exactly the way
we just practiced, and pay attention to the moment where a value first stops matching what
you’d expect. That moment is where the actual root cause lives, which may well be a line or two
earlier than where the program eventually crashes or produces the wrong result. Once you’ve
found it, be ready to describe the root cause in your own words, not just point at the line.
When you are finished, please click the button, and I will show you one possible solution.




                                               17
````

## Page 018 — Solution 02: Find a Bug with GDB

````text
Slide 17: Solution 02: Find a Bug with GDB




Script

So the root problem of this source code in the second exercise was the same as in the other
exercise in the first one. Simple index problem. Let’s have a look at the source code. So to
explain you this here, this structure. The reason for this is we just want to be sure that after
the array of numbers, here this one, we have an invalid value. So this number 7 is just to
demonstrate that there is an invalid value in the memory. Normally this should be zero. But
because we iterate here, one iteration too much, we will reach this position where the 7 is. So
the expected result would have been 150 as the sum of these five values here. But if we add
the 7, it’s 157. So let’s see if this is correct. We have a make file here and we call exercise 2. So
this is the wrong result 157. How can we find this problem? We start the debugger. We set a
breakpoint in exercise 2, line number 15. We are again with relative numbers here. Number 8.
And we run the program. And now we watch the total. And we just iterate over the elements.
So here we add the first element 10, then 30 as the new value. 60, everything okay. 100, good.
150, good. And now here we can see this is the invalid value. This should point us to the correct
position in the source code where we have to fix the error. And this was all that I wanted to
demonstrate here. This is the way how you find the position in your source code where the
error is. You iterate step by step. You compare expected values of variables with the actual
ones and then you find hopefully the error.




                                                 18
````

## Page 019 — Summary

````text
Slide 18: Summary




Script

That’s it for today. We started by sorting bugs into three categories, syntax, runtime, and logic
errors, and that distinction turned out to matter throughout everything that followed, because
each kind points you toward a different way of looking for it. From there we spent time learning
to actually read what the compiler is telling you rather than skimming past its warnings, and
we went through a set of mistakes, from uninitialized variables to off-by-one errors to comparing
floating-point numbers for equality, that account for a striking share of the bugs beginners run
into. We then built up a strategy for dealing with the ones the compiler can’t catch: narrowing
a problem down with well-placed print statements, and reducing a failing case to its smallest
possible form so the cause becomes visible. Finally, we brought in GDB, and you saw how
setting breakpoints, stepping through code, and inspecting variables and memory directly lets
you watch a program’s actual behavior instead of only guessing at it from the outside. Taken
together, this is the toolkit you’ll reach for every single time a program you write doesn’t do
what you expected, and by now you’ve seen that reliable reproduction, careful reading, and a
systematic narrowing-down process matter at least as much as any particular tool. In the next
unit, we turn to performance, and you’ll learn how to look at a program that works correctly
and ask a rather different question: how efficiently is it actually doing what it does.




                                               19
````

## Page 020 — Literature

````text
Slide 19: Literature




Script

[Musik]




                       20
````
