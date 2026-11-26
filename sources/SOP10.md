---
source_id: SOP10
original_file: 10-using_script_2026-10-15.pdf
source_type: mixed
source_subtype: lecture_transcript_with_exercises
language: en
page_count: 47
source_sha256: 0b0dce4a1b91cddf328108ac03efd765618ee12752000c7a628da17707acbb3d
verification: partial
verification_note: "All pages captured from indexed PDF text; embedded slide images and their code, figures, tables, and formulas not fully represented or verified."
---

# Using Git on the Command Line

**Course:** System-oriented Programming — Prof. Dr. Peter Braun, THWS.

**Source fidelity:** This is the original-language text extracted page by page, not a summary. Embedded slide pictures, including code and diagrams, have **not** been transferred into this text representation. Consult the PDF original for these elements. Verification **partial**.

## Page 001 — Script

````text
           System-oriented Programming
                 Using Git on the Command Line
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

Welcome to this unit, in which we take on one of the most important tools in a developer’s daily
life: Git. If you already use Git through your IDE, clicking buttons for “commit” and “push”,
this unit pulls back the curtain. We start with the fundamentals: why version control exists
at all, how a basic Git workflow looks on the command line, and how branches let you work
on several ideas at once without getting in your own way. From there, we go somewhere most
Git tutorials never take you: inside the “.git” folder itself. You will see that Git is not a pile of
magic commands, but a small, understandable object database, and once you understand what
a commit, a tree, and a blob actually are, almost every Git command starts to make sense on
its own. We then look at Git in its natural habitat, the Unix command line: working over SSH,
and automating tasks with hooks. And because everyone eventually makes a mistake with Git,
we close with recovering from exactly that: undoing changes, resetting your repository, and
using the reflog to bring back a commit you thought was gone forever. Let’s get started.




                                                 2
````

## Page 003 — Git Fundamentals

````text
Slide 3: Git Fundamentals




Script

[Musik]




                            3
````

## Page 004 — Why Version Control?

````text
Slide 4: Why Version Control?




Script

Let’s begin with the most basic question: why do we need version control at all? Imagine you
are writing a longer document, or a piece of software, entirely by yourself. At some point, you
will want to go back to an earlier version, because the new idea did not work out after all.
Without any tool, that means keeping copies around, with file names like “final”, “final two”,
and, inevitably, “final really final”. Version control replaces that mess with a system that tracks
every change to a project over time, and lets you recover any earlier version whenever you need
it. But version control is not only about your own past. It is also about accountability: being
able to answer the question “who changed this line, and why”, months after the fact. And it
gives you room to experiment. You can try out a risky idea, knowing that you can always go
back if it fails, without ever touching the version that already works. Once you are not the
only person on the project, a second problem appears: several people editing the same files
at the same time. Version control is what lets their work be merged together, instead of one
person’s changes silently overwriting another’s. That combination, a safety net for yourself and
a coordination mechanism for a team, is exactly what Git provides. So how does it actually do
that, and where does Git sit alongside tools you have already heard of, like GitHub? That’s
next.




                                                4
````

## Page 005 — Git, GitHub, and GitLab

````text
Slide 5: Git, GitHub, and GitLab




Script

Now let’s clear up something that trips up almost every beginner: Git, GitHub, and GitLab are
not the same thing. Git is the version control system itself. It is a program that runs entirely on
your own machine. You can create a Git repository, commit changes, look at history, and create
branches without ever connecting to the internet or having any kind of account. Git does not
need a server to function. GitHub and GitLab, on the other hand, are hosting platforms. They
store a copy of your Git repository on a server, so that you and your teammates can share it.
But they do much more than that: issues for tracking bugs and tasks, pull or merge requests for
reviewing code before it is combined, and automation pipelines that run tests or deployments
whenever you push. None of that is part of Git itself; it is functionality the platform builds
on top. And there is more than one such platform. GitHub and GitLab are the best known,
but other providers and self-hosted alternatives exist too, and underneath all of them runs the
exact same Git you are learning in this unit. Learn Git once, and you can work with any of
these platforms. Keep that distinction in mind, because from here on, we focus entirely on Git
itself, the part that works identically no matter which platform, if any, you connect it to.




                                                5
````

## Page 006 — Local and Remote Repositories

````text
Slide 6: Local and Remote Repositories




Script

With that distinction in mind, let’s look at the two kinds of repositories you will work with.
A local repository lives on your own machine. It contains the complete history of the project,
every commit that was ever made, not just the current state of the files. A remote repository is,
structurally, the exact same thing, a full Git repository, just hosted somewhere else, typically
on a server like GitHub or GitLab. The connection between the two is made with “git clone”.
When you clone a remote repository, Git does not just copy the current files; it copies the entire
history behind them. The moment cloning finishes, you have a complete, independent repository
on your machine. By convention, that original remote you cloned from is called “origin”, though
that is just a name, not a rule enforced by Git. This has a very practical consequence: because
your local repository is complete, you can work entirely offline. You can commit, branch, look
at history, all without a network connection. Syncing with the remote, catching up on other
people’s work or sharing your own, is a separate, deliberate step that you take when you choose
to, not something Git does automatically in the background. We will get to exactly how that
syncing works a little later. First, we need to understand what actually happens inside your
own working copy when you make a change.




                                                6
````

## Page 007 — Working Tree, Staging Area, and Repository

