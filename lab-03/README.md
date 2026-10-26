
# Лабораторна робота №3. Керування життєвим циклом процесів у C/Linux

## Студент - Пінчук Кирило Григорович ІПЗ-42

### Виконання роботи

1. Результат виконання програми:
    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./process_demo
    Parent: pid=12312, ppid=381
    Child: pid=12313, ppid=12312
    Child executed command echo
    Parent: child finished with coed 0
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./process_demo
    Parent: pid=12323, ppid=381
    Child: pid=12324, ppid=12323
    Child executed command echo
    Parent: child finished with coed 0
    ```

2. Пояснення до програми:
    1. чому fork повертає різні значення батькові й нащадкові: нащадок отримує "0" як сигнал що він є новоствореним процесом, pid батька тут можна не передавати оскільки його завжди можна отримати через "getppid()". В свою чергу батько отримує PID нащадка оскільки в батька може бути багато нащадків й це надійний спосіб їх розрізняти.
    2. що робить execlp: завантажує та запускає нову програму, замінюючи нею поточну.
    3. чому код після успішного exec не виконується: тому що exec замінює цей код повністю новим процесом.
    4. що означає waitpid(pid, &status, 0):
        - pid: ідентифікатор нащадка на заверщення якого чекає батько.
        - &status: вказівник на змінну куди ядро запише інформацію про завершення нащадка.
        - 0: батьківський процес переходить у стан очікування доки нащадок із заданим pid не завершиться.
3. Програма з ls -la:
    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./process_demo
    Parent: pid=12370, ppid=381
    Child: pid=12371, ppid=12370
    total 32
    drwxrwxrwx 1 kyrya kyrya  4096 Oct 26 17:35  .
    drwxrwxrwx 1 kyrya kyrya  4096 Oct 26 16:55  ..
    -rwxrwxrwx 1 kyrya kyrya  6752 Oct 26 17:33  README.md
    -rwxrwxrwx 1 kyrya kyrya   738 Oct 26 17:02 '\'
    -rwxrwxrwx 1 kyrya kyrya 16352 Oct 26 17:35  process_demo
    -rwxrwxrwx 1 kyrya kyrya   710 Oct 26 17:35  process_demo.c
    Parent: child finished with coed 0
    ```

4. Програма з навмисною помилкою:
    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./process_demo
    Parent: pid=12458, ppid=381
    Child: pid=12459, ppid=12458
    execlp: No such file or directory
    Parent: child finished with coed 127
    ```

5. Пояснення до програми:
    1. що вивела функція perror: функція вивела повідомлення про помилку через те шо не існує названої директорії чи файлу.
    2. чому код завершення 127: тому що команда _exit негайно завершила процес й передала відповідний код (стандартний POSIX-код для "команду/програму не знайдено").

6. Результат виконання програми:
    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./worker_children
    Child 0: code fineshed 10
    Child 1: signal 6
    Child 2: code fineshed 12
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-03$ ./worker_children
    Child 0: code fineshed 10
    Child 1: signal 6
    Child 2: code fineshed 12
    ```

7. Пояснення до програми:
    1. чому нащадок 1 завершився від сигналу, а решта — із звичайним кодом завершення: в циклі було прописано що якщо нащадок першої ітерації (починаючи з нуля), то він виконує abort(). Це не дозволило йому досягти рядка _exit(10+i) який завершує роботу зі звичайним кодом завершення.
    2. перевірте чи завжди звіт друкується в тому самому порядку, чому: так, звіт завжди друкується в одному порядку. Це досягається завдяки команді waitpid, яка послідовно викликається в циклі за конкретним масивом PID (pids[i]), призупиняючи програму до завершення саме $i$-го нащадка, що гарантує суворий порядок виведення результатів ($0, 1, 2$).