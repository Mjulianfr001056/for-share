uses crt;

var 
    n : integer;

procedure cetak(n, row : integer);
    var
        i : integer;
    begin
        if row < n then begin
            for i := 1 to row do write(i, ' ');
            for i := row - 1  downto 1 do write(i, ' ');
            writeln();
            cetak(n, row + 1);
        end else begin
            if n = 1 then writeln('1') 
            else begin
                for i := 1 to n do begin
                    write(i, ' ');
                end;

                for i := n-1 downto 1 do begin
                    write(i, ' ');
                end;

                writeln();
                cetak (n-1, row + 1);
            end;
        end;
    end;
begin
    readln(n);
    cetak(n, 1);
end.