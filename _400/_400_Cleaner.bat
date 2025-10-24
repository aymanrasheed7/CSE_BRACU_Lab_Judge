@echo off
set TID=_400
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_400_0*
del /f /q .\_400_1*
del /f /q .\_400_2*
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%