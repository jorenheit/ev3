#!/bin/bash

#1: password
#2: file
#3: username
#4: ip
#5: folder

sshpass sshpass -p $1 scp $2 $3@$4:$5

