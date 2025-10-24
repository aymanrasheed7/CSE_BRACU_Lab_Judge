@echo off
set TID=_A1F
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A1F_0*
del /f /q .\_A1F_1*
del /f /q .\_A1F_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%