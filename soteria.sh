#!/bin/bash
INPUT = sudo timeout 5 tcpdump 

sleep 5

grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b" $INPUT





#grep -oE "\b([0-9]{1,3}\.){3}[0-9]{1,3}\b"



