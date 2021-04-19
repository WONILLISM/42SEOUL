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
	pop		rdx			; 스택에 담겨있던 값을 rdx에 저장
	mov		[rax], rdx	; ___error 함수에서 반환된 주소값이 가리키는 곳에 rdx 대입
	mov		rax, -1		; rax에 -1 대입
	ret					; 반환