````text
Slide 7: Working Tree, Staging Area, and Repository




Script

Every file you work with in Git passes through three distinct areas, and understanding them is
probably the single most useful mental model for the rest of this unit. The first is the working
tree: simply the files as you see them in your editor or file browser right now, the ones you
can open and edit like any other file. The second is the staging area, also called the index.
This is where you place changes that you have decided belong in the next commit. Note the
word “decided”: staging is a deliberate step. Editing a file does not automatically prepare it for
commit. The third is the repository itself, the permanent history stored inside the “.git” folder.
Once a change is committed, it lives here, safely recorded, as a snapshot you can always return
to. Why three separate stages, and not just edit, then save permanently? Because it gives you
precise control. You might have changed five files, but only want to commit two of them, or
even only part of one file. The staging area is exactly what makes that possible: nothing gets
committed by accident, only what you have explicitly staged. Keep this picture, working tree,
staging area, repository, in mind, because the next slide walks through exactly how a change
moves through all three.




                                                7
````

## Page 008 — A Basic Git Workflow

````text
Slide 8: A Basic Git Workflow




Script

Let’s put the three areas from the last slide into motion. The basic Git workflow is a short,
repeating loop. First, you edit files in the working tree, exactly as you always have. Second,
you stage exactly the changes you want to keep for the next commit, using the area we just
discussed. Third, you commit the staged changes, together with a message describing what you
did and why. At this point, the change exists safely in your local repository, but if you are
working with others, it is not yet visible to them. That happens when you push your commits
to a remote repository, making them available to your team and to any backup that repository
provides. And in the other direction, you pull to bring in commits that other people have made,
so your local repository stays up to date with everyone else’s work. Edit, stage, commit, push,
pull; that loop is the heartbeat of working with Git day to day, and everything else in this unit
builds on top of it. The one thing we have quietly skipped over so far is how you actually know
what you have changed, before you stage or commit anything. That is exactly what we look at
next.




                                               8
````

## Page 009 — Inspecting Changes with Status and Diff

````text
Slide 9: Inspecting Changes with Status and Diff




Script

Before you stage or commit anything, you want to know exactly what has changed, and “git
status” is where you start. It gives you an overview of your working tree: which files were
modified, which are already staged, and which are completely new and untracked by Git. It
is the command you will run more often than any other. Status tells you which files changed,
but not what changed inside them, and that is where “git diff” comes in. Run on its own, it
shows you the exact, line-by-line differences that are not yet staged, everything added shown
one way, everything removed shown the other way. Once you have staged something with “git
add”, plain “git diff” will no longer show it; for that, you use “git diff dash-dash staged”, which
shows exactly what is currently sitting in the staging area, ready for the next commit. Why does
this matter so much? Because reviewing your own changes before committing catches mistakes
early, a stray debug line, a file you did not mean to touch, before it becomes a permanent
part of your history. Once you are confident in what you are about to commit, staging and
committing it is the natural next step, and that is exactly where we go now.




                                                9
````

## Page 010 — Staging and Committing Changes

````text
Slide 10: Staging and Committing Changes




Script

Now that you know how to inspect your changes, let’s actually record them. Staging a specific
file is done with “git add” followed by the file name; if you want to stage everything that changed
in one go, “git add dot” does exactly that. Either way, the result is the same: the changes now sit
in the staging area, ready for the next commit. Committing them permanently is done with “git
commit dash m”, followed by a message in quotes. That message matters more than beginners
usually expect. A good commit message explains why a change was made, not merely what
changed, because the “what” is already visible in the diff itself; the reasoning behind it is not.
There is also a question of size: should you make one enormous commit at the end of the day,
or many small, focused ones along the way? Favor the latter. Small, focused commits are easier
to review, easier to understand months later, and, as we will see near the end of this unit, much
easier to undo individually if something turns out to be wrong. Once you have committed a
series of changes this way, you naturally build up a history, and that history is exactly what
we look at next.




                                                10
````

## Page 011 — Inspecting the Commit History

````text
Slide 11: Inspecting the Commit History




Script

Every commit you make becomes part of a history that you can walk through at any time, and
“git log” is how you do it. Run on its own, it lists every commit, newest first, together with
its author, date, and commit message; everything you need to reconstruct what happened to
a project and when. That full output can be long, so for a quick overview, “git log dash-dash
oneline” compresses each commit down to a single line: just enough to scan a long history
quickly. And if one particular commit catches your eye, “git show” followed by that commit
gives you its full details, including the actual changes it introduced. Notice that every commit
in this history is identified not by a number like one, two, three, but by a hash: a long string
that looks like a random sequence of letters and digits. That is not an accident, and it is not
arbitrary either; commit hashes are stable, unique identifiers, and where they actually come
from is one of the central ideas we return to once we open up the “.git” folder later in this
unit. For now, keep in mind that a hash is simply how Git refers to one exact, specific commit,
unambiguously. Next, let’s extend this picture beyond your own machine, to repositories other
people are working on too.




                                              11
````

## Page 012 — Working with Remote Repositories

````text
Slide 12: Working with Remote Repositories




Script

