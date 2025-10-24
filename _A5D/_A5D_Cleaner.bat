@echo off
set TID=_A5D
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A5D_0*
del /f /q .\_A5D_1*
del /f /q .\_A5D_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%