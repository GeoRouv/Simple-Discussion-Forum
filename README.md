# Simple-Discussion-Forum
An automated creation of a simple discussion forum where you can choose how to print a thread or more.

## Description
A forum consists of its "title" and a number of threads. Each thread consists of a "theme", its "creator", its "creation date" and a number of posts.<br>Each post consists of a "numeric id" (id is unique to each post), its "title", "creator", "date of creation", and a text.

These are the actions that can be performed to the forum:<br>
0.Exit<br>
1.Print forum<br>
2.Print rules of forum<br>
3.Print random posts<br>
4.Print sorted<br>

About "Print sorted", its goal is to print all posts sorted in ascending order by creator using a binary search tree.

## Compile 
    $ g++ FORUMmain.c++ FORUMfunctions.c++ FORUMclasses.h FORUMtext.c++ FORUMtext.h

## Run
    $ ./a.out
