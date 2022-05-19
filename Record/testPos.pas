uses SysUtils;


var
    a, b : integer;

function GCD(a, b : integer) : Integer;
    begin
        if (b = 0) then GCD := a else GCD := GCD(b, a mod b);
    end;

begin
    read(a, b);
    writeln(GCD(a,b));
end.