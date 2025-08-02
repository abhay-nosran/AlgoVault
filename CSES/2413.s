; NASM x86-64 assembly program equivalent to the given C++ code.
; Precomputes dp[i][0] and dp[i][1] for i=1 to 999999 (adjusted to < 1000100 as in loop).
; Then reads t, and for each test case reads n and outputs (dp[n][0] + dp[n][1]) % mod followed by newline.
; Uses buffered input/output for efficiency.
; Assumes Linux syscalls (adapt for other OS if needed).

section .data
    mod dq 1000000007  ; Modulo value

section .bss
    input_buf resb 1048576    ; Input buffer
    output_buf resb 65536     ; Output buffer
    dp resq 2000000           ; dp[1000000][2] as array of qwords (long long), indexed as dp + i*16 + 0/8 (i from 0 unused)

section .text
    global _start

_start:
    ; Read entire input into buffer
    xor eax, eax          ; sys_read
    xor edi, edi          ; fd=0 (stdin)
    mov rsi, input_buf
    mov edx, 1048576
    syscall
    mov r8, input_buf     ; r8 = input pointer

    ; Precompute dp
    mov qword [dp + 8], 1 ; dp[1][0] = 1 (offset: 16*1 + 0 = 16, but dp+8? Wait, adjust indexing)
    mov qword [dp + 16], 1; dp[1][1] = 1 (dp + 16*1 + 8 = 24, fix to proper offset)

    ; Note: dp base at 0, i=1 at dp+16 (0 for [0][0], 8 for [0][1], but we start from i=1 at dp+16+0=16, dp+16+8=24)
    ; To simplify, let's set dp + 16*1 + 0 = dp+16 for [1][0], dp+24 for [1][1]

    mov rcx, 2            ; i starts from 2
.precompute_loop:
    cmp rcx, 1000000      ; i < 1000100, but loop to 999999
    jge .precompute_end

    ; Offset for i-1: (i-1)*16 + dp
    mov rax, rcx
    dec rax
    shl rax, 4            ; rax = (i-1)*16
    add rax, dp           ; rax = &dp[i-1][0]

    ; dp[i][0] = (2 * dp[i-1][0] + dp[i-1][1]) % mod
    mov rbx, [rax]        ; rbx = dp[i-1][0]
    shl rbx, 1            ; 2 * dp[i-1][0]
    add rbx, [rax + 8]    ; + dp[i-1][1]
    mov rax, rbx
    xor rdx, rdx
    div qword [mod]       ; rdx = rax % mod
    mov rbx, rcx
    shl rbx, 4            ; rbx = i*16
    add rbx, dp
    mov [rbx], rdx        ; dp[i][0] = rdx

    ; dp[i][1] = (dp[i-1][0] + 4 * dp[i-1][1]) % mod
    mov rax, rcx
    dec rax
    shl rax, 4            ; rax = (i-1)*16
    add rax, dp
    mov rbx, [rax + 8]    ; rbx = dp[i-1][1]
    shl rbx, 2            ; 4 * dp[i-1][1]
    add rbx, [rax]        ; + dp[i-1][0]
    mov rax, rbx
    xor rdx, rdx
    div qword [mod]       ; rdx = rax % mod
    mov rbx, rcx
    shl rbx, 4            ; rbx = i*16
    add rbx, dp
    mov [rbx + 8], rdx    ; dp[i][1] = rdx

    inc rcx
    jmp .precompute_loop

.precompute_end:
    ; Read t (number of test cases)
    call read_uint64
    mov r10, rax          ; r10 = t

    mov r9, output_buf    ; r9 = output pointer

    ; Process t test cases
.test_loop:
    test r10, r10
    jz .output_flush

    ; Read n for this test case
    call read_uint64
    mov rbx, rax          ; rbx = n

    ; Compute (dp[n][0] + dp[n][1]) % mod
    mov rcx, rbx
    shl rcx, 4            ; rcx = n*16
    add rcx, dp
    mov rax, [rcx]        ; rax = dp[n][0]
    add rax, [rcx + 8]    ; + dp[n][1]
    xor rdx, rdx
    div qword [mod]       ; rdx = rax % mod

    ; Write the result to output
    mov rax, rdx
    call write_uint64

    call write_newline

    dec r10
    jmp .test_loop

.output_flush:
    ; Write output buffer to stdout
    mov eax, 1            ; sys_write
    mov edi, 1            ; fd=1 (stdout)
    mov rsi, output_buf
    mov rdx, r9
    sub rdx, output_buf   ; rdx = length
    syscall

    ; Exit
    mov eax, 60           ; sys_exit
    xor edi, edi          ; status=0
    syscall

; Function: read_uint64 (reads unsigned 64-bit integer from r8, skips non-digits)
read_uint64:
    push rcx
    xor rax, rax
.loop:
    movzx rcx, byte [r8]
    inc r8
    cmp cl, 0x30          ; < '0'
    jl .end
    cmp cl, 0x39          ; > '9'
    jg .end
    sub cl, 0x30          ; convert to digit
    imul rax, rax, 10
    add rax, rcx
    jmp .loop
.end:
    pop rcx
    ret

; Function: write_uint64 (writes unsigned 64-bit integer to r9, followed by space)
write_uint64:
    push rax
    push rbp
    push rcx
    push rdx
    mov rcx, 10
    mov rbp, rsp
.div:
    xor rdx, rdx
    div rcx
    add rdx, 0x30         ; to ASCII '0'
    sub rsp, 1
    mov byte [rsp], dl
    test rax, rax
    jnz .div
.loop:
    mov cl, byte [rsp]
    add rsp, 1
    mov byte [r9], cl
    inc r9
    cmp rsp, rbp
    jl .loop
    mov byte [r9], 0x20   ; space
    inc r9
    pop rdx
    pop rcx
    pop rbp
    pop rax
    ret

; Function: write_newline (writes \n to r9)
write_newline:
    mov byte [r9], 0x0a
    inc r9
    ret
