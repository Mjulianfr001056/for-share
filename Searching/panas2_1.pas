uses crt;
Type 
    Larik = array [1..100] of integer;

var
    A: larik;
    i,H,x: integer;

function BinarySearch (A:larik; X:integer; L:integer; H:integer):Integer;
    var
        mid:integer;
        ditemukan:boolean;
    Begin
        mid:=((L+H) div 2);
        if L<=H then
        begin
            if (A[mid] > x) then
            BinarySearch:=BinarySearch(A,x,L,(mid-1));
            if (A[mid] < x) then
            BinarySearch:=BinarySearch(A,x,L,(mid+1));
            if (A[mid] = x) then
            Begin
                BinarySearch:=mid; {ditemukan}
                ditemukan:=true;
            end;
        end;
        if not ditemukan then
        BinarySearch:=0; {tidak ditemukan}
        end;

begin
    clrscr;
    //Isi array
    H := 10;
    for i:=1 to H do A[i] := i*100;

    //Yang dicari
    X := 500;

    writeln('Nilai yang dicari ada di index ke-', BinarySearch(A, x, 1, H));
end.