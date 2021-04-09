@ECHO OFF
SET STARTADDR=$9800
SET INPUTFN=charset_s
SET OUTTAP=charset.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%
rem copy %OUTTAP% c:\emulate\oric\shared /Y
rem pause

IF "%LANG%"=="EN" GOTO EnglishSplash
IF "%LANG%"=="FR" GOTO FrenchSplash
IF "%LANG%"=="ES" GOTO SpanishSplash
IF "%LANG%"=="IT" GOTO ItalianSplash
REM %osdk%\bin\PictConv.exe -m0 -f6 -o4image img\splash.png image_s.s 

:EnglishSplash
SET SPLASH_IMG=img\splash_en.png
GOTO EndSplash
:FrenchSplash
SET SPLASH_IMG=img\splash_fr.png
GOTO EndSplash
:SpanishSplash
SET SPLASH_IMG=img\splash_es.png
GOTO EndSplash
:ItalianSplash
SET SPLASH_IMG=img\splash_it.png
GOTO EndSplash
:EndSplash
%osdk%\bin\PictConv.exe -m0 -f6 -o4image %SPLASH_IMG% image_s.s

SET STARTADDR=$a000
SET INPUTFN=image_s
SET OUTTAP=splash.tap
SET AUTOFLAG=0
%osdk%\bin\xa.exe %INPUTFN%.s -o BUILD\final.out -e xaerr.txt -l %INPUTFN%.txt
%osdk%\bin\header.exe -a%AUTOFLAG% BUILD\final.out BUILD\%OUTTAP% %STARTADDR%

echo "%LANG%"
IF "%LANG%"=="EN" GOTO EnglishSplash
IF "%LANG%"=="FR" GOTO FrenchSplash
IF "%LANG%"=="ES" GOTO SpanishSplash
IF "%LANG%"=="IT" GOTO ItalianSplash
echo HERE
:EnglishSplash
SET INPUTFN=loader_en
echo "English"
GOTO EndLoader
:FrenchSplash
SET INPUTFN=loader_fr
echo "French"
GOTO EndLoader
:SpanishSplash
SET INPUTFN=loader_es
GOTO EndLoader
:ItalianSplash
SET INPUTFN=loader_it
GOTO EndLoader
:EndLoader

SET OUTTAP=loader.tap
%osdk%\bin\bas2tap.exe -b2t1 %INPUTFN%.bas BUILD\%OUTTAP% 