So far, everything we have discussed happens entirely within your local repository. Let’s bring
remotes properly into the picture. “git remote dash v” lists every remote your repository current-
ly knows about, together with the URLs behind them. To add another one, “git remote add”
followed by a name and a URL connects your repository to it. We already mentioned “origin”
as the conventional name for the remote you cloned from, but it really is just a convention, a
name Git happens to use by default, not something enforced by the tool. And a repository is
not limited to exactly one remote: it is entirely possible, and sometimes useful, to have several,
for example, your own fork and the original project you forked from. Behind the scenes, Git
keeps track of each remote’s branches through what are called remote-tracking branches, a local
mirror of what the remote’s branches looked like the last time you communicated with it. That
distinction, your local view of a remote branch versus its actual current state, becomes import-
ant the moment we talk about actually exchanging commits, which is exactly what fetching,
pulling, and pushing are about.




                                               12
````

## Page 013 — Fetch, Pull, and Push

````text
Slide 13: Fetch, Pull, and Push




Script

Now let’s look at the three commands that actually move commits between your local repository
and a remote one. “git fetch” downloads any new commits from the remote, but it deliberately
does not merge them into your current work; it simply updates your local knowledge of where
the remote stands. “git pull” does more: it fetches, and then immediately merges those changes
into your current branch, in a single step. In the other direction, “git push” uploads your local
commits to the remote, making them visible to everyone else working with that repository. Why
would you ever fetch without pulling? Because fetching first lets you see what changed on the
remote before you decide to merge it into your own work, which is often the safer habit once a
project has several contributors. And as a general rule: pull before you push. If the remote has
moved on since you last synced, pulling first and dealing with any differences avoids most of
the conflicts that would otherwise appear when you try to push. Speaking of diverging work:
so far, everything we have done happened on a single line of history. Branches are how Git lets
you deliberately create more than one, and that is where we turn next.




                                               13
````

## Page 014 — Creating and Switching Branches

````text
Slide 14: Creating and Switching Branches




Script

A branch sounds like a complicated feature, but the underlying idea is refreshingly simple: a
branch is nothing more than a movable pointer to one specific commit. Nothing is duplicated,
and no files are copied, when you create one. “git branch” followed by a name creates a new
branch, but leaves you exactly where you were, still on your current branch. To actually move
onto a branch, you use “git switch” followed by its name. And because creating a branch and
immediately switching to it is such a common pattern, there is a shortcut for that too: “git
switch dash c” followed by a name does both in a single step. Why bother with branches at all?
Because they make isolated, parallel work possible. You can start an experimental feature on
its own branch, without touching the code that already works on your main branch, and switch
back and forth between them freely. Several people, or even just yourself working on several
ideas, can each have their own branch, moving forward independently. Sooner or later, though,
that separate work needs to come back together, and that process, merging, is exactly what we
look at next.




                                             14
````

## Page 015 — Merging Branches

````text
Slide 15: Merging Branches




Script

Once a branch has served its purpose, you typically want its changes back on your main line of
work, and that is what “git merge” does: run while on the branch you want to update, followed
by the name of the branch to bring in, it integrates the other branch’s commits. There are two
rather different outcomes, depending on the situation. If your current branch has not moved at
all since the other branch split off from it, Git can simply move your branch pointer forward
to catch up; this is called a fast-forward merge, and it is the simplest possible case. But if
both branches have moved independently since they diverged, Git instead creates a new merge
commit, one with two parents, that represents the point where the two lines of development
come back together. Notice that the branch you are currently on when you run the merge is
always the target; the other branch’s changes are brought into it, not the other way around.
Merging is, in the end, exactly what makes branches useful rather than just a way of losing
track of your work: two independent lines of development, combined back into one. Of course,
that combination does not always go smoothly, and what happens when it does not is exactly
our next topic.




                                             15
````

## Page 016 — Resolving Merge Conflicts

````text
Slide 16: Resolving Merge Conflicts




Script

Sometimes, a merge cannot be completed automatically, and that happens for one specific
reason: both sides changed the same lines of the same file in different ways. Git has no way of
guessing which version you actually want, so it stops and asks you to decide. What that looks
like in practice is that Git marks the conflicting section directly inside the affected file, using
a set of markers that show “ours”, your current branch’s version, side by side with “theirs”, the
version coming from the branch being merged in. Nothing is hidden or automatically discarded;
both versions are right there in front of you, in the file itself. Resolving the conflict means editing
that file by hand: deciding which version to keep, combining both, or writing something new
entirely, and then removing the conflict markers once you are satisfied. After that, you stage the
resolved file exactly as you would stage any other change, and a normal “git commit” finishes
the merge, recording your resolution as part of the history. Conflicts can feel intimidating the
first time you see them, but they are really just Git being honest about a situation it cannot
resolve on its own. Now it is your turn to put this entire workflow, from a first commit through
a branch and a merge, into practice yourself.




                                                  16
````

## Page 017 — Exercise: A Complete Git Workflow

### Exercise SOP10-E01 (source slide)

````text
Slide 17: Exercise: A Complete Git Workflow




Script

In this exercise, you carry out a complete Git workflow from scratch, using nothing but the
commands from this first part of the unit. Start by creating a brand new local repository. Add a
single file to it, and take a moment to inspect its status before doing anything else. Then stage
that file and commit it, with a message that actually describes what you did. Next, create a
new branch and switch onto it. Change the file again on that branch, and commit that change
separately from the first one. Finally, switch back to your main branch, merge the branch you
just created into it, and take a look at the resulting history to confirm that both commits are
there. The video stops now to give you time for this exercise. When you are done, press the
button, and I will show you a possible solution.




                                               17
