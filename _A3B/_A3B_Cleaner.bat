@echo off
set TID=_A3B
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A3B_0*
del /f /q .\_A3B_1*
del /f /q .\_A3B_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%