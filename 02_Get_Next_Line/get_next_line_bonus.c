#include "get_next_line_bonus.h"

static int	proc_remain(char **line, char **store, char *tmp_ptr)
{
	char *tmp;

	if (tmp_ptr)
	{
		*line = ft_strndup(*store, tmp_ptr - *store);
		tmp = ft_strndup(tmp_ptr + 1, ft_strlen(tmp_ptr + 1));
		free(*store);
		*store = tmp;
		return (_SUC_READ);
	}
	if (*store)
	{
		*line = *store;
		*store = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int			get_next_line(int fd, char **line)
{
	int			byte;
	char		*buf;
	char		*tmp_ptr;
	static char *store[OPEN_MAX];

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (_ERROR);
	if (!store[fd])
		store[fd] = ft_strndup("", 1);
	while (!(tmp_ptr = ft_strchr(store[fd], '\n')) &&
	(byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		if (store[fd])
			tmp_ptr = ft_strjoin(store[fd], buf);
		else
			tmp_ptr = ft_strndup(buf, byte);
		if (store[fd])
			free(store[fd]);
		store[fd] = tmp_ptr;
	}
	if (byte < 0)
		return (_ERROR);
	return (proc_remain(line, &store[fd], tmp_ptr));
}

/*
** get_next_line
** int byte : read() 의 반환 값, read 함수를 이용하여 읽은 바이트 수
** char buf[BUFFER_SIZE + 1] : read 함수로 읽어온 내용을 저장하는 공간
** char *tmp_ptr : 개행을 찾기위한 변수
** static char *store[OPEN_MAX] : fd 값에 따라 읽은 데이터를 저장하는 정적 변수
** OPEN_MAX : Maximum number of files that one process can have open at any one time.
**     - limit.h에 있음.
**
** if (fd < 0 || !line || BUFFER_SIZE <= 0) 예외처리
**
** 1. while 조건 : 저장된 값 중 개행이 없고, 읽어온 바이트 수가 0보다 클 때 버퍼에 데이터를 저장함
** 2. buf[byte] = 0 : 버퍼의 끝에 널값을 미리 너어둠
** 3. 만약 저장공간에 값이 있으면 strjoin을 이용하여 이어 붙이고 tmp_ptr에 주솟값을 저장해둔다
** 4. 그렇지 않으면 버퍼에 있는 값을 새로 할당하여 tmp_ptr에 주솟값을 저장해둔다.
** 5. store[fd]에 저장된 값이 있으면 해당 메모리를 해제해준다.
** 6. store[fd]에 주솟값을 다시 복사한다.
** 7. 개행을 찾거나 파일의 끝이라면 반복문을 종료하고 그렇지 않으면 반복한다.
**
** 예외처리 후 처리되지 않은 나머지부분을 처리한다. (byte가 음수일 때)
**
** proc_remain
** tmp_ptr에 값이 있으면 -> 이전에 버퍼에서 받아온 값이 남아있음 = 개행문자
**   현재까지 저장된 store뒤에 tmp_ptr - (*store)만큼 *line에 저장
**
*/
