@echo off
set TID=_A2C
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A2C_0*
del /f /q .\_A2C_1*
del /f /q .\_A2C_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%