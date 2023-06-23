#include "cfg.c"

int main(void)
{
    short err = 0;
    _start_msg();
    _loop(&err);

    return (int) err;
}