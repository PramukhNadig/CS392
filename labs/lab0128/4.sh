#!/bin/bash

DIR=$1

NUMFILES=$(ls $DIR | wc -l)
echo $NUMFILES
