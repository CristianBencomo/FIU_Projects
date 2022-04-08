# EEL4831_A3_CellArray

Author: Cristian Bencomo        
Class: EEL4831                     
Assignment #: 3          

## Description
The cellArray program takes an X,Y,Z input that represents the size of an array.              
A dynamic 3d array is generated with each location storing a pointer to an object that stores its location in the array and the pointer to a function

## Contents
* src folder containing source code and headers
* objs folder containing separately built objects
* Final cellArray Object
* Makefile

## How to compile
The makefile is ready to compile on a linux terminal, simply run the following command:
```
make
```      

This command will compile all the objects and link them, then you can run thge program on a linux terminal by using the command:
```
./cellArray 
```             

