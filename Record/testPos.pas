uses SysUtils;

type
    pecahan = record
        num : integer;
        denum : integer;
    end;

var
    str : string;
    hasil : pecahan;

procedure mat_input(str : string);
    var
        idx, len, i : integer;
        resultElement : pecahan;
        tmp_result: string;

    begin
        tmp_result := '';
        len := length(str);
        idx := pos('/', str);
        if(idx = 0) then begin
            resultElement.num := StrToInt(str);
            resultElement.denum := 1;
            end
        else begin
            for i := 1 to idx-1 do begin
                tmp_result += str[i];
            end;
            resultElement.num := StrToInt(tmp_result);
            tmp_result := '';
            

            for i := idx + 1 to len do begin
                tmp_result += str[i];
            end;
            
            resultElement.denum := StrToInt(tmp_result);            
        end;
        
        hasil := resultElement; 
    end;

begin
    read(str);
    mat_input(str);
    writeln(hasil.num, '/', hasil.denum);
end.