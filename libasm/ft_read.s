# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 14:58:51 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 14:51:22 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER			64-BIT	32-BIT	16-BIT	8-BIT H/L 
;--------------------------------------------------------
; 1 - ACCUMULATOR		RAX		EAX		AX		AH-AL
; 2 - COUNTER			RCX		ECX		CX		CH-CL
; 3 - DATA				RDX		EDX		DX		DH-DL
; 4 - BASE				RBX		EBX		BX		BH-BL

			section 	.text
			global 		ft_read
			extern		__errno_location

ft_read: 	xor			eax, eax		; fd = rdi, buffer = rsi, bytes = rdx
			syscall
			cmp			rax, 0
			jnge		set_err
			ret
set_err:	mov			r10, rax
			call		__errno_location
			neg			r10
			mov			[rax], r10
neg_rax:	mov			rax, -1
			ret							; return (rax) -1
