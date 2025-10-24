@echo off
set TID=_A5F
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A5F_0*
del /f /q .\_A5F_1*
del /f /q .\_A5F_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%