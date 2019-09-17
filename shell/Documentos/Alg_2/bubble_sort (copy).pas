program BUBBLE_SORT;

const
	MAX=500001;
type	
	elemento=qword;
	Tvetor = array [1..MAX] of elemento;
procedure ler_vetor (var v:Tvetor;n:longint);
var i:longint;
begin
	Read (n);
	for i:=1 to n do
		Read (v[i]);	
end;
procedure troca (var v:Tvetor;j:longint);
var
	aux:elemento;
begin
	aux:=v[j];
	v[j+1]:=v[j];
	v[j+1]:=aux;
end;
var 
	v:Tvetor;
	j,i,n:longint;
	mudou:boolean;
begin
	Read (n);
	ler_vetor (v,n);
	i:=0;
	mudou:=true;
	while (i<=n) and (mudou) do
	begin
		mudou:=false;
		for j:=1 to n-i do
		begin
			if v[j]>v[j+1] then
			begin
				mudou:=true;
				troca (v,j);
			end;
		end;
	end;
end.
