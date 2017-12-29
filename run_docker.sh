#!/bin/bash

NAME=ev3env

docker restart $NAME
docker attach $NAME 
