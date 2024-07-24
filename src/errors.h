#ifndef ERRORS_H_
#define ERRORS_H_

typedef enum {
    SUCCESS = 0,
    FILE_OPEN_ERROR = 1,
    FILE_CLOSE_ERROR = 2,
    MEMORY_ALLOCATION_ERROR = 3,
} ErrorCode;

#endif // ERRORS_H_
