@echo off
set TID=_A1G
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A1G_0*
del /f /q .\_A1G_1*
del /f /q .\_A1G_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%