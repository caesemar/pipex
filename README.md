# Pipex 

<p align="center"> <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Fira+Code&duration=3000&pause=1000&color=77F7A0&center=true&width=435&lines=Pipex+is+a+42+project+consisting+in;+a+replication+of+bash%C2%B4s+pipes" alt="Typing SVG" /></a></p>

## Requirements
The exact command that should be replicated is:

                                                        < infile command1 | command2 > outfile

and the input must be entered in the following way:

                                                ./pipex infile "command1 + args" "command2 + args" outfile
                                                
For the command part of the input you can receive either a standard command i.e. "ls" or the relative/absolute route i.e. (./.. , /usr/bin/ls, ../...),  the error handling as well has to be very bash-like so I made it quite similar.
Also, your program has to be able to execute and handle the lack of environment variables (compilation with env -i).

Aditionally, I implemented single quote support (') so awk commands could be functionals, not the case with $x since it´s on bash to handle them properly.

On the makefile some tests are implemented, only for success cases, error cases have to be manually checked. You can check this tests by using:

                                                                  make tests

# <p align="center"> ![pipe](https://user-images.githubusercontent.com/47799144/231563677-b84a535e-39ee-4e15-8058-87191f427fe1.png)</p>
