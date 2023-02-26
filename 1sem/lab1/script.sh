#!/bin/bash

# Вывели путь к текущему местоположению
echo 'Current path: '`pwd`

# Записали строку в file.txt
echo 'Test_message' > file.txt

# Создали пустую директорию
mkdir temporary_folder

# Переместили file.txt в temporary_folder
mv file.txt temporary_folder  

pushd temporary_folder

echo test message 2 > file.txt

# Записали содержимое file.txt в file2.txt и удалили file.txt
cat file.txt >> file2.txt
rm file.txt

ls | grep f > file2.txt

echo 'вывожу файлы, в названии кторых есть "f": ' &&  cat file2.txt
 
find /home   -name "*.sh" 1>result.txt 2>/dev/null

echo 'Пути ко всем скриптам: '
cat result.txt
echo

popd

# Удаляем директрию и все файлы внутри
rm -r temporary_folder

echo 'Done!'