````

## Page 018 — Solution: A Complete Git Workflow

````text
Slide 18: Solution: A Complete Git Workflow




Script

The goal of this exercise was to practice a complete workflow using the basic Git commands. So
we start by initializing a Git repository. We therefore create a temporary directory, just a safe
space where we work in. Then we create a repository. Normally when you create a repository,
you do this in the directory where you actually work in. So where you already have some files.
And then git init is just the command that you need. You can also pass a name of a directory
here. And then git would create this directory first, workflow demo, jump into it, and then
create the repository in there. And there’s another option, dash B, that we use to define the
name of the initial branch to work on. So now we have initialized an empty Git repository in
temp workflow demo.git. We are still in temp, so we now cd into workflow demo. And there
we can see this hidden Git repository. It’s hidden because if you just call ls, you don’t see it.
The next step is we create a file, and therefore we just write something into a demo file. So this
demo text file just contains this first line. We can call git status here, and it tells us demo.txt
is not yet tracked. So we add this now. Now we have git as a new file in the index. And then
we can commit. And that’s it. Now the status is clear, working tree is clean, so there’s nothing
modified, so to speak, in the current working tree. The next step is that we create and switch
to a new branch. We use the switch command, which is normally used to switch to another
branch. But we use it using the C flag to create a feature branch. So we are now in this feature
branch. You can also check this. So this branch dash l gives you the list of all branches that we
have. And the one that is marked with a star or the asterisk sign is the one you are currently
in. So we have our file here, and this contains the first line as expected. Now we add another
line here to the end of this document. We check the status, and then git tells us this file was
modified. So now we do a new thing. We combine add and commit. So we say commit a for
add the files, m for the message. And then we have in one step added this file to the index
and then committed this. So we are still in our branch feature. So now we switch back to the



                                                18
````

## Page 019 — Continuation / untitled

````text
main branch and we check the contents of the file, first line. And the last step is now to merge
the content. So we call merge and we do this without fast forward, which would normally be
the case to use here because we want to have a merge commit here. And this is our commit
message. And the last parameter is the name of the branch. And now we have a feature, a
merge commit message here. That was the commit message from the feature branch you can
see here. This was our initial commit. So now the contents of the file, as expected, are the two
lines. And what we have not shown in this first demo, which was not part of the first demo, is
to use push and pull. And this comes then next.




                                              19
````

## Page 020 — Git Under the Hood

````text
Slide 19: Git Under the Hood




Script

[Musik]




                          20
````

## Page 021 — What Is Inside the .git Directory?

````text
Slide 20: What Is Inside the .git Directory?




Script

Up to now, we have used Git entirely through its commands, without asking what actually
happens underneath them. That changes now. Every Git repository has, at its root, one hidden
folder named “.git”, and everything Git does happens by reading or writing something inside it.
Inside, you will find a handful of familiar names: a “config” file with the repository’s settings,
a “HEAD” file we will get back to shortly, an “objects” folder, and a “refs” folder. Every single
Git command you have used so far, status, add, commit, log, branch, ultimately comes down
to reading or writing something in one of these places. This has a rather blunt consequence:
delete the “.git” folder, and you delete the entire history of the project, commits, branches,
everything, while the files in your working tree, the ones you can currently see and edit, remain
completely untouched. That is a useful thing to remember precisely because it sounds surprising:
the working tree is not special to Git at all; it is the “.git” folder that actually matters. With
that in mind, let’s open it up and look at what is actually inside.




                                               21
````

## Page 022 — Git as an Object Database

````text
Slide 21: Git as an Object Database




Script

Here is the idea that everything else in this part of the unit builds on: Git does not store a
list of differences between versions, the way you might expect from a tool whose job is to track
changes. Instead, it stores content directly. Every version of every file you have ever committed
exists, in full, as one object inside the “.git” folder. These objects are found by their content, not
by a filename or a path; we will see exactly what that means, and why it matters, in a moment.
Strip away all the familiar commands, and underneath, Git is really just a minimal key-value
store: content goes in, and a way to look that same content back up comes out. This is not a
minor implementation detail. Once you accept that Git is fundamentally an object database,
almost every command you have already learned starts to make a lot more sense, and several
you have not learned yet will feel far less mysterious once you meet them. So let’s meet the
objects themselves, starting with the three kinds that make up nearly everything Git stores.




                                                 22
````

## Page 023 — Git Objects: Blobs, Trees, and Commits

````text
Slide 22: Git Objects: Blobs, Trees, and Commits




Script

Git works with three main kinds of objects, and once you know them, you can mentally re-
construct almost anything Git does. The first is the blob: simply the raw content of exactly
one file, nothing more, not even its name. The second is the tree. A tree is Git’s representation
of a directory: a listing of the blobs and other trees it contains, along with the name and the
permissions of each entry. A project with subdirectories is therefore built from several nested
tree objects, one for each directory level. The third is the commit. A commit is a snapshot: it
points to exactly one tree, the state of the entire project at that moment, and, critically, it also
points back to its parent commit, or commits, in the case of a merge. It is that chain of parent
pointers, commit after commit after commit, that forms the whole history you saw earlier with
“git log”. Three simple kinds of objects, blobs, trees, and commits, referencing each other, and
together, they are the entire history of your project. But how does Git actually find any of
them again? That comes down to one elegant idea: the hash.




                                                23
