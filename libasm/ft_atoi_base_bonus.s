# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 20:04:23 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 16:53:36 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER          64-BIT  32-BIT  16-BIT  8-BIT H/L
;--------------------------------------------------------
; 1 - ACCUMULATOR       RAX     EAX     AX      AH-AL
; 2 - COUNTER           RCX     ECX     CX      CH-CL
; 3 - DATA              RDX     EDX     DX      DH-DL
; 4 - BASE              RBX     EBX     BX      BH-BL
;
; in 64bits mode, all instructions implicitly zero the upper 32 bits when
; writing the lower 32 bits so xor e*x, e*x is smaller and faster than
; xor r*x, r*x (eg: lines 29, 20)
;
; rdi = *str, rsi = *base

						section 	.text
						global 		ft_atoi_base
														; delete r8, r9, r10 and rax
ft_atoi_base: 			push		rbx 				; save rbx (sign)
						push		r12					; save r12 (base_length)
						xor			eax, eax			; total = 0
						xor			ebx, ebx			; sign = 0
						xor			r12, r12			; base_length = 0
						jmp			base_check_loop		; goto base_check_loop
base_check_increment:	inc			r12					; base_length++
base_check_loop:		cmp			BYTE[rsi + r12], 0
						jz			base_check_end		; goto base_check_end if base[r12] == 0
						mov			r8, r12				; i = base_length
base_check_dup_inc:		inc			r8					; i++
base_check_dup_loop:	cmp			BYTE[rsi + r8], 0	; BYTE for char compare
						jz			base_check_correct	; goto base_check_correct if b[i] == 0
						mov			r9b, [rsi + r8]		; r9b = next char
						cmp			BYTE[rsi + r12], r9b
						jz			set_rax				; goto set_rax if b[b_l] == b[i]
						jmp			base_check_dup_inc	; goto base_check_dup_inc
base_check_correct:		cmp			BYTE[rsi + r12], 32
						jz			set_rax				; goto set_rax if b[b_l] == ' '
						cmp			BYTE[rsi + r12], 43
						jz			set_rax				; goto set_rax if b[b_l] == '+'
						cmp			BYTE[rsi + r12], 45
						jz			set_rax				; goto set_rax if b[b_l] == '-'
						cmp			BYTE[rsi + r12], 9
						jz			set_rax				; goto set_rax if b[b_l] == '\t'
						cmp			BYTE[rsi + r12], 10
						jz			set_rax				; goto set_rax if b[b_l] == '\n'
						cmp			BYTE[rsi + r12], 13
						jz			set_rax				; goto set_rax if b[b_l] == '\r'
						cmp			BYTE[rsi + r12], 11
						jz			set_rax				; goto set_rax if b[b_l] == '\v'
						cmp			BYTE[rsi + r12], 12
						jz			set_rax				; goto set_rax if b[b_l] == '\f'
						jmp			base_check_increment; goto base_check_increment
base_check_end:			cmp			r12, 1
						jle			set_rax				; goto set_rax if base_length <= 1
						xor			r8, r8				; i = 0
						jmp			skip_whitespaces	; goto skip_whitespaces	
skip_whitespaces_inc:	inc			r8					; i++
skip_whitespaces:		cmp			BYTE[rdi + r8], 32
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == ' '
						cmp			BYTE[rdi + r8], 9
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == '\t'
						cmp			BYTE[rdi + r8], 10
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == '\n'
						cmp			BYTE[rdi + r8], 13
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == '\r'
						cmp			BYTE[rdi + r8], 11
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == '\v'
						cmp			BYTE[rdi + r8], 12
						jz			skip_whitespaces_inc; goto skip_whitespaces_inc if str[i] == '\f'
						jmp			check_sign			; goto check_sign
is_negative:			xor			bl, 0x00000001		; bl = 0x00000001 (1 byte)
is_positive:			inc			r8					; i++
check_sign:				cmp			BYTE[rdi + r8], 45
						jz			is_negative			; goto is_negative if str[i] == '-'
						cmp			BYTE[rdi + r8], 43
						jz			is_positive			; goto is_positive if str[i] == '+'
						jmp			atoi_loop			; goto atoi_loop
atoi_increment:			inc			r8					; i++
atoi_loop:				cmp			BYTE[rdi + r8], 0
						jz			set_rax				; goto set_rax if str[i] == 0
						xor			r9, r9				; j = 0
						jmp			atoi_idx			; goto atoi_idx
atoi_idx_inc:			inc			r9					; j++
atoi_idx:				mov			r10b, BYTE[rsi + r9]; r10b = base[j]
						cmp			r10b, 0
						jz			set_rax				; goto set_rax if base[j] == 0
						cmp			BYTE[rdi + r8], r10b
						jnz			atoi_idx_inc		; goto atoi_idx_inc if str[i] != base[j]
add_to_total:			mul			r12					; total *= base_length
						add			rax, r9				; total += j
						jmp			atoi_increment
set_rax:				mov			eax, eax			; rax = 0
						cmp			rbx, 0
						jz			return				; goto return if rbx == 0
						neg			rax					; ret = -ret
return:					pop			r12					; restore r12
						pop			rbx					; restore rbx
						ret
