#!bin/bash
NOME=$0
TEXTO=$(basename -s .sh $NOME)
cat script.sh > $TEXTO.bkp 