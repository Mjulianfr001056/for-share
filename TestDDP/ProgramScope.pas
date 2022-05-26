program scope;

var
a,b,c,d : integer;

procedure scope1;
    var
    d,e: integer;
    begin
    d := a + b; e := d * 2;
    end;
procedure scope2(var x:integer; y:integer);
    var
    a: integer;
    begin
    a := x;
    x := y;
    y := x;
    end;
procedure scope3(p: integer; var q:integer; r:integer);

function scope4(z:integer) : integer;
    begin
    scope4 := z + 1;
    end;
    begin
    p := scope4(p);
    end;

procedure scope5;
    begin
    writeln('a=',a); writeln('b=',b);
    writeln('c=',c); writeln('d=',d);
    end;

begin (* MAIN PROGRAM *)
    a := 10; b := 20; c := 30; d := 40;
    Writeln('A');
    scope5; (* A *)

    Writeln('B');
    scope1; (* B *)

    Writeln('C');
    scope5; (* C *)

    Writeln('D');
    scope2(a,b); (* D *)

    Writeln('E');
    scope5; (* E *)

    Writeln('F');
    scope3(a,b,c); (* F *)

    Writeln('G');
    scope5; (* G *)
end.