# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 10:46:00 by micarras          #+#    #+#              #
#    Updated: 2020/06/24 14:50:48 by micarras         ###   ########.fr        #
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
; writing the lower 32 bits so xor eax, eax is smaller and faster than
; xor rax, rax (eg: line 27)

			section		.text
			global 		ft_strlen
											; delete rax
ft_strlen: xor			eax, eax 			; i = 0
			jmp 		compare
increment:	inc			rax 				; i++
compare:	cmp			BYTE[rdi + rax], 0 	; str[i] == 0
			jne			increment			; goto increment if str[i] != 0
done:		ret 							; return (i) rax
