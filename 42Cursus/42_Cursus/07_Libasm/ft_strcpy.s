; char	*ft_strcpy(char *dst, char *src)
; {
; 	char	*tmp;

; 	tmp = dst;
; 	while(*tmp = *src++)
; 		;
; 	return (dst);
; }

section	.text
		global	_ft_strcpy

_ft_strcpy:
	mov	rax, 0	; 리턴할 값, 인덱스로 사용할 rax 레지스터 0으로 초기화
	cmp rsi, 0	; rsi(src 데이터의 주소)가 0인지 아닌지 비교
	je	end		; 0이라면 end로 점프

copy:
	mov	cl, BYTE [rsi + rax]	; cl(8비트 카운터 레지스터)에 BYTE(부호x, 1byte, rsi + rax 주소 참조)를 대입
	mov	BYTE [rdi + rax], cl	; BYTE (rdi(dst 데이터의 주소) + rax)에, cl 대입
	cmp	cl, 0					; cl이 0인지 아닌지 비교
	je	end						; 0이라면 end로 점프
	inc	rax						; rax += 1
	jmp	copy					; copy 반복

end:
	mov	rax, rdi				; rax에 rdi 대입
	ret
