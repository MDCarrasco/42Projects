# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_sort_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 20:04:23 by micarras          #+#    #+#              #
#    Updated: 2020/06/29 18:20:24 by micarras         ###   ########.fr        #
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
; xor r*x, r*x (eg: line 44)
;
; rdi = t_list **begin_list, rsi = int *(cmp())

							section     .text
							global		ft_list_sort

swap:						push 		rdx						; save rdx
							push 		r14						; save r14
							mov 		rdx, [rdi]				; rdx = *begin_list->data
							mov 		r14, [rsi]				; r14 = *begin_list->next->data 
							mov 		QWORD [rdi], r14		; (*begin_list)->data = (*begin_list)->next->data
							mov 		QWORD [rsi], rdx		; (*begin_list)->next->data = (*begin_list)->data 
							xor 		eax, eax				; rax = 0
							pop			r14						; restore r14
							pop			rdx						; restore rdx
							ret									; return rax
ft_list_sort:				cmp 		rdi, 0
							jz 			ft_list_sort_end		; goto ft_list_sort_end if rdi == 0
							cmp			rsi, 0
							jz			ft_list_sort_end		; goto ft_list_sort_end if rsi == 0
							mov			r13, rsi				; r13 = *(cmp())
							mov			r15, [rdi]				; r15 = *begin_list
ft_list_sort_loop1:			cmp			r15, 0
							jz			ft_list_sort_end		; goto ft_list_sort_end if *begin_list == 0
							mov			rdx, [r15 + 8]			; rdx = (*begin_list)->next
							mov			r12, rdx				; r12 = rdx
							call		ft_list_sort_loop2
							mov			r15, rdx
							jmp			ft_list_sort_loop1
ft_list_sort_loop2:			cmp			r12, 0
							jz			ft_list_sort_end		; goto ft_list_sort_end if r12 == 0
							mov			rax, r13				; rax = *(cmp())
							mov			rdi, QWORD [r15]		; rdi = (*begin_list)->data
							mov			rsi, QWORD [r12]		; rsi = (*begin_list)->next->data
							push		rdx
							call		rax						; call cmp()
							pop			rdx
							cmp 		eax, BYTE 0
							jle			ft_list_sort_loop2_end 	; goto ft_list_sort_loop2_end if rax <= 0
							mov			rdi, r15				; rdi = *begin_list
							mov			rsi, r12				; rsi = (*begin_list)->next
							call		swap
							jmp			ft_list_sort_loop2_end
ft_list_sort_loop2_end:		mov			r14, [r12 + 8]			; r14 = r12->next
							mov			r12, r14				; r12 = r14
							jmp			ft_list_sort_loop2
ft_list_sort_end:			ret
