@ECHO OFF
SET STARTADDR=$9800
SET INPUTFN=charset_s
SET OUTTAP=charset.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%
rem copy %OUTTAP% c:\emulate\oric\shared /Y
rem pause

REM %osdk%\bin\PictConv.exe -m0 -f6 -o4image img\splash.png image_s.s 

SET STARTADDR=$a000
SET INPUTFN=image_s
SET OUTTAP=splash.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%
SET INPUTFN=loader
SET OUTTAP=loader.tap
%osdk%\bin\bas2tap.exe -b2t1 %INPUTFN%.bas BUILD\%OUTTAP% 


