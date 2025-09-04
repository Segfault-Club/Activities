# Instructions:

You are provided with the `main.hex` file, you are expected to convert this
back into an x86-64 ELF executable for linux, then, you should find the solution.
This challenge is purposefully made easy: it is our first one! If you're one of
the advanturers who like to challenge themselves, we propose you to only use
the tools from binutils after having reversed back the file you were provided,
if you're using a GNU/Linux system, you should alredy have this installed.

## How to run:

The binaries here are made for Linux, source code and compilation instructions
will later be providade on our github page if you'd like to solve it later.

For obvious reasons, you shouldn't be running binaries from discord on your
computer, that's unsecure (and quite dumb!), a good idea would to be use a
virtual machine, if you're too lazy for that, well, don't run it! (The program
is not malware, but were to spark curiosity and entretain you, not to incentivate
bad practices!)

You are expected to have a file called `exploit` with executable permissions in
your cwd (current working directory), this will be ran by the test.sh script, it's 
output get's piped into `./main` (the file you should have reversed), see the 
description inside of test.sh on how to use it, and send a screenshot of you 
running it (with the output) so we can verify you solved the challenge (You may
send this screenshot in the club's chat, but do not provide solutions)

## Help

You are allowed to help and be helped within the club's chat, but do not give your
solution away, let others have the chance to try and learn before you can showoff,
please do not go to #compsci-help for questions related to this. A list of 
resources you may find usefull is linked below:

### Resources
1. [Hex-dump]{https://en.wikipedia.org/wiki/Hex_dump}
2. [git-log (can also do `man git log`)]{https://git-scm.com/docs/git-log}
3. [GNU binutils (look for objdump)]{https://www.gnu.org/software/binutils/}
4. [GNU debugger]{https://www.sourceware.org/gdb/documentation/}
5. [CTFs]{https://ctf101.org/binary-exploitation/buffer-overflow/}

