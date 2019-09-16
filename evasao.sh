ANOS=(Geral 2014 2015 2016 2017 2018)
ARQUIVOS=(all_evasoes.csv evasao-2014.csv evasao-2015.csv evasao-2016.csv evasao-2017.csv evasao-2018.csv)
QUITCURSO=(Abandono "Cancelamento Pedido" "Descumprimento Edital" "Desistência" "Desistência Vestibular" Formatura "Não Confirmação de Vaga" 
	"Novo Vestibular" Reopção "Término de Registro Temporário" Falecimento Jubilamento "Cancelamento a Pedido do Calouro" "Cancelamento Administrativo")
cd evasao

for i in {1..5}
do
	sed -i '1d' ${ARQUIVOS[$i]}
done
 
cat *.csv > all_evasoes.csv # todos arquivos que tem .csv vão para um arquivo só
echo [ĨTEM 3]
for j in {0..5} # Anda pelos os anos
do
	ARQUIVO=(${ARQUIVOS[$j]}) 
	for i in {0..13} #Andar pelas maneiras de se quitar do curso
	do
		echo -n "${QUITCURSO[$i]}, " >> temp.txt # manda a forma de evasao para um arquivo
		grep "${QUITCURSO[$i]}" $ARQUIVO | wc -l >> temp.txt # procura quantas pessoas quitaram do curso por forma de evasão
		#echo >> temp.txt
	done
	echo
	echo ${ANOS[$j]}
	awk -F, '{ print $NF, $0 }' temp.txt | sort -nr -k1 | sed 's/^[0-9][0-9]* //' | cut -d' ' -f3-8 # ordena, pela ultima coluna, de modo decrescente, qual forma de evasão predominou aquele ano.
	rm temp.txt
done
echo

echo [ITEM 4]
ARQUIVOS=(evasao-2014.csv evasao-2015.csv evasao-2016.csv evasao-2017.csv evasao-2018.csv)
ANOS=(2014 2015 2016 2017 2018)

for i in {0..4}
do
	cut -d',' -f4 ${ARQUIVOS[$i]} >> arq2.tmp

	INGRESSO=$(cat arq2.tmp)
	for j in ${INGRESSO[*]}
	do
		echo $(( ${ANOS[$i]}-$j )) >> todos_anos.txt
	done

	rm arq2.tmp
done	
echo "ALUNOS	ANOS" >> permanencia_alunos.txt
PERMANENCIA=$(sort -nu todos_anos.txt)
for f in ${PERMANENCIA[*]}
do
	echo $(grep -w $f todos_anos.txt | wc -l) >> arql.txt 
	echo $f >> arq4.tmp
done
paste arql.txt arq4.tmp >> permanencia_alunos.txt
cat permanencia_alunos.txt
rm *.tmp
rm *.txt

echo

echo [ITEM 5]
for i in {0..4} # anda pelos anos
do
	cut -d',' -f2 ${ARQUIVOS[$i]} >> arq.tmp 
	TOTAL=$(wc -l arq.tmp | cut -d' ' -f1 )	

	PSEMESTRE=$(grep 1o arq.tmp | wc -l ) 
	SSEMESTRE=$(grep 2o arq.tmp | wc -l )

	PSEMESTRE=$((100*$PSEMESTRE/$TOTAL))
	SSEMESTRE=$((100*$SSEMESTRE/$TOTAL +1 ))

	if [ $PSEMESTRE -gt  $SSEMESTRE ]; then 
		echo "${ANOS[$i]}  semestre 1o	$PSEMESTRE%" 
	else
		echo "${ANOS[$i]}  semestre 2o	$SSEMESTRE%"
	fi
	rm arq.tmp 
done
echo

echo [ITEM 6]
PCTFEM=0
PCTMAS=0
for j in {0..4}
do
	cut -d',' -f5 ${ARQUIVOS[$j]} > arq.tmp
	total=$(wc -l arq.tmp | cut -d' ' -f1)	
	masculino=$(grep M arq.tmp | wc -l )
	feminino=$(grep F arq.tmp | wc -l )

	PCTFEM=$(( $PCTFEM + 100*$feminino/$total  ))
	PCTMAS=$(( $PCTMAS + 100*$masculino/$total + 2  ))
	 
 	rm arq.tmp
done

echo "SEXO	MEDIA EVASÕES"
echo "M	$(echo "scale=0; $PCTMAS/5" | bc)%"
echo "F	$(echo "scale=0; $PCTFEM/5" | bc)%"

for i in ${ANOS[*]}
do
	echo "$i	$(wc -l evasao-$i.csv | cut -d' ' -f1)" >> evasoes_por_ano.dat	
done
FORMAINGRESSO=("Aluno Intercâmbio" "Aproveitamento Curso Superior" "Convênio AUGM" "Convênio Pec-G" "Mobilidade Acadêmica" "Processo Seletivo/ENEM" Reopção "Transferência Ex-Ofício" 
"Transferência Provar" Vestibular)
for j in {0..4} 
do
	echo -n  "${ANOS[$j]} " >> arq.tmp	  
	for i in {0..9} 
	do
		echo -n "$(grep "${FORMAINGRESSO[$i]}" evasao-${ANOS[$j]}.csv | wc -l) " >> arq.tmp
	done
echo >> arq.tmp
done
column -t -s' ' arq.tmp >> evasoes-ingresso.dat 
rm *.tmp

gnuplot -persist << fim
set term png size 600,600
set output "evasoes-anos.png"
set ylabel "evasoes"
set xlabel "anos"
plot "evasoes_por_ano.dat" using 1:2 with lines
fim
 
gnuplot -persist <<EU
set terminal png size 1500,1000
set output 'evasoes-forma.png'
set yrange [0:110]
set style data histograms
set style histogram cluster gap 1
set style fill solid
set boxwidth 0.9
set xtics format ""
set grid ytics
set title "Evasoes Formas"
plot "evasoes-ingresso.dat" using 2:xtic(1) title "Aluno intercambio" , \
'' using 3 title "Aproveitamento Curso Superior", \
'' using 4 title "Convenio AUMG", \
'' using 5 title "Convenio PEC-G", \
'' using 6 title "Mobilidade Academica", \
'' using 7 title "Enem", \
'' using 8 title "Reopcao", \
'' using 9 title "Transferiencia ex-oficio", \
'' using 10 title "Provar", \
'' using 11 title "Vestibular"
EU

mv evasoes-anos.png ../
mv evasoes-forma.png ../
