#!bin/bash
ARQUIVO=$1
DIRETORIO=$2
VARIAVEL=("warn" "info" "error")
DATINHA=$(date +%d-%m-%Y)

if [ ! -d ~/$2 ]; then
	mkdir $2
fi 

for i in ${VARIAVEL[*]}
do
	grep -w "$i" $ARQUIVO >> $DIRETORIO/${DATINHA}_"$i".log 
done

tar -czvf $DIRETORIO/logs.tar.gz $DIRETORIO/*

if [ -f logs.tar.gz ]; then
	logger Boa campeão, arquivo compactado!
else
	logger Já existe esse arquivo campeão!
fi