````

## Page 024 — Content-Addressed Storage

````text
Slide 23: Content-Addressed Storage




Script

Let’s look at how Git actually finds an object once it has been stored, because this is the elegant
idea the whole object database rests on. Every object, whether a blob, a tree, or a commit,
is run through a hash function, and the resulting hash becomes that object’s name and its
address inside “.git/objects”. This has a very specific consequence: identical content always
produces the identical hash, no matter when or where it was committed. And the reverse is
just as strict: change even a single byte inside a file, and the resulting hash changes completely
and unpredictably. There is no such thing as almost the same hash. One elegant side effect of
this follows almost for free: if the exact same content appears twice, in different files, or in the
same file across several commits, it is stored only once. Git does not know or care that it is
“the same file committed again”; it only sees identical content, producing an identical hash, and
simply reuses what is already there. Traditionally, Git computes this hash using SHA-1. With
the theory in place, let’s actually look at some real objects on the command line.




                                                24
````

## Page 025 — Inspecting Git Objects

````text
Slide 24: Inspecting Git Objects




Script

Everything we have just described is not some hidden internal mechanism you have to take on
faith; you can inspect it directly, right now, on the command line. “git cat-file dash p”, followed
by a hash, prints that object’s content exactly as it is stored, whether it turns out to be a
blob, a tree, or a commit. “git cat-file dash t”, followed by the same hash, tells you which of
those three it actually is. Going the other direction, “git hash-object” followed by a file name
computes the hash that file’s content would get, without even creating a commit; it is a direct
window into the hashing mechanism itself. And “git rev-parse HEAD” turns a familiar reference
like “HEAD” into the actual raw hash it currently points to, the same kind of hash we have been
discussing this whole time. None of this requires special tools, because, as we said a moment
ago, objects are ordinary files sitting under “.git/objects”, one file per object, named after its
own hash. Try these commands on a repository of your own; seeing a commit’s raw content on
your screen for the first time tends to make the whole object model click. Speaking of “HEAD”:
let’s look more closely at what that, and references in general, actually are.




                                                25
````

## Page 026 — HEAD and References

````text
Slide 25: HEAD and References




Script

We have used the word “HEAD” several times already without properly defining it, so let’s fix
that now. A reference, in Git, is simply a human-readable name that stands in for a commit
hash, so that you never have to type or remember a long hash by hand. “HEAD” is one specific,
special reference: it always points to whatever commit you currently have checked out. Branches,
which we met earlier, are themselves just references, but ones with an important property: they
move forward automatically every time you commit while that branch is checked out. Tags are
references too, but with the opposite intention: they are meant to mark one specific commit
and stay fixed there forever, typically used for released versions. There is also a less common
situation worth knowing about: a detached “HEAD”, where “HEAD” points directly at a specific
commit instead of at a branch. You are still looking at a perfectly valid commit, just without
a branch name moving along with you, something worth remembering before it surprises you
one day. With references and “HEAD” in place, we are ready to answer a question that sounds
simple but has a genuinely satisfying technical answer: what is a branch, really?




                                              26
````

## Page 027 — What Is a Branch, Really?

````text
Slide 26: What Is a Branch, Really?




Script

Let’s finally answer the question we deferred until we had the vocabulary for it: what is a branch,
really? Concretely, a branch is usually just one small file, sitting under “.git/refs/heads”, named
after the branch. Open it, and you will find exactly one thing inside: a single commit hash.
That is genuinely all there is to it, and it explains a lot. Creating a branch is instant, and
copies absolutely nothing, because there is nothing to copy; Git just writes one small new
file containing a hash. Committing while a branch is checked out simply overwrites that file’s
content with the new commit’s hash, moving the pointer forward. And this same simplicity
explains something that often worries beginners: deleting a branch never deletes the commits
behind it. You are only removing one small file that pointed at them; the commits themselves,
the actual objects, remain exactly where they were, at least for now. We will come back to
exactly what “for now” means, and how to recover a commit even after the branch pointing at
it is gone, later in this unit. For the moment, let’s turn to the other side of the picture we built
earlier: not the repository, but the staging area.




                                                27
````

## Page 028 — The Git Index

````text
Slide 27: The Git Index




Script

Earlier in this unit, we talked about the staging area as one of the three places a change passes
through. Now that we understand objects, let’s look at what that staging area actually is under
the hood: Git’s own internal name for it is the index, and technically, it is one single binary
file, “.git/index”. The index is the bridge between your working tree and your next commit: it
holds exactly the state that will become the new snapshot, the moment you run “git commit”.
When you run “git add”, you are not touching the repository’s history at all yet; you are only
updating the specific entries in this one file that you named. This gives us three distinct states
to compare at any moment: the working tree, the actual files on disk right now; the index, what
is staged and about to be committed; and “HEAD”, the last commit that was actually recorded.
Every Git status message you have ever seen is really just describing differences between these
three. With the index itself understood, let’s trace the full journey a change takes, from an edit
in your working tree all the way to a finished commit object.




                                               28
````

## Page 029 — From Working Tree to Commit

````text
Slide 28: From Working Tree to Commit




Script

