;size_t	ft_strlen(const char *s)
;{
;	size_t	i;
;
;	i = 0;
;	while (s[i])
;		i++;
;	return (i);
;}

section	.text
		global	_ft_strlen

_ft_strlen:
	mov	rax, 0	; 리턴값이 s의 인덱스 이므로 rax 레지스터를 인덱스로 사용, 0으로 초기화
	jmp	count	; count lable로 점프
count:
	cmp	BYTE [rdi + rax], 0
	je	end		; 비교연산 결과 두 인자가 같으면 end label로 점프, 아니면 무시
	inc	rax		; NULL이 아니라면 인덱스 +1
	jmp	count	; count label 반복
end:
	ret			; 함수 종료, rax 반환

