#include "main.h"

SocketException::SocketException(SOCKET_ISSUE_FOR_SERVER Issue)
	: SocketIssue(Issue)
{
	;
}

const char* SocketException::what(void)
{
	switch (SocketIssue)
	{
	case SOCKET_ISSUE_FOR_SERVER::WSAStartup:
		StlIssueMessage = "윈도우 소켓 초기화 실패";
		break;

	case SOCKET_ISSUE_FOR_SERVER::Bind:
		StlIssueMessage = "바인드 실패";
		break;

	case SOCKET_ISSUE_FOR_SERVER::Accept:
		StlIssueMessage = "서버에 대한 클라이언트 접속 실패";
		break;

	case SOCKET_ISSUE_FOR_SERVER::Listen:
		StlIssueMessage = "서버 대기 실패";
		break;

	default:
		StlIssueMessage = "알 수 없는 에러";
	}

	return StlIssueMessage.c_str();
}

SocketException::SOCKET_ISSUE_FOR_SERVER SocketException::GetErrorCode(void)
{
	return SocketIssue;
}