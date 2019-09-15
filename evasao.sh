ANOS=(Geral 2014 2015 2016 2017 2018)
ARQUIVOS=(all_evasoes.csv evasao-2014.csv evasao-2015.csv evasao-2016.csv evasao-2017.csv evasao-2018.csv)
QUITCURSO=(Abandono "Cancelamento Pedido" "Descumprimento Edital" "Desistência" "Desistência Vestibular" Formatura "Não Confirmação de Vaga" 
	"Novo Vestibular" Reopção "Término de Registro Temporário" Falecimento Jubilamento "Cancelamento a Pedido do Calouro" "Cancelamento Administrativo")
tar -xzf evasao2014-18.tar.gz # descompactando o arquivo
cd evasao
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
	sed -i '1d' arq2.tmp

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
echo

echo [ITEM 5]
for i in {0..4} # anda pelos anos
do
	cut -d',' -f2 ${ARQUIVOS[$i]} >> arq.tmp 
	sed -i '1d' arq.tmp 
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

SEXO=(M F)
cut -d',' -f5 all_evasoes.csv > arq.tmp
TOTAL=0
for i in ${SEXO[*]}
do
	A=$(grep $i arq.tmp | wc -l)
	TOTAL=$(($TOTAL + $A))
done

echo "SEXO	MEDIA EVASÕES"
echo "M	$((100*$(grep ${SEXO[0]} arq.tmp | wc -l)/$TOTAL))%"
echo "F	$((100*$(grep ${SEXO[1]} arq.tmp | wc -l)/$TOTAL + 1))%"

rm *arq.tmp

for i in ${ANOS[*]}
do
	sed -i '1d' evasao-$i.csv
	echo "$i	$(wc -l evasao-$i.csv | cut -d' ' -f1)" >> evasoes_por_ano.dat	
done
FORMAINGRESSO=("Aluno Intercâmbio" "Aproveitamento Curso Superior" "Convênio AUGM" "Convênio Pec-G" "Mobilidade Acadêmica" "Processo Seletivo/ENEM" Reopção "Transferência Ex-Ofício" 
"Transferência Provar" Vestibular)
for j in {0..4} 
do
	echo -n  "${ANOS[$j]} " >> evasoes-forma.txt	  
	for i in {0..9} 
	do
		echo -n "$(grep "${FORMAINGRESSO[$i]}" evasao-${ANOS[$j]}.csv | wc -l) " >> evasoes-forma.txt
	done
echo >> evasoes-forma.txt
done
#column -t -s, evasoes-forma.txt >> 
#[ITEM 5] grep -o "numero" file

