@echo off
set TID=_A1F
@REM for %%a in ("%CD%") do set TID=%%~nxa
set SID=00000000
set LNG=java
c++ %TID%.cpp
.\a.exe %TID% %SID% %LNG%
del /f /s /q /a .\out.txt >nul
del /f /s /q /a .\in.txt >nul
del /f /s /q /a .\*.exe >nul
del /f /s /q /a .\*.class >nul
pause