Let’s put everything from this part of the unit together, and trace one single change all the way
from your editor to a finished commit object. It starts when “git add” copies your working tree
changes into the index, exactly the step we just discussed. When you then run “git commit”,
Git takes the current content of the index and writes it out as a tree object, or several, one
for every directory involved, using precisely the blob and tree objects we introduced earlier.
Next, a brand new commit object is created, pointing at that root tree, and also pointing back
at whatever commit was previously at the tip of your branch, its parent. Finally, the branch
reference itself, that one small file we opened up two slides ago, is updated to contain this
new commit’s hash. Files, to blobs, to trees, to one commit, with the branch pointer moved
to match; that is genuinely the entire mechanism behind every commit you have ever made,
no matter how ordinary or routine it felt at the time. There are two more details about what
Git actually records for a file that we have not touched on yet: its permissions, and one special
case, links. Let’s look at those next.




                                               29
````

## Page 030 — File Modes and Executable Files

````text
Slide 29: File Modes and Executable Files




Script

There is one more thing Git records about every file, beyond its content: permission bits,
specifically, whether or not the file is executable. This is stored as part of the tree entry we
discussed a few slides ago, right alongside the file’s name and its blob hash. An ordinary file,
one you cannot directly run, is recorded with mode 100644. A file marked as executable, a
script you can run directly from the shell, is recorded with mode 100755; same content, same
blob potentially, just a different mode number attached to it in the tree. You change this the
same way you would on any Unix system: “chmod plus x” on a file makes it executable, and
Git will notice, because that is exactly the mode it records. If you run “git diff” after only
changing a file’s permissions, without touching a single character of its content, Git will show
you a mode-only change, on its own line, with no content difference at all; genuinely useful the
first time a script mysteriously stops working after being cloned, because its executable bit was
lost somewhere along the way. There is one more special file type Git treats specially in exactly
this same spot, and that is what we look at next.




                                               30
````

## Page 031 — Symbolic Links in Git

````text
Slide 30: Symbolic Links in Git




Script

The special case we just alluded to is the symbolic link, and Git gives it its own distinct mode:
120000, different from both file modes we just discussed. A symbolic link is not treated as a
regular file at all. Here is the detail worth remembering: the blob behind a symbolic link does
not store the target file’s content. It stores the link’s target path, as plain text, nothing else.
Git itself never follows the link to see what it points at; it simply records where the link says it
points. This has a genuinely practical consequence: because operating systems handle symbolic
links differently, especially between Unix-like systems and Windows, this is a frequent, easily
misread source of confusing diffs, where what looks like a one-line content change is actually a
completely different link target. It is a small detail, but exactly the kind that a solid mental
model of blobs, modes, and trees lets you diagnose in seconds, instead of staring at a confusing
diff wondering what on earth changed. With the object model now essentially complete, let’s
step outside “.git” for a moment, and look at Git in its natural Unix environment.




                                                31
````

## Page 032 — Git and the Unix Environment

````text
Slide 31: Git and the Unix Environment




Script

[Musik]




                           32
````

## Page 033 — Git over SSH

````text
Slide 32: Git over SSH




Script

So far, whenever we mentioned a remote, we left open exactly how your machine actually au-
thenticates to it, and on the command line, that is very often SSH: an encrypted, authenticated
way of connecting to a remote machine, one you may already know from logging into Linux
servers. Git remotes over SSH use a distinctive URL form: something like “user at host colon
path”, rather than the familiar “https colon slash slash” you might expect. Behind that URL
sits public-key authentication: instead of typing a password every time you push or pull, your
machine proves its identity using a key pair. “ssh-keygen” generates exactly that pair: one pri-
vate key that stays on your machine, and one public key that you add, once, to your GitHub
or GitLab account. After that one-time setup, every future push and pull happens without a
single password prompt. HTTPS remotes remain the simpler alternative, especially when you
are just getting started, but SSH is what you will typically find configured on servers and in
automated environments, which makes it worth understanding now. Speaking of automation:
once a repository is set up, Git can also run your own scripts automatically, and that is exactly
our next topic.




                                               33
````

## Page 034 — Automating Tasks with Git Hooks

````text
Slide 33: Automating Tasks with Git Hooks




Script

Let’s look at a feature that turns Git from something you operate into something that can
operate on your behalf: hooks. A hook is simply a script that Git runs automatically at a
specific point in its workflow, for example, right before a commit is finalized, or right before
a push leaves your machine. Hooks live under “.git/hooks”, one file per hook, named after the
moment it runs: “pre-commit”, “commit-msg”, “pre-push”, and several more besides. Crucially,
a hook can be any executable script at all, a shell script, a Python script, anything your
system can run; Git does not care what language it is written in, only that it is executable and
produces the right exit code. One detail is easy to overlook, but important: hooks live only in
your own local “.git” folder. They are not part of the commits or the history, so they are not
transferred when someone clones your repository; anyone who wants the same hook has to set
it up separately, in their own clone. In the following exercise, you will write exactly one such
hook yourself.




                                              34
````

## Page 035 — Exercise: A Pre-Commit Hook

### Exercise SOP10-E02 (source slide)

````text
Slide 34: Exercise: A Pre-Commit Hook




Script

