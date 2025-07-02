@echo off
set TID=_001
@REM for %%a in ("%CD%") do set TID=%%~nxa
set SID=00000000
set LNG=cpp
c++ %TID%.cpp
.\a.exe %TID% %SID% %LNG%
del /f /s /q /a .\out.txt >nul
del /f /s /q /a .\in.txt >nul
del /f /s /q /a .\*.exe >nul
pause