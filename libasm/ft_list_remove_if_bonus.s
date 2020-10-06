# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_remove_if_bonus.s                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 20:04:23 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 15:56:05 by micarras         ###   ########.fr        #
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
; xor r*x, r*x (eg: line 35)
;
; rdi = t_list **begin, rsi = *data_ref, rdx = int (*cmp)(data, data_ref),
; rcx = void (*free_fct)(data)

						section 	.text
						global 		ft_list_remove_if
						extern		free
														; delete rdi, r8
ft_list_remove_if:		push		rbp					; save rbp (tmp)  
						push		rbx					; save rbx (previous)
						push		r12					; save r12 (first)
						mov			r12, [rdi]			; r12 = *begin
						xor			ebx, ebx			; previous = 0
						cmp			rdi, 0
						jz			return				; goto return if rdi == 0
						cmp			rdx, 0
						jz			return				; goto return if rdx == 0
						cmp			rcx, 0
						jz			return				; goto return if rcx == 0
						jmp			compare_start		; goto compare_start
free_elt				mov			r8, [rdi]			; r8 = *begin
						mov			rbp, [r8 + 8]		; tmp = (*begin)->next
						push		rsi					; save rsi data_ref
						push		rdx					; save rdx cmp()
						push		rcx					; save rcx free_fct()
						push		rdi					; save rdi begin
						mov			rdx, [rdi]			; rdx = *begin
						mov			rdi, [rdx]			; rdi = (*begin)->data
						call		rcx					; (*free_fct)((*begin)->data)
						pop			rdi					; restore rdi
						push		rdi					; save rdi
						mov			rdx, [rdi]			; rdx = *begin
						mov			rdi, rdx			; begin = *begin
						call		free				; free(*begin)
						pop			rdi					; restore rdi
						pop			rcx					; restore rcx
						pop			rdx					; restore rdx
						pop			rsi					; restore rsi
						mov			[rdi], rbp			; *begin = tmp
						cmp			rbx, 0
						jnz			set_previous_next	; goto set_previous_next if previous == 0
						mov			r12, rbp			; first = tmp
						jmp			compare_start		; goto compare start
set_previous_next:		mov			[rbx + 8], rbp		; previous.next = tmp
						jmp			compare_start		; goto compare start
compare_null:			xor			rdi, rsi			; xor begin.data, data_ref
						mov			rax, rdi			; rax = 1 or 0
						jmp			compare_end
move_next:				mov			rbx, [rdi]			; previous = *begin
						mov			r8, [rbx + 8]		; tmp = (*begin)->next
						mov			[rdi], r8			; *begin = tmp
compare_start:			cmp			QWORD [rdi], 0		; QWORD for a full 64 compare
						jz			return				; goto return if *begin == 0
						push		rdi					; save rdi begin
						push		rsi					; save rsi data_ref
						push		rdx					; save rdx cmp()
						push		rcx					; save rcx free_fct()
						mov			r8, [rdi]			; tmp = *begin
						mov			rdi, [r8]			; rdi = begin.data
						cmp			rdi, 0
						jz			compare_null		; goto compare_null if begin.data == 0
						call		rdx					; (*cmp)((*begin)->data, data_ref)
compare_end:			pop			rcx					; restore rcx
						pop			rdx					; restore rdx
						pop			rsi					; restore rsi
						pop			rdi					; restore rdi
						cmp			rax, 0
						jz			free_elt			; goto free_elt if (*cmp) == 0
						jmp			move_next
return:					mov			[rdi], r12			; *begin = first
						pop			r12					; restore r12
						pop			rbx					; restore rbx
						pop			rbp					; restore rbp
						ret
