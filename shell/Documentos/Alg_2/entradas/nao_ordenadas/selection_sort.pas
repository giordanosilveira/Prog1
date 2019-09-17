program selection_sort;
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
procedure troca (var v:Tvetor;i,m:longint);
var
        aux:elemento;
begin
        aux:=v[i];
        v[i]:=v[m];
        v[m]:=aux;
end;
procedure imprime_vetor (v:Tvetor;n:longint);
var i:longint;

begin
        For i:=1 to n do
                write (v[i],' ');
end;
var
        i,j,n,min:longint;
        v:Tvetor;
begin   
        Read (n);
        ler_vetor (v,n);
        for i:=1 to n-1 do
        begin
                min:=i;
                for j:=i+1 to n do
                begin
                        if v[j] < v[min] then
                                min:=j;
                        troca (v,i,min);
                end;
        end;
end.  