In this exercise, you write your first Git hook. Open the hooks folder of a test repository, and
create a new file in it, named exactly “pre-commit”, with no file extension. Its job is to reject
any commit whose staged changes contain the word “TODO”, so that such a marker can never
accidentally slip into your project’s history. Once you have written it, remember that a hook
has to be executable before Git will run it at all. Test it twice: once by staging a change that
does contain “TODO”, and once with a change that does not, to confirm the hook behaves
correctly in both cases. Finally, be ready to explain what exactly the hook’s exit code controls,
and why that one number is what determines whether your commit goes through, or is rejected.
The video stops now to give you time for this exercise. When you are done, press the button,
and I will show you a possible solution.




                                               35
````

## Page 036 — Solution: A Pre-Commit Hook

````text
Slide 35: Solution: A Pre-Commit Hook




Script

The goal of this exercise was to implement a pre-commit hook that rejects commit messages
or commits when the file still contains some to-do marker. The first question is how do we
know that files contain this to-do marker? And instead of just browsing through all files of
the repository, which would be unnecessary, we only look at the differences. And there is a
command named git diff that would show us the differences between the current state of the
files and the last committed version of the files. So we are now on a clear repository here. So
the output is empty. So first to demonstrate this, we modify the file and we add a to-do marker
here. And now git diff gives us this information that in this file here we have a new line edit
marked with a plus here, edit containing to-do. Notice that we have not yet added this file to
the staging area. Therefore, if we call git diff with the parameter cached, this output is empty.
And now we add this file to the staging area. Then git diff is empty because git diff only works
against the working tree. And we call git diff cached and this now works against the index and
there we have this modified. And this is exactly what we want. So now we go into the hidden
git directory. We go to hooks. Here you have already a list of samples, but we want to create a
new one. So we call it bitpre-commit, nothing else, so no extension here. And then we just type
in our first shell command. And we say if git diff cached, so if this, the output of this command,
we type this into rep for to-do. And then, so if there is a to-do in this differences list, then
we echo, which would actually not be necessary, but just for demonstration, commit rejected.
And we exit with one. So this would be the kind of error case. And otherwise we exit with
zero. And we go back to the working directory. And now, oh no, I forgot we have to change the
permissions here. So now pre-commit is executable. And now we try to commit. And it tells
us commit rejected. So this works as expected. We could demonstrate how it would work if we
delete this. So the file is, we edit once again to the staging area, and we reuse the last commit.
It worked.



                                               36
````

## Page 037 — Recovering from Mistakes

````text
Slide 36: Recovering from Mistakes




Script

[Musik]




                           37
````

## Page 038 — Undoing Changes with Restore and Revert

````text
Slide 37: Undoing Changes with Restore and Revert




Script

We have spent this whole unit building up a fairly complete picture of Git, and it is time to
admit something every developer eventually has to face: sooner or later, you will need to undo
something. Let’s start with the gentlest tools available for that. “git restore” followed by a file
name discards uncommitted changes in your working tree, bringing that file back to how it
looked at your last commit. If you have already staged a change but changed your mind about
committing it, “git restore dash-dash staged” followed by a file name unstages it again, moving
it back to the working tree, without discarding the change itself. And if the change is already
committed, “git revert” followed by a commit undoes it properly: not by erasing that commit,
but by creating a brand new commit that applies the exact opposite change. That distinction
matters enormously: history stays completely intact, nothing is ever erased by revert, which is
exactly why it is safe to use even on branches that others are already working from, and have
already pulled. But sometimes, you want something more forceful than restoring or reverting,
and that brings us to reset.




                                                38
````

## Page 039 — Resetting Repository State

````text
Slide 38: Resetting Repository State




Script

Where restore and revert are careful, targeted tools, “git reset” is a blunter, more powerful one,
and it comes in three variants that differ only in how much they actually touch. “git reset dash-
dash soft” moves “HEAD” to point at a different commit, but leaves both your index and your
working tree completely untouched. “git reset dash-dash mixed”, the default if you don’t specify
one, additionally resets the index, though your working tree files still keep their content. “git
reset dash-dash hard” goes all the way: “HEAD”, the index, and the working tree are all moved
together, discarding any uncommitted work in the process. Here is the one rule to genuinely
remember: reset does not add to history the way revert does; it rewrites it, by moving where
your branch points. That makes it perfectly safe on commits that only you have ever seen,
still sitting locally, unpushed. It becomes risky the moment those commits have already been
pushed and someone else may have already built on top of them. Used carefully, though, reset
is exactly the tool behind our very last topic: recovering something that reset itself just seemed
to throw away.




                                               39
````

## Page 040 — The Reflog

````text
Slide 39: The Reflog




Script

That last sentence deserves an explanation, and it starts with a tool we have not mentioned at
all so far: the reflog. “git reflog” shows you a local record of every place “HEAD” has pointed to
recently, in this exact repository, on this exact machine. Every checkout, every commit, every
reset, every rebase, gets logged here, in order, each entry with its own short description of what
just happened. Crucially, and unlike the commit history itself, none of this is shared, pushed, or
transmitted anywhere; the reflog exists purely locally, as your own private safety record, and it
is not part of what someone else sees when they clone your repository. It is also not permanent:
entries do eventually expire, after a configurable period, so this is not an infinite archive, but it
comfortably outlasts the kind of mistake we are about to fix. In practice, the reflog is the safety
net behind almost any “undo” situation that feels hopeless at first glance. So let’s use exactly
that safety net to recover something that looks, at first, like it has been lost for good.




                                                 40
````

## Page 041 — Recovering Lost Commits

