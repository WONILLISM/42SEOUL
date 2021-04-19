section	.text
	global	_ft_write
	extern	___error	; 외부 함수인 ___error 함수 호출하기 위함

_ft_write:
	mov	rax, 0x2000004	; sys_call numver 4 = sys_write 를 rax에 대입
	syscall	; syscall
	jc	_err	; carry flag가 1이면 _err 로 점프
	ret

_err:
	push	rax			; syscall 함수를 호출한 결과의 에러코드인 rax 값을 스택에 push
	call	___error	; __error 함수 호출
	pop		rdx			;
	mov		[rax], rdx
	mov		rax, -1
	ret
