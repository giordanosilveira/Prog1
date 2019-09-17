program insertion_sort;
const
        MAX=500001;
type
        elemento=qword;
        Tvetor = array [1..MAX] of elemento;
procedure ler_vetor (var v:Tvetor;n:longint);
var i:longint;
begin
        for i:=1 to n do
                Read (v[i]);
end;
procedure imprime_vetor (v:Tvetor;n:longint);
var i:longint;

begin
        For i:=1 to n do
                write (v[i],' ');
end;
var n,i,j:longint;
    pivo:elemento;
    v:Tvetor;
begin
	Read (n);
	ler_vetor (v,n);
	for i:=2 to n do
	begin
		pivo:=v[i];
		j:=i-1;
		while (j>0) and (v[j]>pivo) do
		begin
			v[j+1]:=v[j];
			j:=j-1;
		end;
		v[j+1]:=pivo;
	end;
end.
