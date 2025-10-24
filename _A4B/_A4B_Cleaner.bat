@echo off
set TID=_A4B
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A4B_0*
del /f /q .\_A4B_1*
del /f /q .\_A4B_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%