StringGenerator.py - python3-скрипт. Принимает три параметра командной строки: имя файла, количество строк, длина строчек. Генерирует случайные строки и записывает в указанный файл.

OuterSort.exe - производит сортировку файла и выводит результат в другой файл. Принимает 3 параметра командной строки:
1) Файл, который нужно отсортировать
2) Файл, в который нужно вывести
3) Число строк, которые будут одновременно загружаться в память. 

Остальное - исходники OuterSort, проект Microsoft Visual Studio.


Описание работы алгоритма: 
1) Считываем из файла кусок указанного размера, сортируем, выводим в промежуточный файл chunk<N>.txt .
2) Повторяем 1), пока не закончатся входные данные.
3) Объединяем все промежуточные файлы в выходной методом k-путевого слияния, где k - их число.
