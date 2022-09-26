; int	strcmp(const char *s1, const char *s2)
; {
; 	while (*s1 == *s2++)
; 		if (*s1++ == 0)
; 			return (0);
; 	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
; }

section	.text
		global	_ft_strcmp

_ft_strcmp:
	mov	rax, 0	; 리턴값, s1, s2의 인덱스 역할
	mov	rbx, 0	; 주솟값 반환 연산을 위해 선언 (bl, cl은 8비트, rbx, rcx는 64비트)
	mov	rcx, 0
	jmp	compare	; compare로 점프

compare:
	mov	bl, BYTE [rdi + rax]	; bl에 [s1주솟값 + 인덱스]이 참조하는 값 대입
	mov	cl, BYTE [rsi + rax]	; cl에 [s2주솟값 + 인덱스]이 참조하는 값 대입
	cmp	bl, cl	; bl과 cl 비교
	jne	nequal	; 다르면 nequal로 점프
	je	equal	; 같으면 equal로 점프

nequal:
	sub	rbx, rcx	; rbx(s1의 주솟값) - rcx(s2의 주솟값)
	mov	rax, rbx	; rax에 연산 결과 대입
	ret

equal:
	cmp	bl, 0	; b1이 0인지 아닌지 비교
	je	end		; 0이면 종료
	inc	rax		; 인덱스 1 증가
	jmp compare	; compare로 점프(반복)

end:
	mov	rax, 0	; rax에 0 대입
	ret



