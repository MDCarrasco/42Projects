# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 13:06:01 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 18:11:01 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER			64-BIT	32-BIT	16-BIT	8-BIT H/L 
;--------------------------------------------------------
; 1 - ACCUMULATOR		RAX		EAX		AX		AH-AL
; 2 - COUNTER			RCX		ECX		CX		CH-CL
; 3 - DATA				RDX		EDX		DX		DH-DL
; 4 - BASE				RBX		EBX		BX		BH-BL
;
; in 64 bits mode, all instrucions implicitly zero the upper 32 bits when
; writing the lower 32 bits so xor e*x, e*x is smaller and faster than
; xor r*x, r*x (eg: lines 27 and 28)

			section 	.text
			global 		ft_strcmp
											; delete rdx, rcx, rax
ft_strcmp: 	xor 		ecx, ecx			; s1 = rdi, s2 = rsi, i = 0
			xor 		edx, edx			; cmp = 0
			cmp 		rdi, 0
			jz 			check_null			; goto check_null rdi == 0
			cmp 		rsi, 0
			jz 			check_null			; goto check_null si rsi == 0
			jmp 		check
check_null:	cmp 		rdi, rsi
			jz 			equal				; goto equal si rdi (0) == rsi (0)
			jg 			superior			; goto superior si rdi > 0
			jmp 		inferior
compare:	mov 		dl, BYTE[rsi + rcx] ; tmp = rsi[i]
			cmp 		BYTE[rdi + rcx], dl	
			jnz 		last_char			; goto last_char if rdi[i] != tmp
increment:	inc 		rcx					; i++
check:		cmp 		BYTE[rdi + rcx], 0
			jz 			last_char			; goto last_char if rdi[i] == 0
			cmp 		BYTE[rsi + rcx], 0
			jz 			last_char			; goto last_char if rsi[i] == 0
			jmp 		compare
last_char:	mov 		dl, BYTE[rdi + rcx]	; cmp = rdi[i]
			cmp 		dl, BYTE[rsi + rcx]
			jz 			equal				; goto equal if cmp == 0
			jb 			inferior			; goto inferior if cmp below 0
superior:	mov 		rax, 1
			ret								; return rax
inferior:	mov 		rax, -1
			ret								; return rax
equal:		mov 		rax, 0
			ret								; return rax
