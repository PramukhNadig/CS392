#!/bin/bash

echo "My home dir is:" /home/$(whoami)
echo "My home dir is " $HOME
echo $(cd; pwd)