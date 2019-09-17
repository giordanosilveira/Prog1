#!/bin/bash
cd /home/bcc
finger * | grep Name: | cut -d':' -f3 | cut -d' ' -f2 | sort -u > ~/nomes_de_informatas.txt


