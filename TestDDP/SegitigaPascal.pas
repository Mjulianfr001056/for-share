
uses crt;


var
    n, i, j: integer;
    seg : array[0..25, 0..25] of longint;

procedure hitung (row, n : integer);
    var
        i : integer;

    begin
        for i := 1 to row - 1 do begin
            seg[row, i] := seg[row-1, i-1] + seg[row-1, i];
        end;
        
        seg[row, 0] := 1;
        seg[row, row] := 1;
        
        if(row <> n) then begin hitung(row+1, n);
    end;
end;

procedure cetak(odd: boolean);
    var
        i, j, k : integer;
    begin
        k := 0;
        for i := 0 to n-1 do begin
                for j := 0 to (n - i + 1) div 2 do begin
                    write('    ');
                end;

                if((i mod 2 = 0) and odd) then write('  ');
                if((i mod 2 = 1) and not odd) then write('  ');


                for  k := 0 to i do begin
                    write(seg[i, k]:3, ' ');
                end;

                writeln();
            end;
    end;

begin
    clrscr;
    write('Masukkan tinggi segitiga: ');
    readln(n);
    
    if (n = 1) then 
        writeln('1':3)
    else if (n = 2) then begin
        writeln('1':3);
        write('1   1');
    end else begin

        for i := 0 to n do begin
            for j := 0 to n do begin
                seg[i, j] := 0;
            end;
        end;

        seg[0, 0] := 1;
        seg[1, 0] := 1;
        seg[1, 1] := 1;
        
        hitung(2, n);

        cetak(n mod 2 = 0);
    end;
end.