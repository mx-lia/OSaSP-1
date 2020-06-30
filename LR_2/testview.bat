chcp 65001
ECHO HELLO WORLD
REM показать список каталогов дисков C:,D:
FOR %%A IN (c,d) DO dir %%A:
REM вывести на экран содержимое всех текстовых файлов текущей директории
FOR %%f IN (*.txt) DO type %%f 
IF EXIST D:\Study\OSISP\LR_2\example.txt type example1.txt
ECHO Сейчас будет отформатирован диск C:. Для остановки нажмите Ctrl-Break!
PAUSE
ECHO Вы проигнорировали предупреждение!
ECHO Если Вы действительно хотите отформатировать свой диск, воспользуйтесь командой format c: 
REM Этот комментарий будет выводится на экран
ECHO OFF
REM А этот комментарий не будет выводится на экран 
ECHO ON
PAUSE
:LOOP
ECHO Для остановки нажмите Ctrl-Break!
GOTO LOOP 
