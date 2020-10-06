# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 20:04:23 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 15:38:44 by micarras         ###   ########.fr        #
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
; xor r*x, r*x (eg: line 28)

					section 	.text
					global 		ft_list_size
													; delete rsi, rax
ft_list_size:		mov			rsi, rdi			; rsi = rdi = begin			
					xor			eax, eax			; rax = 0
					jmp			count				; goto count
increment:			inc			rax					; rax++
count:				cmp			rdi, 0
					jz			return				; goto return if begin == 0
					mov			rdi, [rdi + 8]		; begin = begin.next
					jmp			increment			; goto increment
return:				mov			rdi, rsi			; begin.next = begin
					ret
