program MatriksRev;

uses crt;

type
    pecahan = record
        num, denum : integer;
    end;
    array2D = array[0..2, 0..2] of pecahan;

var
    matriks : array2D;
    dum_Matriks : array2D;
    local_input, in_tmp, i, j: integer;

function mat_iput(str : string) : pecahan;
    var
        idx, len : integer;
        resultElement : pecahan;
        tmp_result: TStringArray;

    begin
        idx := pos('/', str);
        if(idx = 0) then begin
            resultElement.num := StrToInt(str);
            resultElement.denum := 1;
        end else begin
            tmp_result := str.split('/');
            resultElement.num := StrToInt(tmp_result[1]);
            resultElement.denum := StrToInt(tmp_result[2]);            
        end;
        mat_input = resultElement;
    end;
procedure print_matriks(var tmp_mat : array2D);
    var
        i, j : integer;
    begin
        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                write(tmp_mat[i, j], ' ');
            end;
            writeln();
        end;
    end;

procedure print_matriksReal(var tmp_mat : array2DReal);
    var
        i, j : integer;
    begin
        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                write(tmp_mat[i,j]:5:2, ' ');
            end;
            writeln();
        end;
    end;

procedure kaliMatriks(var tmp_mat1, tmp_mat2 : array2D);
    var
        resultMat : array2D;
        i, j, k : integer;

    begin

        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                resultMat [i,j] := 0;
            end;
        end;

        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                for k := 0 to 2 do begin
                resultMat[i, j] += tmp_mat1[i, k] * tmp_mat2[k, j];
                end;
            end;
        end;
        
        clrscr;
        writeln('Hasil perkalian matriks');
        print_matriks(tmp_mat1);

        writeln('dan');
        print_matriks(tmp_mat2);
        
        writeln();
        writeln('Adalah:');
        print_matriks(resultMat);
    end;

// procedure OBE(var tmp_mat : array2D);
//     var
//         i, j : integer;
    
//     begin
//         for(int)
//     end;

function detMatriks(var tmp_mat : array2D) : real;
    begin
        detMatriks := tmp_mat[0,0] * (tmp_mat[2, 2] * tmp_mat[1, 1] - tmp_mat[2, 1] * tmp_mat[1, 2]);
        detMatriks += tmp_mat[1,0] * (tmp_mat[0, 1] * tmp_mat[1, 2] - tmp_mat[1, 1] * tmp_mat[0, 2]);
        detMatriks += tmp_mat[2,0] * (tmp_mat[0, 1] * tmp_mat[2, 2] - tmp_mat[2, 1] * tmp_mat[1, 2]);
    end;

procedure tpMatriks(var tmp_mat : array2D);
    begin
        tmp_mat[0,1] += tmp_mat[1,0];
        tmp_mat[1,0] := tmp_mat[0,1] - tmp_mat[1,0];
        tmp_mat[0,1] -= tmp_mat[1,0];
    end;

procedure invers_mat(var tmp_mat : array2D);
    var
        resultMat : array2DReal;
        determinan : real;
    begin
        determinan := detMatriks(tmp_mat);
        if (determinan = 0) then writeln('Matriks ini invertible!') else begin
            resultMat[0,0] := tmp_mat[1,1] / determinan;
            resultMat[0,1] := -tmp_mat[1,0] / determinan;
            resultMat[1,0] := -tmp_mat[0,1] / determinan;
            resultMat[1,1] := tmp_mat[0,0] / determinan;

            writeln('Hasil Matriks: ');
            print_matriksReal(resultMat);
        end;
    end;

begin
    clrscr;
    Writeln('Selamat datang di aplikasi matriks sederhana 3x3');
    Writeln('================================================');
    
    writeln('Masukkan nilai matriks');
    
    for i := 0 to 2 do begin
        for j := 0 to 2 do begin
            read(str);
            
            matriks[i, j] := mat_input(str);
        end;
    end;

    repeat 
        writeln();
        writeln('Matriks kamu saat ini: ');
        print_matriks(matriks);
        writeln();

        Writeln('Silahkan pilih menu berikut:');
        writeln('1. Perkalian matriks');
        writeln('2. Determinan matriks');
        writeln('3. Transpos matriks');
        writeln('4. Invers matriks');
        writeln('5. keluar');
        write('Masukkan menu: ');
        readln(in_tmp);
    
        case in_tmp of 
            1 : begin
                    writeln('Masukkan nilai matriks kedua (b) ');
                    for i := 0 to 2 do begin
                        for j := 0 to 2 do begin
                            read(dum_matriks[i, j]);
                        end;
                    end;

                    writeln('Masukkan jenis perkalian');
                    writeln('1. AB');
                    writeln('2. BA');
                    write('Masukkan menu: ');
                    
                    readln(local_input);

                    if(local_input = 1) then kaliMatriks(dum_Matriks, matriks) else kaliMatriks(matriks, dum_Matriks);

                    writeln;
                end;
            2 : begin
                    clrscr;
                    writeln('Determinan dari matriks ini adalah ', detMatriks(matriks):0:2);
                end;
            3 : begin
                    tpMatriks(matriks);
                end;
            4 : begin
                    invers_mat(matriks);
                end;
            5 : begin
                    exit();
                end;
            else writeln('Masukan anda salah');
        end;
    until false;
End.