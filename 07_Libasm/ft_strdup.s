; char	*ft_strdup(const char *src)
; {
; 	char	*dest;
; 	int		len;
; 	int		i;

; 	len = 0;
; 	i = 0;
; 	while (src[len])
; 		len++;
; 	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
; 		return (0);
; 	while (src[i])
; 	{
; 		dest[i] = src[i];
; 		i++;
; 	}
; 	dest[i] = '\0';
; 	return (dest);
; }

section	.text
	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	je		end
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

end:
	ret
