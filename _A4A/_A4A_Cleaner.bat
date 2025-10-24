@echo off
set TID=_A4A
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A4A_0*
del /f /q .\_A4A_1*
del /f /q .\_A4A_2*
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%