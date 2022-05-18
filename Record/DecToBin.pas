uses crt;

var
    n : integer;

function konversi(n: integer; str: string) : string;
    begin
        if(n <= 1) then 
            konversi := concat('1', str) 
        else if (n mod 2 = 1 ) then 
            konversi := konversi(n div 2, concat('1', str))
        else 
            konversi := konversi(n div 2, concat('0', str));
    end;

begin
    write('Input: ');
    readln(n);
    if (n = 0) then 
        writeln('Output: ', 0)
    else
        writeln('Output: ', konversi(n, ''));
end.