````text
Slide 40: Recovering Lost Commits




Script

Here is the reassuring fact this entire unit has been building toward: a commit that no branch
points to anymore is not deleted, at least not immediately. It is still sitting, completely intact,
as an object somewhere under “.git/objects”, simply unreachable, because nothing currently
points to it. It stays exactly like that, untouched, until Git’s garbage collection eventually runs
and cleans up objects that truly are not referenced by anything anymore, which, in an ordinary
local repository, can be quite a while. That gives you a genuine window to recover it. The tool
for finding it again is exactly the one from the previous slide: “git reflog”, scanning through its
entries for the commit hash from right before the action that seemingly lost it. Once you have
that hash, recovery itself is almost anticlimactic: “git branch”, a new name, and that hash, and
you have a branch pointing at the commit again, exactly as reachable as any other. Nothing
was ever really gone; it was only unreachable, and now it is not. Let’s put this exact scenario
into practice yourself, in one final exercise.




                                                41
````

## Page 042 — Exercise: Recover a Lost Commit

### Exercise SOP10-E03 (source slide)

````text
Slide 41: Exercise: Recover a Lost Commit




Script

In this final exercise, you engineer your own small disaster, and then fix it. Make a commit
with some meaningful content, and then use a hard reset to move back to the commit before it,
exactly the kind of reset we described a few slides ago. Confirm with the log that the commit
genuinely appears to be gone, at least from your branch’s point of view. Now bring it back.
Use the reflog to find the hash of the commit you just seemingly lost, and point a brand new
branch at that exact hash. Finally, verify that the recovered content is exactly what you expect,
confirming that nothing was actually lost at any point, only temporarily unreachable. The video
stops now to give you time for this exercise. When you are done, press the button, and I will
show you a possible solution.




                                               42
````

## Page 043 — Solution: Recover a Lost Commit

````text
Slide 42: Solution: Recover a Lost Commit




Script

We want to demonstrate a workflow for recovering from some kind of severe problems. We have
here our demo file. We add another line. And we commit this to our history. So we have here our
last commit, very important change. So now we modify manually the history of our repository
by calling git reset. And we want to have a hard reset. And we set the pointer back by one
commit. So this is the symbolic name for this, beginning from the head, back one step. So now
the repository head points to this last commit, important change. And this very important
change commit seems to be lost. We can check this. Now the first lock and the head points to
is important change, not a very important change. So what can we do to integrate this seem to
be lost commit back into our history? So we have the command reflock, which is a local history
of the modifications. What sequence of git commands have you executed? And we want to have
this commit here, this bde and so on, hash value. And we now use this way to create a new
branch. So we call it branch. And we name this rescued. And we just type in the hash value,
so bde 781f. We are still on the main branch, but we can demonstrate what is the contents of
this file. So the last line, the fourth line that was integrated in the last commit is now invisible
here. But we can switch to this branch. So now we have a name for this head again, or this
seem to be lost head, and the name is rescued. So we change to this branch and there we have
this fourth line. So now we can go back to main and we can call merge and we want to merge
rescued. And then git tells us fast forward was an appropriate way to merge. And then we have
demo here and there we have our modifications again.




                                                43
````

## Page 044 — Conclusion

````text
Slide 43: Conclusion




Script

[Musik]




                       44
````

## Page 045 — Git: From Tool to System

````text
Slide 44: Git: From Tool to System




Script

We have covered a great deal of ground in this unit, from your very first commit to reaching
into “.git” and pulling a supposedly lost one back out, so let’s step back and name what actually
connects all of it. Every single Git command we have used, no matter how different they looked
on the surface, ultimately reduces to reading or writing objects, and to moving references
around to point at them. That is genuinely the whole model. There is no hidden, unexplainable
magic anywhere in Git, no step that just has to be taken on faith; every behavior we have
seen follows directly from blobs, trees, commits, and references pointing at them. And that is
precisely why understanding the internals pays off so directly in practice: instead of memorizing
which command to run when something goes wrong, you now have enough of a model to reason
your way to the answer yourself, the same way we did with the reflog a few slides ago. That
confidence, being able to recover from a problem rather than only knowing how to avoid it, is
really the point of everything in this unit, whether you end up using Git alone, or as part of a
much larger team. With that whole picture in view, let’s pull it all together one last time.




                                               45
````

## Page 046 — Summary

````text
Slide 45: Summary




Script

That’s it for today. We started this unit with a very ordinary question, why version control
matters at all, and ended up somewhere far more interesting: actually understanding what Git is
doing underneath its commands, not just which commands to type. The red thread connecting
all of it was really one idea, followed all the way through: Git as a content-addressed store of
blobs, trees, and commits, with the index bridging your working tree and each new snapshot,
and branches as nothing more than small pointers into that store. On top of that foundation,
we saw Git operating comfortably in its native Unix environment, authenticating over SSH, and
automating tasks through hooks that run your own scripts at exactly the right moment. And
we closed with the part every developer eventually needs: restoring, resetting, and, when things
really go wrong, using the reflog to recover a commit that only looked lost. In practice, this
understanding pays off exactly when you least expect to need it: the moment something in Git
seems to have gone irreversibly wrong. In the next unit, we continue with the C programming
language.




                                              46
````

## Page 047 — Literature

````text
Slide 46: Literature




Script

[Musik]




                       47
````
