@echo off
set TID=_A5F
@REM for %%a in ("%CD%") do set TID=%%~nxa
set SID=00000000
set LNG=cpp
c++ %TID%.cpp
.\a.exe %TID% %SID% %LNG%
del /f /q .\*.exe >nul 2>&1
del /f /q .\*.class >nul 2>&1
rd /s /q __pycache__ >nul 2>&1
pause