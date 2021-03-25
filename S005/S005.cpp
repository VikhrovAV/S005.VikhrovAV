#include <iostream>

int main()
{
    char s[256];
    char s2[256];
    char f[] = "%s";
    char fd[] = "%d\n";

    _asm {
        //вводим 1 строку
        lea esi, s
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //вводим 2 строку
        lea esi, s2
        push esi
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //сам поиск
        lea ebx, s
        dec ebx
        lea ecx, s2
        b1:
        inc ebx
        mov al, [ebx]
        cmp al, 0
        je b5
        cmp al, [ecx]
        jnz b1
        mov edx,ebx
        b2:
        inc ebx
        inc ecx
        mov al, [ebx]
        cmp al, 0
        je b3
        mov al, [ecx]
        cmp al, 0
        je b4
        cmp al, [ebx]
        je b2
        mov ebx,edx
        lea ecx,s2
        jmp b1
        b3:
        mov al, [ecx]
        cmp al, 0
        jne b5
        b4:
        lea ebx, s
        sub edx, ebx
        push edx
        jmp b6
        //вывод
        b5:
        push ebx
        b6:
        lea ebx, fd
        push ebx
        call printf
        add esp, 8
    }
}

