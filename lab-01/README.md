
# Лабораторна робота №1. Навігація, маніпулювання файловою ієрархією та базова фільтрація даних у GNU Bash

## Студент - Пінчук Кирило Григорович ІПЗ-42


### Виконання роботи

1. Назва оболонки, версія, поточний каталог, назва користувача:

    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-01$ bash --version
    GNU bash, version 5.3.9(1)-release (x86_64-pc-linux-gnu)
    Copyright (C) 2025 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>

    This is free software; you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-01$ pwd
    /mnt/c/Projects/College/OS/lab-01
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-01$ whoami
    kyrya

2. Які файли показала команда ls -la у щойно створеній папці:

    ```bash
    kyrya@HOME:/mnt/c/Projects/College/OS/lab-01$ ls -la
    total 4
    drwxrwxrwx 1 kyrya kyrya 4096 Oct 23 10:24 .
    drwxrwxrwx 1 kyrya kyrya 4096 Oct 23 10:31 ..
    -rwxrwxrwx 1 kyrya kyrya 3802 Oct 23 10:37 README.md
    drwxrwxrwx 1 kyrya kyrya 4096 Oct 23 10:23 backup
    drwxrwxrwx 1 kyrya kyrya 4096 Oct 23 10:23 data
    drwxrwxrwx 1 kyrya kyrya 4096 Oct 23 10:23 reports

3. Що робить:

    - sort: сортує елементи файлу за певним параметром (за замовчуванням в алфавітному-зростаючому)
    - grep: вибирає ті елементи, в яких міститься вказаний текст
    - wc -l: виводить кількість рядочків у файлі
    - cut: вибирає частину елементи за певним параметром (наприклад, все що перед пробілом)
    - tail: вибирає певну кількість елементів починаючи з кінця
    - uniq: залишає тільки один елемнт з вибірки де вони повторюються
    - символ |: дозволяє об'єднувати команди в порядку написання зліва-направо