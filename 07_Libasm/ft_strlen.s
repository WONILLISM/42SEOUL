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
		mov	rax, 0
		jmp	count
count:
		cmp BYTE [rdi + rax], 0
		je	end
		inc	rax
		jmp	count
end:
		ret
