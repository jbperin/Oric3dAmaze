@ECHO OFF

SET LANG=FR

::
:: Set the build paremeters
::
SET OSDKADDR=$600
SET OSDKNAME=POG_OP1
SET OSDKFILE= ay_s tablogtrigo_s keybuf_s kernel keyboard print texel_s raycast_s dda_s drawWalls_s viewport_s column_s game_s collision_s  main 
REM charset_s image_s 
SET OSDKCOMP=-O2


REM need to add %OSDKPREPROC% in parameters of cpp.exe preprocess command in file %OSDK%\bin\make.bat
REM 0:english 1:french 2:spanish 3:italian
IF "%LANG%"=="EN" GOTO English
IF "%LANG%"=="FR" GOTO French
IF "%LANG%"=="ES" GOTO Spanish
IF "%LANG%"=="IT" GOTO Italian

:English
SET OSDKPREPROC=-DLANG=0
GOTO End
:French
SET OSDKPREPROC=-DLANG=1
GOTO End
:Spanish
SET OSDKPREPROC=-DLANG=2
GOTO End
:Italian
SET OSDKPREPROC=-DLANG=3
GOTO End


:End
