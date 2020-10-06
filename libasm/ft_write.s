# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 13:51:33 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 14:51:49 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; # - REGISTER			64-BIT	32-BIT	16-BIT	8-BIT H/L 
;--------------------------------------------------------
; 1 - ACCUMULATOR		RAX		EAX		AX		AH-AL
; 2 - COUNTER			RCX		ECX		CX		CH-CL
; 3 - DATA				RDX		EDX		DX		DH-DL
; 4 - BASE				RBX		EBX		BX		BH-BL

			section 	.text
			global 		ft_write
			extern		__errno_location

ft_write:	mov			rax, 1			; fd = rdi, buffer = rsi, bytes = rdx
			syscall
			cmp			rax, 0
			jnge		set_err			; if rax < 0 goto set err
			ret							; return (rax)
set_err:	mov			r10, rax		; r10 = rax
			call		__errno_location
			neg			r10
			mov			[rax], r10		; set errno
neg_rax:	mov			rax, -1	
			ret
