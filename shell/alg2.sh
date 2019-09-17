#!/bin/bash
for ((i=1000;i<=50000;i+=1000))
do
        echo $i >> tamanho.tmp
        command time -o tempo_bolha.tmp -a -f "%U" ../../bubble_sort <  $i.txt
        command time -o tempo_selection.tmp -a -f "%U" ../../insertion_sort <  $i.txt
        command time -o tempo_insertion.tmp -a -f "%U" ../../selection_sort <  $i.txt
done
echo "Tam    bubble   insert    selec" >> ordenado.txt 
paste tamanho.tmp tempo_bolha.tmp tempo_insertion.tmp tempo_selection.tmp > ordenado.txt
rm *.tmp
cd ..
echo "Tam    bubble   insert    selec" >> 
cat ordenado.txt
gnuplot -persist <<-EU
plot "ordenado.txt" using 2 title 'Bolha' with lines, "ordenado.txt" using 3 title 'Insertion' with lines, "ordenado.txt" using 4 title 'Selection' with lines
EU
##############################################################################################################################################################
cd ~/entradas/ordenadas
for ((i=1000;i<=50000;i+=1000))
do
        echo $i >> tamanho.tmp
        command time -o tempo_bolha.tmp -a -f "%U" ./bubble_sort <  $i.txt
        command time -o tempo_selection.tmp -a -f "%U" ./insertion_sort <  $i.txt
        command time -o tempo_insertion.tmp -a -f "%U" ./selection_sort <  $i.txt
done
paste tamanho.tmp tempo_bolha.tmp tempo_insertion.tmp tempo_selection.tmp > ../nao_ordenado.txt
rm *.tmp
cd ..
echo "Tam    bubble   insert    selec"
cat nao_ordenado.txt
gnuplot -persist <<-GIBA
plot "ordenado.txt" using 2 title 'Bolha' with lines, "ordenado.txt" using 3 title 'Insertion' with lines, "ordenado.txt" using 4 title 'Selection' with lines
GIBA



