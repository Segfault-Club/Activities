# Simple Capture the Flag

Provided with a [main.hex](./main.hex) file, you are expected to convert it back into an
x86-64 ELF executable for Linux -- for you to find the solution.

This challenge is purposefully made easy - it is our first one! If you're one of
the adventurers who like to challenge themselves, we propose you only use
the tools from [binutils](https://www.gnu.org/software/binutils/) after having
reversed back the file you were provided. If you're using a GNU/Linux system,
you should already have this installed.


## How to run:

The binaries are made for Linux. Source code and compilation instructions
will later be provided on our GitHub page if you'd like to solve it later.

For obvious reasons, you shouldn't be running binaries from Discord on your
computer -- that's insecure (and quite dumb!). A good idea would be to use a
virtual machine; if you're too lazy for that, well, then don't run it! (The program
is not malware, but we want to spark curiosity and entertain you, not to incentivize
bad practices!).

You are expected to have a file called `exploit` with executable permissions in
your cwd (current working directory). It will be run by the [test.sh](./test.sh) script,
and its output will get piped into `./main` (the file you should have reversed). See the 
description in [test.sh](./test.sh) on how to use it, and send us a screenshot of you 
running it (with the output) -- so we can verify you solved the challenge. (You may
send this screenshot in the club's chat, but do not provide solutions.)


## Help

You are allowed to help and be helped within the club's chat; but do not give your
solution away. Let others have the chance to try and learn before you can showoff.
Also, please do not go to #compsci-help for questions related to this. A list of 
resources you may find useful is linked below:


### Resources
1. [Hex-dump](https://en.wikipedia.org/wiki/Hex_dump)
2. [git-log (can also do `man git log`)](https://git-scm.com/docs/git-log)
3. [GNU binutils (look for objdump)](https://www.gnu.org/software/binutils/)
4. [GNU debugger](https://www.sourceware.org/gdb/documentation/)
5. [CTFs](https://ctf101.org/binary-exploitation/buffer-overflow/)

