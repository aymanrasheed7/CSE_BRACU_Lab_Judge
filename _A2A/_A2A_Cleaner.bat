@echo off
set TID=_A2A
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A2A_0*
del /f /q .\_A2A_1*
del /f /q .\_A2A_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%