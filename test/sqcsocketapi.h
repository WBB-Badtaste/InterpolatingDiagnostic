/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: firmware
 *  Subsystem Name: sqc
 *  %full_filespec: sqcsocketapi.h`16:incl:1 %
 */
/**
 *  @file
 *  @brief  Public interface to the socket functionality of SQC subsystem.
 *
 */
#ifndef __SQCSOCKETAPI_H__
#define __SQCSOCKETAPI_H__

#include <stddef.h>

/*
 * Use Winsock2 API when using in simulation
 */
#ifdef NT
#ifndef _WINSOCK2API_
#ifndef _WINSOCKAPI_
#pragma message("winsock.h already included, probably by windows.h. Define WIN32_LEAN_AND_MEAN before including windows.h.")
#endif
#include <winsock2.h>
#endif

#pragma comment(lib,"ws2_32.lib") //Winsock2 Library

#endif

#include "nyceint.h"

#ifdef __cplusplus
    extern "C"
    {
#endif

/*-----------------------------------------------------------------------
 * DOCUMENTATION GROUPING
 *-----------------------------------------------------------------------
 */

/**
 *  @ingroup sqc
 *
 *  @defgroup sqc_socket Socket functionality
 *
 *  This module contains the data structure and function definitions for the socket functionality.
 *  @{
 */

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------
 */
/**
 *  @brief  Sequence limitations.
 */
#define SQC_MAX_BUFFER_SIZE  176                /**< Maximum buffer size to use in recv and send */
#define SQC_MAX_NR_OF_OPEN_SOCKETS 8            /**< Maximum number of open sockets per sequence */

#ifdef errno
#undef errno    // errno will be redefined; it depends on the target to build on.
#endif
/**
 *  @brief  Macro to read errno as used by Berkeley sockets
 */
#define errno SqcGetErrno()


/*
 * Sequences Simulation support
 */
#ifdef NT

/*
 * Defines for the most likely socket errors.
 */
#define EINTR           WSAEINTR                /**< Interrupted system call */
//#define EIO             5                       /**< I/O error */
#define EBADF           WSAEBADF                /**< Bad file number */
//#define EAGAIN          11                      /**< Try again */
//#define ENOMEM          12                      /**< Out of memory */
#define EACCES          WSAEACCES               /**< Permission denied */
#define EFAULT          WSAEFAULT               /**< Bad address */
#define EINVAL          WSAEINVAL               /**< Invalid argument */
//#define ENFILE          23                      /**< File table overflow */
#define EMFILE          WSAEMFILE               /**< Too many open files */
#define EPIPE           WSAENOTCONN             /**< Broken pipe */
#define EPROTO          WSAEPROTOTYPE           /**< Protocol error */
//#define EBADFD          77                      /**< File descriptor in bad state */
#define ENOTSOCK        WSAENOTSOCK             /**< Socket operation on non-socket */
#define EDESTADDRREQ    WSAEDESTADDRREQ         /**< Destination address required */
#define EMSGSIZE        WSAEMSGSIZE             /**< Message too long */
#define EOPNOTSUPP      WSAEOPNOTSUPP           /**< Operation not supported on transport endpoint */
#define EAFNOSUPPORT    WSAEAFNOSUPPORT         /**< Address family not supported by protocol */
#define EADDRINUSE      WSAEADDRINUSE           /**< Address already in use */
#define ENETUNREACH     WSAENETUNREACH          /**< Network is unreachable */
#define ECONNABORTED    WSAECONNABORTED         /**< Software caused connection abort */
#define ECONNRESET      WSAECONNRESET           /**< Connection reset by peer */
#define ENOBUFS         WSAENOBUFS              /**< No buffer space available */
#define EISCONN         WSAEISCONN              /**< Transport endpoint is already connected */
#define ENOTCONN        WSAENOTCONN             /**< Transport endpoint is not connected */
#define ETIMEDOUT       WSAETIMEDOUT            /**< Connection timed out */
#define ECONNREFUSED    WSAEADDRNOTAVAIL        /**< Connection refused */

/**
 *  @brief  Socket length type definition.
 */
typedef int32_t socklen_t;

#define SqcGetErrno WSAGetLastError

#else
/* Real mode specifics */

/*
 * Defines for the most likely socket errors.
 */
#define EINTR           4                       /**< Interrupted system call */
#define EIO             5                       /**< I/O error */
#define EBADF           9                       /**< Bad file number */
#define EAGAIN          11                      /**< Try again */
#define ENOMEM          12                      /**< Out of memory */
#define EACCES          13                      /**< Permission denied */
#define EFAULT          14                      /**< Bad address */
#define EINVAL          22                      /**< Invalid argument */
#define ENFILE          23                      /**< File table overflow */
#define EMFILE          24                      /**< Too many open files */
#define EPIPE           32                      /**< Broken pipe */
#define EPROTO          71                      /**< Protocol error */
#define EBADFD          77                      /**< File descriptor in bad state */
#define ENOTSOCK        88                      /**< Socket operation on non-socket */
#define EDESTADDRREQ    89                      /**< Destination address required */
#define EMSGSIZE        90                      /**< Message too long */
#define EOPNOTSUPP      95                      /**< Operation not supported on transport endpoint */
#define EAFNOSUPPORT    97                      /**< Address family not supported by protocol */
#define EADDRINUSE      98                      /**< Address already in use */
#define ENETUNREACH     101                     /**< Network is unreachable */
#define ECONNABORTED    103                     /**< Software caused connection abort */
#define ECONNRESET      104                     /**< Connection reset by peer */
#define ENOBUFS         105                     /**< No buffer space available */
#define EISCONN         106                     /**< Transport endpoint is already connected */
#define ENOTCONN        107                     /**< Transport endpoint is not connected */
#define ETIMEDOUT       110                     /**< Connection timed out */
#define ECONNREFUSED    111                     /**< Connection refused */

/**
 *  @brief  Supported protocol definitions.
 */
#define AF_INET         2                       /**< IP protocol family */
#define SOCK_STREAM     1                       /**< Sequenced, reliable, connection-based byte streams */
#define IPPROTO_TCP     6                       /**< Transmission Control Protocol */
#define INADDR_ANY      (uint32_t)0x00000000    /**< all local host interfaces */

#define INVALID_SOCKET ((SOCKET)-1)             /**< Generic failure code. Use this error check code to be enable to build&run a sequence in real and in simulation mode. */


/*-----------------------------------------------------------------------
 * DATA TYPES
 *-----------------------------------------------------------------------
 */
typedef int32_t SOCKET;                         /**< File descriptor for a socket. Use this type to be enable to build&run a sequence in real and in simulation mode. */

/**
 *  @brief  Base structure to store most addresses.
 */
typedef struct sockaddr
{
    uint16_t sa_family;             /**< address family */
    char     sa_data[14];           /**< up to 14 bytes of direct address */
} SOCKADDR;

/**
 *  @brief  Internet address.
 */
typedef struct s_un_b
{
    uint8_t s_b1;
    uint8_t s_b2;
    uint8_t s_b3;
    uint8_t s_b4;
} S_UN_B;

typedef struct s_un_w
{
    uint16_t s_w1;
    uint16_t s_w2;
} S_UN_W;

typedef union s_un
{
    S_UN_B   S_un_b;
    S_UN_W   S_un_w;
    uint32_t S_addr;
} S_UN;

typedef struct in_addr
{
    S_UN S_un;
} IN_ADDR;

#define s_addr  S_un.S_addr         /**< can be used for most tcp & ip code */
#define s_host  S_un.S_un_b.s_b2    /**< host on imp */
#define s_net   S_un.S_un_b.s_b1    /**< network */
#define s_imp   S_un.S_un_w.s_w2    /**< imp */
#define s_impno S_un.S_un_b.s_b4    /**< imp # */
#define s_lh    S_un.S_un_b.s_b3    /**< logical host */


/**
 *  @brief  Socket address, internet style sockaddr.
 */
typedef struct sockaddr_in
{
    int16_t  sin_family;      /**< address family */
    uint16_t sin_port;        /**< port number */
    IN_ADDR  sin_addr;        /**< IPv4 address */
    int8_t   sin_zero[8];
} SOCKADDR_IN;

/**
 *  @brief  Socket length type definition.
 */
typedef uint32_t socklen_t;

/*-----------------------------------------------------------------------
 * FUNCTION DECLARATIONS
 *-----------------------------------------------------------------------
 */

/**
 *  @brief  Creates an endpoint for communication and returns a file descriptor for the socket.
 *
 *  @param[in]  domain    The protocol family of the created socket. (Should be AF_INET)
 *  @param[in]  type      Type of connection. (Should be SOCK_STREAM)
 *  @param[in]  protocol  Transport protocol to use. (Should be IPPROTO_TCP)
 *
 *  @return     The newly assigned descriptor.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EACCES, EINVAL, EMFILE, ENFILE, ENOBUFS or ENOMEM
 *     - Other errors may be generated by the underlying protocol modules.
*/
int socket(int domain, int type, int protocol);

/**
 *  @brief  Assigns a socket to an address.
 *
 *  When a socket is created using socket(), it is only given a protocol family, but not assigned an
 *  address. This association with an address must be performed with the bind() system call before
 *  the socket can accept connections to other hosts.
 *
 *  @param[in]  sockFd   Descriptor representing the socket to bind on.
 *  @param[in]  pMyAddr  The address to bind to.
 *  @param[in]  addrLen  Size of the sockaddr structure.
 *
 *  @retval 0   On success.
 *  @retval -1  An error occured. errno contains detailed error code:
 *     - EACCES, EADDRINUSE, EBADF, EINVAL or ENOTSOCK
 *     - Other errors may be generated by the underlying protocol modules.
 */
int bind(int sockFd, const SOCKADDR *pMyAddr, socklen_t addrLen);

/**
 *  @brief  Prepares for incoming connections.
 *
 *  Once a connection is accepted, it is dequeued.
 *
 *  @param[in]  sockFd   A valid socket descriptor.
 *  @param[in]  backLog  Number of pending connections that can be queued.
 *
 *  @retval 0   On success.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EADDRINUSE, EBADF or ENOTSOCK
 *     - Other errors may be generated by the underlying protocol modules.
 */
int listen(int sockFd, int backLog);

/**
 *  @brief  Accept a received incoming attempt to create a new TCP connection.
 *
 *  The server creates a new socket associated with the socket address pair of this connection.
 *
 *  @remark The application (another sequence) must be listening for connections.
 *
 *  @param[in]      sockFd    Descriptor of the listening socket that has the connection queued.
 *  @param[out]     pCliAddr  Structure to receive the address information of the client.
 *  @param[in,out]  pAddrLen  Size of the client address structure.
 *
 *  @return     The new socket descriptor identifier.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EBADF, ECONNABORTED, EFAULT, EINTR, EINVAL, EMFILE, ENFILE, ENOBUFS, ENOMEM, ENOTSOCK or EPROTO
 *     - Other errors may be generated by the underlying protocol modules.
 */
int accept(int sockFd, SOCKADDR *pCliAddr, socklen_t *pAddrLen);

/**
 *  @brief  Receive data from a remote.
 *
 *  If no data is available, the receive blocks.
 *
 *  @param[in]  sockFd  Descriptor connected to the remote.
 *  @param[out] pBuf    size(len); Buffer to store received data.
 *  @param[in]  len     max(SQC_MAX_BUFFER_SIZE); Maximum number of bytes to receive.
 *  @param[in]  flags   Special purpose (Should be 0).
 *
 *  @return     Number of bytes received.
 *  @retval 0   A remote has closed the connection.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EBADF, ECONNREFUSED, EFAULT, EINTR, EINVAL, ENOMEM, ENOTCONN, ENOTSOCK or EMSGSIZE
 *     - Other errors may be generated by the underlying protocol modules.
 */
int recv(int sockFd, void *pBuf, size_t len, int flags);

/**
 *  @brief  Send data to a remote.
 *
 *  @param[in]  sockFd  Descriptor connected to the remote.
 *  @param[in]  pBuf    size(len); Data to send.
 *  @param[in]  len     max(SQC_MAX_BUFFER_SIZE); Number of bytes to send.
 *  @param[in]  flags   Special purpose (Should be 0).
 *
 *  @return     Number of bytes sent.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EBADF, ECONNRESET, EDESTADDRREQ, EFAULT, EINTR, EINVAL, EISCONN, EMSGSIZE,
 *     - ENOBUFS, ENOMEM, ENOTCONN, ENOTSOCK or EOPNOTSUPP
 *     - Other errors may be generated by the underlying protocol modules.
 */
int send(int sockFd, const void *pBuf, size_t len, int flags);

/**
 *  @brief  Terminate the connection and release resources allocated to the socket.
 *
 *  @param[in]  sockFd  The socket to close.
 *
 *  @retval 0   On success.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EBADF, EINTR or EIO
 *     - Other errors may be generated by the underlying protocol modules.
 */
int closesocket(int sockFd);

/**
 *  @brief  Connect a socket, identified by its file descriptor, to a remote host
 *          specified by that host's address in the argument list.
 *
 *  @param[in]  sockFd     Descriptor representing the local socket to connect.
 *  @param[in]  pServAddr  The address to connect to.
 *  @param[in]  addrLen    Size of the sockaddr structure.
 *
 *  @retval 0   On success.
 *  @retval -1  An error occurred. errno contains detailed error code:
 *     - EADDRINUSE, EAGAIN, EBADFD, ECONNREFUSED, EFAULT, EINTR, EISCONN, ENETUNREACH,
 *     - ENOTSOCK or ETIMEDOUT
 *     - Other errors may be generated by the underlying protocol modules.
 */
int connect(int sockFd, const SOCKADDR *pServAddr, socklen_t addrLen);

/**
 *  @brief  Convert short from host to network byte ordering.
 *
 *  @param[in]  hs  Number to be converted.
 *
 *  @return Converted number.
 */
uint16_t htons(uint16_t hs);

/**
 *  @brief  Convert long from host to network byte ordering.
 *
 *  @param[in]  hl  Number to be converted.
 *
 *  @return Converted number.
 */
uint32_t htonl(uint32_t hl);

/**
 *  @brief  Convert short from network to host byte ordering.
 *
 *  @param[in]  ns  Number to be converted.
 *
 *  @return Converted number.
 */
uint16_t ntohs(uint16_t ns);

/**
 *  @brief  Convert long from network to host byte ordering.
 *
 *  @param[in]  nl  Number to be converted.
 *
 *  @return Converted number.
 */
uint32_t ntohl(uint32_t nl);


/**
 *  @brief Function to retrieve the internal socket errno value.
 *
 *  @return     socket errno value.
 */
int SqcGetErrno(void);


#endif

/**
 *  @}
 */ /* End group sqc_socket */

#ifdef __cplusplus
    }
#endif

#endif /* __SQCSOCKETAPI_H__ */
