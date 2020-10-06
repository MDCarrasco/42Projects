# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front_bonus.s                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 20:04:23 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 16:02:01 by micarras         ###   ########.fr        #
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
; xor r*x, r*x (eg: line 34)
;
; rdi = t_list **begin, rsi = void *data

						section 	.text
						global 		ft_list_push_front
						extern		malloc
														; delete rcx, rdx, rax
ft_list_push_front:		push		rsp					; align stack
						push		rdi					; save begin
						push		rsi					; save data
						mov			rdi, 16				; rdi = 16
						xor			eax, eax			; rax = 0
						call		malloc				; malloc(16) (sizeof(t_list))
						pop			rsi					; restore rsi (data)
						pop			rdi					; restore rdi (begin)	
						cmp			rax, 0
						jz			return				; goto return if malloc failed
						mov			[rax], rsi			; new.data = data
						mov			rcx, [rdi]			; rcx = *begin
						mov			[rax + 8], rcx		; new.next = *begin
						mov			[rdi], rax			; *begin = new
return:					pop			rsp					; align stack
						ret
