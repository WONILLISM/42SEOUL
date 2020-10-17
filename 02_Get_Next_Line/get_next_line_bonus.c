#include "get_next_line_bonus.h"

int get_next_line(int fd, char **line)
{
	int byte;
	char buf[BUFFER_SIZE + 1];
	char *tmp_ptr;
	static char *store
}
/*
** int byte : read() 의 반환 값, read 함수를 이용하여 읽은 바이트 수
** char buf[BUFFER_SIZE + 1] : read 함수로 읽어온 내용을 저장하는 공간
** char *tmp_ptr : 개행을 찾기위한 변수
** static char *store[OPEN_MAX] : fd 값에 따라 읽은 데이터를 저장하는 정적 변수
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
** 예외처리 후 처리되지 않은 나머지부분을 처리한다.
*/
