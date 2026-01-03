@echo off
set TID=_A8F
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A8F_0*
del /f /q .\_A8F_1*
del /f /q .\_A8F_2*
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%