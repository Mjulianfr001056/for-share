program MatriksRev;

uses crt, sysutils;

type
    pecahan = record
        num, denum : integer;
    end;
    array2D = array[0..2, 0..2] of pecahan;

var
    matriks : array2D;
    dum_Matriks : array2D;
    hasil : pecahan;
    local_input, in_tmp, i, j: integer;
    str : string;

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

procedure print_matriks(var tmp_mat : array2D);
    var
        i, j : integer;
        tmp_element : pecahan;
    begin
        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                tmp_element := tmp_mat[i, j];

                if (tmp_element.denum = 1) then 
                    write(tmp_element.num, ' ')
                else
                    write(tmp_element.num, '/', tmp_element.denum, ' ');
            end;
            writeln();
        end;
    end;

function GCD(a, b : integer) : Integer;
    begin
        if (b = 0) then GCD := a else GCD := GCD(b, a mod b);
    end;

procedure simplify(var frac : pecahan);
    var
        FPB : integer;
    begin
        FPB := GCD(frac.num, frac.denum);
        frac.num := frac.num div FPB;
        frac.denum := frac.denum div FPB;
    end;

// procedure tambahPecahan(var a, b : pecahan);
//     var
//         hasil : pecahan;
//     begin
//         hasil.num := a.num * b.denum + a.denum * b.num;
//         hasil.denum := a.denum * b.denum;
//         simplify(hasil);

//         a := hasil;
//     end;

procedure kaliMatriks(var tmp_mat1, tmp_mat2 : array2D);
    var
        resultMat : array2D;
        i, j, k : integer;
        opr1, opr2, hasil : pecahan;
    begin

        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                resultMat[i, j].num := 0;
                resultMat[i, j].denum := 1;
            end;
        end;

        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                for k := 0 to 2 do begin
                    opr1 := tmp_mat1[i, k];
                    opr2 := tmp_mat2[k, j];
                    hasil.num := opr1.num * opr2.num;
                    hasil.denum := opr1.denum * opr2.denum;
                    simplify(hasil);
                    
                    tambahPecahan(resultMat[i, j],  hasil);
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



 function detMatriks(var tmp_mat : array2D) : real;
     begin
         detMatriks := tmp_mat[0,0] * (tmp_mat[2, 2] * tmp_mat[1, 1] - tmp_mat[2, 1] * tmp_mat[1, 2]);
         detMatriks += tmp_mat[1,0] * (tmp_mat[0, 1] * tmp_mat[1, 2] - tmp_mat[1, 1] * tmp_mat[0, 2]);
         detMatriks += tmp_mat[2,0] * (tmp_mat[0, 1] * tmp_mat[2, 2] - tmp_mat[2, 1] * tmp_mat[1, 2]);
     end;

procedure tpMatriks(var tmp_mat : array2D);
    var
        result_mat : array2D;

    begin
        for i := 0 to 2 do begin
            for j := 0 to 2 do begin
                result_mat[i, j] := tmp_mat[j, i];
            end;
        end;

        tmp_mat := result_mat;
    end;

// procedure invers_mat(var tmp_mat : array2D);
//     var
//         resultMat : array2DReal;
//         determinan : real;
//     begin
//         determinan := detMatriks(tmp_mat);
//         if (determinan = 0) then writeln('Matriks ini invertible!') else begin
//             resultMat[0,0] := tmp_mat[1,1] / determinan;
//             resultMat[0,1] := -tmp_mat[1,0] / determinan;
//             resultMat[1,0] := -tmp_mat[0,1] / determinan;
//             resultMat[1,1] := tmp_mat[0,0] / determinan;

//             writeln('Hasil Matriks: ');
//             print_matriksReal(resultMat);
//         end;
//     end;

begin
    clrscr;
    Writeln('Selamat datang di aplikasi mobile matriks sederhana 3x3');
    Writeln('================================================');
    
    writeln('Masukkan nilai matriks');
    
    for i := 0 to 2 do begin
        for j := 0 to 2 do begin
            write('Baris ', i + 1, ' kolom ', j + 1, ': ');
            readln(str);
            mat_input(str);
            matriks[i, j] := hasil;
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
                            write('Baris ', i + 1, ' kolom ', j + 1, ': ');
                            readln(str);
                            mat_input(str);
                            dum_matriks[i, j] := hasil;
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
            // 2 : begin
            //         clrscr;
            //         writeln('Determinan dari matriks ini adalah ', detMatriks(matriks):0:2);
            //     end;
            3 : begin
                    tpMatriks(matriks);
                end;
            // 4 : begin
            //         invers_mat(matriks);
            //     end;
            5 : begin
                    exit();
                end;
            else writeln('Masukan anda salah');
        end;
    until false;
End.
