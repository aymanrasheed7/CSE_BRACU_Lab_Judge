@echo off
set TID=_600
@REM for %%a in ("%CD%") do set TID=%%~nxa
set SID=00000000
set LNG=py
c++ %TID%.cpp
.\a.exe %TID% %SID% %LNG%
del /f /q .\*.exe >nul 2>&1
del /f /q .\*.class >nul 2>&1
rd /s /q __pycache__ >nul 2>&1
pause