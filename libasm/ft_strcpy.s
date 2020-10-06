# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 12:21:13 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 14:19:37 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER			64-BIT	32-BIT	16-BIT	8-BIT H/L 
;--------------------------------------------------------
; 1 - ACCUMULATOR		RAX		EAX		AX		AH-AL
; 2 - COUNTER			RCX		ECX		CX		CH-CL
; 3 - DATA				RDX		EDX		DX		DH-DL
; 4 - BASE				RBX		EBX		BX		BH-BL
;
; in 64 bits mode, all instructions implicitly zero the upper 32 bits when 
; writing the lower 32 bits so xor e*x, e*x is smaller and faster than
; xor r*x, r*x (eg: lines 27 and 28)

			section 	.text
			global 		ft_strcpy
											; delete rdx, rcx, rax
ft_strcpy: 	xor 		ecx, ecx			; src = rsi, dest = rdi, i = 0
			xor 		edx, edx			; tmp = 0
			cmp 		rsi, 0				; rsi == 0
			jz 			return				; goto return if rsi == 0
			jmp 		copy
increment:	inc			rcx					; i++
copy:		mov 		dl, BYTE[rsi + rcx] ; dl = rsi[i]
			mov 		BYTE[rdi + rcx], dl ; rdi[i] = dl
			cmp 		dl, 0				; dl == 0
			jnz			increment			; goto increment if dl != 0
return:		mov 		rax, rdi			; rax = dest
			ret								; return (rax);
