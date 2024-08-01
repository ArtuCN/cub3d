==770040== Memcheck, a memory error detector
==770040== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==770040== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==770040== Command: ./cub3d maps/map3.cub
==770040== 
==770040== Invalid write of size 8
==770040==    at 0x10AB8B: len_mat (parsing_map.c:29)
==770040==    by 0x10AC96: regular_map (parsing_map.c:71)
==770040==    by 0x10A835: main (main.c:36)
==770040==  Address 0x4c05288 is 24 bytes inside a block of size 25 alloc'd
==770040==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==770040==    by 0x10AB4A: len_mat (parsing_map.c:26)
==770040==    by 0x10AC96: regular_map (parsing_map.c:71)
==770040==    by 0x10A835: main (main.c:36)
==770040== 
==770040== Use of uninitialised value of size 8
==770040==    at 0x10B198: check_map (map_checks.c:102)
==770040==    by 0x10ACEC: regular_map (parsing_map.c:78)
==770040==    by 0x10A835: main (main.c:36)
==770040== 
==770040== Use of uninitialised value of size 8
==770040==    at 0x10B169: check_map (map_checks.c:105)
==770040==    by 0x10ACEC: regular_map (parsing_map.c:78)
==770040==    by 0x10A835: main (main.c:36)
==770040== 
==770040== Invalid read of size 1
==770040==    at 0x10B174: check_map (map_checks.c:105)
==770040==    by 0x10ACEC: regular_map (parsing_map.c:78)
==770040==    by 0x10A835: main (main.c:36)
==770040==  Address 0x8949ed31fa1e0ff3 is not stack'd, malloc'd or (recently) free'd
==770040== 
==770040== 
==770040== Process terminating with default action of signal 11 (SIGSEGV)
==770040==  General Protection Fault
==770040==    at 0x10B174: check_map (map_checks.c:105)
==770040==    by 0x10ACEC: regular_map (parsing_map.c:78)
==770040==    by 0x10A835: main (main.c:36)
==770040== 
==770040== HEAP SUMMARY:
==770040==     in use at exit: 40 bytes in 4 blocks
==770040==   total heap usage: 18 allocs, 14 frees, 102 bytes allocated
==770040== 
==770040== LEAK SUMMARY:
==770040==    definitely lost: 0 bytes in 0 blocks
==770040==    indirectly lost: 0 bytes in 0 blocks
==770040==      possibly lost: 0 bytes in 0 blocks
==770040==    still reachable: 40 bytes in 4 blocks
==770040==         suppressed: 0 bytes in 0 blocks
==770040== Rerun with --leak-check=full to see details of leaked memory
==770040== 
==770040== Use --track-origins=yes to see where uninitialised values come from
==770040== For lists of detected and suppressed errors, rerun with: -s
==770040== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
