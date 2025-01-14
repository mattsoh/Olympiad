section .data
    fmt db "%lld", 10, 0             ; Format string for printing (64-bit)

section .bss
    fib resq 100                     ; Reserve space for 100 Fibonacci numbers (64-bit)
    cntt resq 1                      ; Reserve space for cntt (final count)
    a resq 1                         ; Reserve space for variable a (64-bit)
    b resq 1                         ; Reserve space for variable b (64-bit)
    cnt resq 1                       ; Reserve space for variable cnt (64-bit)
    i resq 1                         ; Reserve space for i (64-bit)
    sum resq 1                       ; Reserve space for sum (64-bit)

section .text
    global _start
    extern printf

_start:
    ; Initialize Fibonacci sequence
    mov qword [a], 1                ; a = 1
    mov qword [b], 2                ; b = 2
    mov qword [cnt], 2              ; cnt = 2
    mov qword [fib], 1              ; fib[0] = a
    mov qword [fib+8], 2            ; fib[1] = b

    ; Generate Fibonacci numbers up to 5000000000
generate_fibs:
    mov rax, [a]                    ; rax = a
    add rax, [b]                    ; rax = a + b
    cmp rax, 5000000000             ; Check if fib number exceeds the limit
    jg finish_fib_gen
    mov rdi, rax                    ; Store Fibonacci number into rdi
    mov rbx, [cnt]                  ; Get the current index (cnt)
    mov rdx, fib                    ; Base address of fib array
    add rdx, rbx                    ; Calculate the address fib[rbx]
    mov [rdx], rdi                  ; Store Fibonacci number into the fib array
    mov [a], [b]                    ; Update a = b
    mov [b], rdi                    ; Update b = fib[cnt]
    add qword [cnt], 1               ; Increment cnt
    jmp generate_fibs

finish_fib_gen:
    ; Initialize cntt = 0
    mov qword [cntt], 0

    ; Start loop from 1000000000 to 5000000000
    mov rsi, 1000000000
    jmp check_loop_start

check_loop_start:
    ; Check if the current value satisfies the condition in z(i)
    mov rax, rsi
    call z_function
    cmp rax, 1
    je increment_cntt

    jmp check_next

increment_cntt:
    inc qword [cntt]                 ; cntt++

check_next:
    add rsi, 10000000                ; Increment i by 10000000
    cmp rsi, 5000000000
    jle check_loop_start

finish:
    ; Print cntt (result)
    mov rdi, [cntt]                  ; Load cntt
    mov rsi, fmt                     ; Load format string
    mov rax, 0                       ; Clear rax for printf (in x86-64, rax must be 0 before calling printf)
    call printf

    ; Exit program
    mov rax, 60                      ; sys_exit
    xor rdi, rdi                     ; Exit status 0
    syscall

z_function:
    ; Function z(i)
    mov rbx, 50                      ; Set cnt = 50
    xor rcx, rcx                     ; Set sum = 0
    mov rdx, rsi                     ; i = input argument (passed in rsi)
    jmp z_loop_start

z_loop_start:
    ; Loop through Fibonacci numbers and check the condition
    dec rbx
    mov r8, [fib + rbx*8]            ; fib[cnt]
    add rcx, r8                      ; sum += fib[cnt]
    cmp rcx, rdx                     ; sum < i
    jge z_return_false
    cmp r8, 701408733                ; Check if fib[cnt] == 701408733
    je z_return_false
    cmp rbx, 0                       ; Check if we reached the end of the Fibonacci sequence
    jg z_loop_start

z_return_false:
    mov rax, 0
    ret

z_return_true:
    mov rax, 1
    ret
