# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 15:10:28 by micarras          #+#    #+#              #
#    Updated: 2020/06/29 15:22:02 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER			64-BIT	32-BIT	16-BIT	8-BIT H/L 
;--------------------------------------------------------
; 1 - ACCUMULATOR		RAX		EAX		AX		AH-AL
; 2 - COUNTER			RCX		ECX		CX		CH-CL
; 3 - DATA				RDX		EDX		DX		DH-DL
; 4 - BASE				RBX		EBX		BX		BH-BL
;
; in 64 bits mode, all instructions implicitly zeroes the upper 32 bits when
; writing the lower 32 bits so xor e*x, e*x is smaller and faster than
; xor r*x, r*x (eg: lines 30, 42, 43 and 51)

				section	.text
				global 	ft_strdup
				extern 	malloc
											; delete rdx, rcx, rax
ft_strdup: 		cmp 	rdi, 0				; rdi = src && rdi == 0
				jz		error				; goto error if rdi == 0
len_start:		xor 	ecx, ecx			; i = 0
				jmp 	len_compare
len_increment:	inc 	rcx					; i++;
len_compare:	cmp 	BYTE[rdi + rcx], 0	; src[i] == 0
				jnz 	len_increment		; goto len_increment if src[i] != 0
malloc_start:	inc 	rcx					; i++
				push 	rdi					; save src
				mov 	rdi, rcx			; rdi = i
				call 	malloc				; rax = malloc(rdi)
				pop 	rdi					; restore src
				cmp 	rax, 0				; rax == 0
				jz 		error				; goto error if rax == 0
copy_start:		xor 	ecx, ecx			; i = 0
				xor 	edx, edx			; tmp = 0
				jmp 	copy_copy
copy_increment:	inc 	rcx					; i++
copy_copy:		mov 	dl, BYTE[rdi + rcx] ; tmp = src[i] 
				mov 	BYTE[rax + rcx], dl	; rax[i] = tmp
				cmp 	dl, 0				; tmp == 0
				jnz 	copy_increment		; goto copy_increment if tmp != 0
				jmp 	return
error:			xor 	eax, eax			; rax = 0
return:			ret
