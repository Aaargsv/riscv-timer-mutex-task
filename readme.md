### compile & run

``` shell
make clean
make
make run
```
### description
Core 0 executes the function *timer_output* and handles timer interrupt.
Core 1 executes main function.
Uart access is synchronized with mutex.
